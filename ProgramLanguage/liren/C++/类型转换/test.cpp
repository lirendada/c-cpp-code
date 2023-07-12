#include <iostream>
using namespace std;

//int main()
//{
//	int i = 1;
//	// 隐式类型转换
//	double d = i;
//	printf("%d, %.2f\n", i, d);
//
//	int* p = &i;
//	// 显示的强制类型转换
//	int address = (int)p;
//	printf("%x, %d\n", p, address);
//
//	return 0;
//}

//int main()
//{
//	double a = 3.14;
//	int b = reinterpret_cast<int>(a); // ❌相关类型无法有效转换
//
//	int* ptr = &b;
//	int c = reinterpret_cast<int>(ptr); // 将指针类型转化为int类型是可以的
//	cout << c << endl;
//	return 0;
//}

//int main()
//{
//	volatile const int a = 1;
//	int* p = const_cast<int*>(&a);
//	*p = 3;
//	cout << a << endl;
//	cout << *p << endl;
//	return 0;
//}

class Parent
{
public:
	virtual void Print()
	{
		cout << "this is Parent!" << endl;
	}
};

class Child : public Parent
{
public:
	virtual void Print()
	{
		cout << "this is Child!" << endl;
	}
};

void Func(Parent* ptr)
{
	// static_cast不做检查，如果发生了数据越界则很危险，不推荐使用
	Child* pb1 = static_cast<Child*>(ptr);
	pb1->Print();

	// dynamic_cast会先检查是否能转换成功，能成功则转换，不能则返回nullptr
	// 父转子会导致不安全，所以dynamic_cast会直接转换失败，所以下面可以有一个判空
	Child* pb2 = dynamic_cast<Child*>(ptr);
	if (pb2 != nullptr)
		pb2->Print();
	else
		cout << "pb2 is nullptr" << endl;
}

int main()
{
	Parent p;
	Child c;
	Func(&p);
	Func(&c);
	return 0;
}