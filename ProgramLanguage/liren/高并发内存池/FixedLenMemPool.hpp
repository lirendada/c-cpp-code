#pragma once
#include <iostream>
#include <vector>
#include <ctime>
using std::cout;
using std::endl;

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

template <class T>
class MemPool
{
public:
	// 申请内存块并初始化
	T* apply()
	{
		T* obj = nullptr; // 最后返回的内存块地址

		// 首先判断自由链表是否有未使用的内存块
		if (_freelist != nullptr)
		{
			// 有的话，直接从自由链表拿取，就是头删操作
			obj = (T*)_freelist;      // 先拿取
			_freelist = NextObj(obj); // 再指向下一个
		}
		else
		{
			// 没有的话，则从内存池中拿
			// 保证对象能够存储得下地址，也就是做内存对齐
			size_t obj_size = sizeof(T) < sizeof(void*) ? sizeof(void*) : sizeof(T);

			// 如果剩余内存不够一个对象大小时，则重新开大块空间
			if (obj_size > _leftbytes)
			{
				_leftbytes = 128 * 1024;    // 开辟128个字节
				_memory = (char*)SystemAlloc(_leftbytes >> 13); // 右移13位是因为SystemAlloc中左移了13位

				if (_memory == nullptr)
				{
					throw std::bad_alloc(); // 若开辟失败则返回开辟内存异常
				}
			}

			// 从内存池中切出obj_size字节的内存，但是内存块间本质还是连续的
			obj = (T*)_memory;
			_memory += obj_size;    // 记得要移动_memory到新的起始位置
			_leftbytes -= obj_size; // 有效大小也要记得减少
		}

		// 定位new，显示调用T的构造函数初始化
		new(obj) T;
		return obj;
	}

	// 释放内存块obj并头插至自由链表
	void release(T* obj)
	{
		// 显示调用析构函数清理对象
		obj->~T();

		// 将释放的对象头插到自由链表
		NextObj(obj) = _freelist;
		_freelist = obj;
	}
private:
	// 取当前指针所指对象的前4或8个字节
	void*& NextObj(void* ptr)
	{
		return (*(void**)ptr);
	}
private:
	size_t _leftbytes = 0;     // 定长内存池可用部分的剩余大小
	char* _memory = nullptr;   // 定长内存池可用部分的起始指针（使用char类型是为了切内存块的时候更精细方便）
	void* _freelist = nullptr; // 自由链表的头指针
};


// 测试数据 /////////////////////////////////////////////
struct TreeNode
{
	int _val;
	TreeNode* _left;
	TreeNode* _right;

	TreeNode()
		:_val(0)
		, _left(nullptr)
		, _right(nullptr)
	{}
};
void TestObjectPool()
{
	// 申请释放的轮次
	const size_t Rounds = 5;

	// 每轮申请释放多少次
	const size_t N = 1000000;

	std::vector<TreeNode*> v1;
	v1.reserve(N);

	size_t begin1 = clock();
	for (size_t j = 0; j < Rounds; ++j)
	{
		for (int i = 0; i < N; ++i)
		{
			v1.push_back(new TreeNode);
		}
		for (int i = 0; i < N; ++i)
		{
			delete v1[i];
		}
		v1.clear();
	}

	size_t end1 = clock();

	std::vector<TreeNode*> v2;
	v2.reserve(N);

	MemPool<TreeNode> TNPool;
	size_t begin2 = clock();
	for (size_t j = 0; j < Rounds; ++j)
	{
		for (int i = 0; i < N; ++i)
		{
			v2.push_back(TNPool.apply());
		}
		for (int i = 0; i < N; ++i)
		{
			TNPool.release(v2[i]);
		}
		v2.clear();
	}
	size_t end2 = clock();

	cout << "new cost time:" << end1 - begin1 << endl;
	cout << "object pool cost time:" << end2 - begin2 << endl;
}