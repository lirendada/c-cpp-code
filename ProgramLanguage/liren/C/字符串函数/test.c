#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>

//         strlen函数
size_t my_strlen(const char* str)
{
	assert(str);
	size_t count = 0;
	while (*str != '\0')
	{
		++count;
		++str;
	}
	return count;
}

//        strcpy函数
char* my_strcpy(char* dst, const char* str)
{
	assert(dst && str);
	char* tmp = dst;
	while (*dst++ = *str++);
	return tmp;
}

//        strcat函数
char* my_strcat(char* dst, const char* str)
{
	assert(dst && str);
	char* tmp = dst;

	while (*dst++ != '\0');
	while (*dst++ = *str++);

	return tmp;
}

//          strcmp函数
int my_strcmp(const char* str1, const char* str2)
{
	assert(str1 && str2);
	while (*str1++ == *str2++)
	{
		if (*str1 == '\0')
			return 0;
	}
	return (*str1 - *str2);
}

//          strstr函数(KMP算法)
void GetNext(const char* s, int* next, size_t n)
{
	next[0] = -1;
	next[1] = 0;

	size_t i = 1;
	int k = 0;
	while (i < n - 1)
	{
		if (k == -1 || s[i] == s[k])
		{
			next[i + 1] = k + 1;
			++i;
			++k;
		}
		else
		{
			k = next[k];
		}
	}
}
char* my_strstr(char* s1, const char* s2)
{
	assert(s1 && s2);
	
	int n1 = my_strlen(s1);
	int n2 = my_strlen(s2);

	int* next = (int*)malloc(sizeof(int) * n2);
	assert(next != NULL);

	GetNext(s2, next, n2);

	int i = 0;//控制主串
	int j = 0;//控制子串
	while (i < n1 && j < n2)
	{
		if (j == -1 || s1[i] == s2[j])
		{
			++i;
			++j;
		}
		else
		{
			j = next[j];
		}
	}
	if (j >= n2)
		return s1 + (i - j);
	return NULL;
}

//         memcpy函数
void* my_memcpy(void* dst, const void* src, size_t n)
{
	assert(dst && src);
	void* tmp = dst;

	while (n--)
	{
		*(char*)dst = *(char*)src;
		dst = (char*)dst + 1;
		src = (char*)src + 1;
	}

	return tmp;
}

//        memmove函数
void* my_memmove(void* dst, const void* src, size_t n)
{
	assert(dst && src);
	void* tmp = dst;

	if (dst < src)
	{
		while (n--)
		{
			*(char*)dst = *(char*)src;
			dst = (char*)dst + 1;
			src = (char*)src + 1;
		}
	}
	else
	{
		while (n--)
		{
			*((char*)dst + n) = *((char*)src + n);
		}
	}

	return tmp;
}

int main()
{
	char* s1 = "liendadasb pmas love tt";
	char* s2 = "dasc";
	printf("%s\n", my_strstr(s1, s2));
	return 0;
}