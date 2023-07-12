#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//输出X型图形
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			if (i == j || i + j == n - 1)
//				printf("*");
//			else
//				printf(" ");
//		}
//		printf("\n");
//	}
//	return 0;
//}


//输入七个成绩，去掉最小值和最大值后算平均分，按两位小数点输出
//int main()
//{
//	int score = 0;
//	int max = 0;
//	int min = 100;
//	int sum = 0;
//	for (int i = 0; i < 7; i++)
//	{
//		scanf("%d", &score);
//		sum += score;
//		if (score > max)
//			max = score;
//		else if (score < min)
//			min = score;
//	}
//	printf("sum=%.2f\n", (sum - max - min) / 5.0);
//	return 0;
//}


//输入年和月，输出该月的天数
//int main()
//{
//	int y = 0;
//	int m = 0;
//	int days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//	while (scanf("%d %d", &y, &m)!=EOF)
//	{
//		int day = days[m];
//		if (m == 2)
//			if (y % 400 == 0 || y % 4 == 0 && y % 100 != 0)
//				day++;
//		printf("%d\n", day);
//	}
//	return 0;
//}


//有序序列插入一个数
int main()
{
	int arr[51] = { 0 };
	int n = 0;
	int i = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	int s = 0;
	scanf("%d", &s);
	for (i = n - 1; i > 0; i--)
	{
		if (arr[i] > s)
		{
			arr[i + 1] = arr[i];
		}
		else
			break;
	}
	arr[i + 1] = s;
	for (i = 0; i < n+1; i++)
		printf("%d ", arr[i]);
	return 0;
}