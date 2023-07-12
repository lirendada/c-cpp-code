#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void bubble_sort(int arr[],int sz)
{
	int i = 0, j = 0;
	for(i = 0; i < sz-1; i++)
	{
		int flag = 1;
		for (j = 0; j < sz - i-1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int t = 0;
				t=arr[j+1];
				arr[j + 1] = arr[j];
				arr[j] = t;
				flag = 0;
			}
		}
		if (flag == 1)
			break;
	}
}
int main()
{
	int i = 0;
	int arr[] = {123,54,652,13,14,59,51,63,8,5};
	int sz = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr,sz);
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}