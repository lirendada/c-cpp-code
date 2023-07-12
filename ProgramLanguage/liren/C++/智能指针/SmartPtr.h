#pragma once
#pragma once
#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

namespace liren
{
	// unique_ptr/scoped_ptr
	// 原理：简单粗暴 -- 防拷贝
	template<class T>
	class unique_ptr
	{
	public:
		unique_ptr(T* ptr)
			:_ptr(ptr)
		{}

		unique_ptr(unique_ptr<T>& sp) = delete; // 封掉拷贝构造
		unique_ptr<T>& operator=(unique_ptr<T>& ap) = delete; // 封掉=赋值

		~unique_ptr()
		{
			if (_ptr)
			{
				cout << "delete:" << _ptr << endl;
				delete _ptr;
			}
		}

		// 像指针一样使用
		T& operator*()
		{
			return *_ptr;
		}
		T* operator->()
		{
			return _ptr;
		}
		T& operator[](size_t pos)
		{
			return _ptr[pos];
		}
	private:
		T* _ptr;
	};

	template<class T, class D = default_delete<T>>
	class shared_ptr
	{
	public:
		// 带有默认删除器的构造函数
		shared_ptr(T* ptr, D del = default_delete<T>())
			:_ptr(ptr)
			, _count(new int(1))
			, _mtx(new mutex)
			, _del(del) // 删除器
		{}

		~shared_ptr()
		{
			Release();
		}

		shared_ptr(const shared_ptr<T>& ptr)
			:_ptr(ptr._ptr)
			, _count(ptr._count)
			, _mtx(ptr._mtx) // 记得把锁指针也赋值过去
			, _del(ptr._del)
		{
			_mtx->lock(); // 加锁
			(*_count)++;
			_mtx->unlock();
		}

		shared_ptr<T>& operator=(const shared_ptr<T>& ptr)
		{
			if (ptr._ptr != _ptr)
			{
				Release();

				_ptr = ptr._ptr;
				_count = ptr._count;
				_mtx = ptr._mtx; // 记得把锁指针也赋值过去
				_del = ptr._del;

				_mtx->lock(); // 加锁
				(*_count)++;
				_mtx->unlock();
			}
			return *this;
		}

		void Release()
		{
			bool flag = false; // 对于每个线程来说flag是局部私有的，互不影响

			_mtx->lock();
			if (--(*_count) == 0)
			{
				// delete _ptr;
				_del(_ptr); // 使用删除器来删除

				delete _count;
				flag = true;
			}
			_mtx->unlock();

			// 只有当真的减到0才会进入去释放锁，但是由于只能在unlock只会才能释放，所以我们在外面用flag进行判断释放
			if (flag == true)
				delete _mtx;
		}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

		T* get() const 
		{
			return _ptr;
		}

		int use_count() const 
		{
			return *_count;
		}
	private:
		T* _ptr;
		int* _count;
		mutex* _mtx;

		D _del; // 删除器
	};

	//void test_shared_ptr1()
	//{
	//	int n = 1000;
	//	liren::shared_ptr<int> sp1(new int);

	//	// 创建两个线程进行shared_ptr的增删
	//	thread t1([&]()
	//		{
	//			for (int i = 0; i < n; ++i)
	//			{
	//				liren::shared_ptr<int> sp2(sp1);
	//			}
	//		});

	//	thread t2([&]()
	//		{
	//			for (int i = 0; i < n; ++i)
	//			{
	//				liren::shared_ptr<int> sp3(sp1);
	//			}
	//		});

	//	t1.join();
	//	t2.join();

	//	cout << sp1.get() << endl;
	//	cout << sp1.use_count() << endl;
	//}

	template<class T>
	class weak_ptr
	{
	public:
		weak_ptr()
			:_ptr(nullptr)
		{}

		weak_ptr(const shared_ptr<T>& sptr)
			:_ptr(sptr.get())
		{}

		weak_ptr<T>& operator=(const shared_ptr<T>& sptr)
		{
			_ptr = sptr.get();
			return *this;
		}

	private:
		T* _ptr;
	};

	struct Date
	{
		int _year = 0;
		int _month = 0;
		int _day = 0;
	};

	//void test_shared_ptr2()
	//{
	//	int n = 1000000;
	//	liren::shared_ptr<Date> sp1(new Date);

	//	mutex mtx;
	//	// 创建两个线程进行shared_ptr的增删
	//	thread t1([&]()
	//		{
	//			for (int i = 0; i < n; ++i)
	//			{
	//				liren::shared_ptr<Date> sp2(sp1);
	//				mtx.lock();
	//				sp2->_year++;
	//				sp2->_month++;
	//				sp2->_day++;
	//				mtx.unlock();
	//			}
	//		});

	//	thread t2([&]()
	//		{
	//			for (int i = 0; i < n; ++i)
	//			{
	//				liren::shared_ptr<Date> sp3(sp1);
	//				mtx.lock();
	//				sp3->_year++;
	//				sp3->_month++;
	//				sp3->_day++;
	//				mtx.unlock();
	//			}
	//		});
	//	t1.join();
	//	t2.join();

	//	cout << sp1->_year << endl;
	//	cout << sp1->_month << endl;
	//	cout << sp1->_day << endl;
	//}

	//struct ListNode
	//{
	//	int _val;
	//	liren::weak_ptr<ListNode> _prev; // 使用weak_ptr，不增加引用计数
	//	liren::weak_ptr<ListNode> _next;

	//	~ListNode() { cout << "~ListNode()" << endl; }
	//};

	//void test_circle_ref()
	//{
	//	liren::shared_ptr<ListNode> node1(new ListNode);
	//	liren::shared_ptr<ListNode> node2(new ListNode);

	//	node1->_next = node2;
	//	node2->_prev = node1;
	//}

	// C++11的库中也有一个lock_guard，下面的LockGuard造轮子其实就是为了学习他的原理
	template<class Mutex>
	class LockGuard
	{
	public:
		LockGuard(Mutex& mtx)
			:_mutex(mtx)
		{
			_mutex.lock();
		}

		~LockGuard()
		{
			_mutex.unlock();
		}

		LockGuard(const LockGuard<Mutex>&) = delete; // 防止锁的拷贝构造
	private:
		// 注意这里必须使用引用，否则锁的就不是一个互斥量对象
		Mutex& _mutex;
	};

	/*void test_security()
	{
		mutex mtx;
		int n = 10000;
		liren::shared_ptr<int> sp1(new int(0));

		thread t1([&]()
			{
				for (int i = 0; i < n; ++i)
				{
					LockGuard<mutex> lock(mtx);
					++(*sp1);
				}
			});

		thread t2([&]()
			{
				for (int i = 0; i < n; ++i)
				{
					LockGuard<mutex> lock(mtx);
					++(*sp1);
				}
			});
		t1.join();
		t2.join();

		cout << *sp1 << endl;
	}*/
}