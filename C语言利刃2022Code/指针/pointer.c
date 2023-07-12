#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//int main()
//{
//	int a = 0x11223344;
//	char* pa = &a;
//	*pa = 0;
//	return 0;
//}

//                            计算字符串长度
//int mystrlen(char* str)
//{
//	char* start = str;
//	char* end = str;
//	while (*end != '\0')
//		end++;
//	return end - start;
//}
//int main()
//{
//	char arr[] = "liren";
//	int len = mystrlen(arr);
//	printf("%d\n", len);
//	return 0;
//}


//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int* pa = arr;
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", *(pa + i));
//	}
//	return 0;
//}

//void reverse(char arr[],int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz / 2; i++)
//	{
//		int tmp = 0;
//		tmp = arr[i];
//		arr[i] = arr[sz - 1-i];
//		arr[sz - 1-i] = tmp;
//	}
//}
//int main()
//{
//	char arr[] = "lirendada";
//	int len = sizeof(arr) / sizeof(arr[0]) - 1;
//	reverse(arr,len);
//	for (int i = 0; i < len; i++)
//	{
//		printf("%c", arr[i]);
//	}
//	return 0;
//}


//int* statistics(int l, char ch[])//l为数组ch的长度
//{
//	int i, a[4] = { 0 };
//	for (i = 0; i < l; i++)
//	{
//		if ((ch[i] > 64 && ch[i] < 91) || (ch[i] > 96 && ch[i] < 123))
//			a[0]++;
//		else if (ch[i] > 47 && ch[i] < 58)
//			a[1]++;
//		else if (ch[i] == ' ')
//			a[2]++;
//		else if (ch[i] != 0)
//			a[3]++;
//	}
//	return (a);
//}
//int main()
//{
//	int* p;//a[0]代表letter,a[1]代表num,a[2]代表space,a[3]代表other character
//	char ch[100] = { 0 };
//	printf("请输入一个字符串\n");
//	gets(ch);
//	p = statistics(100, ch);
//	printf("该字符串的\nletter=%d\nnum=%d\nspace=%d\nother character=%d\n", p[0], p[1], p[2], p[3]);
//	return 0;
//}

int main()
{
	int arr[3] = { 1,2,3 };
	printf("%p\n", arr);
	printf("%p\n", arr+1);
	printf("%p\n", &arr);
	printf("%p\n", &arr+1);
	return 0;
}