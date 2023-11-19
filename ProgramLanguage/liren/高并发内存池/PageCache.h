#pragma once
#include "Common.h"
#include "FixedLenMemPool.hpp"
#include "PageMap.h"

// 单例模式：饿汉方式
class PageCache
{
private:
	SpanList _spanlists[PAGELIST_NUMS];
	std::mutex _mtx; 

	static PageCache _page_instance; // 该类的单例对象（需要在cpp文件中定义）

	//std::unordered_map<page_t, Span*> _tables; // 存放页号与对应span对象的映射关系
	TCMalloc_PageMap2<32 - PAGE_SHIFT> _tables;  // 基数树结构的哈希表

	fixed_size_pool<Span> _fixed_pool; // 定长内存池
public:
	static PageCache* get_instance()
	{
		return &_page_instance;
	}

	// 获取一个k页大小的span
	Span* new_span(size_t k);

	// 根据传入的内存块地址返回对应的span对象的指针
	Span* get_span_from_pageID(void* ptr);

	// 将CentralCache传来的span对象合并到页缓存中管理
	void merge_memory_from_CentralCache(Span* span);

	std::mutex& get_mutex() { return _mtx; }
private:
	// 将构造函数私有化，将拷贝构造和赋值重载封掉
	PageCache() {}
	PageCache(const PageCache&) = delete;
	PageCache& operator=(const PageCache&) = delete;
};