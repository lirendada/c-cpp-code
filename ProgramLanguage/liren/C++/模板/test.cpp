#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;

//#define X 1000

//template<class T, size_t X>
//class Srray
//{
//public:
//	void Change()
//	{
//		X = 10;
//	}
//private:
//	T _arr[X];
//};
//
////template<string S>
////class A
////{
////	//类内成员定义
////};
////
////template<double D>
////class B
////{
////	//类内成员定义
////};
//
//int main()
//{
//	Srray<int, 100> a1;	 //开辟了100个空间大的静态数组
//	Srray<int, 1000> a2;  //开辟了1000个空间大的静态数组
//
//	//a1.Change();
//
//	return 0;
//}

//#include<cstring>
//
//template<class T>
//bool IsSame(const T& a, const T& b)
//{
//	return a == b;
//}
//
////给存放字符数组的特化
//bool IsSame(char* a, char* b)
//{
//	return strcmp(a, b) == 0;
//}
//
////给字符串常量的特化
//bool IsSame(const char* a, const char* b)
//{
//	return strcmp(a, b) == 0;
//}
//
//template<>
//bool IsSame<const char*>(const char* const& a, const char* const& b)
//{
//	return strcmp(a, b) == 0;
//}
//
//
//int main()
//{
//	//对于一般的类型对比，没有问题
//	cout << IsSame(1, 2) << endl;
//	cout << IsSame(1.1, 2.2) << endl;
//
//	char s1[] = "liren";
//	char s2[] = "liren";
//	cout << IsSame(s1, s2) << endl;
//
//	const char* s3 = "lirendada";
//	const char* s4 = "lirendada";
//	cout << IsSame(s3, s4) << endl;
//
//	return 0;
//}


//template<class T1, class T2>
//class Data
//{
//public:
//	Data() { cout << "Data<T1, T2>" << endl; }
//private:
//	T1 _d1;
//	T2 _d2;
//};
//// 将第二个参数特化为int
//template <class T1>
//class Data<T1, int>
//{
//public:
//	Data() { cout << "Data<T1, int>" << endl; }
//private:
//	T1 _d1;
//	int _d2;
//};
////两个参数偏特化为指针类型
//template <typename T1, typename T2>
//class Data <T1*, T2*>
//{
//public:
//    Data() { cout << "Data<T1*, T2*>" << endl; }
//private:
//    T1 _d1;
//    T2 _d2;
//};
//
////两个参数偏特化为引用类型
//template <typename T1, typename T2>
//class Data <T1&, T2&>
//{
//public:
//    Data(const T1& d1, const T2& d2)
//        : _d1(d1)
//        , _d2(d2)
//    {
//        cout << "Data<T1&, T2&>" << endl;
//    }
//private:
//    const T1& _d1;
//    const T2& _d2;
//};
//
//void test2()
//{
//    Data<double, int> d1; // 调用特化的int版本
//    Data<int, double> d2; // 调用基础的模板 
//    Data<int*, int*> d3; // 调用特化的指针版本
//    Data<int&, int&> d4(1, 2); // 调用特化的指针版本
//}
//
//int main()
//{
//    test2();
//    return 0;
//}

