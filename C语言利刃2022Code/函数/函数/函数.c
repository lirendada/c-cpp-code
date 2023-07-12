#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<math.h>
//int main()
//{
//	char arr1[] = "yangtongshizhu";
//	char arr2[20] = "******************";
//	strcpy(arr2, arr1);          //拷贝函数strcpy
//	printf("%s\n", arr2);
//	return 0;
//}

#include<time.h>
#include<stdlib.h>
//void menu()
//{
//	printf("*****************************\n");
//	printf("****  1.play    2.exit   ****\n");
//	printf("*****************************\n");
//}
//void game()
//{
//	int a = 0;
//	int guess = 0;
//	srand((unsigned int)time(NULL));
//	a = rand() % 1000 + 1;
//	while (1)
//	{
//		printf("请输入你的数字:");
//		scanf("%d", &guess);
//		if (guess > a)
//			printf("大了\n");
//		else if (guess < a)
//			printf("小了\n");
//		else
//		{
//			printf("找到了!\n");
//			break;
//		}
//	}
//}
//
//int main()
//{
//	int choice = 0;
//	srand((unsigned int)time(NULL));
//	menu();
//	do
//	{
//		printf("请确认》：");
//		scanf("%d", &choice);
//		switch (choice)
//		{
//		case 1:
//			game();
//			break;
//		case 2:
//			printf("退出游戏\n");
//			break;
//		default:
//			printf("输入错误\n");
//			break;
//		}
//	} while (choice == 1);
//	return 0;
//}
//int main()
//{
//	char arr[] = "hello world";
//	memset(arr, '*', 6);
//	printf("%s\n", arr);
//	return 0;
//}
//void Swap(int* pa, int* pb)
//{
//	int tmp = 0;
//	tmp = *pa;
//	*pa = *pb;
//	*pb = tmp;
//}
//int main()
//{
//	int a, b;
//	scanf("%d %d", &a, &b);
//	printf("%d,%d\n",a,b);
//	Swap(&a, &b);
//	printf("%d,%d\n",a,b);
//	return 0;
//}
// void sushu(int x)
//{
//	int i = 0;
//	for (i = 2; i < x; i++)
//	{
//		if (x % i == 0)
//			break;
//	}
//	if (i == x)
//		printf("是素数");
//	else
//		printf("不是素数");
//}
// void sushu1()
// {
//	 int i = 0, j = 0;
//	 for (i = 2; i < 100; i++)
//	 {
//		 for (j = 2; j < i; j++)
//		 {
//			 if (i % j == 0)
//				 break;
//		 }
//		 if (i == j)
//			 printf("%2d ", i);
//	 }
// }
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	sushu(a);
//	sushu1();
//	return 0;
//}
//void find(int arr[], int k, int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//	while (left <= right)
//	{
//		int mid = (right + left) / 2;
//		if (arr[mid] > k)
//			right = mid - 1;
//		else if (arr[mid] < k)
//			left = mid + 1;
//		else
//		{
//			printf("找到了，下标为：%d\n", mid);
//			break;
//		}
//	}
//	if (left > right)
//		printf("找不到");
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int k = 0;
//	scanf("%d", &k);
//	find(arr, k,sz);
//	return 0;
//}

//void arr(int n)
//{
//	if (n > 0)
//	{
//		printf("%d ", n % 10);
//		arr(n / 10);
//	}
//}
//int main()
//{
//	unsigned int num = 0;
//	scanf("%d", &num);
//	arr(num);
//	return 0;
//}
//int stl(char* str)
//{
//	if (*str != '\0')
//		return 1 + stl(str + 1);
//	else
//		return 0;
//}
//int main()
//{
//	char arr[] = "lirendada";
//	int len = stl(arr);
//	printf("%d\n", len);
//	return 0;
//}
//int factorial(int n)
//{
//	if (n > 0)
//		return n * factorial(n - 1);
//	else
//		return 1;
//}
//int main()
//{
//	int n= 0,sum=0;
//	scanf("%d", &n);
//	sum = factorial(n);
//	printf("%d\n", sum);
//	return 0;
//}
//int count = 0;
//int fib(int n)
//{
//	if (n == 3)
//		count++;
//	if (n > 2)
//		return fib(n - 1) + fib(n - 2);
//	else
//		return 1;
//}
//int count = 1;
//void move(char a, char b)
//{
//	printf("第%d步：把%c移到%c\n", count++, a, b);
//}
//void hanoi(int n, char x, char y, char z)
//{
//	if (n == 1)
//	{
//		move(x, z);
//	}
//	else
//	{
//		hanoi(n - 1, x, z, y);
//		move(x, z);
//		hanoi(n - 1, y, x, z);
//	}
//}
//
//int main()
//{
//	int n = 0;
//	printf("请输入盘子数量：");
//	scanf("%d", &n);
//	hanoi(n, 'A', 'B', 'C');
//	return 0;
//}
//float add(int n)
//{
//	int i = 0;
//	float sum = 0;
//	float a = 1;
//	float b = 2;
//	float t = 0;
//	for (i = 1; i <= n; i++)
//	{
//		sum = sum + a / b;
//		t = b;
//		b = a + b;
//		a = t;
//	}
//	return sum;
//}
//int main()
//{
//	int n = 0;
//	float s1, s2, s3;
//	s1 = add(10);
//	s2 = add(15);
//	s3 = add(20);
//	printf("%6.2f %6.2f %6.2f", s1, s2, s3);
//	return 0;
//}
//int min;
//int find()
//{
//	int max, x, i;
//	x = rand() % 101 + 100;
//	printf("%d ", x);
//	max = x; min = x;
//	for (i = 1; i < 10; i++)
//	{
//		x = rand() % 101 + 100;
//		printf("%d ", x);
//		if (x > max)
//			max = x;
//		if (x < min)
//			min = x;
//	}
//	return max;
//}
//int main()
//{
//	int m = find();
//	printf("\n最大值：%d，最小值：%d\n", m, min);
//	return 0;
//}


//int twodiff(int m, int n)
//{
//	int count = 0, tmp = 0;
//	tmp = m ^ n;
//	while (tmp)
//	{
//		tmp = tmp & (tmp - 1);
//		count++;
//	}
//	return count;
//}
//int main()
//{
//	int m = 0, n = 0;
//	scanf("%d%d", &m, &n);
//	int count = twodiff(m, n);
//	printf("%d\n", count);
//	return 0;
//}

//void multable(int n)
//{
//	int i = 0, j = 0;
//	for (i = 1; i <= n; i++)
//	{
//		for (j = 1; j <= i; j++)
//			printf("%d*%d=%-2d ", i, j, i * j);
//		printf("\n");
//	}
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	multable(n);
//	return 0;
//}

//double Pow(int n, int k)
//{
//	if (k == 0)
//		return 1;
//	else if (k > 0)
//		return n * Pow(n, k-1);
//	else
//		return 1.0 /  Pow(n, -k);
//}
//int main()
//{
//	int n = 0, k = 0;
//	scanf("%d%d", &n, &k);
//	double sum = Pow(n, k);
//	printf("%d^%d=%lf\n", n, k, sum);
//	return 0;
//}
//#include<assert.h>
//char* strcpy_(char* dest, const char* src)
//{
//	assert(src != NULL);
//	assert(dest != NULL);
//	while (*dest++ = *src++)
//	{
//
//	}
//}
//int main()
//{
//	char a[] = "liren";
//	char b[] = "*******";
//	printf("%s\n", strcpy(b,a));
//	return 0;
//}

int main()
{
	int a ,b,ret=0;
	scanf("%d%d", &a, &b);
	while ((a%b)!=0)
	{
		ret = a % b;
		a = b;
		b = ret;
	}
	ret = a * b / ret;
	printf("%d\n", ret);
	return 0;
}