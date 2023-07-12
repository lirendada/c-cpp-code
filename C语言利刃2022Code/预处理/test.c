#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//int main()
//{
//	printf("%s\n", __FILE__);
//	printf("%d\n", __LINE__);
//	printf("%s\n", __DATE__);
//	printf("%s\n", __TIME__);
//	printf("%s\n", __FUNCTION__);
//	return 0;
//}

//#define square(x) x*x
//int main()
//{
//	printf("%d\n", square(3));
//	return 0;
//}


//#define print(x,format) printf("the value of "#x"is "format"\n",x);
//int main()
//{
//	int a = 1,b=2,c=3;
//	float f = 2.50f;
//	print(a,"%d");
//	print(b, "%d");
//	print(c,"%d");
//	print(f, "%f");
//	return 0;
//}


//#define MALLOC(num,type) (type*)malloc(num*sizeof(type))
//int main()
//{
//	int* p = MALLOC(10, int);
//	return 0;
//}


//#define liren
//int main()
//{
//#ifdef liren
//	printf("lirendada\n");
//#endif
//	return 0;
//}


int main()
{
#if i==1
	printf("liren");
#elif i==2
	printf("tongtong");
#else i==3
	printf("love");
#endif
	return 0;
}