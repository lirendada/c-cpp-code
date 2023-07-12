#define  _CRT_SECURE_NO_WARNINGS
// #include "ObjectPool.h"
//#include "FixedLenMemPool.hpp"
//
//struct S
//{
//	char a : 3;
//	char b : 4;
//	char c : 5;
//	char d : 4;
//};
//
//int main()
//{
//	S s{ 0 };
//	s.a = 10;
//	s.b = 12;
//	s.c = 3;
//	s.d = 4;
//	cout << sizeof s << endl;
//	cout << &s << endl;
//	// TestObjectPool();
//	return 0;
//}


#include <stdio.h>
#define MIN 10
int main()
{
#if !defined(MAX)
#ifdef MIN
	printf("hello\n");
#else
	printf("world\n");
#endif
#endif
	return 0;
}
