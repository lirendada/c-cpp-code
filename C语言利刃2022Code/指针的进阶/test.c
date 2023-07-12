#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//void test(int arr[])
//{
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	printf("%d\n", sz);
//}
//int main()
//{
//	int arr[10] = { 0 };
//	test(arr);
//	return 0;
//}

//int main()
//{
//	const char* p = "lirendada";
//	//printf("%c\n", *p);
//	//printf("%s\n", p);
//	*p = 'w';
//	printf("%s\n", p);
//	return 0;
//}

//int main()
//{
//	int a[5] = { 1,2,3,4,5 };
//	int b[5] = { 6,4,8,3,1 };
//	int c[5] = { 2,5,8,6,1 };
//	int* arr[] = { a,b,c };
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 5; j++)
//		{
//			printf("%d ", *(arr[i]+j));
//		}
//		printf("\n");
//	}
//	return 0;
//}


//int main()
//{
//	char a[10], * p;
//	scanf("%s", a);
//	p = a;
//	while (*p)
//	{
//		putchar(*p++);
//	}
//	putchar(10);
//	return 0;
//}


//int main()
//{
//	int i, a[10], * p;
//	p = a;
//	for (i = 0; i < 10; i++)
//	{
//		scanf("%d,", p++);
//	}
//	p = a;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", *p++);
//	}
//	return 0;
//}


//void swap(int* pa, int* pb)
//{
//	int i = 0;
//	i = *pa;
//	*pa = *pb;
//	*pb = i;
//}
//int main()
//{
//	int a, b;
//	scanf("%d,%d", &a, &b);
//	int* pa = &a; int* pb = &b;
//	printf("%交换前：%d %d\n", a, b);
//	swap(pa, pb);
//	printf("%交换后：%d %d", a, b);
//	return 0;
//}

//int main()
//{
//	int a = 5;
//	int* p = &a;
//	int** pa = &p;
//	printf("%d\n", **pa);
//	return 0;
//}

//int main()
//{
//	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int* p = a;
//	printf("%d,%d,%d,%d\n", a[1], *(a + 1), *(p + 1), p[1]);
//	return 0;
//}

//int main()
//{
//	int a[3][4] = { {1,2,3,4} ,{5,6,7,8} ,{9,10,11,12} };
//	int(*pa)[4] = &a;
//	printf("%d\n", sizeof(*(pa + 1)));
//	printf("%p\n", pa);
//	printf("%p\n", pa+1);
//	printf("%p\n", *pa);
//	printf("%p\n", *(pa)+1);
//	printf("%d\n", *( * (pa)));
//	printf("%d\n", *(* (pa)+1));
//	return 0;
//}

//int main()
//{
//	int i = 0;
//	int a[3][4] = { {1,2,3,4} ,{5,6,7,8} ,{9,10,11,12} };
//	int* pa[3];
//	for (i = 0; i < 3; i++)
//		pa[i] = a[i];
//	for (i = 0; i < 3; i++)
//	{
//		int j;
//		for (j = 0; j < 4; j++)
//			printf("%d ", *(*(pa + i) + j));
//		printf("\n");
//	}
//	printf("%d,%d\n", a[1][1], *(pa[1] + 1));
//	printf("%d,%d\n", a[1][1], *(*(pa+1) + 1));
//	printf("%d,%d\n", a[1][1], (*(pa + 1))[1]);
//	printf("%d,%d\n", a[1][1], pa[1][1]);
//	return 0;
//}


//int main()
//{
//	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int arr2[] = { 10,9,8,7,6,5,4,3,2,1 };
//	int* p[] = { arr1,arr2 };
//	for (int i = 0; i < 2; i++)
//	{
//		for(int j=0;j<10;j++)
//			printf("%d ", *(*(p + i) + j));
//		printf("\n");
//	}
//
//	return 0;
//}

//void print(int (*p)[5],int r,int c)
//{
//	for (int i = 0; i < r; i++)
//	{
//		for (int j = 0; j < c; j++)
//			printf("%-2d ",*(* (p + i) + j));
//		printf("\n");
//	}
//}
//int main()
//{
//	int arr[3][5] = { {1,2,3,4,5} ,{6,7,8,9,10} ,{11,12,13,14,15} };
//	print(arr, 3, 5);
//	return 0;
//}

//int i;//i是全局变量，不初始化时候，默认为0
//int main()
//{
//	i--;//i=-1
//
//	//sizeof这个操作符，算出的结果的类型是unsigned int
//	if (i > sizeof(i))
//		printf("大于\n");
//	else
//		printf("小于\n");
//	return 0;
//}
// 
//#include<math.h>
//int main()
//{
//	int n = 0, a = 0;
//	printf("请输入n项，还有a的值：");
//	scanf("%d%d", &n, &a);
//	int sum = 0;
//	int ret = 0;
//	for (int i = 0; i < n; i++)
//	{
//		ret = ret * 10 + a;
//		sum += ret;
//	}
//	printf("%d\n", sum);
//	return 0;
//}

//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int* p = arr;
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", *(p + i));
//		printf("%d ", p[i]);
//	}
//	return 0;
//}


//int main()
//{
//	int a = 0, b = 0, c = 0, d = 0, e = 0;
//	for (a = 1; a <= 5; a++)
//	{
//		for (b = 1; b <= 5; b++)
//		{
//			for (c = 1; c <= 5; c++)
//			{
//				for (d = 1; d <= 5; d++)
//				{
//					for (e = 1; e <= 5; e++)
//					{
//						if (((b == 2) + (a == 3) == 1) + ((b == 2) + (e == 4) == 1) + ((c == 1) + (d == 2) == 1) + ((c == 5) + (d == 3) == 1) + ((e == 4) + (a == 1) == 1) == 5)
//						{
//							if (a * b * c * d * e == 120)
//								printf("a=%d,b=%d,c=%d,d=%d,e=%d\n", a, b, c, d, e);
//						}
//					}
//				}
//			}
//		}
//	}
//	return 0;
//}

//int add(int x,int y)
//{
//	return x + y;
//}
//int main()
//{
//	int (*pf)(int, int) = add;
//	int ret = pf(2, 2);
//	printf("%d\n", ret);
//	printf("%p\n", add);
//	printf("%p\n", pf);
//	printf("%p\n", &add);
//	return 0;
//}


//int main()
//{
//	typedef void(*pfun_t)(int) ;
//	void (*signal(int, void(*)(int)))(int);
//	pfun_t signal(int, void(*)(int));
//	return 0;
//}

//int add(int x,int y)
//{
//	return x + y;
//}
//int sub(int x, int y)
//{
//	return x - y;
//}
//int main()
//{
//	int (*p1)(int, int) = add;
//	int (*p2)(int, int) = sub;
//	int (*pfarr[2])(int, int) = {add,sub };
//	int (*(*pfarrp)[2])(int, int) = &pfarr;
//	return 0;
//}

//#include<string.h>
//#include<stdlib.h>
//int sort_int(const void* e1, const void* e2)
//{
//	return *(int*)e1 - *(int*)e2;
//}
//int sort_float(const void* e1, const void* e2)
//{
//	return *(float*)e1 - *(float*)e2;
//}
//struct Stu
//{
//	char name[20];
//	int age;
//};
//int sort_by_age(const void* e1, const void* e2)
//{
//	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
//}
//int sort_by_name(const void* e1, const void* e2)
//{
//	return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);
//}
//void test2()//打印浮点型数据排序
//{
//	float arr1[] = { 1.3,-126.5,56.1,123.2 };
//	int sz1 = sizeof(arr1) / sizeof(arr1[0]);
//	qsort(arr1, sz1, sizeof(arr1[0]), sort_float);
//	for (int i = 0; i < sz1; i++)
//	{
//		printf("%2.1f ", arr1[i]);
//	}
//}
//void test1()//打印整型数据排序
//{
//	int arr[] = { 1,62,4,6,11,3,45,8,3 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	qsort(arr, sz, sizeof(arr[0]), sort_int);
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%2d ", arr[i]);
//	}
//}
//void test3()//排序结构体
//{
//	struct Stu s[] = { {"张三",11}, {"李四",19} ,{"王五",25} };
//	int sz = sizeof(s) / sizeof(s[0]);
//	qsort(s, sz, sizeof(s[0]), sort_by_age);//按年龄排
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%s,%d ",(s+i)->name, (s+i)->age);
//	}
//	printf("\n");
//	qsort(s, sz, sizeof(s[0]), sort_by_name);//按名字排
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%s,%d ", (s + i)->name, (s + i)->age);
//	}
//}
//int main()
//{
//	test1();
//	printf("\n");
//	test2();
//	printf("\n");
//	test3();
//	return 0;
//}

//int main()
//{
//	int a[5][5];
//	int(*p)[4];
//	p = a;
//	printf("%p   %d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);
//	return 0;
//}



//int find_num(int arr[3][3], int* px, int* py, int n)
//{
//	int x = 0;
//	int y = *py - 1;
//	while (x < *px && y >= 0)
//	{
//		if (n > arr[x][y])
//			x++;
//		else if (n < arr[x][y])
//			y--;
//		else
//		{
//			*px = x;
//			*py = y;
//			return 1;
//		}
//	}
//	return 0;
//}
//int main()
//{
//	int arr[3][3] = { 1,3,5,4,6,7,6,8,9 };
//	int n = 0;
//	int x = 3, y = 3;
//	scanf("%d", &n);
//	int ret=find_num(arr, &x,&y , n);
//	if (ret == 1)
//		printf("找到了，下标为：(%d,%d)\n", x, y);
//	else
//		printf("查无\n");
//	return 0;
//}

void left_rotation(char* arr, int n,int sz)
{
	for (int i = 0; i < n; i++)
	{
		char tmp = *arr;
		for (int j = 0; j < sz - 1; j++)
		{
			*(arr + j) = *(arr + j + 1);
		}
		*(arr + sz - 1) = tmp;
	}
}
int main()
{
	char arr[] = "ABCDEF";
	int n = 0;
	int sz = strlen(arr);
	scanf("%d", &n);
	left_rotation(arr, n,sz);
	printf("%s\n", arr);
	return 0;
}