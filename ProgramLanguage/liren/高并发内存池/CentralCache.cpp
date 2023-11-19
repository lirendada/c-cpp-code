#include "CentralCache.h"

CentralCache CentralCache::_central_instance; // 静态单例对象的定义

// 从central cache中获取一定数量的对象给thread cache
size_t CentralCache::give_memory_to_ThreadCache(void*& start, void*& end, size_t num, size_t size, size_t index)
{
	// 1. 因为可能多个线程都来获取，所以需要加锁，并且这里是桶锁，所以效率不会很低！
	_spanlists[index].get_mutex().lock();

	// 2. 调用函数获取一个span对象（函数内部会将span对象都插入到spanlists中）
	Span* span = get_span(_spanlists[index], size);
	assert(span != nullptr && span->_freelist != nullptr);

	// 3. 在span对象中定位要获取的内存块的首尾地址（因为有可能不足num个小内存块，所以用actual_num记录实际拿到的内存块）
	size_t actual_num = 1;
	start = span->_freelist;
	end = start;
	size_t i = 0;
	while (i < num - 1 && get_next(end) != nullptr)
	{
		// 因为我们需要将span中的小内存块取走，就需要考虑小内存块个数不足num的情况，就需要判断一下是否下个位置为空
		// 并且我们每次只走num-1步就停下来，这样子方便下面取走小内存块的操作，因为freelist是单向链表！
		end = get_next(end);
		++i;
		++actual_num;
	}

	// 4. 根据首尾地址将内存块从span对象中取出，就是链表删除操作！
	span->_freelist = get_next(end);
	get_next(end) = nullptr;

	// 5. 将使用数量增加实际取到的个数
	span->_use_count += actual_num;

	// 6. 别忘了释放锁
	_spanlists[index].get_mutex().unlock();
	return actual_num;
}

// 获取一个非空的span对象
Span* CentralCache::get_span(SpanList& list, size_t size)
{
	// 1. 遍历当前的spanlist中是否还有未分配对象的span
	Span* it = list.begin();
	while (it != list.end())
	{
		// 存在未分配对象的话直接返回该span即可
		if (it->_freelist != nullptr)
			return it;

		it = it->_next;
	}

	// 2. 因为下面就是向page cache申请内存的操作了，就涉及到page cache的加锁，那么此时
	/*
	    我们可以把中心缓存当前的桶锁释放，这样子就算释放了其它线程，它们也需要进来这个函数，当他们
	    访问下面的new_span()函数的时候还是需要被锁住，不需要担心线程安全问题！
	    不过我们在这提前释放锁的好处就是如果其他线程是释放内存对象回来的话，因为不会被阻塞而提高效率！
	*/
	list.get_mutex().unlock();

	// 3. 走到这里说没有空闲span了，只能找page cache要
	/*
		此时先计算要申请多少页，然后再去申请，并且这个过程要进行加锁！
		之所以不到new_span()函数中去加锁，其实是因为内部有递归调用自己的操作，所以我们就统一在这里处理加锁问题！
		当然如果new_span()函数中使用的是递归锁，或者不使用递归调用自己的操作，那是可用在其内部处理锁问题的！
	*/
	PageCache::get_instance()->get_mutex().lock();
	Span* newspan = PageCache::get_instance()->new_span(AlignClass::get_nums_of_page(size));
	newspan->_is_used = true;
	newspan->_size = size;
	PageCache::get_instance()->get_mutex().unlock();

	// 4. 先计算获取到的span的大小以及span的起始地址（方便后面的遍历切分）
	size_t span_size = newspan->_num << PAGE_SHIFT;
	char* start = reinterpret_cast<char*>(newspan->_pid << PAGE_SHIFT);
	char* end = start + span_size;

	// 5. 然后对获取到的span进行切分，此时不需要加锁，因为这个时候其他线程访问不到这个span局部对象！
	//  5.1 先切一块下来做头节点，方便尾插（头插的话地址是倒着链起来的，缓存命中率会降低）
	void* tail = start;
	newspan->_freelist = tail;
	start += size;

	//  5.2 将剩下的内存块进行尾插
	while (start < end)
	{
		get_next(tail) = start;
		tail = start;
		start += size;
	}
	get_next(tail) = nullptr; // 关键点

	// 6. 切好之后将内存块链接到对应的SpanList上（这里采用头插），但是因为涉及线程安全问题，这里要重新上桶锁
	list.get_mutex().lock();
	list.push_front(newspan);
	return newspan;
}

// 将size大小的内存块合并到对应的span哈希桶中
void CentralCache::merge_memory_from_ThreadCache(void* start, size_t size)
{
	// 1. 获取对应哈希桶下标并且加上桶锁
	size_t index = AlignClass::get_index(size);
	_spanlists[index].get_mutex().lock();

	// 2. 遍历每一个小内存块
	while (start != nullptr)
	{
		// 3. 找到小内存块对应的span对象，并将该小内存块链接到该span上面（先记录下start后面的指针next，防止start修改连接后丢失）
		void* next = get_next(start);
		Span* span = PageCache::get_instance()->get_span_from_pageID(start);
		get_next(start) = span->_freelist;
		span->_freelist = start;

		// 4. 减少span的使用个数，然后判断是否可以回收给PageCache
		span->_use_count--;
		if (span->_use_count == 0)
		{
			// 可以的话调用PageCache对应的接口回收该span对象
			// 再次之前要先将该span对象从central cache中弹出，并且修改span的链接属性
			_spanlists[index].erase(span);
			span->_freelist = nullptr;
			span->_next = span->_prev = nullptr;

			// 因为涉及到页缓存操作，所以需要加锁，并且此时可以顺便先将中心缓存的锁给释放，让其它线程可以执行，提高效率
			_spanlists[index].get_mutex().unlock();
			PageCache::get_instance()->get_mutex().lock();
			PageCache::get_instance()->merge_memory_from_CentralCache(span); // 这步就是PageCache回收span对象的操作
			PageCache::get_instance()->get_mutex().unlock();
			_spanlists[index].get_mutex().lock();
		}

		// 5. 别忘了让start迭代
		start = next;
	}

	// 6. 最后别忘了释放桶锁
	_spanlists[index].get_mutex().unlock();
}