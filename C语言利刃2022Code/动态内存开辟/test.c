#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//int main()
//{
//	int* p = (int*)malloc(1000 * sizeof(int));
//	if (p == NULL)
//	{
//		perror("main");
//		return 0;
//	}
//	for (int i = 0; i < 10; i++)
//	{
//		*(p + i) = i;
//	}
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d\t", *(p + i));
//	}
//	free(p);
//	p = NULL;
//	return 0;
//}


//int main()
//{
//	int* p = (int*)malloc(10 * sizeof(int));
//	int* ptr = realloc(p, 20 * sizeof(int));
//	*ptr = 1;
//	return 0;
//}


//int main()
//{
//	int* p =(int*) malloc(10 * sizeof(int));
//	if (p == NULL)
//	{
//		return 1;
//	}
//	for (int i = 0; i < 5; i++)
//	{
//		*p++ = i;
//	}
//	free(p);
//	p = NULL;
//	return 0;
//}


//#include<string.h>
//void GetMemory(char** p)
//{
//	*p = (char*)malloc(100);
//}
//void test(void)
//{
//	char* str = NULL;
//	GetMemory(&str);
//	strcpy(str, "lirendada");
//	printf(str);
//}
//int main()
//{
//	test();
//	return 0;
//}


//struct S
//{
//	int n;
//	int arr[0];
//};
//int main()
//{
//	struct S* p = (struct S*)malloc(sizeof(struct S) + 10 * sizeof(int));
//	p->n = 10;
//	for (int i = 0; i < 10; i++)
//	{
//		p->arr[i] = i;
//	}
//	/*printf("%d\n", sizeof(struct S));*/
//	return 0;
//}


//struct test
//{
//	char f : 1;
//	char  n : 4;
//	char s : 7;
//};
//int main()
//{
//	struct test t={0};
//	t.f = 1;
//	t.n = 2;
//	t.s = 8;
//	printf("%d\n", sizeof(t));
//	return 0;
//}


//struct sb
//{
//	int a;
//	int arr[0];
//};
//int main()
//{
//	struct sb* ps = (struct sb*)malloc(sizeof(struct sb) + 10 * sizeof(int));
//	ps->a = 1;
//	for (int i = 0; i < 10; i++)
//	{
//		ps->arr[i] = i;
//	}
//	struct sb* ptr = (struct sb*)realloc(ps, sizeof(struct sb) + 20 * sizeof(int));
//	if (ptr != NULL)
//		ps = ptr;
//	free(ps);
//	ps = NULL;
//	return 0;
//}


//struct s
//{
//	int a;
//	int* arr;
//};
//int main()
//{
//	struct s* ps = (struct s*)malloc(sizeof(struct s));
//	if (ps == NULL)
//		return;
//	ps->arr=(int *)malloc(10 * sizeof(int));
//	if (ps->arr == NULL)
//		return 1 ;
//	ps->a = 1;
//	for (int i = 0; i < 10; i++)
//	{
//		ps->arr[i] = i + 1;
// 	}
//	int *a=(int*)realloc(ps->arr, 20 * sizeof(int));
//	if (a != NULL)
//		ps->arr = a;
//	for (int i = 0; i < 20; i++)
//	{
//		ps->arr[i] = i + 1;
//	}
//	free(ps->arr);
//	ps->arr = NULL;
//	free(ps);
//	ps = NULL;
//	return 0;
//}


struct S
{
	int a;
	int arr[0];
};
int main()
{
	struct S* ps = (struct S*)malloc(sizeof(struct S)+10*sizeof(int));
	if (ps == NULL)
		return 1;
	ps->a = 8;
	for (int i = 0; i < 10; i++)
	{
		ps->arr[i] = i;
	}
	struct S* ptr = (struct S*)realloc(ps,sizeof(struct S) + 20 * sizeof(int));
	if (ptr != NULL)
		ps = ptr;
	for (int i = 0; i < 20; i++)
	{
		ps->arr[i] = i + 1;
	}
	return 0;
}
