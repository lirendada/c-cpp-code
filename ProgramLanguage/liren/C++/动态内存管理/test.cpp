#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class B
{
public:
	B(int b = 0) :_b(b) {}
	int _b;
};
class A
{
public:
	void print()
	{
		cout << a << endl;
		cout << b._b << endl;
		cout << p << endl;
	}
private:
	int a = 10;
	B b = 20;
	int* p = new int(4);
	static int n;
};
int A::n = 0;
int main()
{
	A a;
	a.print();
	return 0;
}