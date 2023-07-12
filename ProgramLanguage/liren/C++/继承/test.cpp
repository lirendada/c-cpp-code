#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

//class People
//{
//public:
//	void Print()
//	{
//		cout << "name: " << _name  << " age: " << _age << endl;
//	}
//protected:
//	string _name = "liren";
//	int _age = 250;
//};
//
//// Teacher以public的方式继承了People
//class Teacher : public People
//{
//	// ...
//private:
//	int _Workid = 324;
//};
//
//// Student以public的方式继承了People
//class Student : public People
//{
//	// ...
//private:
//	int _Stuid = 811;
//};
//
//int main()
//{
//	People p;
//	p.Print();
//
//	Teacher t;
//	t.Print();
//
//	Student s;
//	s.Print();
//
//	return 0;
//}

//class People
//{
//protected:
//	void Print()
//	{
//		cout << "name: " << _name << " age: " << _age << endl;
//	}
//
//	string _name = "liren";
//	int _age = 250;
//};
//
//class Teacher : private People
//{
//public:
//	void getName(string& name)
//	{
//		_name = name;
//		cout << _name << endl;
//	}
//private:
//	int _Workid = 324;
//};
//
//int main()
//{
//	People p;
//	p.Print();
//	Teacher t;
//	t.Print();
//	t._name();
//	string s = "lirendada";
//	t.getName(s);
//
//	return 0;
//}
//
//class People
//{
//public:
//	string _name = "liren";
//	int _age = 250;
//};
//
//// Student以public的方式继承了People
//class Student : public People
//{
//	// ...
//private:
//	int _Stuid = 811;
//};
//
//int main()
//{
//	Student s;
//	// 子类对象可以赋值给父类对象/指针/引用
//	People p = s;
//	People* pp = &s;
//	People& rp = s;
//
//	//s = p;  // 父类不能赋给子类
//
//	return 0;
//}

//
//class People
//{
//public:
//	string _name = "liren";
//	int _age = 250;
//};
//
//class Student : public People
//{
//	// ...
//private:
//	int _age = 100;
//};
//
//int main()
//{
//	Student s;
//
//	People p = s;
//
//	return 0;
//}

//// Student的_num和Person的_num构成隐藏关系，可以看出这样代码虽然能跑，但是非常容易混淆
//class Person
//{
//protected:
//	string _name = "liren"; // 姓名
//	int _num = 250; // 身份证号
//};
//class Student : public Person
//{
//public:
//	void Print()
//	{
//		cout << " 姓名:" << _name << endl;
//		cout << " 身份证号:" << Person::_num << endl;
//		cout << " 学号:" << _num << endl;
//	}
//protected:
//	int _num = 999; // 学号
//};
//
//int main()
//{
//	Student s1;
//	s1.Print();
//}

// B中的fun和A中的fun不是构成重载，因为不是在同一作用域
// B中的fun和A中的fun构成隐藏，成员函数满足函数名相同就构成隐藏。
//class A {
//public:
//	void fun()
//	{
//		cout << "func()" << endl;
//	}
//};
//class B : public A {
//public:
//	void fun(int i)
//	{
//		A::fun();
//		cout << "func(int i)->" << i << endl;
//	}
//};
//int main()
//{
//	B b;
//	b.fun(10);
//	return 0;
//}

//class Person
//{
//public:
//    Person() { ++_count; }
//protected:
//    string _name; // 姓名
//public:
//    static int _count; // 统计人的个数。
//};
//
//int Person::_count = 0; //静态成员需要在类外完成初始化
//
//class Student : public Person
//{
//protected:
//    int _stuNum; // 学号
//};
//
//class Graduate : public Student
//{
//protected:
//    string _seminarCourse; // 研究科目
//};
//
//int main()
//{
//    Student s1;
//    Student s2;
//    Student s3;
//    Graduate s4;
//	Person s;
//
//	cout << "大家都可以访问" << endl;
//	cout << "人数 : " << Person::_count << endl;
//	cout << "人数 : " << Student::_count << endl;
//	cout << "人数 : " << s4._count << endl;
//
//	cout << "大家也都可以变动" << endl;
//	s3._count = 0;
//	cout << "人数 : " << Person::_count << endl;
//
//	cout << "并且他们的地址也都是一样的，因为所有继承体系中只有一个" << endl;
//	cout << "人数 : " << &Person::_count << endl;
//	cout << "人数 : " << &Student::_count << endl;
//	cout << "人数 : " << &s4._count << endl;
//
//    return 0;
//}


//class Person
//{
//public:
//	/* 父类构造函数 */
//	Person(const char* name = "lirendada")
//		:_name(name)
//	{
//		cout << "Person()" << endl;
//	}
//protected:
//	string _name;
//};
//
//class Student : public Person
//{
//public:
//	/* 子类构造函数 */
//	Student(const char* name, int num)
//		:Person(name),   // 父类成员，调用自己的构造完成初始化
//		_num(num)
//	{
//		cout << "Student()" << endl;
//	}
//protected:
//	int _num;
//};
//
//int main()
//{
//	Student s("yangtong", 811);
//
//	return 0;
//}

//class A
//{
//private:   
//	A() {}   // 将A的构造函数私有化
//};
//
//class B : public A
//{
//};
//
//int main()
//{
//	B b;   //?
//	return 0;
//}

//
//class A 
//{
//public:
//    static A CreateObject()//提供一个获取对象的方式
//    {
//        return A();
//    }
//private:
//    A()
//    {
//        cout << "A()" << endl;
//    }
//};
//
//class B : public A {};
//
//int main()
//{
//    A a = A::CreateObject();
//
//    return 0;
//}

//class Person
//{
//public:
//	/* 父类构造函数 */
//	Person(const char* name = "lirendada")
//		:_name(name)
//	{
//		cout << "Person()" << endl;
//	}
//
//	/* 父类拷贝构造函数 */
//	Person(const Person& p)
//		:_name(p._name)
//	{
//		cout << "Constructor Person()" << endl;
//	}
//protected:
//	string _name;
//};
//
//class Student : public Person
//{
//public:
//	/* 子类构造函数 */
//	Student(const char* name, int num)
//		:Person(name)   // 父类成员，调用父类的构造函数完成初始化
//		,_num(num)
//	{
//		cout << "Student()" << endl;
//	}
//
//	/* 子类拷贝构造函数 */
//	Student(const Student& s)
//		:Person(s)
//		, _num(s._num)
//	{
//		cout << "Constructor Student()" << endl;
//	}
//
//protected:
//	int _num;
//};
//
//int main()
//{
//	Student s("yangtong", 811);
//
//	Student s1(s);
//
//	return 0;
//}


//class Person
//{
//public:
//	/* 父类构造函数 */
//	Person(const char* name = "lirendada")
//		:_name(name)
//	{
//		cout << "Person()" << endl;
//	}
//
//	/* 父类拷贝赋值运算符重载 */
//	Person operator=(const Person& p)
//	{
//		cout << "Person& operator=(const Person& p)" << endl;
//		if (this != &p)
//		{
//			_name = p._name;
//		}
//		return *this;
//	}
//
//protected:
//	string _name;
//};
//
//class Student : public Person
//{
//public:
//	/* 子类构造函数 */
//	Student(const char* name, int num)
//		:Person(name)   // 父类成员，调用父类的构造函数完成初始化
//		, _num(num)
//	{
//		cout << "Student()" << endl;
//	}
//
//	/* 子类拷贝赋值运算符重载 */
//	Student operator=(const Student& s)
//	{
//		cout << "Student& operator=(const Student& s)" << endl;
//		if (this != &s)
//		{
//			// 小心这里是隐藏
//			Person::operator=(s);
//			_num = s._num;
//		}
//		return *this;
//	}
//
//protected:
//	int _num;
//};
//
//int main()
//{
//	Student s("yangtong", 811);
//	Student s1("liren", 324);
//	
//	s = s1;
//
//	return 0;
//}


//class Person
//{
//public:
//	/* 父类构造函数 */
//	Person(const char* name = "lirendada")
//		:_name(name)
//	{
//		cout << "Person()" << endl;
//	}
//
//	/* 父类析构函数 */
//	~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//
//protected:
//	string _name;
//};
//
//class Student : public Person
//{
//public:
//	/* 子类构造函数 */
//	Student(const char* name, int num)
//		:Person(name)   // 父类成员，调用父类的构造函数完成初始化
//		, _num(num)
//	{
//		cout << "Student()" << endl;
//	}
//
//	/* 子类析构函数 */
//	~Student()
//	{
//		cout << "~Student()" << endl;
//	}
//
//protected:
//	int _num;
//};
//
//int main()
//{
//	Student s("yangtong", 811);
//
//	return 0;
//}

//class Person 
//{
//public:
//	string _name; // 姓名
//};
//
//class Student : virtual public Person 
//{
//protected:
//	int _num; //学号
//};
//
//class Teacher : virtual public Person 
//{
//protected:
//	int _id; // 职工编号
//};
//
//class Assistant : public Student, public Teacher 
//{
//protected:
//	string _majorCourse; // 主修课程
//};
//
//int main()
//{
//	// 这样会有二义性无法明确知道访问的是哪一个
//	Assistant a;
//	//a._name = "peter";  ?
//
//	// 需要显示指定访问哪个父类的成员可以解决二义性问题，但是数据冗余问题无法解决
//	a.Student::_name = "xxx";
//	a.Teacher::_name = "yyy";
//
//	return 0;
//}

class A 
{
public:
	int _a;
};

class B : public A
//class B : virtual public A 
{
public:
	int _b;
};

class C : public A
//class C : virtual public A
{
public:
	int _c;
};

class D : public B, public C {
public:
	int _d;
};

int main()
{
	D d;
	d.B::_a = 1;
	d._b = 3;
	d.C::_a = 2;
	d._c = 4;
	d._d = 5;
	cout << sizeof(d);
	return 0;
}