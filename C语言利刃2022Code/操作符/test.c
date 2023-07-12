#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//                不创建第三变量进行变量的值交换（运用按位异或^）
//int main()
//{
//	int x, y;
//	scanf("%d%d", &x, &y);
//	printf("改变前：x=%d,y=%d\n", x, y);
//	x = x ^ y;
//	y = x ^ y;
//	x = x ^ y;
//	printf("改变后：x=%d,y=%d\n", x, y);
//	return 0;
//}

//                   求一个整数存储在内存中的二进制的1的个数(多种方法，第一种最精简)
//int onecount(int n)
//{
//	int count = 0;
//	while (n)
//	{
//		n = n & (n - 1);
//		count++;
//	}
//	return count;
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	n = onecount(n);
//	printf("个数为：%d\n", n);
//}



//int main()
//{
//	int n = 0,sum=0;
//	scanf("%d", &n);
//	for (int i = 0; i < 32; i++)
//	{
//		if (1 == ((n >> i) & 1))
//			sum++;
//	}
//	printf("个数：%d\n", sum);
//	return 0;
//}



//int onecount(unsigned int n)
//{
//	int count = 0;
//	while (n)
//	{
//		if (n % 2 == 1)
//			count++;
//		n = n / 2;
//	}
//	return count;
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	n = onecount(n);
//	printf("个数为：%d\n", n);
//	return 0;
//}