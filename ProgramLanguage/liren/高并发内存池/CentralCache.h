#pragma once
#include "Common.h"
#include "PageCache.h"

// 单例模式：饿汉方式
class CentralCache
{
private:
	SpanList _spanlists[FREELIST_NUMS];

	static CentralCache _central_instance; // 该类的单例对象（需要在cpp文件中定义）
public:
	// 获取单例对象
	static CentralCache* get_instance()
	{
		return &_central_instance;
	}

	// 从central cache中获取一定数量的对象给thread cache
	// 参数：
	//	  start和end分别是返回内存块的起始位置地址，为输出型参数
	//	  num是根据慢开始启动算法得到的要申请的内存块个数
	//	  size为线程缓存申请的内存块空间的总大小
	//    index为线程缓存当前申请的内存块空间对应的哈希桶下标
	// 返回值：
	//    实际从central cache中拿到的内存块个数
	size_t give_memory_to_ThreadCache(void*& start, void*& end, size_t num, size_t size, size_t index);

	// 获取一个非空的span对象
	Span* get_span(SpanList& list, size_t size);

	// 将size大小的小内存块合并到对应的span哈希桶中
	void merge_memory_from_ThreadCache(void* start, size_t size);
private:
	// 将构造函数私有化，将拷贝构造和赋值重载封掉
	CentralCache() {}
	CentralCache(const CentralCache&) = delete;
	CentralCache& operator=(const CentralCache&) = delete;
};