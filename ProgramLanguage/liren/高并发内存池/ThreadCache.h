#pragma once
#include "Common.h"
#include "CentralCache.h"

class ThreadCache
{
private:
	FreeList _freelists[FREELIST_NUMS];
public:
	// 申请和释放内存对象
	void* allocate(size_t size);
	void deallocate(void* ptr, size_t size);
private:
	// 从中心缓存获取对象空间
	void* fetch_from_CentralCache(size_t index, size_t size);

	// 释放对象时，链表过长时，归还对应数量的内存块给central cache
	void give_back_memory(FreeList& list, size_t size);
};

// 定义并且初始化一个每个线程独立的ThreadCache类指针
static __declspec(thread) ThreadCache* tls_thread_cache = nullptr;