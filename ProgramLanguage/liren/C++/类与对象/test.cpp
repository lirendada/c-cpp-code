#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//void add(int a, int b = 1)
//{
//	cout << a << endl << b << endl;
//}
//int main()
//{
//	add(1);
//	add(1, 2);
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	int& b = a;
//	const int& c = 10;
//	const int& d = b;
//
//	double j = 1;
//	const double& k = a;
//	const int& l = j;
//	return 0;
//}

//int main()
//{
//	int x = 10;
//	auto y1 = x;
//	auto y2 = &x;
//	auto* x1 = &x;
//	auto& x2 = x;
//	cout << typeid(x).name() << endl;
//	cout << typeid(x1).name() << endl;
//	cout << typeid(x2).name() << endl;
//	cout << typeid(y1).name() << endl;
//	cout << typeid(y2).name() << endl;
//	return 0;
//}

//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9 };
//	for (auto i : arr)
//		cout << i << endl;
//	return 0;
//}


//class A
//{
//public:
//	void print() { cout << _a << endl; }
//	~A() { cout << "noa" << endl; }
//private:
//	int _a;
//};
//
//class Date
//{
//public:
//	Date(int year = 0, int month = 1, int day = 1) :_year(year), _month(month), _day(day) {}
//
//	Date(const Date& d) :_year(d._year), _month(d._month), _day(d._day) {}
//
//	//Date& operator=(const Date& d)
//	//{
//	//	if (this != &d)//防止自己给自己赋值时候又得做以下步骤，省略时间
//	//	{
//	//		_year = d._year;
//	//		_month = d._month;
//	//		_day = d._day;
//	//	}
//	//	return *this;
//	//}
//
//	void Print() { cout << _year << " " << _month << " " << _day << endl;/* _aa.print();*/ }
//private:
//	int _year, _month, _day;
//	/*A _aa;*/
//};
//
//class Stack
//{
//public:
//	Stack(int capacity = 4)
//	{
//		if (capacity <= 0)
//		{
//			_a = nullptr;
//			_size = _capacity = 0;
//		}
//		else
//		{
//			_a = (int*)malloc(sizeof(int) * capacity);
//			_size = 0;
//			_capacity = capacity;
//		}
//	}
//	~Stack()
//	{
//		free(_a);
//		_a = nullptr;
//		_size = _capacity = 0;
//	}
//private:
//	int* _a;
//	int _capacity;
//	int _size;
//};
//
//int main()
//{
//	Date d1;
//	d1.Print();
//
//	Date d2(2022, 5, 9);
//	d2.Print();
//
//	Date d3;
//	d3.Print();
//
//	d3 = d2;
//	d3.Print();
//
//	d2 = d3 = d1;
//	d1.Print();
//	d2.Print();
//	d3.Print();
//
//	/*Stack s1;*/
//	return 0;
//}



int main() {
    int totalday = 1;
    int year = 0, month = 0, day = 0;
    int arr[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
    cin >> year >> month >> day;
    int firstday = 1, firstmonth = 1;
    if ((month > 2) && (year % 4 == 0 && year % 100 != 0) | year % 4 == 0)
    {
        arr[2] = 29;
        while ((month != firstmonth) || (day != firstday))
        {
            if (firstday == arr[firstmonth])
            {
                firstday = 1;
                firstmonth++;
                if (firstmonth == month && day == firstday)
                    break;
            }
            else
                firstday++;
            totalday++;
        }
    }
    else
    {
        while ((month != firstmonth) || (day != firstday))
        {
            if (firstday == arr[firstmonth])
            {
                firstday = 1;
                firstmonth++;
            }
            else
                firstday++;
            totalday++;
        }
    }
    cout << totalday << endl;
    return 0;
}