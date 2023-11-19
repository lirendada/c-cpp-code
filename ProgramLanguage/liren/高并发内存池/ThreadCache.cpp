#include "ThreadCache.h"

// 申请内存接口
void* ThreadCache::allocate(size_t size)
{
	assert(size <= THREAD_MAX_SIZE); // 要求申请的空间是小于256KB的

	// 获取对齐数和下标，然后进行判断：
	//  1. 如果对应哈希桶中存在空闲的空间，则将其分配出来即可
	//  2. 如果没有空闲空间，则向下一层central cache进行内存申请
	size_t align_num = AlignClass::get_align(size);
	size_t index = AlignClass::get_index(size);
	if (!_freelists[index].empty())
		return _freelists[index].pop();
	else
		return fetch_from_CentralCache(index, align_num);
}

// 释放内存接口
void ThreadCache::deallocate(void* ptr, size_t size)
{
	assert(size <= THREAD_MAX_SIZE); // 要求申请的空间是小于256KB的
	assert(ptr != nullptr);

	// 将ptr指向的空间插入到对应的哈希桶中即可
	size_t index = AlignClass::get_index(size);
	_freelists[index].push(ptr);

	// 当一个桶中的内存块超过了其当前申请内存块的数量的时候，
	// 就将当前申请的内存块数量的内存块还给central cache，防止占用太多内存块
	if (_freelists[index].get_size() >= _freelists[index].get_maxsize())
		give_back_memory(_freelists[index], size);
}

void* ThreadCache::fetch_from_CentralCache(size_t index, size_t size)
{
	// 1. 采用慢开始反馈调节算法获取实际申请的内存数量
	/*
		原理：
			让该申请大小的极限值，与当前空闲链表允许允许获得的最大内存块个数取最小值，得到的就是实际申请的内存块个数
		其作用如下：
			1、最开始不会一次向central cache一次批量要太多，因为要太多了可能用不完
			2、如果你不要这个size大小内存需求，那么num就会不断增长，直到上限
			3、size越大，一次向central cache要的num就越小
			4、size越小，一次向central cache要的num就越大
	*/
	size_t& maxsize = _freelists[index].get_maxsize();
	size_t upper_size = AlignClass::get_upper_memory(size);
	size_t num = min(maxsize, upper_size);

	if (num == maxsize) // 如果还不是到申请大小的极限值的话，则让其申请内存块的数量递增
		maxsize += 1;

	// 2. 通过CentralCache实例获取实际拿到的内存块的个数，以及首尾地址
	void* start = nullptr;
	void* end = nullptr;
	size_t actual_num = CentralCache::get_instance()->give_memory_to_ThreadCache(start, end, num, size, index);
	
	// 3. 根据实际拿到的内存块是否有多申请的内存块
	if (actual_num == 1)
	{
		// 如果只有一个内存块，则直接返回给用户就行
		assert("start == end");
		return start;
	}
	else
	{
		/* 
			注意这里第一个内存块是要返回给用户使用的，但是因为申请的内存块
			有多个，所以剩下的内存块要链接到thread cache的哈希桶上备用！
		*/
		_freelists[index].append(get_next(start), end, actual_num - 1);
		return start;
	}
}

// 释放对象时，链表过长时，归还对应数量的内存块给central cache
void ThreadCache::give_back_memory(FreeList& list, size_t size)
{
	// 1. 先从当前空闲链表中取出当前申请内存块的数量个内存块
	void* start = nullptr;
	void* end = nullptr;
	list.pop_range(start, end, list.get_maxsize());

	// 2. 然后调用central cache的接口将这些内存块合并到central cache中
	CentralCache::get_instance()->merge_memory_from_ThreadCache(start, size);
}