#define _CRT_SECURE_NO_WARNINGS
#include "sort.h"

// 测试排序的性能对比
void TestOP()
{
	srand((unsigned int)time(0));
	const int N = 100000;
	int* a1 = (int*)malloc(sizeof(int) * N);
	int* a2 = (int*)malloc(sizeof(int) * N);
	int* a3 = (int*)malloc(sizeof(int) * N);
	int* a4 = (int*)malloc(sizeof(int) * N);
	int* a5 = (int*)malloc(sizeof(int) * N);
	int* a6 = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; ++i)
	{
		a1[i] = rand();
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
	}
	int begin1 = clock();
	InsertSort(a1, N);
	int end1 = clock();

	int begin2 = clock();
	ShellSort(a2, N);
	int end2 = clock();

	int begin3 = clock();
	SelectSort(a3, N);
	int end3 = clock();

	int begin4 = clock();
	HeapSort(a4, N);
	int end4 = clock();

	int begin5 = clock();
	QuickSort(a5, 0, N - 1);
	int end5 = clock();

	int begin6 = clock();
	MergeSort(a6, N);
	int end6 = clock();

	printf("InsertSort:%d\n", end1 - begin1);
	printf("ShellSort:%d\n", end2 - begin2);
	printf("SelectSort:%d\n", end3 - begin3);
	printf("HeapSort:%d\n", end4 - begin4);
	printf("QuickSort:%d\n", end5 - begin5);
	printf("MergeSort:%d\n", end6 - begin6);
	free(a1);
	free(a2);
	free(a3);
	free(a4);
	free(a5);
	free(a6);
}

void TestInsert()
{
	int arr[] = { 9,3,4,8,7,3,58,1,52,6,5,10 };
	int n = sizeof(arr) / sizeof(arr[0]);
	InsertSort(arr, n);
	print(arr, n);
}

void TestShell()
{
	int arr[] = { 9,3,4,8,7,3,58,1,52,6,5,10 };
	int n = sizeof(arr) / sizeof(arr[0]);
	ShellSort(arr, n);
	print(arr, n);
}

void TestSelect()
{
	int arr[] = { 9,3,4,8,7,3,58,1,52,6,5,10 };
	int n = sizeof(arr) / sizeof(arr[0]);
	SelectSort(arr, n);
	print(arr, n);
}

void TestHeap()
{
	int arr[] = { 9,3,4,8,7,3,58,1,52,6,5,10 };
	int n = sizeof(arr) / sizeof(arr[0]);
	HeapSort(arr, n);
	print(arr, n);
}

void TestBubble()
{
	int arr[] = { 9,3,4,8,7,3,58,1,52,6,5,10 };
	int n = sizeof(arr) / sizeof(arr[0]);
	BubbleSort(arr, n);
	print(arr, n);
}

void TestQuick()
{
	int arr[] = { 9,3,4,8,7,3,58,1,52,6,5,10,5,3 };
	int n = sizeof(arr) / sizeof(arr[0]);
	QuickSortNonR(arr, 0, n - 1);
	//QuickSort(arr, 0, n - 1);
	print(arr, n);
}

void TestMerge()
{
	int arr[] = { 9,3,4,8,7,3,58,1,52,6,5,10,5,3,4 };
	int n = sizeof(arr) / sizeof(arr[0]);
	//MergeSort(arr, n);
	MergeSortNonR(arr, n);
	print(arr, n);
}

void TestCount()
{
	int arr[] = { 9,3,4,8,7,3,58,1,52,6,5,10,5,3,4 };
	int n = sizeof(arr) / sizeof(arr[0]);
	CountSort(arr, n);
	print(arr, n);
}

int main()
{
	//TestInsert();
	//TestShell();
	//TestSelect();
	//TestHeap();
	//TestBubble();
	//TestQuick();
	//TestMerge();
	//TestCount();
	TestOP();
	return 0;
}