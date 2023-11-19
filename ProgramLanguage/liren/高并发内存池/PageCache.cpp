#include "PageCache.h"

PageCache PageCache::_page_instance; // 静态单例对象的定义

// 获取一个k页大小的span
Span* PageCache::new_span(size_t k)
{
	// 如果k大于128的话，则直接向系统申请内存即可
	if (k > PAGELIST_NUMS - 1)
	{
		void* ptr = SystemAlloc(k);

		Span* span = _fixed_pool.apply();
		span->_num = k;
		span->_pid = (page_t)ptr >> PAGE_SHIFT;

		_tables.set(span->_pid, span);
		return span;
	}

	// 1. 看看当前k页大小的哈希桶中是否有可用的span对象，找到了直接将其取出然后进行返回即可
	if (!_spanlists[k].empty())
	{
		Span* span = _spanlists[k].pop_front();

		// 建立back中每个页号和span的映射，方便central cache回收小块内存时，查找对应的span
		for (page_t i = 0; i < span->_num; ++i)
			_tables.set(span->_pid + i, span);

		return span;
	}

	// 2. 没有的话向更大的页大小的哈希桶中查找是否有可用的span对象
	for (int i = k + 1; i < PAGELIST_NUMS; ++i)
	{
		if (!_spanlists[i].empty())
		{
			/* 
				找到了可用的span对象之后，进行切分操作（只需要改变span对象中的属性以及链接关系即可）
				这里采用将前i-k大小的span对象也就是front继续留在该哈希桶中，然后将后半部分k大小的span对象也就是back进行返回！
			*/
			Span* front = _spanlists[i].pop_front();
			Span* back = _fixed_pool.apply();

			// back就是我们要返回的span对象，设置其属性
			back->_pid = front->_pid;
			back->_num = k;

			// 修改front的属性，然后将其插入到i-k大小的哈希桶中！
			front->_pid += k;
			front->_num -= k;
			_spanlists[front->_num].push_front(front);

			/*
				对于front中每个页号与span的映射，我们只需要记录首尾页号即可，因为front是没有分配中心缓存使用的，
				所以后面我们再合并已经分配的那些内存块的时候，是中心发散的去查找内存块左右临近的内存块进行合并的，
				此时我们对于front的页号与span的映射只需要记录下首尾即可，而不需要向back一页每个小内存块的页号都要
				去进行映射，因为back是被分配去使用的，所以需要进行每个页号的映射
			*/
			_tables.set(front->_pid, front);
			_tables.set(front->_pid + front->_num - 1, front);

			// 建立back中每个页号和span的映射，方便central cache回收小块内存时，查找对应的span
			for (page_t i = 0; i < back->_num; ++i)
				_tables.set(back->_pid + i, back);

			return back;
		}
	}

	// 3. 如果所有哈希桶都没有可用的span对象，那么就得向系统申请内存了
	//    当前为windows环境，所以调用的就是windows的接口，这里申请的是128页大小的内存！
	void* ptr = SystemAlloc(PAGELIST_NUMS - 1);

	// 4. 将申请到的内存与span对象进行属性绑定（页号为ptr的地址然后按一页大小进行编号得到即可）
	Span* newspan = _fixed_pool.apply();
	newspan->_num = PAGELIST_NUMS - 1;
	newspan->_pid = (page_t)ptr >> PAGE_SHIFT;
	_spanlists[newspan->_num].push_front(newspan);

	// 5. 这里可用按照上面切分的步骤那样子再写一遍，但是没必要，有更妙的方法：再调用当前函数一次
	/*   
		因为当前新申请到的内存插入到了哈希桶中，但是没有返回给中心缓存使用，如果此时我们再调用一次当前函数的话，
		此时哈希桶中就有span对象挂着了，就会走到上面的第二步去进行span对象的切分和返回，就不需要再写一遍同样的逻辑了！
		这点调用函数的开销，对于程序执行速度来说，是无足挂齿的，并且因为内存是比较连续的，效率也是不低的，所以无需多虑！
	*/ 
	return new_span(k);
}

// 根据传入的内存块地址返回对应的span对象的指针
Span* PageCache::get_span_from_pageID(void* ptr)
{
	// 1. 先根据地址求出其所属的页号
	page_t pid = ((page_t)ptr >> PAGE_SHIFT);

	// 2. 找到对应的页号对应的span指针进行返回，注意查找过程是需要加锁的，并且最好是守卫锁
	/*std::unique_lock<std::mutex> lock(_mtx);
	auto it = _tables.find(pid);
	if (it != _tables.end())
		return it->second;
	else
	{
		assert(false);
		return nullptr;
	}*/
	auto it = (Span*)_tables.get(pid);
	assert(it != nullptr);
	return it;
}

// 将CentralCache传来的span对象合并到页缓存中管理
void PageCache::merge_memory_from_CentralCache(Span* span)
{
	// 大于128页的直接还给系统即可
	if (span->_num > PAGELIST_NUMS - 1)
	{
		void* ptr = (void*)(span->_pid << PAGE_SHIFT);
		SystemFree(ptr);
		_fixed_pool.release(span);
		return;
	}

	// 1. 向前合并空闲的span对象
	while (true)
	{
		// 获取前面一个span对象（如果没有则直接退出）
		page_t prev_pid = span->_pid - 1;
		auto it = (Span*)_tables.get(prev_pid);
		if (it == nullptr)
			break;

		// 如果span对象被使用着，或者和当前span的页数加起来超过了PAGELIST_NUMS-1页的话，则直接退出
		Span* prev_span = it;
		if (prev_span->_is_used == true)
			break;
		if (prev_span->_num + span->_num > PAGELIST_NUMS - 1)
			break;

		// 走到这说明prev_span对象是可以合并的，则将其进行合并操作
		// 合并操作其实只需要修改span的属性即可，然后将原本prev_span从哈希表中去除，最后释放prev_span空间的内容即可
		span->_pid = prev_span->_pid;
		span->_num += prev_span->_num;

		_spanlists[prev_span->_num].erase(prev_span);
		_fixed_pool.release(prev_span);
	}

	// 2. 向后合并空闲的span对象（和上面是类似的操作，就是位置变了而已）
	while (true)
	{
		// 获取后面一个span对象（如果没有则直接退出）
		page_t next_pid = span->_pid + span->_num;
		auto it = (Span*)_tables.get(next_pid);
		if (it == nullptr)
			break;

		// 如果span对象被使用着，或者和当前span的页数加起来超过了PAGELIST_NUMS-1页的话，则直接退出
		Span* next_span = it;
		if (next_span->_is_used == true)
			break;
		if (next_span->_num + span->_num > PAGELIST_NUMS - 1)
			break;

		// 走到这说明next_span对象是可以合并的，则将其进行合并操作
		// 合并操作其实只需要修改span的属性即可，然后将原本next_span从哈希表中去除，最后释放next_span空间的内容即可
		span->_num += next_span->_num;

		_spanlists[next_span->_num].erase(next_span);
		_fixed_pool.release(next_span);
	}

	// 3. 将合并后的span对象插入到page cache的哈希桶中，然后设置其映射关系
	_spanlists[span->_num].push_front(span);
	span->_is_used = false;
	_tables.set(span->_pid, span);
	_tables.set(span->_pid + span->_num - 1, span);
}