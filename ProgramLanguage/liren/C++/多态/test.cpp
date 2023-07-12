#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//class Person
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << "全价购票" << endl;
//	}
//};
//
//class Student : public Person
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << "半价购票" << endl;
//	}
//};
//
//class Soldier : public Person
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << "优先购票" << endl;
//	}
//};
//
//void Fun(Person p)
//{
//	p.BuyTicket();
//}
//
//int main()
//{
//	Person p;
//	Student st;
//	Soldier sd;
//	
//	Fun(p);
//	Fun(st);
//	Fun(sd);
//	return 0;
//}


//class A 
//{};
//
//class B : public A 
//{};
//
//class Person 
//{
//public:
//	virtual A* f() 
//	{ 
//		cout << "A::f()" << endl;
//		return new A; 
//	}
//};
//
//class Student : public Person 
//{
//public:
//	virtual B* f() 
//	{
//		cout << "B::f()" << endl;
//		return new B; 
//	}
//};
// 
//int main()
//{
//	Person p;
//	Student s;
//	Person* ptr;
//
//	ptr = &p;
//	ptr->f();
//
//	ptr = &s;
//	ptr->f();
//	return 0;
//}

//class Person 
//{
//public:
//	~Person() 
//	{ 
//		cout << "~Person()" << endl; 
//	}
//};
//class Student : public Person 
//{
//public:
//	~Student() 
//	{
//		cout << "~Student()" << endl;
//	}
//};
//// 只有派生类Student的析构函数重写了Person的析构函数，下面的delete对象调用析构函数，才能构成多态，才能保证p1和p2指向的对象正确的调用析构函数。
//int main()
//{
//	Person* p1 = new Person;
//	Person* p2 = new Student;
//	delete p1;
//	delete p2;
//
//	return 0;
//}

//class Person
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << "全价购票" << endl;
//	}
//};
//
//class Student : public Person
//{
//public:
//	void BuyTicket()
//	{
//		cout << "半价购票" << endl;
//	}
//};
//
//void Fun(Person& p)
//{
//	p.BuyTicket();
//}
//
//int main()
//{
//	Person p;
//	Student s;
//
//	Fun(p);
//	Fun(s);
//	return 0;
//}


//class A final
//{
//public:
//	int _a;
//};
//
//class B : public A
//{
//
//};

//class Car
//{
//public:
//	virtual void Drive(char ch) {}
//};
//
//class Benz :public Car
//{
//public:
//	//在想检测的虚函数的实现之前加上override
//	virtual void Drive(int i) override { cout << "Benz-舒适" << endl; }
//};

//class A
//{
//public:
//	A(){ cout << "A()" << endl; }
//
//	virtual void fun() = 0
//	{
//		cout << "可以有实现内容，但是没有意义" << endl;
//	}
//};
//
//class B : public A
//{
//public:
//	B() { cout << "B()" << endl; }
//
//	virtual void fun()
//	{
//		cout << "B::fun()" << endl;
//	}
//};
//
//int main()
//{
//	//A a;   //❌不允许实例化出抽象类
//
//	B b;
//	b.A::fun();  //是可以通过b来调用A的虚函数的
//
//	A& pa = b;  //也可以用A类的引用来调用子类的虚函数
//	b.fun();
//
//	//A* ppa = new A;  //❌也不运行通过动态内存开辟A类
//	return 0;
//}


//// 这里常考一道笔试题：sizeof(Base)是多少？
//class Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Func1()" << endl;
//	}
//private:
//	char _c = '\0';
//	int _b = 1;
//};
//
//int main()
//{
//	cout << sizeof(Base) << endl;
//	Base b;
//	return 0;
//}

////Base再增加一个虚函数Func2和一个普通函数Func3
//class Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Func1()" << endl;
//	}
//
//	virtual void Func2()
//	{
//		cout << "Func2()" << endl;
//	}
//
//	void Func3()
//	{
//		cout << "Func3()" << endl;
//	}
//private:
//	char _c = '\0';
//	int _b = 1;
//};
//
//int main()
//{
//	Base bs;
//	return 0;
//}

//class A
//{
//public:
//	virtual void fun()
//	{
//		cout << "A::fun()" << endl;
//	}
//
//	int _a = 1;
//};
//
//class B : public A
//{
//public:
//	virtual void fun()
//	{
//		cout << "B::fun()" << endl;
//	}
//
//	int _b = 250;
//};
//
//void Func(A p)
//{
//	p.fun();
//}
//
//int main()
//{
//	A a;
//	Func(a);
//
//	B b;
//	b._a = 100;
//	Func(b);
//	return 0;
//}

//class Person {
//public:
//	virtual void BuyTicket() { cout << "买票-全价" << endl; }
//};
//class Student : public Person {
//public:
//	virtual void BuyTicket() { cout << "买票-半价" << endl; }
//};
//void Func(Person* p) {
//	p->BuyTicket();
//}
//int main()
//{
//	Person mike;
//	Func(&mike);
//	mike.BuyTicket();
//
//	return 0;
//}


//class Base
//{
//public:
//	virtual void fun1()
//	{
//		cout << "Base::fun1()" << endl;
//	}
//	virtual void fun2()
//	{
//		cout << "Base::fun2()" << endl;
//	}
//};
//class Derive : public Base
//{
//public:
//	virtual void fun1()
//	{
//		cout << "Derive::fun1()" << endl;
//	}
//	virtual void fun2()
//	{
//		cout << "Derive::fun2()" << endl;
//	}
//	void fun3()
//	{
//		cout << "Derive::fun3()" << endl;
//	}
//};
//
//int main()
//{
//	Base b;
//	Base* p = &b;
//	printf("_vfptr:%p\n", *((int*)p));
//
//	int i;
//	int* j = new int;
//	static int Global = 0;
//	const char* c = "liren";
//	printf("栈上的地址：%p\n", &i);
//	printf("堆上的地址：%p\n", j);
//	printf("静态区上的地址:%p\n", &Global);
//	printf("常量区上的地址:%p\n", c);
//
//	return 0;
//}

//单继承
class Base
{
public:
	virtual void func1() { cout << "Base::func1()" << endl; }
	virtual void func2() { cout << "Base::func2()" << endl; }
private:
	int _a;
};

class Derive : public Base
{
public:
	virtual void func1() { cout << "Derive::func1()" << endl; }
	virtual void func3() { cout << "Derive::func3()" << endl; }
	virtual void func4() { cout << "Derive::func4()" << endl; }
private:
	int _b;
};

//写一个程序，打印出虚表里面的函数，确认一下是否真的在虚表里面
typedef void(*VFunc)();  //由于等会要传_vfptr也就是存函数指针的数组指针，类型是void*，所以我们把他们都统一重命名为VFTunc

void PrintVFT(VFunc* ptr)  //这里ptr是个存函数指针的数组指针
{
	// 依次取虚表中的虚函数指针打印并调用。调用就可以看出存的是哪个函数
	printf("_vfptr:%p\n", ptr);

	for (int i = 0; ptr[i] != nullptr; ++i)
	{
		printf("_vfptr[%d]:%p --> ", i, ptr[i]);
		ptr[i]();  //通过函数指针来调用虚函数来打印函数的内容
	}
	cout << endl;
}

int main()
{
	// 思路：取出b、d对象的头4bytes，就是虚表的指针，前面我们说了虚函数表本质是一个存虚函数指针的指针数组，这个数组最后面放了一个nullptr
	// 1.先取b的地址，强转成一个int*的指针
	// 2.再解引用取值，就取到了b对象头4bytes的值，这个值就是指向虚表的指针
	// 3.再强转成VFunc*，因为虚表就是一个存VFunc类型(虚函数指针类型)的数组。
	// 4.虚表指针传递给PrintVTable进行打印虚表
	// 5.需要说明的是这个打印虚表的代码经常会崩溃，因为编译器有时对虚表的处理不干净，虚表最后面
	//   没有放nullptr，导致越界，这是编译器的问题。我们只需要点目录栏的 - 生成 - 清理解决方案，再编译就好了。

	Base b;
	PrintVFT((VFunc*)(*((int*)&b)));

	/*int i;
	int* j = new int;
	static int Global = 0;
	const char* c = "liren";
	printf("栈上的地址：%p\n", &i);
	printf("堆上的地址：%p\n", j);
	printf("静态区上的地址:%p\n", &Global);
	printf("常量区上的地址:%p\n", c);*/

	Derive d;
	PrintVFT((VFunc*)(*((int*)&d)));

	return 0;
}


//class Person {
//public:
//	Person()
//	{
//		cout << "Person_gou_zao" << endl;
//	}
//	virtual void Fun1()//final
//	{}
//	virtual void Fun2()//final
//	{}
//private:
//	int _a = 0;
//};
//class Student :public Person {
//
//public:
//	Student()
//	{
//		cout << "Student_gou_zao" << endl;
//	}
//	virtual void Fun1()override
//	{
//		cout << "Fun1" << endl;
//	}
//	virtual void Fun2()override
//	{
//		cout << "Fun2" << endl;
//	}
//private:
//	int _id = 0;
//};
//typedef void(*VFP)();
//void PrintVFTable(VFP a[])
//{
//	int i = 0;
//	for (i = 0; a[i]; ++i)
//	{
//		cout << a[i] << endl;
//		a[i]();
//
//	}
//
//}
//int main()
//{
//	Student stu;
//	PrintVFTable((VFP*)*(void**)&stu);
//
//
//	system("pause");
//	return 0;
//}

//多继承
//class Base1 
//{
//public:
//	virtual void func1() { cout << "Base1::func1" << endl; }
//	virtual void func2() { cout << "Base1::func2" << endl; }
//private:
//	int b1;
//};
//
//class Base2 
//{
//public:
//	virtual void func1() { cout << "Base2::func1" << endl; }
//	virtual void func2() { cout << "Base2::func2" << endl; }
//private:
//	int b2;
//};
//
//class Derive : public Base1, public Base2 
//{
//public:
//	virtual void func1() { cout << "Derive::func1" << endl; }
//	virtual void func3() { cout << "Derive::func3" << endl; }
//private:
//	int d1;
//};
//
//typedef void(*VFunc)();  //由于等会要传_vfptr也就是存函数指针的数组指针，类型是void*，所以我们把他们都统一重命名为VFTunc
//
//void PrintVFT(VFunc* ptr)  //这里ptr是个存函数指针的数组指针
//{
//	// 依次取虚表中的虚函数指针打印并调用。调用就可以看出存的是哪个函数
//	printf("_vfptr:%p\n", ptr);
//
//	for (int i = 0; ptr[i] != nullptr; ++i)
//	{
//		printf("_vfptr[%d]:%p --> ", i, ptr[i]);
//		ptr[i]();
//	}
//	cout << endl;
//}
//
//int main()
//{
//	Base1 b1;
//	PrintVFT((VFunc*)(*(int*)&b1));
//
//	Base2 b2;
//	PrintVFT((VFunc*)(*(int*)&b2));
//
//	Derive d;
//	PrintVFT((VFunc*)(*(int*)&d));
//	PrintVFT((VFunc*)(*(int*)((char*)&d + sizeof(Base1))));
//
//	return 0;
//}

//class A
//{
//public:
//	virtual void fun()
//	{
//		cout << "A::fun()" << endl;
//	}
//};
//
//class B : public A
//{
//public:
//	virtual void fun()
//	{
//		cout << "B::fun()" << endl;
//	}
//};
//
//int main()
//{
//	A a;
//	B b;
//	return 0;
//}

//菱形虚拟继承
//class A
//{
//public:
//	virtual void fun()
//	{
//		cout << "A::fun()" << endl;
//	}
//public:
//	int _a;
//};
//
////class B : public A
//class B : virtual public A
//{
//public:
//	virtual void fun()
//	{
//		cout << "B::fun()" << endl;
//	}
//
//	virtual void fun1()
//	{
//		cout << "B::fun1()" << endl;
//	}
//public:
//	int _b;
//};
//
////class C : public A
//class C : virtual public A
//{
//public:
//	virtual void fun()
//	{
//		cout << "C::fun()" << endl;
//	}
//
//	virtual void fun1()
//	{
//		cout << "C::fun1()" << endl;
//	}
//public:
//	int _c;
//};
//
//class D : public B, public C
//{
//public:
//	virtual void fun()
//	{
//		cout << "D::fun()" << endl;
//	}
//public:
//	int _d;
//};
//
//int main()
//{
//	D d;
//	d.B::_a = 1;
//	d.C::_a = 2;
//
//	d._b = 3;
//	d._c = 4;
//	d._d = 5;
//
//	return 0;
//}


//class A {
//public:
//    A(const char* s) { cout << s << endl; }
//    ~A() {}
//};
//
//class B :virtual public A {
//public:
//    B(const char* s1, const char* s2) :A(s1) { cout << s2 << endl; }
//};
//
//class C :virtual public A {
//public:
//    C(const char* s1, const char* s2) :A(s1) { cout << s2 << endl; }
//};
//
//class D :public C, public B {
//public:
//    D(const char* s1, const char* s2, const char* s3, const char* s4) :B(s1, s2), C(s1, s3), A(s1)
//    {
//        cout << s4 << endl;
//    }
//};
//
//int main() {
//    D* p = new D("class A", "class B", "class C", "class D");
//    delete p;
//    return 0;
//}

//class A
//{
//public:
//	A() { cout << "A()" << endl; }
//
//	virtual void fun() = 0
//	{
//		cout << "可以有实现内容，但是没有意义" << endl;
//	}
//};
//
//class B : public A
//{
//public:
//	B() { cout << "B()" << endl; }
//
//	virtual void fun()
//	{
//		cout << "B::fun()" << endl;
//	}
//};
//
//int main()
//{
//	//A a;   //❌不允许实例化出抽象类
//
//	//A* ppa = new A;  //❌也不允许通过动态内存开辟A类
//
//	B b;
//	b.A::fun();  //可以通过b来调用A的虚函数
//
//	A& pa = b;  //也可以用A类的引用来调用子类的虚函数
//	pa.fun();
//
//	return 0;
//}

//class A 
//{ 
//public: 
//	int n = 1;
//	virtual void test(float a) { cout << "A:test()" << endl; }
//}
//; 
//class B :public A 
//{ 
//public: 
//	void test(float a) { cout << "B:test()" << endl; }
//	int n = 2;
//}; 
//int main() 
//{
//	A* a = new A; 
//	B* b = new B;
//	a = b; 
//	a->test(1.1); 
//	b->test(1.1); 
//
//	return 0;
//}

