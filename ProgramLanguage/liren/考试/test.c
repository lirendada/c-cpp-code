#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	int n = 0;
	scanf_s("%d\n", &n);

	char* arr[1000];
	for (int i = 0; i < n; ++i)
	{
		arr[i] = (char*)malloc(sizeof(char) * 100);
		gets(arr[i]);
	}

	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = 0; j < n - 1 - i; ++j)
		{
			if (strcmp(arr[j], arr[j + 1]) > 1)
			{
				char* tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		puts(arr[i]);
	}
	return 0;
}