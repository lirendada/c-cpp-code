#include <iostream>
using namespace std;

//class CopyBan
//{
//	// ......
//private:
//	// 设为私有，只声明不实现
//	CopyBan(const CopyBan&);
//	CopyBan& operator=(const CopyBan&);
//
//	// ......
//};

class CopyBan
{
	// 直接使用delete关键字
	CopyBan(const CopyBan&) = delete;
	CopyBan& operator=(const CopyBan&) = delete;

	// ......
};

class HeapOnly
{
public:
	// static的好处就是我们不需要对象就可以在类外通过类名::函数名直接访问
	static HeapOnly* CreateObject()
	{
		return new HeapOnly;
	}
private:
	// 默认构造函数不能直接封掉，因为上面的CreateObject()需要调用
	// 可以只声明不实现，这里直接使用default关键字
	HeapOnly() = default;
	

	// 拷贝构造和赋值重载要封掉
	HeapOnly(const HeapOnly&) = delete;
	HeapOnly& operator=(const HeapOnly&) = delete;
};

class StackOnly
{
public:
	static StackOnly CreateObject()
	{
		return StackOnly();
	}
private:
	StackOnly() = default;

	/* 或者只声明不定义
	StackOnly()
	{}
	*/
};

//class StackOnly
//{
//public:
//	StackOnly() 
//	{}
//private:
//	void* operator new(size_t size);
//	void operator delete(void* p);
//};

//int main()
//{
//	StackOnly s1 = StackOnly::CreateObject();
//
//	// 无法封掉这种情况，因为如果封掉拷贝构造的话，那么我们就无法在CreateObject中return一个临时栈对象了
//	static StackOnly s2 = StackOnly::CreateObject(); 
//	cout << typeid(s2).name() << endl;
//	return 0;
//}

//int main()
//{
//	HeapOnly* h1 = HeapOnly::CreateObject();
//
//	// HeapOnly h2 = h1; // ❌
//	// static HeapOnly h3; // ❌
//
//	static HeapOnly* h3 = HeapOnly::CreateObject(); // 本质还是一个指向堆空间的对象
//	cout << typeid(h3).name() << endl;
//	return 0;
//}
//#include <tuple>
//int main()
//{
//	int k = 10;
//	auto t1 = make_tuple(1, "lirendada", string("lirendada"), 's', 3.14, k);
//
//	cout << typeid(t1).name() << endl;
//	return 0;
//}


// 饿汉模式
// 优点：简单
// 缺点：可能会导致进程启动慢，且如果有多个单例类对象实例启动顺序不确定。
//class Singleton
//{
//public:
//	static Singleton& CreateObject()
//	{
//		return single_object;
//	}
//
//	void Print()
//	{
//		cout << "饿汉模式::Print()" << endl;
//	}
//private:
//	// 构造函数私有，并且不实现
//	Singleton() {}
//
//	// 拷贝构造以及赋值重载封掉
//	Singleton(const Singleton&) = delete;
//	Singleton& operator=(const Singleton&) = delete;
//
//private:
//	static Singleton single_object; // 声明一个当前类的静态变量
//};
//
//Singleton Singleton::single_object; // 类外初始化这个静态变量
//int main()
//{
//	// 第一种访问方法：通过CreateObject()直接调用相关接口
//	Singleton::CreateObject().Print();
//
//	// 第二种访问方法：可以使用引用接收CreateObject()，通过该对象调用相关接口
//	Singleton& s = Singleton::CreateObject();
//	s.Print();
//
//	//Singleton s1; // ❌
//	//Singleton* s2 = new Singleton; // ❌
//	//static Singleton s3; // ❌
//
//	return 0;
//}


#include <thread>
#include <mutex>
//template<class Lock>
//class LockGuard
//{
//public:
//	LockGuard(Lock& lock)
//		:_lock(lock)
//	{
//		_lock.lock();
//	}
//	~LockGuard()
//	{
//		_lock.unlock();
//	}
//private:
//	// 这里的_lock要用引用接收，不然如果只是一个Lock类型的对象，那么在构造函数中是不允许拷贝构造的（锁不允许拷贝）
//	// 当然这里也可以用指针，只不过这里用引用更贴切c++的方式
//	Lock& _lock; 
//};
//// 懒汉
//// 优点：第一次使用实例对象时，创建对象。进程启动无负载。多个单例实例启动顺序自由控制。
//// 缺点：复杂
//class Singleton
//{
//public:
//	static Singleton& CreateObject()
//	{
//		// 涉及多线程，要加锁
//		// 但是有可能new会抛异常导致死锁，所以我们可以用一个守卫锁
//		// 除此之外，当前对象已经new出来之后，为了防止后面来的线程都会被锁住影响效率，我们可以用双层判断来防止这种情况
//		if (single_ptr == nullptr)
//		{
//			// std::lock_guard<mutex> lock(_mtx); // 当然也可以用库里的lock_guard
//
//			LockGuard<mutex> lock(_mtx); // 使用守卫锁
//			if (single_ptr == nullptr)
//			{
//				single_ptr = new Singleton;
//			}
//		}
//		return *single_ptr;
//	}
//
//	// 自动回收资源的管理类：
//	// 如果提前手动释放，则不会回收；
//	// 如果没有提前手动释放，则会在这里自动释放
//	class GC
//	{
//	public:
//		~GC()
//		{
//			// 如果没有被提前手动释放，则才会去释放，防止不小心多次释放
//			if (single_ptr != nullptr)
//			{
//				// 内部类是外部类的友元，可以直接调用
//				DeleteInstance();
//			}
//		}
//	};
//
//	static GC _gc; // 定义一个静态成员变量，程序结束时，系统会自动调用它的析构函数从而释放单例对象
//
//	// 一般我们不需要考虑释放
//	// 但是如果我们想要保存资源的时候，就得处理一下
//	static void DeleteInstance()
//	{
//		// 保存文件等操作
//		// .......
//		
//		// 删除和保存的时候可能有多线程问题，要加锁
//		LockGuard<mutex> lock(_mtx);
//		if (single_ptr != nullptr)
//		{
//			delete single_ptr;
//			single_ptr = nullptr; // 记得置空，下一个线程进来的时候判断后就不会进入该代码块
//		}
//		cout << "资源处理完成，释放成功" << endl;
//	}
//
//	void Print()
//	{
//		cout << "懒汉模式::Print()" << endl;
//	}
//private:
//	// 构造函数私有，并且不实现
//	Singleton() {}
//
//	// 拷贝构造以及赋值重载封掉
//	Singleton(const Singleton&) = delete;
//	Singleton& operator=(const Singleton&) = delete;
//
//private:
//	static Singleton* single_ptr; // 单例对象指针
//	static mutex _mtx; // 静态的互斥锁
//};
//
//Singleton* Singleton::single_ptr = nullptr; // 初始化为空
//mutex Singleton::_mtx;
//Singleton::GC Singleton::_gc;
//
//int main()
//{
//	// 第一种访问方法：通过CreateObject()直接调用相关接口
//	Singleton::CreateObject().Print();
//
//	// 第二种访问方法：可以使用引用接收CreateObject()，通过该对象调用相关接口
//	Singleton& s = Singleton::CreateObject();
//	s.Print();
//
//	// s.DeleteInstance(); // 如果需要的话就提前手动释放一下
//
//	//Singleton s1; // ❌
//	//Singleton* s2 = new Singleton; // ❌
//	//static Singleton s3; // ❌
//	return 0;
//}



class Singleton
{
public:
	// 会不会有线程安全问题？？？
	// c++11之前，这里是不能保证single_object初始化是线程安全的！
	// c++11之后，这里是线程安全的！
	// 也就是说，c++11之后，局部静态变量初始化是线程安全的！
	// 所以这种写法不是通用的，比较少用，但是也是可以用的！
	static Singleton& CreateObject()
	{
		// 直接在CreateObject()创建一个静态单例类对象直接返回
		static Singleton single_object;
		return single_object;
	}

	void Print()
	{
		cout << "懒汉模式::Print()" << endl;
	}
private:
	// 构造函数私有，并且不实现
	Singleton() {}

	// 拷贝构造以及赋值重载封掉
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;
};

int main()
{
	// 第一种访问方法：通过CreateObject()直接调用相关接口
	Singleton::CreateObject().Print();

	// 第二种访问方法：可以使用引用接收CreateObject()，通过该对象调用相关接口
	Singleton& s = Singleton::CreateObject();
	s.Print();

	//Singleton s1; // ❌
	//Singleton* s2 = new Singleton; // ❌
	//static Singleton s3; // ❌
	return 0;
}