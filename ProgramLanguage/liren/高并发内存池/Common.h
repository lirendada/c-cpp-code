#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <time.h>
#include <assert.h>
#include <thread>
#include <mutex>
#include <atomic>
using std::cout;
using std::endl;

#ifdef _WIN64
	using page_t = unsigned long long;
#elif _WIN32
	using page_t = size_t;
#endif

#ifdef _WIN32
	#include <Windows.h>
#else
	//...
#endif

// 直接去堆上申请按页申请空间
inline static void* SystemAlloc(size_t kpage)
{
#ifdef _WIN32
	void* ptr = VirtualAlloc(0, kpage << 13, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
#else
	// linux下brk mmap等
#endif
	if (ptr == nullptr)
		throw std::bad_alloc();
	return ptr;
}

// 直接向堆中释放内存
inline static void SystemFree(void* ptr)
{
#ifdef _WIN32
	VirtualFree(ptr, 0, MEM_RELEASE);
#else
	// sbrk unmmap等
#endif
}

static const size_t THREAD_MAX_SIZE = 256 * 1024; // 单个线程最大申请的空间大小（单位为字节）
static const size_t FREELIST_NUMS = 208;		  // 空闲链表的个数
static const size_t PAGELIST_NUMS = 129;		  // 页缓存中哈希桶的个数
static const size_t PAGE_SHIFT = 13;			  // 一页大小对应以2为底的指数

// 获取所指对象的开头指针大小的空间的地址
static inline void*& get_next(void* ptr)
{
	return (*(void**)ptr);
}

class FreeList
{
private:
	void* _freelist = nullptr; // 指向空闲链表头节点的指针

	size_t _size = 0;    // 表示当前空闲链表中内存块的个数
	size_t _maxsize = 1; // 表示当前空闲链表申请空间块时允许获得的最大个数（会不断递增）
public:
	// 将单个内存对象头插插入空闲链表
	void push(void* obj)
	{
		get_next(obj) = _freelist;
		_freelist = obj;

		_size++; // 记得累加个数
	}

	// 将多个内存对象头插插入空闲链表
	void append(void* start, void* end, size_t size)
	{
		get_next(end) = _freelist;
		_freelist = start;

		_size += size; // 记得累加个数
	}

	// 头删方式取出空闲链表中的空间
	void* pop()
	{
		void* obj = _freelist;
		_freelist = get_next(obj);

		_size--; // 记得减去个数
		return obj;
	}

	// 将多个内存块从空闲链表弹出，通过输出型参数获取首尾地址
	void pop_range(void*& start, void*& end, size_t num)
	{
		// 1. 先定位首尾位置（end要停在第num块上，所以实际走的是num-1步）
		start = _freelist;
		end = start;
		for (size_t i = 0; i < num - 1; ++i)
			end = get_next(end);

		// 2. 将该区间的内存块与空闲链表断开，然后将end的next置为空即可
		_freelist = get_next(end);
		get_next(end) = nullptr;
		
		// 3. 最后别忘了内存块个数要减少
		_size -= num;
	}

	bool empty() { return _freelist == nullptr; }

	size_t& get_maxsize() { return _maxsize; }
	size_t& get_size() { return _size; }
};


// 管理对象大小的对齐与映射规则
class AlignClass
{
public:
	// 整体控制在最多10%左右的内碎片浪费
	// [1,128]					8byte对齐	    freelist[0,16)
	// [128+1,1024]				16byte对齐	    freelist[16,72)
	// [1024+1,8*1024]			128byte对齐	    freelist[72,128)
	// [8*1024+1,64*1024]		1024byte对齐     freelist[128,184)
	// [64*1024+1,256*1024]		8*1024byte对齐   freelist[184,208)

	// 传入一个对象大小size，返回它对应的对齐数
	static inline size_t get_align(size_t size)
	{
		// 根据字节的范围，将size以及其范围对应的对齐数交给align替我们计算对齐数
		if (size <= 128) return align(size, 8);
		else if (size <= 1024) return align(size, 16);
		else if (size <= 8 * 1024) return align(size, 128);
		else if (size <= 64 * 1024) return align(size, 1024);
		else if (size <= 256 * 1024) return align(size, 8 * 1024);

		// 走到这说明超过了单个线程最大申请的空间大小，则返回一页大小的对齐数即可
		return align(size, 8 * 1024);
	}

	// 传入一个对象大小size，返回它当前所处的哈希桶下标
	static inline size_t get_index(size_t size)
	{
		// 事先给出每个区间有多少个空闲链表
		static int groupArray[4] = { 16, 56, 56, 56 }; 

		// 这里对齐数传入的是对齐数以2为底，此时对应的指数
		// 并且这里因为index函数中计算下标的时候，只考虑当前字节数属于哪一个区间，所以要将前面区间的字节数减去
		if (size <= 128) 
			return index(size, 3);
		else if (size <= 1024) 
			return index(size - 128, 4) + groupArray[0];
		else if (size <= 8 * 1024) 
			return index(size - 1024, 7) + groupArray[0] + groupArray[1];
		else if (size <= 64 * 1024) 
			return index(size - 8*1024, 10) + groupArray[0] + groupArray[1] + groupArray[2];
		else if (size <= 256 * 1024) 
			return index(size - 256*1024, 13) + groupArray[0] + groupArray[1] + groupArray[2] + groupArray[3];
			
		// 走到这说明超过了单个线程最大申请的空间大小，则进行断言错误然后返回-1即可
		assert(false);
		return -1;
	}

	// 根据size返回thread cache从central cache中一次获取多少内存块
	static inline size_t get_upper_memory(size_t size)
	{
		assert(size > 0);

		// 小对象一次获取批量的上限高，控制在512个对象
		// 大对象一次获取批量的上限低，控制在2个对象
		// 也就是说控制获取的对象在[2, 512]区间内
		size_t num = THREAD_MAX_SIZE / size;
		if (num < 2) num = 2;
		else if (num > 512) num = 512;

		return num;
	}

	// 根据size计算一次向页缓存申请多少个页
	static inline size_t get_nums_of_page(size_t size)
	{
		// 先算出该大小要申请多少内存块
		size_t num = get_upper_memory(size);	 

		// 然后用大小乘以内存块得到总的大小，然后除以一页的大小也就是8K，得到的就是申请的页数
		size_t ret = (num * size) >> PAGE_SHIFT; 

		// 最后返回的时候判断一下如果得到的是0，那么返回1页，否则直接返回ret即可
		return ret == 0 ? 1 : ret;
	} 

	static inline size_t align(size_t bytes, size_t alignNum)
	{
		// 比如bytes为1~8，则alignNum为8，此时前面bytes + alignNum - 1得到的最小值和最大值分别是8和15
		// 然后alignNum - 1得到的就是7，此时取反得到就是低三位比特位都是0，其它都是1
		// 如果此时为8，也就是0000 1000，而上面取反是1111 1000，此时它们相互按位与之后得到就是0000 1000也就是8
		// 如果此时为15， 就是0000 1111，而上面取反是1111 1000，此时它们相互按位与之后得到就是0000 1000还是8
		return ((bytes + alignNum - 1) & ~(alignNum - 1));
	}

	static inline size_t index(size_t bytes, size_t alignShift)
	{
		// 比如bytes为1~8，则alignShift为3，此时前面(1 << alignShift) - 1得到的就是7
		// 然后bytes + 7 得到的区间就是8~15了
		// 接着让8~15区间的值右移alignShift位也就是3位然后减一，如下所示：
		// 如果为8，即0000 1000，右移3位得到0000 0001 - 1 = 0
		// 如果为15，即0000 1111，右移3位得到0000 0001 - 1 = 0
		// 可以看到它们都是属于对齐数8的空闲链表中，哈希桶中下标为0的对象！
		return ((bytes + (1 << alignShift) - 1) >> alignShift) - 1;
	}
};

// 管理以页为单位的大内存块
struct Span
{
	page_t _pid = 0; // 大块内存起始页的页号
	size_t _num = 0; // 页的个数

	Span* _next = nullptr; // 双向链表结构
	Span* _prev = nullptr;

	size_t _use_count = 0;	   // 当前分配给ThreadCache对象的小内存块个数
	void* _freelist = nullptr; // 当前大内存块对应的空闲链表

	bool _is_used = false; // 表示当前对象是否被线程使用着

	size_t _size = 0; // 表示当前span对象的大小
};

// 管理Span结构的带头双向链表
class SpanList
{
private:
	Span* _head;	 // 头节点
	std::mutex _mtx; // 互斥锁，在central cache中用于桶锁保护
public:
	SpanList()
	{
		// 构造函数进行头节点的初始化，让其指向自己
		_head = new Span;
		_head->_next = _head;
		_head->_prev = _head;
	}
	
	// 获取链表的首尾节点，用于遍历
	Span* begin() { return _head->_next; }
	Span* end() { return _head; }

	// 将node插入到pos位置前（node来自于page cache）
	void insert(Span* pos, Span* node)
	{
		assert(pos != nullptr && node != nullptr);

		Span* prev = pos->_prev;
		prev->_next = node;
		node->_prev = prev;
		node->_next = pos;
		pos->_prev = node;
	}

	// 将pos处的节点从链表中删掉
	void erase(Span* node)
	{
		assert(node != nullptr && node != _head);

		Span* prev = node->_prev;
		Span* next = node->_next;
		prev->_next = next;
		next->_prev = prev;
	}

	// 头插接口
	void push_front(Span* node)
	{
		insert(begin(), node);
	}

	// 头删并且获取该span对象的接口
	Span* pop_front()
	{
		Span* front = begin();
		erase(front);
		return front;
	}

	bool empty() { return _head->_next == _head; }

	std::mutex& get_mutex() { return _mtx; }
};
