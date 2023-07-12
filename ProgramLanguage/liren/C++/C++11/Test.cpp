#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//struct Point
//{
//	int _x;
//	int _y;
//};
//int main()
//{
//    // 内置类型变量
//    int x1 = { 10 };
//    int x2{ 10 };
//    int x3 = 1 + 2;
//    int x4 = { 1 + 2 };
//    int x5{ 1 + 2 };
//    // 数组
//    int arr1[5] = { 1,2,3,4,5 };
//    int arr2[]{ 1,2,3,4,5 };
//
//    // 动态数组，在C++98中不支持
//    int* arr3 = new int[5] {1, 2, 3, 4, 5};
//
//    // 标准容器
//    vector<int> v1{ 1,2,3,4,5 };
//    vector<int> v2 = { 1,2,3,4,5 };
//
//    map<int, int> m1{ {1,1}, {2,2},{3,3},{4,4} };
//    map<int, int> m2 = { {1,1}, {2,2},{3,3},{4,4} };
//
//    return 0;
//}

//int main()
//{
//	// the type of il is an initializer_list 
//	auto il = { 10, 20, 30 };
//	cout << typeid(il).name() << endl;
//	return 0;
//}

// decltype的一些使用使用场景
//template<class T1, class T2>
//void F(T1 t1, T2 t2) 
//{
//	decltype(t1 * t2) ret;
//	cout << typeid(ret).name() << endl;
//}
//
//int Fun(int a)
//{
//	return 1;
//}
//
//int main()
//{
//	const int x = 1;
//	double y = 2.2;
//
//	decltype(x * y) ret = 13.5; // ret的类型是double
//	decltype(&x) p; // p的类型是int*
//	
//	cout << typeid(ret).name() << endl;
//	cout << typeid(p).name() << endl; 
//
//	// 对于函数指针也可以
//	int(*pfunc1)(int) = Fun; // 普通的函数指针写法
//	decltype(&Fun) pfunc2 = Fun;
//	decltype(pfunc2) pfunc3 = Fun;
//	
//	F(1, 'a');
//
//	auto it = { 1, 2, 3, 4, 5 };
//	// 如果vector中要存的是自动推导的类型，那么auto是做不到的，因为auto需要初始化
//	// vector<auto> v;  
//	vector<decltype(it)> v;
//	v.push_back(it);
//	return 0;
//}


//template <class T>
//struct ListNode
//{
//	T _data;
//	ListNode* _next;
//
//	ListNode(T val)
//	{
//		_data = val;
//		_next = NULL;
//	}
//};
//
//template <class T>
//class queue
//{
//public:
//	queue()
//	{
//		_sz = 0;
//		ListNode<T>* newnode = new ListNode<T>(-1);
//		_head = newnode;
//		_tail = _head;
//	}
//
//	// 析构函数
//	~queue()
//	{
//		ListNode<T>* cur = _head->_next;
//		while (cur != NULL)
//		{
//			_head->_next = cur->_next;
//			delete cur;
//			cur = _head->_next;
//		}
//		delete _head;
//	}
//
//	bool empty() const
//	{
//		return _head->_next == NULL;
//	}
//
//	T& front()
//	{
//		return _head->_next->_data;
//	}
//
//	T& tail()
//	{
//		return _tail->_data;
//	}
//
//	bool push(T val)
//	{
//		ListNode<T>* newnode = new ListNode<T>(val);
//		_tail->_next = newnode;
//		_tail = newnode;
//		_sz++;
//		return true;
//	}
//
//	void Print()
//	{
//		if (this->empty())
//			return;
//
//		ListNode<T>* cur = _head->_next;
//		while (cur != _tail)
//		{
//			cout << cur->_data << " ";
//			cur = cur->_next;
//		}
//		cout << cur->_data << endl;
//	}
//
//	bool pop()
//	{
//		if (this->empty())
//			return false;
//
//		ListNode<T>* destroy = _head->_next;
//		_head->_next = destroy->_next;
//		free(destroy);
//		_sz--;
//		return true;
//	}
//private:
//	// 带头结点的队列
//	ListNode<T>* _head;
//	ListNode<T>* _tail;
//	size_t _sz;
//};
//int main()
//{
//	queue<int> q;
//	q.push(1);
//	q.push(1);
//	q.push(1);
//	q.push(1);
//	q.push(1);
//	q.Print();
//
//	q.pop();
//	q.pop();
//	q.pop();
//	q.pop();
//	q.pop();
//	q.pop();
//	q.Print();
//	return 0;
//}

//namespace liren
//{
//    class string
//    {
//    public:
//        string(const char* str = "")
//            :_size(strlen(str))
//            , _capacity(_size)
//        {
//            cout << "string(char* str) -- 构造函数" << endl;
//            _str = new char[_capacity + 1];
//            strcpy(_str, str);
//        }
//
//        // string的移动构造
//        string(string&& s)
//            :_str(nullptr)
//            , _size(0)
//            , _capacity(0)
//        {
//            cout << " string(string&& s) -- 移动资源" << endl;
//            this->swap(s);
//        }
//
//        // string的拷贝构造
//        string(const string& s)
//            :_str(nullptr)
//            , _size(0)
//            , _capacity(0)
//        {
//            cout << " string(const string& s) -- 深拷贝" << endl;
//            string tmp(s._str);
//            this->swap(tmp);
//        }
//
//        void swap(string& s)
//        {
//            std::swap(s._size, this->_size);
//            std::swap(s._capacity, this->_capacity);
//            std::swap(s._str, this->_str);
//        }
//
//        // 赋值重载
//        string& operator=(const string& s)
//        {
//            cout << " string& operator=(const string& s) -- 深拷贝" << endl;
//
//            string tmp(s);
//            swap(tmp);
//            return *this;
//        }
//
//        // 移动赋值
//        string& operator=(string&& s)
//        {
//            cout << "string& operator=(string&& s) -- 移动语义" << endl;
//            swap(s);
//            return *this;
//        }
//
//        ~string() { if (_str) delete[] _str; }
//    private:
//        char* _str;
//        size_t _size;
//        size_t _capacity;
//    };
//}
//
//template<class T>
//struct ListNode
//{
//    ListNode* _next = nullptr;
//    ListNode* _prev = nullptr;
//    T _data;
//};
//template<class T>
//class List
//{
//    typedef ListNode<T> Node;
//public:
//    List()
//    {
//        _head = new Node;
//        _head->_next = _head;
//        _head->_prev = _head;
//    }
//    void PushBack(T&& x)
//    {
//        //Insert(_head, x);
//        Insert(_head, std::forward<T>(x));
//    }
//    void PushFront(T&& x)
//    {
//        //Insert(_head->_next, x);
//        Insert(_head->_next, std::forward<T>(x));
//    }
//    void Insert(Node* pos, T&& x)
//    {
//        Node* prev = pos->_prev;
//        Node* newnode = new Node;
//        newnode->_data = std::forward<T>(x); // 关键位置,使用std::forward
//
//        // prev newnode pos
//        prev->_next = newnode;
//        newnode->_prev = prev;
//        newnode->_next = pos;
//        pos->_prev = newnode;
//    }
//    void Insert(Node* pos, const T& x)
//    {
//        Node* prev = pos->_prev;
//        Node* newnode = new Node;
//        newnode->_data = x; // 关键位置，接收的是左值，不需要完美转发
//
//        // prev newnode pos
//        prev->_next = newnode;
//        newnode->_prev = prev;
//        newnode->_next = pos;
//        pos->_prev = newnode;
//    }
//private:
//    Node* _head;
//};
//int main()
//{
//    List<liren::string> lt;
//    lt.PushBack("1111");
//    lt.PushFront("2222");
//    return 0;
//}

//struct Goods
//{
//    string _name;
//    double _price;
//};
//struct Compare
//{
//    bool operator()(const Goods& gl, const Goods& gr)
//    {
//        return gl._price <= gr._price;
//    }
//};
//int main()
//{
//    vector<Goods> gds = { { "苹果",2.1 }, { "相交",3 }, { "橙子",2.2 }, {"菠萝",1.5} };
//    //sort(gds.begin(), gds.end(), Compare());
//    return 0;
//}

//struct Goods
//{
//    string _name;
//    double _price;
//};
//int main()
//{
//	vector<Goods> gds = { { "苹果",2.1 }, { "相交",3 }, { "橙子",2.2 }, {"菠萝",1.5} };
//	sort(gds.begin(), gds.end(), [])
//	return 0;
//}

//int main()
//{
//	// 最简单的lambda表达式, 该lambda表达式没有任何意义
//	[]{};
//
//	int a = 3, b = 11;
//
//	// 实现两个数相加的lambda表达式（返回值也可以省略，让编译器推导）
//	auto add1 = [](int x, int y)->int{ return x + y; };
//	cout << add1(a, b) << endl;
//
//	// 若想定义和add1一样的变量，则有两种方法：auto或者decltype
//	auto add2 = add1;
//	decltype(add1) add3 = add1;
//	cout << typeid(add2).name() << endl;
//	cout << typeid(add3).name() << endl;
//
//	return 0;
//}

//int main()
//{
//	int a = 10, b = 20;
//
//	// 两数交换的lambda表达式
//	auto swap = [](int& x, int& y) {
//		int z = x;
//		x = y;
//		y = z;
//	};
//	swap(a, b);
//	cout << a << " " << b << endl;
//	return 0;
//}

//int main()
//{
//	int a = 10, b = 20;
//
//	// 两数交换的lambda表达式
//	auto swap = [&a, &b]()mutable{
//		int c = a;
//		a = b;
//		b = c;
//	};
//	swap();
//	cout << a << " " << b << endl;
//	return 0;
//}

//void (*PF)();
//
//int f = 10, g = 100;
//// 全局的lambda捕捉不了变量
//// auto cat1 = [&a, &b] {};
//// auto cat2 = [f, g] {};
//	auto cat3 = [] {cout << "just only empty!" << endl; };
//
//int main()
//{
//	int a = 1, b = 2, c = 3;
//	auto change1 = [&, b] {
//		a = 10;
//		//b = 20; b无法被修改因为是传值接收的，而其余变量是传引用接收
//		c = 30;
//	};
//	change1();
//	cout << a << " " << b << " " << c << endl;
//
//	auto f1 = [] {cout << "hello world" << endl; };
//	auto f2 = [] {cout << "hello world" << endl; };
//	// 此处先不解释原因，等lambda表达式底层实现原理看完后，大家就清楚了
//	// f1 = f2; // 编译失败--->提示找不到operator=()
//	// 允许使用一个lambda表达式拷贝构造一个新的副本
//	auto f3(f2);
//	f3();
//
//	// 可以将lambda表达式赋值给相同类型的函数指针
//	PF = f2;
//	PF();
//
//	// 调用全局中的lambda
//	cat3();
//
//	// 不能捕捉重复属性的！
//	// auto func1 = [=, a]() {};
//	// auto func2 = [&, &a]() {};
//
//	return 0;
//}

//class Rate
//{
//public:
//	Rate(double rate) : _rate(rate)
//	{}
//	double operator()(double money, int year)
//	{
//		return money * _rate * year;
//	}
//private:
//	double _rate;
//};
//int main()
//{
//	// 函数对象
//	double rate = 0.49;
//	Rate r1(rate);
//	cout << r1(10000, 2) << endl;;
//
//	// lamber
//	auto r2 = [=](double money, int year)->double {return money * rate * year; };
//	cout << r2(10000, 2) << endl;
//	return 0;
//}
//
//#include<graphics.h>
//#include<math.h>
//#include<conio.h>
//#include <stdio.h>
//
//#define PI 3.1415926535
//
//int main()
//{
//	initgraph(640, 480);
//	setorigin(320, 240);
//	setcolor(GREEN);
//
//	//画花朵
//	double e;
//	int x1, y1, x2, y2;
//	for (double a = 0; a < 2 * PI; a += 2 * PI / 720)
//	{
//		e = 100 * (1 + sin(4 * a));
//		x1 = (int)(e * cos(a));
//		y1 = (int)(e * sin(a));
//		x2 = (int)(e * cos(a + PI / 5));
//		y2 = (int)(e * sin(a + PI / 5));
//
//		line(x1, y1, x2, y2);
//
//		Sleep(1);		// 延迟函数，实现慢速绘制的动画效果
//	}
//
//	getchar();
//	closegraph();
//	return 0;
//}

//class Student
//{
//	static int n;
//public:
//	Student()
//	{
//		n++;
//		show("Student");
//	}
//	Student(const Student&)
//	{
//		n++;
//		show("Student");
//	}
//	~Student()
//	{
//		n--;
//		show("~Student");
//	}
//	static void show(const char* str = nullptr)
//	{
//		if (str)
//			cout << str << ":";
//		cout << "n = " << n << endl;
//	}
//};
//int Student::n = 0;
//Student f(Student x)
//{
//	x.show("x inside f()");
//	return x;
//}
//
//int main()
//{
//	Student s1;
//	Student s2 = f(s1);
//	Student::show("after call f()");
//	return 0;
//}

//class Person
//{
//public:
//    Person(const char* name = "", int age = 0)
//        :_name(name)
//        , _age(age)
//    {}
//    Person(const Person& p)
//        :_name(p._name)
//        , _age(p._age)
//    {}
//    Person(Person&& p) = default;
//private:
//    liren::string _name;
//    int _age;
//};
//int main()
//{
//    Person s1;
//    Person s2 = s1;
//    Person s3 = std::move(s1);
//    return 0;
//}
//
//class Person
//{
//public:
//    Person(const char* name = "", int age = 0)
//        :_name(name)
//        , _age(age)
//    {}
//    Person(const Person& p) = default;
//    Person(Person&& p) = default;
//private:
//    liren::string _name;
//    int _age;
//};
//int main()
//{
//    Person s1;
//    Person s2 = s1;
//    Person s3 = std::move(s1);
//    return 0;
//}


//// 特殊版本的ShowList，是递归终止的函数
//template <class T>
//void ShowList(const T& val)
//{
//    cout << typeid(val).name() << ":" << val << endl << endl;
//}
//
//template<class T, class ...Args>
//void ShowList(T val, Args... args)
//{
//    cout << typeid(val).name() << ":" << val << endl;
//    ShowList(args...); // 调用自己的时候，直接传自己的包过去成为新的val
//}
//
//int main()
//{
//    ShowList(1);
//    ShowList(1, 'A');
//    ShowList(1, 'A', std::string("liren"));
//    return 0;
//}

//int main()
//{
//    list<std::pair<int, std::string>> mylist;
//    mylist.emplace_back(1, "liren");
//
//    auto it = mylist.begin();
//    while (it != mylist.end())
//    {
//        cout << it->first << " " << it->second << endl;
//        ++it;
//    }
//    cout << endl;
//    return 0;
//}

//template <class T>
//int PrintArg(T val)
//{
//    cout << typeid(val).name() << ":" << val << endl;
//    return 0;
//}
//
////展开函数
//template <class ...Args>
//void ShowList(Args... args)
//{
//    int arr[] = { PrintArg(args)... };
//    cout << endl;
//}
//int main()
//{
//    ShowList(1);
//    ShowList(1, 'A');
//    ShowList(1, 'A', std::string("sort"));
//    return 0;
//}
//namespace liren
//{
//    class string
//    {
//    public:
//        string(const char* str = "")
//            :_size(strlen(str))
//            , _capacity(_size)
//        {
//            cout << "string(char* str) -- 构造函数" << endl;
//            _str = new char[_capacity + 1];
//            strcpy(_str, str);
//        }
//
//        // string的移动构造
//        string(string&& s)
//            :_str(nullptr)
//            , _size(0)
//            , _capacity(0)
//        {
//            cout << " string(string&& s) -- 移动构造" << endl;
//            this->swap(s);
//        }
//
//        // string的拷贝构造
//        string(const string& s)
//            :_str(nullptr)
//            , _size(0)
//            , _capacity(0)
//        {
//            cout << " string(const string& s) -- 拷贝构造：深拷贝" << endl;
//            string tmp(s._str);
//            this->swap(tmp);
//        }
//
//        void swap(string& s)
//        {
//            std::swap(s._size, this->_size);
//            std::swap(s._capacity, this->_capacity);
//            std::swap(s._str, this->_str);
//        }
//
//        // 赋值重载
//        string& operator=(const string& s)
//        {
//            cout << " string& operator=(const string& s) -- 赋值重载：深拷贝" << endl;
//
//            string tmp(s);
//            swap(tmp);
//            return *this;
//        }
//
//        // 移动赋值
//        string& operator=(string&& s)
//        {
//            cout << "string& operator=(string&& s) -- 移动赋值" << endl;
//            swap(s);
//            return *this;
//        }
//
//        ~string() { if (_str) delete[] _str; }
//    private:
//        char* _str;
//        size_t _size;
//        size_t _capacity;
//    };
//}
//int main()
//{
//    // 下面我们试一下带有拷贝构造和移动构造的liren::string，再试试呢
//    // 我们会发现其实差别也不大，emplace_back是直接构造了
//    // push_back是先构造，再移动构造，其实也还好，因为移动构造的消耗比较小。
//    std::list< std::pair<int, liren::string> > mylist2;
//    mylist2.emplace_back(10, "sort");
//    mylist2.emplace_back(make_pair(20, "sort"));
//    cout << endl;
//    mylist2.push_back(make_pair(30, "sort"));
//    mylist2.push_back({ 40, "sort" });
//
//    return 0;
//}

//int main()
//{
//    int a = 10;
//    double b{ a };
//
//    double c = 10.0;
//    int d{ c };
//}



//int main()
//{
//    int m = 100;
//    // char n = { m }; // ❌，收窄，无法通过编译
//
//    const int x = 1024;
//    const int y = 10;
//    char a = x;                   // 收窄，但可以通过编译
//    char* b = new char(1024);     // 收窄，但可以通过编译
//    //char c = { x };               // ❌, 收窄，无法通过编译
//    char c = static_cast<char>(x); // 显式进行类型转换，并进行范围检查
//    char d = { y };               // 可以通过编译
//
//    //unsigned char e{ -1 };        // ❌,收窄，无法通过编译
//    float f{ 7 };                 // 可以通过编译
//    //int g{ 2.0f };                // ❌,收窄，无法通过编译
//    //float* h = new float{ 1e48 }; // ❌,收窄，无法通过编译
//    float i = 1.2l;               // 可以通过编译
//    return 0;
//}


//void func(int arr[]) //形参中的数组不是数组，而是指针变量，存放数组的地址，无法确定元素个数
//{
//    //使用基于范围的 for 循环， 其 for 循环迭代的范围必须是可确定的：
//    for (int& tmp : arr) {
//        std::cout << tmp << " ";
//    }
//}
//
//int main()
//{
//    int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//    func(arr);//传过去的是arr数组的地址
//    return 0;
//}


//#include <type_traits>
//
//template <class T>
//void do_something(T value)
//{
//    static_assert(std::is_integral<T>::value, "T must be an integral type");
//    // 如果T不是整数类型，编译器会在这里报错
//
//    // 此处省略具体的代码实现
//}
//
//int main()
//{
//    do_something(42); // 正常调用
//    do_something("hello"); // 编译错误：T must be an integral type
//    return 0;
//}


//void foo() noexcept
//{
//    // do something
//    //throw 1;
//}
//
//int main()
//{
//        foo();  
//    return 0;
//}


//enum class Color : char { Red, Green, Blue };
//enum struct Animal : int { Dog, Pig, Cat };
////enum struct Food : double { Rice, HotDog, Hamburger }; // ❌double不是合法的枚举类型
//
//int main() 
//{
//    //Color c = Red; // 错误的定义方法，必须要指明Red的作用域
//    Color c = Color::Red;
//    std::cout << "The color is red." << std::endl;
//    std::cout << "this color type is " << typeid(c).name() << std::endl;
//    std::cout << "this color size is " << sizeof(c) << std::endl;
//
//    Animal a = Animal::Pig;
//    std::cout << "The animal is pig." << std::endl;
//    std::cout << "this animal type is " << typeid(a).name() << std::endl;
//    std::cout << "this animal size is " << sizeof(a) << std::endl;
//    return 0;
//}



//// constexpr修饰fib函数使得其在编译期间就进行计算结果！
//constexpr int fib(int n) 
//{
//    return (n <= 1) ? n : fib(n - 1) + fib(n - 2);
//}
//
//int main() 
//{
//    int a[10] = { fib(0), fib(1), fib(2), fib(3), fib(4), fib(5), fib(6), fib(7), fib(8), fib(9) };
//    for (int i = 0; i < 10; ++i) 
//    {
//        std::cout << a[i] << " ";
//    }
//    return 0;
//}

//static const int u = 10;
//const int v = 10; // 以上两个具有全局属性的常量是可以被return的
//
//int w = 10; // ❌全局属性的非常量，return后会报错
//
//constexpr int sum(int a, int b) 
//{
//    const int tmp = 10; // 可以定义常量语句
//    int c = 20; 
//    // 该函数体中的非常量c是可以在return中出现的，因为能在编译的时候确定
//    // 但不是该函数体中的非常量
//    return a + b + tmp + c + v + u;
//}
//
//constexpr void nothing(int a, int b) // 返回值可以为void，但是没什么价值
//{
//    const int tmp = 10;
//    int f = 10;
//}
//
//constexpr int add(int a, int b)
//{
//    constexpr int c = sum(1, 2); // sum中已经有了return语句，所以编译时会展开，也就说return a + b;根本就没有被执行
//    return a + b; // 执行不到这步就return结束了
//}
//
//int main() 
//{
//    // ❌main函数中定义的static只有在调用main后才会被定义，所以是无法被constexpr编译的时候找到并返回的
//    static int k = 10; 
//
//    // int x = 1, y = 2; // ❌传给constexpr函数的参数必须也是常量
//    const int x = 1, y = 2; // 或者用constexpr也行，后面会讲两者的区别
//    constexpr int z = sum(x, y);  // 编译时计算出z的值
//    cout << z << endl;
//
//    // 使用非常量t接收constexpr函数的返回值，在编译器看来t相当于还是一个非常量类型int
//    // 因为变量的类型是由编译器在编译时推导出来的，而不是由运行时环境决定的。
//    int t = sum(x, z); 
//    cout << t << endl;
//    t = 10;
//    cout << t << endl;
//
//    nothing(x, y); // 调用无返回值的constexpr函数是可以的，但是意义不大
//    return 0;
//}


//class Date 
//{
//public:
//    //constexpr修饰构造函数，构造函数体必须为空
//    constexpr Date(int year, int month, int day)
//        :year_(year)
//        , month_(month)
//        , day_(day) 
//    {
//        //构造函数体必须为空，那么不能使用赋值初始化，而是使用参数列表初始化
//    }
//
//    ~Date() {}
//
//    constexpr int getYear() {
//        return year_;
//    }
//    constexpr int getMonth() {
//        return month_;
//    }
//    constexpr int getDay() {
//        return day_;
//    }
//private:
//    int year_;
//    int month_;
//    int day_;
//};
//
//int main() 
//{
//    Date date(2022, 9, 18);  //必须使用常量给构造函数传参
//    std::cout << date.getYear() << std::endl;
//    std::cout << date.getMonth() << std::endl;
//    std::cout << date.getDay() << std::endl;
//    return 0;
//}




////用户自定义字面值， 或者叫“自定义后缀”更直观些， 主要作用是简化代码的读写。
////自定义变量，名字要求operator""  xxx
//
//long double operator"" _mm(long double x) {
//    return x / 1000;
//}
//long double operator"" _m(long double x) {
//    return x;
//}
//long double operator"" _km(long double x) {
//    return x * 1000;
//}
//int main()
//{
//    cout << 1.0_mm << endl; // 0.001
//    cout << 1.0_m << endl;  // 1
//    cout << 1.0_km << endl; // 1000
//    return 0;
//}

//size_t operator"" _len(char const*, size_t len)
//{
//    return len;
//}
//int main()
//{
//    cout << "lirendada"_len << endl;
//    return 0;
//}

//const char * operator"" _r(const char* s) { return s; }
//
//int main()
//{
//    std::cout << 250_r << '\n';
//}

//string operator"" _rs(char const* s)
//{
//    return 'x' + string(s) + 'y';
//}
//
//int main()
//{
//    cout << 520_rs << endl;
//    return 0;
//}

//int main()
//{
//    string str = "D:\hello\world\test.text";
//    cout << str << endl;
//
//    string str1 = "D:\\hello\\world\\test.text";
//    cout << str1 << endl;
//
//    string str2 = R"(D:\hello\world\test.text)";
//    cout << str2 << endl;
//
//    return 0;
//}

//class A
//{
//public:
//    // ...
//private:
//    int x = 10;
//    string str = "liren";
//    const float ft = 10.3;
//};

//class Base {
//public:
//    // 基类拥有多个构造函数
//    Base(int v) : _value(v), _c('0') {}
//    Base(char c) : _value(0), _c(c) {}
//private:
//    int _value;
//    char _c;
//};
//
//class Derived : public Base {
//public:
//    // 初始化基类需要透传参数至基类的各个构造函数，非常麻烦
//    Derived(int v) : Base(v) {}
//    Derived(char c) : Base(c) {}
//
//    // 假设派生类只是添加了一个普通的函数
//    void display() {
//        // dosomething		
//    }
//};


//class Base {
//public:
//    // 基类拥有多个构造函数
//    Base(int v) : _value(v), _c('0') {}
//    Base(char c) : _value(0), _c(c) {}
//private:
//    int _value;
//    char _c;
//};

//class Derived : public Base {
//public:
//    using Base::Base;
//
//    // 新增派生类构造函数
//    Derived(int a, double d) : Base(a), _d(d) {}
//
//    void display() {
//        // dosomething		
//    }
//private:
//    // 派生类新增数据成员
//    double _d = 10.0;
//};

//class Derived : public Base {
//public:
//    using Base::Base;
//
//    // 新增派生类构造函数
//    Derived(int a, double d) : Base(a), _d(d) {}
//
//    void display() {
//        // dosomething		
//    }
//private:
//    // 派生类新增数据成员并声明缺省值
//    double _d = 10.0;
//};

//class A {
//public:
//    A(int a = 3, double b = 4) : _a(a), _b(b) {}
//
//    void display() {
//        cout << _a << " " << _b << endl;
//        cout << this << endl;
//    }
//private:
//    int _a;
//    double _b;
//};
//
//class B :public A {
//public:
//    using A::A;
//};
//
//int main()
//{
//    A a;
//    a.display();
//
//    B b;
//    b.display();
//    return 0;
//}


//class A {
//public:
//    A(int i) {}
//};
//
//class B {
//public:
//    B(int i) {}
//};
//
//class C : public A, public B {
//public:
//    using A::A;
//    using B::B;  //编译出错，重复定义C(int)
//
//    // 显示定义继承构造函数 C(int)
//    C(int i) :A(i), B(i) {}
//};


//class Test {
//public:
//    Test() {}
//    // 此处为成员初始化，没有委托
//    Test(string str) : _str{ str } {}
//
//    // can't do member initialization here
//    // error C3511: a call to a delegating constructor shall be the only member-initializer
//    Test(string str, double dbl) : Test(str), _dbl{ dbl } {}  // ❌
//
//    // 若仅仅是成员赋值而不是初始化则可以
//    Test(string str, double dbl) : Test(str) { _dbl = dbl; }
//private:
//    double _dbl{ 1.0 };
//    string _str;
//};

//class class_a {
//public:
//    class_a() {}
//    class_a(string str) : m_string{ str } {}
//    class_a(string str, double dbl) : class_a(str) { m_double = dbl; }
//
//    void print() { cout << m_double << endl << m_string << endl; }
//private:
//    double m_double{ 1.0 };
//    string m_string{ m_double < 10.0 ? "alpha" : "beta" };
//};
//
//int main() {
//    class_a a{ "hello", 2.0 };  // expect a.m_double == 2.0, a.m_string == "hello"
//    a.print();
//}

//class class_f {
//public:
//    // don't do this
//    class_f() : class_f(6, 3) { }
//    class_f(int my_max, int my_min) : class_f() { }
//private:
//    int max;
//    int min;
//};

//class entrust
//{
//public:
//    entrust() {}
//    entrust(int first) 
//    {
//        cout << "this is first" << endl;
//    }
//    entrust(int first, int second) 
//    {
//        cout << "this is first" << endl;
//        cout << "this is second" << endl;
//    }
//    entrust(int first, int second, int third) 
//    {
//        cout << "this is first" << endl;
//        cout << "this is second" << endl;
//        cout << "this is third" << endl;
//    }
//private:
//    int _first;
//    int _second;
//    int _third;
//};

//class entrust
//{
//public:
//    entrust() {}
//    entrust(int f)
//    {
//        cout << "this is first " << f << endl;
//    }
//    entrust(int f, int s) : entrust(f)
//    {
//        cout << "this is second " << s << endl;
//    }
//    entrust(int f, int s, int t) : entrust(f, s)
//    {
//        cout << "this is third " << t << endl;
//    }
//private:
//    int _first;
//    int _second;
//    int _third;
//};
//
//int main()
//{
//    entrust et(1, 2, 3);
//    return 0;
//}

//class Test {
//public:
//    Test() {}
//    Test(string str) : _str(str) {}
//    Test(string str, double dbl) : Test(str) { _dbl = dbl; }
//
//    void print() { cout << _dbl << '\n' << _str << endl; }
//private:
//    double _dbl = 1.0; // 声明缺省值为1.0
//    string _str;
//};
//
//int main()
//{
//    Test t{ "liren", 2.0 };
//    t.print(); 
//}

//class Test {
//public:
//    // ❌don't do this
//    Test() : Test(6, 3) { }  
//    Test(int my_max, int my_min) : Test() { }
//private:
//    int max;
//    int min;
//};

//template<size_t i>
//class X {};
//
//template<class T>
//class Y {};
//
//int main()
//{
//    Y<X<1>> x1; // 在c++11中编译通过
//    Y<X<2>> x2; // 在c++98中编译失败
//
//    return 0;
//}


//#include<iostream>
//#include<type_traits>
//
//typedef int int32;    // 通过typedef 给一个类型起别名，不是新建类型
//using my_int = int;   // c++11的方式
//
//int main() 
//{
//    // is_same是判断两个类型是否一致，如果是则返回真，否则返回假
//    std::cout << std::is_same<int32, my_int>::value << std::endl;
//    return 0;
//}


//template <typename T>
//struct FuncSt
//{
//    typedef void(*func)(T, T);
//};
//int main()
//{
//    FuncSt<int>::func func_typedef;
//    return 0;
//}

//template<class... Args>
//void func(Args... args)
//{
//    cout << "num= " << sizeof...(args) << endl;
//}
//
//int main() {
//    func();
//    func<int>(10);
//    func<int, char>(10, 'a');
//    func<int, char, string, double>(10, 'a', "abc", 1.0);
//    return 0;
//}

//
//template<class T, class ...Args>
//void ShowList(T val, Args... args)
//{
//    cout << typeid(val).name() << ":" << val << endl;
//    ShowList(args...); // 调用自己的时候，直接传自己的包过去成为新的val
//}
//
//int main()
//{
//    ShowList(1);
//    ShowList(1, 'A');
//    ShowList(1, 'A', std::string("liren"));
//    return 0;
//}

//template<class T>
//int PrintArgs(T val)
//{
//    cout << typeid(val).name() << ":" << val << endl;
//    return 0;
//}
//
//template<class... Args>
//void ShowList(Args... args)
//{
//    int arr[] = { PrintArgs(args)... };
//    cout << endl;
//}
//
//int main()
//{
//    std::list< std::pair<int, char> > mylist;
//    mylist.push_back({ 50, 'e' });
//
//    return 0;
//}

//int main()
//{
//    // 我们会发现其实差别也不大
//    // emplace_back是直接构造了，push_back是先构造，再移动构造，其实也还好。
//    std::list< std::pair<int, liren::string> > mylist;
//    mylist.emplace_back(10, "sort");
//    mylist.emplace_back(make_pair(20, "sort"));
//
//    mylist.push_back(make_pair(30, "sort"));
//    mylist.push_back({ 40, "sort" });
//
//    return 0;
//}

//#include <iostream>
//#include <typeinfo>
//using namespace std;
//
//template<typename... A> class BMW {};  // 变长模板的声明
//
//template<typename Head, typename... Tail>  // 递归的偏特化定义
//class BMW<Head, Tail...> : public BMW<Tail...>
//{	// 当实例化对象时，则会引起基类的递归构造
//public:
//    BMW()
//    {
//        printf("type: %s\n", typeid(Head).name());
//    }
//private:
//    Head head;
//};
//
//template<> class BMW<> {};  // 边界条件
//
//int main()
//{
//    BMW<int, char, float> car;
//    return 0;
//}


//#include "Test.h"
////const double GamePlayer::num = 10.0;
////int main()
////{
////    //GamePlayer gp;
////
////    TextBlock tb("lirendada");
////    cout << tb[1] << endl;
////    tb[1] = 'a';
////    cout << tb[1] << endl;
////    print(tb);
////
////    const TextBlock ctb("const lirendada");
////    print(ctb);
////    cout << ctb[2] << endl;
////    //ctb[2] = 'a';
////    return 0;
////}
//
//int main()
//{
//    CTextBlock ct("lirendada");
//    return 0;
//}


#include "Test.h"

Directory::Directory()
{
    size_t disks = tfs().numDisks();
    cout << disks << endl;
}

Directory& tmpDir()
{
    static Directory td;
    return td;
}
