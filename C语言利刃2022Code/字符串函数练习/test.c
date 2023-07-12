#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<assert.h>

//int mystrlen(const char* str)
//{
//	assert(str);
//	int sz = 0;
//	while (*str++ != '\0')
//		sz++;
//	return sz;
//}
//int main()
//{
//	char arr[] = "lirendada";
//	int sz = mystrlen(arr);
//	printf("%d\n", sz);
//	return 0;
//}


//char* mystrcat(char* dest, const char* src)
//{
//	assert(dest&&src);
//	char* ret = dest;
//	while (*dest != '\0')
//	{
//		dest++;
//	}
//	while (*dest++ = *src++);
//	return ret;
//}
//int main()
//{
//	char arr[30] = "liren ";
//	char arr2[] = "love yangtong!";
//	printf("%s\n", mystrcat(arr, arr2));
//	return 0;
//}


//int mystrcmp(const char* arr, const char* arr1)
//{
//	assert(arr && arr1);
//	while (*arr == *arr1)
//	{
//		if (*arr == 0)
//		{
//			return 0;
//		}
//		arr++;
//		arr1++;
//	}
//	/*if (*arr > *arr1)
//		return 1;
//	else
//		return -1;*/
//	return *arr - *arr1;
//}

//char* mystrncpy(char* dest, const char* src, size_t n)
//{
//	assert(dest && src);
//	char *ret= dest;
//	for (int i = 0; i < n; i++)
//	{
//		if (*dest == '\0'||*src=='\0')
//			break;
//		*dest++ = *src++;
//	}
//	return ret;
//}
//int main()
//{
//	char arr[] = "lirendadada";
//	char arr1[] = "yangtong";
//	printf("%s\n", mystrncpy(arr, arr1, 10));
//	return 0;
//}


//char* mystrstr(const char* arr1, const char* arr2)
//{
//	assert(arr1 && arr2);
//	const char* s1 = NULL;
//	const char* s2 = NULL;
//	const char* cp = arr1;
//	if (*arr2 == '\0')
//	{
//		return (char*)arr1;
//	}
//	while (*cp)
//	{
//		s1 = cp;
//		s2 = arr2;
//		while (*s1 && *s2 && *s1 == *s2)
//		{
//			s1++;
//			s2++;
//		}
//		if (*s2 == '\0')
//		{
//			return cp;
//		}
//		cp++;
//	}
//	return NULL;
//}
//int main()
//{
//	char arr1[] = "abcdeeesda";
//	char arr2[] = "ees";
//	char* ret = mystrstr(arr1, arr2);
//	if (ret == NULL)
//	{
//		printf("找不到\n");
//	}
//	else
//	{
//		printf("找到了，%s\n", ret);
//	}
//	return 0;
//}


//int main()
//{
//	char arr[] = "chh@liren.boke haha";
//	char arr1[] = "@. ";
//	char tmp[30];
//	strcpy(tmp, arr);
//	char* ret = NULL;
//	for (ret = strtok(tmp, arr1); ret != NULL; ret = strtok(NULL, arr1))
//	{
//		printf("%s  ", ret);
//	}
//	return 0;
//}


//#include<errno.h>
//int main()
//{
//	/*printf("%s\n", strerror(0));
//	printf("%s\n", strerror(1));
//	printf("%s\n", strerror(2));
//	printf("%s\n", strerror(3));
//	printf("%s\n", strerror(4));*/
//
//	FILE* pf = fopen("text.txt", "r");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		perror("fopen");
//		return 1;
//	}
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}



//void* mymemcpy(void* dest, const void* src, size_t n)
//{
//	assert(dest && src);
//	void* ret = dest;
//	while (n--)
//	{
//		*(char*)dest = *(char*)src;
//		dest = (char*)dest + 1;
//		src = (char*)src + 1;
//	}
//	return ret;
//}

//void* mymemmove(void* dest, const void* src, size_t n)
//{
//	assert(dest && src);
//	void* ret = dest;
//	if (dest < src)
//	{
//		while (n--)
//		{
//			*(char*)dest = *(char*)src;
//			dest = (char*)dest + 1;
//			src = (char*)src + 1;
//		}
//	}
//	else
//	{
//		while (n--)
//		{
//			*((char*)dest+n) = *((char*)src + n);
//		}
//	}
//	return ret;
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int arr1[20] = { 0 };
//	/*mymemcpy(arr1, arr, 24);*/
//	mymemmove(arr + 3, arr, 20);
//	return 0;
//}


//int main()
//{
//	int arr[10] = { 0 };
//	memset(arr, 1, 20);
//	return 0;
//}


//int main()
//{
//	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int arr2[] = { 1,2,3,3 };
//	int ret=memcmp(arr1, arr2, 16);
//	printf("%d\n", ret);
//	return 0;
//}