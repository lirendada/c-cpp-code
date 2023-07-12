#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void find(int k,int sz,int arr[])
{
	int left = 0;
	int right = sz - 1;
	while (left <= right)
	{
		int mid = (right + left) / 2;
		if (arr[mid] < k)
			left = mid + 1;
		else if (arr[mid] > k)
			right = mid - 1;
		else
		{
			printf("找到了，下标为：%d\n", mid);
			break;
		}
	}
	if (left > right)
		printf("找不到\n");
}
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int k = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);
	printf("请输入想查找的数字：");
	scanf("%d", &k);
	find(k,sz,arr);
	return 0;
}
