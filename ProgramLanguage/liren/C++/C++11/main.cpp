//#include "Test.h"
//
//int main()
//{
//    tmpDir();
//    return 0;
//}

//#include <iostream>
//using namespace std;
//
//class Person
//{
//public:
//	~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//};
//
//class Student : public Person
//{
//public:
//	~Student()
//	{
//		cout << "~Student()" << endl;
//	}
//};
//
//int main()
//{
//	// 只有派生类Student的析构函数重写了Person的析构函数，下面的delete对象调用析构函数，才能构成多态，才能保证p1和p2指向的对象正确的调用析构函数。
//	Person* p1 = new Person;
//	Person* p2 = new Student;
//	delete p1;
//	delete p2;
//	return 0;
//}

//#include <iostream>
//using namespace std;
//class AM
//{
//public:
//	// 因为析构函数是纯虚函数，所以要有实现内容
//	virtual ~AM() = 0  
//	{
//		cout << "~AM()" << endl;
//	}
//};
//class PM : public AM
//{
//public:
//	virtual ~PM()
//	{
//		cout << "~PM()" << endl;
//	}
//};
//int main()
//{
//	PM p;
//	return 0;
//}

//#include<iostream>
//
////模板递归和特化方式展开可变参数模板类
////1、可变参数模板声明
////2、递归继承模板类
////3、边界条件
//
////1、变长模板声明
//template<int ... last>
//class Test {};
//
////2、变长模板类定义
//template<int first, int ... last>
//class Test<first, last...> 
//{
//public:
//    static const int val = first * Test<last...>::val;
//};
//
////3、边界条件
//template<>
//class Test<> 
//{
//public:
//    static const int val = 1;
//};
//
//int main() {
//    int sum = Test<2, 3, 4, 5>::val;
//    std::cout << sum << std::endl;
//    return 0;
//}


//#include<iostream>
//
//class MyFunctor {
//public:
//    MyFunctor(int tmp)
//        :round_(tmp)
//    {}
//    int operator()(int tmp) // 仿函数，重载operator()
//    {
//        return round_ + tmp;
//    }
//private:
//    int round_;  // round_就是这个闭包的状态
//};
//
//int main() {
//    int round = 2;
//    MyFunctor mf(round);   // 调用构造函数
//
//    // 调用仿函数
//    std::cout << "result= " << mf(1) << std::endl;  // operator()(int tmp)
//    return 0;
//}


//#include<iostream>
//#include<functional>
//
//void Func(int x, int y)
//{
//    std::cout << x << " " << y << std::endl;
//}
//
//int main() {
//    std::bind(Func, 10, 20)(30, 40); // 输出10,20
//
//    std::bind(Func, std::placeholders::_1, std::placeholders::_2)(11, 21, 31);  // 输出11,21
//
//    using namespace std::placeholders; // 下面引入std::placeholders，节省代码量
//
//    std::bind(Func, _1, 11)(10, 20, 30); // 输出10,11
//
//    std::bind(Func, _1, _2)(11, 21);   // 输出11,21
//
//    std::bind(Func, _2, _1)(12, 22);   // 先输出_2就是22，在输出_1就是12
//
//    // std::bind(Func,_2,22)(11);  // ❌参数不匹配，没有第二个参数
//
//    std::bind(Func, _2, 22)(11, 0);  // 输出0,22
//
//    std::bind(Func, _3, 22)(0, 1, 2);  // 输出3,22
//    return 0;
//}

//#include<iostream>
//#include<functional>
//// 1、普通函数
//void Func() 
//{
//    std::cout << __LINE__ << ":" << __func__ << std::endl;
//}
//
//// 2、类中静态函数
//class Test 
//{
//public:
//    static int Func(int tmp) {
//        std::cout << __LINE__ << ":" << __func__ << "(" << tmp << ")->:";
//        return tmp;
//    }
//};
//
//// 3、类中仿函数
//class MyFunctor {
//public:
//    MyFunctor(int tmp)
//        :round_(tmp)
//    {}
//    int operator()(int tmp) {
//        std::cout << __LINE__ << ":" << __func__ << "(" << tmp << ")->:";
//        return tmp + round_;
//    }
//private:
//    int round_;
//};
//
//int main() {
//    // 1、绑定普通函数
//    std::function<void(void)> f1 = Func;
//    f1(); // 等价于 func()
//
//    // 2、绑定类中的静态函数
//    std::function<int(int)> f2 = Test::Func;
//    std::cout << f2(10) << std::endl; // Test::Func(10)
//
//    //3、绑定类中的仿函数,绑定对象,仿函数调用obj
//    MyFunctor obj(100);
//    std::function<int(int)> f3 = obj;
//    std::cout << f3(20) << std::endl;
//    return 0;
//}


#include<iostream>
#include<functional>
using namespace std;
using namespace std::placeholders;

//class Func 
//{
//public:
//    void func(int x, int y) 
//    {
//        std::cout << x << " " << y << std::endl;
//    }
//    int a_;  // 成员变量
//};
//
//int main() 
//{
//    Func obj;  // 创建对象
//
//    // 绑定成员函数
//    std::function<void(int, int)> f1 = std::bind(&Func::func, &obj, _1, _2);
//    f1(11, 22);  // obj.func(11,22)
//
//    std::function<int&()> f2 = std::bind(&Func::a_, &obj);
//    f2() = 11;   // obj.a_= 11
//    std::cout << f2() << std::endl;
//
//    return 0;
//}

//typedef std::function<void()> PrintFinFunction;
//void print(const char* text, PrintFinFunction callback) {
//    printf("%s\n", text);
//    if (callback)
//        callback();
//}
//// 普通函数
//void printFinCallback() {
//    cout << "Normal callback" << endl;
//}
//// 类静态函数
//class Test {
//public:
//    static void printFinCallback() {
//        cout << "Static callback" << endl;
//    }
//};
//// 仿函数，重载()运算符
//struct Functor {
//    void operator() () {
//        cout << "Functor callback" << endl;
//    }
//};
//int main()
//{
//    print("test 1", printFinCallback);
//    print("test 2", Test::printFinCallback);
//    print("test 3", Functor());
//    print("test 4", []() {
//        cout << "Lambda callback" << endl;
//        });
//}

//#include "Test.h"
//
//int main()
//{
//    tmpDir();
//    return 0;
//}

//#include <iostream>
//using namespace std;
//
//class Person
//{
//public:
//	~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//};
//
//class Student : public Person
//{
//public:
//	~Student()
//	{
//		cout << "~Student()" << endl;
//	}
//};
//
//int main()
//{
//	// 只有派生类Student的析构函数重写了Person的析构函数，下面的delete对象调用析构函数，才能构成多态，才能保证p1和p2指向的对象正确的调用析构函数。
//	Person* p1 = new Person;
//	Person* p2 = new Student;
//	delete p1;
//	delete p2;
//	return 0;
//}

//#include <iostream>
//using namespace std;
//class AM
//{
//public:
//	// 因为析构函数是纯虚函数，所以要有实现内容
//	virtual ~AM() = 0  
//	{
//		cout << "~AM()" << endl;
//	}
//};
//class PM : public AM
//{
//public:
//	virtual ~PM()
//	{
//		cout << "~PM()" << endl;
//	}
//};
//int main()
//{
//	PM p;
//	return 0;
//}

//#include<iostream>
//
////模板递归和特化方式展开可变参数模板类
////1、可变参数模板声明
////2、递归继承模板类
////3、边界条件
//
////1、变长模板声明
//template<int ... last>
//class Test {};
//
////2、变长模板类定义
//template<int first, int ... last>
//class Test<first, last...> 
//{
//public:
//    static const int val = first * Test<last...>::val;
//};
//
////3、边界条件
//template<>
//class Test<> 
//{
//public:
//    static const int val = 1;
//};
//
//int main() {
//    int sum = Test<2, 3, 4, 5>::val;
//    std::cout << sum << std::endl;
//    return 0;
//}


//#include<iostream>
//
//class MyFunctor {
//public:
//    MyFunctor(int tmp)
//        :round_(tmp)
//    {}
//    int operator()(int tmp) // 仿函数，重载operator()
//    {
//        return round_ + tmp;
//    }
//private:
//    int round_;  // round_就是这个闭包的状态
//};
//
//int main() {
//    int round = 2;
//    MyFunctor mf(round);   // 调用构造函数
//
//    // 调用仿函数
//    std::cout << "result= " << mf(1) << std::endl;  // operator()(int tmp)
//    return 0;
//}


//#include<iostream>
//#include<functional>
//
//void Func(int x, int y)
//{
//    std::cout << x << " " << y << std::endl;
//}
//
//int main() {
//    std::bind(Func, 10, 20)(30, 40); // 输出10,20
//
//    std::bind(Func, std::placeholders::_1, std::placeholders::_2)(11, 21, 31);  // 输出11,21
//
//    using namespace std::placeholders; // 下面引入std::placeholders，节省代码量
//
//    std::bind(Func, _1, 11)(10, 20, 30); // 输出10,11
//
//    std::bind(Func, _1, _2)(11, 21);   // 输出11,21
//
//    std::bind(Func, _2, _1)(12, 22);   // 先输出_2就是22，在输出_1就是12
//
//    // std::bind(Func,_2,22)(11);  // ❌参数不匹配，没有第二个参数
//
//    std::bind(Func, _2, 22)(11, 0);  // 输出0,22
//
//    std::bind(Func, _3, 22)(0, 1, 2);  // 输出3,22
//    return 0;
//}

//#include<iostream>
//#include<functional>
//// 1、普通函数
//void Func() 
//{
//    std::cout << __LINE__ << ":" << __func__ << std::endl;
//}
//
//// 2、类中静态函数
//class Test 
//{
//public:
//    static int Func(int tmp) {
//        std::cout << __LINE__ << ":" << __func__ << "(" << tmp << ")->:";
//        return tmp;
//    }
//};
//
//// 3、类中仿函数
//class MyFunctor {
//public:
//    MyFunctor(int tmp)
//        :round_(tmp)
//    {}
//    int operator()(int tmp) {
//        std::cout << __LINE__ << ":" << __func__ << "(" << tmp << ")->:";
//        return tmp + round_;
//    }
//private:
//    int round_;
//};
//
//int main() {
//    // 1、绑定普通函数
//    std::function<void(void)> f1 = Func;
//    f1(); // 等价于 func()
//
//    // 2、绑定类中的静态函数
//    std::function<int(int)> f2 = Test::Func;
//    std::cout << f2(10) << std::endl; // Test::Func(10)
//
//    //3、绑定类中的仿函数,绑定对象,仿函数调用obj
//    MyFunctor obj(100);
//    std::function<int(int)> f3 = obj;
//    std::cout << f3(20) << std::endl;
//    return 0;
//}


#include<iostream>
#include<functional>
using namespace std;

//class Func 
//{
//public:
//    void func(int x, int y) 
//    {
//        std::cout << x << " " << y << std::endl;
//    }
//    int a_;  // 成员变量
//};
//
//int main() 
//{
//    Func obj;  // 创建对象
//
//    // 绑定成员函数
//    std::function<void(int, int)> f1 = std::bind(&Func::func, &obj, _1, _2);
//    f1(11, 22);  // obj.func(11,22)
//
//    std::function<int&()> f2 = std::bind(&Func::a_, &obj);
//    f2() = 11;   // obj.a_= 11
//    std::cout << f2() << std::endl;
//
//    return 0;
//}

//typedef std::function<void(int)> PrintFinFunction;
//
//void print(const char* text, PrintFinFunction callback)
//{
//    printf("%s\n", text);
//    if (callback)
//        callback(1);
//}
//
//// 类成员函数
//class Test
//{
//public:
//    void printFinCallbackInter(int res) {
//        cout << "Class Inter callback:" << res << endl;
//    }
//};
//
//// 函数签名不一样的函数
//void printFinCallback2(int res1, int res2)
//{
//    cout << "Different callback:" << res1 << " " << res2 << endl;
//}
//
//int main()
//{
//    Test testObj;
//
//    std::function<void(int)> callback5 = std::bind(&Test::printFinCallbackInter, testObj, std::placeholders::_1);
//    print("test 5", callback5); //函数模板只有一个参数，这里需要补充this参数
//
//    auto callback6 = std::bind(&printFinCallback2, std::placeholders::_1, 100);
//    print("test 6", callback6); //这里需要补充第二个参数
//
//    print("test 7", std::bind(&printFinCallback2, std::placeholders::_1, 200));
//}

//#include<iostream>
//
//int main() {
//    int x = 10;
//    //lambda表达式，新建一个变量，外部变量给这个变赋值一份， 值传递,里面修改不会影响外面，外面修改也不会影响里面
//    auto f1 = [=]() mutable {
//        x++;
//        std::cout << "x= " << x << std::endl;
//    };
//    f1();
//    //++;
//    std::cout << "x= " << x << std::endl;
//
//    int y = 100;
//    //lambda表达式，新建一个变量，外部变量给这个变赋值一份，引用传递,里面修改会影响外面，外面修改也会影响里面
//    auto f2 = [&]() {
//        y++;
//        std::cout << "y= " << y << std::endl;
//    };
//    f2();
//    std::cout << "y= " << y << std::endl;
//    return 0;
//}


//#include <iostream>
//#include <thread>
//using namespace std;

//int main()
//{
//	int i = 0;
//	thread t1([&]()
//		{
//			while (i < 100)
//			{
//				cout << "t1 -> " << i << endl;
//				i++;
//			}
//		});
//	thread t2([&]()
//		{
//			while (i < 100)
//			{
//				cout << "t2 -> " << i << endl;
//				i++;
//			}
//		});
//
//	thread t3;
//	t3 = move(thread([&]()
//		{
//			while (i < 100)
//			{
//				cout << "t3 -> " << i << endl;
//				i++;
//			}
//		}));
//	std::cout << "t1's id: " << t1.get_id() << '\n';
//	std::cout << "t2's id: " << t2.get_id() << '\n';
//	std::cout << "t3's id: " << t3.get_id() << '\n';
//	t1.join();
//	t2.join();
//	t3.join();
//	return 0;
//}



// typedef std::function<void()> PrintFinFunction; // 将包装器重命名一下
//using PrintFinFunction = function<void()>;
//
//void print(const char* text, PrintFinFunction callback)
//{
//    printf("%s\n", text);
//    if (callback) // 不为空则去回调
//        callback();
//}
//// 普通函数
//void printFinCallback()
//{
//    cout << "Normal callback" << endl;
//}
//// 类静态函数
//class Test
//{
//public:
//    static void printFinCallback() {
//        cout << "Static callback" << endl;
//    }
//};
//// 仿函数，重载()运算符
//struct Functor
//{
//    void operator() () {
//        cout << "Functor callback" << endl;
//    }
//};
//int main()
//{
//    print("test 1", printFinCallback);
//    print("test 2", Test::printFinCallback);
//    print("test 3", Functor());
//    print("test 4", []() {
//        cout << "Lambda callback" << endl;
//        });
//}

//template<class F, class T>
//T useF(F f, T x)
//{
//	static int count = 0;
//	cout << "count:" << ++count << endl;
//	cout << "count:" << &count << endl;
//	return f(x);
//}
//
//double f(double i) // 函数
//{
//	return i / 2;
//}
//
//struct Functor // 仿函数
//{
//	double operator()(double d)
//	{
//		return d / 3;
//	}
//};

//int main()
//{
//	// 函数名
//	cout << useF(f, 11.11) << endl;
//	// 函数对象
//	cout << useF(Functor(), 11.11) << endl;
//	// lamber表达式
//	cout << useF([](double d)->double { return d / 4; }, 11.11) << endl;
//
//	cout << "################################################################################" << endl;
//
//	// 函数名
//	function<double(double)> func1 = f;
//	cout << useF(func1, 11.11) << endl;
//	// 函数对象
//	function<double(double)> func2 = Functor();
//	cout << useF(func2, 11.11) << endl;
//	// lamber表达式
//	function<double(double)> func3 = [](double d)->double { return d / 4; };
//	cout << useF(func3, 11.11) << endl;
//	return 0;
//}

//#include <iostream>
//#include <stdexcept>
//void divide(int x, int y) {
//    if (y == 0) {
//        throw std::invalid_argument("divide by zero");  // 抛出异常
//    }
//    std::cout << "result = " << x / y << std::endl;
//}
//int main() {
//    try {
//        divide(10, 0);  // 调用可能抛出异常的函数
//    }
//    catch (const std::exception& e) {
//        std::cerr << "Exception caught: " << e.what() << std::endl;  // 捕获异常并处理
//    }
//    return 0;
//}


//class Plus
//{
//public:
//	static int static_add(int a, int b)
//	{
//		return a + b;
//	}
//	double add(double a, double b)
//	{
//		return a + b;
//	}
//};
//
//int main()
//{
//	// 静态成员函数
//	function<int(int, int)> func1 = &Plus::static_add;
//	cout << func1(1, 2) << endl;
//
//	// 非静态成员函数
//	function<double(Plus, double, double)> func2 = &Plus::add; // 第一个参数用类名来占位表示this指针
//	cout << func2(Plus(), 1.1, 2.2) << endl; // 第一个参数传递要传一个类的对象
//
//	// 如果不想非静态成员函数这样子调用加上对象来占位的话，可以使用lambda表达式来捕捉
//	Plus plus;
//	function<double(double, double)> func3 = [&plus](double x, double y)->double { return plus.add(x, y); };
//	cout << func3(1.1, 2.2) << endl;
//	return 0;
//}

//int Plus(int a, int b)
//{
//	return a + b;
//}
//class Sub
//{
//public:
//	int sub(int a, int b)
//	{
//		return a - b;
//	}
//};
//int main()
//{
//	// 表示绑定函数plus参数分别由调用func1的第一，二个参数指定
//	std::function<int(int, int)> func1 = std::bind(Plus, placeholders::_1, placeholders::_2);
//	cout << func1(1, 2) << endl;
//
//	// func2的类型为function<void(int, int, int)>与func1类型一样
//	// 表示绑定函数 plus 的第一，二为： 1， 2
//	auto func2 = std::bind(Plus, 1, 2);
//	cout << func2() << endl;
//	cout << typeid(func2).name() << endl;
//	Sub s;
//	// func3绑定成员函数
//	std::function<int(int, int)> func3 = std::bind(&Sub::sub, s, placeholders::_1, placeholders::_2);
//	// func4与func3的参数调换顺序
//	std::function<int(int, int)> func4 = std::bind(&Sub::sub, s, placeholders::_2, placeholders::_1);
//	cout << func3(1, 2) << endl;
//	cout << func4(1, 2) << endl;
//
//	function<bool(int, int)> func5 = bind(less<int>(), _1, _2);
//	function<bool(int, int)> func6 = bind(less<int>(), _2, _1);
//	cout << func5(1, 2) << endl;
//	cout << func6(1, 2) << endl;
//	return 0;
//}

//void Func(int x, int y)
//{
//    std::cout << x << " " << y << std::endl;
//}
//
//int main() {
//    std::bind(Func, 10, 20)(30, 40); // 输出10,20
//
//    std::bind(Func, std::placeholders::_1, std::placeholders::_2)(11, 21, 31);  // 输出11,21
//
//    using namespace std::placeholders; // 下面引入std::placeholders，节省代码量
//
//    std::bind(Func, _1, 11)(10, 20, 30); // 输出10,11
//
//    std::bind(Func, _1, _2)(11, 21);   // 输出11,21
//
//    std::bind(Func, _2, _1)(12, 22);   // 先输出_2就是22，在输出_1就是12
//
//    // std::bind(Func,_2,22)(11);  // ❌参数不匹配，没有第二个参数
//
//    auto b1 = std::bind(Func, _2, 22);
//    b1(11, 0); // 输出0,22
//    cout << typeid(b1).name() << endl;
//
//    auto b2 = std::bind(Func, _3, 22);
//    b2(0, 1, 2); // 输出3,22
//    
//    return 0;
//}

//double Division(int a, int b)
//{
//	// 当b == 0时抛出异常
//	if (b == 0)
//		throw "Division by zero condition!";
//	else
//		return ((double)a / (double)b);
//}
//void Func()
//{
//	// 这里可以看到如果发生除0错误抛出异常后，如果不接收异常的话会直接跳到main中的catch
//	// 那么另外上面的array没有得到释放。所以这里捕获异常后并不处理异常，异常还是交给外面那层函数也就是main去处理，这里捕获了再重新抛出去。
//	int* array = new int[10];
//	try {
//		int len, time;
//		cin >> len >> time;
//		cout << Division(len, time) << endl;
//	}
//	catch (...) {
//		cout << "delete []" << array << endl; // 捕捉过程中释放上面的动态内存
//		delete[] array;
//		throw; // 代表抛出接收到的任意未知异常
//	}
//
//	// 如果上面没有捕捉异常的话，那么这里就不会被执行到，就会内存泄漏
//	cout << "delete []" << array << endl;
//	delete[] array;
//}
//int main()
//{
//	try {
//		Func();
//	}
//	catch (const char* errmsg) {
//		cout << errmsg << endl;
//	}
//
//	cout << "catch done, exit!" << endl;
//	return 0;
//}

#include <iostream>
#include <Windows.h>
using namespace std;

// 服务器开发中通常使用的异常继承体系
class Exception
{
public:
	Exception(const string& errmsg, int id)
		:_errmsg(errmsg)
		, _id(id)
	{}
	virtual string what() const // 获取错误信息
	{
		return _errmsg;
	}
protected:
	string _errmsg; // 错误描述
	int _id; // 错误id
};

// 数据库异常
class SqlException : public Exception
{
public:
	SqlException(const string& errmsg, int id, const string& sql)
		:Exception(errmsg, id)
		, _sql(sql)
	{}
	virtual string what() const
	{
		string str = "SqlException:";
		str += _errmsg;
		str += "->";
		str += _sql; 
		return str;
	}
private:
	const string _sql;
};

// 缓存异常
class CacheException : public Exception
{
public:
	CacheException(const string& errmsg, int id)
		:Exception(errmsg, id)
	{}
	virtual string what() const
	{
		string str = "CacheException:";
		str += _errmsg;
		return str;
	}
};

// 协议服务异常
class HttpServerException : public Exception
{
public:
	HttpServerException(const string& errmsg, int id, const string& type)
		:Exception(errmsg, id)
		, _type(type)
	{}
	virtual string what() const
	{
		string str = "HttpServerException:";
		str += _type;
		str += ":";
		str += _errmsg;
		return str;
	}
private:
	const string _type;
};

void SQLMgr()
{
	srand(time(0));
	if (rand() % 7 == 0)
	{
		throw SqlException("权限不足", 100, "select * from name = '张三'");
	}
}

void CacheMgr()
{
	srand(time(0));
	if (rand() % 5 == 0)
	{
		throw CacheException("权限不足", 100);
	}
	else if (rand() % 6 == 0)
	{
		throw CacheException("数据不存在", 101);
	}
	SQLMgr();
}

void HttpServer()
{
	srand(time(0));
	if (rand() % 3 == 0)
	{
		throw HttpServerException("请求资源不存在", 100, "get");
	}
	else if (rand() % 4 == 0)
	{
		throw HttpServerException("权限不足", 101, "post");
	}
	CacheMgr();
}

//int main()
//{
//	while (1)
//	{
//		Sleep(1000);
//		try {
//			HttpServer();
//		}
//		catch (const Exception& e) // 自定义的
//		{
//			cout << e.what() << endl;
//		}
//		catch (const exception& e) // 标准库内的
//		{
//			cout << e.what() << endl;
//		}
//		catch (...)
//		{
//			cout << "Unkown Exception" << endl;
//		}
//	}
//	return 0;
//}

//#include <iostream>
//using namespace std;
//int main()
//{
//	// 请在此输入您的代码
//	int arr[50][50] = { 0 };
//	int n = 2;
//	int count = 2;
//	arr[0][0] = 1;
//	while (n < 50)
//	{
//		if (n % 2 == 0)
//			for (int i = 0; i < n; ++i)
//			{
//				arr[i][n - i - 1] = count++;
//			}
//		else
//			for (int i = n - 1; i >= 0; --i)
//			{
//				arr[i][n - 1 - i] = count++;
//			}
//
//		++n;
//	}
//	cout << arr[19][19] << endl;
//	for (int i = 0; i < 20; ++i)
//	{
//		for (int j = 0; j < 20; ++j)
//		{
//			printf("%3d ", arr[i][j]);
//		}
//		cout << endl;
//	}
//	return 0;
//}


#include <iostream>
#include <unordered_set>
#include <time.h>
using namespace std;
int main()
{
	srand((unsigned int)time(0));
	unordered_set<int> ust;
	for (int i = 0; i < 100; ++i)
	{
		ust.insert(rand() % 10000000 + 1);
	}

	for (auto& e : ust)
		cout << e << " ";
	cout << endl;
}