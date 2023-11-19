#pragma once
#include "Common.h"
#include "ThreadCache.h"
#include "FixedLenMemPool.hpp"

// 向高并发内存池申请空间的接口
static void* ConcurrentAlloc(size_t size)
{
	// 如果申请大小超过了256KB，则直接向页缓存申请内存
	if (size > THREAD_MAX_SIZE)
	{
		size_t align = AlignClass::get_align(size);
		size_t page = size >> PAGE_SHIFT;

		// 别忘了加锁
		PageCache::get_instance()->get_mutex().lock();
		Span* newspan = PageCache::get_instance()->new_span(page);
		newspan->_is_used = true;
		newspan->_size = size;
		PageCache::get_instance()->get_mutex().unlock();

		void* ptr = (void*)(newspan->_pid << PAGE_SHIFT);
		return ptr;
	}
	else
	{
		// 通过TLS机制，每个线程都能不加锁的获取到属于自己的ThreadCache对象，并且对于单个来说是全局的！
		if (tls_thread_cache == nullptr)
		{
			//tls_thread_cache = new ThreadCache;
			static fixed_size_pool<ThreadCache> tcmalloc;
			tls_thread_cache = tcmalloc.apply();
		}

		return tls_thread_cache->allocate(size);
	}
}

// 释放内存的接口（实际上并不会真的释放，只是还给内存池管理了）
static void ConcurrentFree(void* ptr)
{
	// 通过内存块地址获取对应的span对象和大小
	Span* span = PageCache::get_instance()->get_span_from_pageID(ptr);
	size_t size = span->_size;

	// 如果释放大小超过了256KB，则直接向页缓存释放内存
	if (size > THREAD_MAX_SIZE)
	{
		// 别忘了加锁
		PageCache::get_instance()->get_mutex().lock();
		PageCache::get_instance()->merge_memory_from_CentralCache(span);
		PageCache::get_instance()->get_mutex().unlock();
	}
	else
	{
		assert(tls_thread_cache != nullptr);
		tls_thread_cache->deallocate(ptr, size);
	}
}