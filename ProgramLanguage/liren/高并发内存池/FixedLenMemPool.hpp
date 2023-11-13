#pragma once
#include <iostream>
#include <vector>
using std::cout;
using std::endl;

#ifdef _WIN32
#include <Windows.h>
#else
//...
#endif

//直接去堆上申请按页申请空间
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
class fixed_size_pool
{
private:
    size_t _left_size = 0;     // 定长内存池可用部分的剩余大小
    char* _memory = nullptr;   // 定长内存池可用部分的起始指针（使用char类型是为了切内存块的时候更精细方便）
    void* _freelist = nullptr; // 空闲链表的头指针
public:
    // 向定长内存池申请一个T对象的空间
    T* apply()
    {
        T* obj = nullptr;

        // 1. 如果可以的话，直接从空闲链表中获取空闲的空间
        if (_freelist != nullptr)
        {
            // 就是一个链表头删的操作
            obj = (T*)_freelist;
            _freelist = get_next(_freelist);
            return obj;
        }

        // 2. 剩余内存不够一个对象大小时，则重新开大块空间
        int size = sizeof(T) < sizeof(void*) ? sizeof(void*) : sizeof(T); // 防止申请空间不足一个指针的大小，要最少开辟一个指针大小的空间
        if (_left_size < size)
        {
            // 剩余内存不够一个对象大小时，则重新开大块空间
            _left_size = 128 * 1024;
            _memory = (char*)SystemAlloc(_left_size >> 13);
            if (_memory == nullptr)
                throw std::bad_alloc(); // 申请空间失败的话就抛异常
        }

        // 3. 从内存池中取出一个对象的空间，然后处理一下指针和大小即可
        obj = (T*)_memory;
        _left_size -= size;
        _memory += size;

        // 4. 进行定位new操作调用对象的构造函数进行初始化，最后进行返回即可
        new(obj)T;
        return obj;
    }

    // 释放T对象的空间
    void release(T* obj)
    {
        // 1. 先调用对象的析构函数进行内部数据的释放
        obj->~T();

        // 2. 再进行空闲链表的头插操作
        get_next(obj) = _freelist;
        _freelist = obj;
    }

    void*& get_next(void* ptr)
    {
        // 函数返回值为void*&类型的引用，是因为这个函数返回的是指针的引用，即返回的是指针本身的地址，而不是指针所指向的对象的地址。
        // 这样做的好处是可以通过修改函数返回值来修改指针本身所指向的地址，从而实现对空闲链表的修改（头插和头删的需要）
        return (*(void**)ptr);
    }
};



// 测试数据
struct TreeNode
{
    int _val;
    TreeNode* _left;
    TreeNode* _right;
    TreeNode()
        : _val(0)
        , _left(nullptr)
        , _right(nullptr)
    {}
};

void TestObjectPool()
{
    // 申请释放的轮次
    const size_t Rounds = 5;

    // 每轮申请释放多少次
    const size_t N = 100000;

    // 测试new和delete的速度
    std::vector<TreeNode*> v1;
    v1.reserve(N);
    size_t begin1 = clock();
    for (size_t j = 0; j < Rounds; ++j)
    {
        for (int i = 0; i < N; ++i)
            v1.push_back(new TreeNode);

        for (int i = 0; i < N; ++i)
            delete v1[i];
        v1.clear();
    }
    size_t end1 = clock();

    // 测试我们实现的内存池的速度
    std::vector<TreeNode*> v2;
    v2.reserve(N);
    fixed_size_pool<TreeNode> TNPool;
    size_t begin2 = clock();
    for (size_t j = 0; j < Rounds; ++j)
    {
        for (int i = 0; i < N; ++i)
            v2.push_back(TNPool.apply());

        for (int i = 0; i < N; ++i)
            TNPool.release(v2[i]);
        v2.clear();
    }
    size_t end2 = clock();

    cout << "new cost time:" << end1 - begin1 << endl;
    cout << "fixed_size_pool cost time:" << end2 - begin2 << endl;
}