#pragma once
#include "Heap.h"

int main()
{
	int arr[] = { 15,18,28,34,65,19,49,25,37,27 };
	int n = sizeof(arr) / sizeof(arr[0]);

	Heap hp;
	HeapCreate(&hp, arr, n);
	HeapPrint(&hp);

	HeapPush(&hp, 28);
	HeapPrint(&hp);
	HeapPush(&hp, 5);
	HeapPrint(&hp);

	HeapPop(&hp);
	HeapPop(&hp);
	HeapPrint(&hp);

	HeapSort(hp.a, hp.size);
	HeapPrint(&hp);

	TestTopk();

	HeapDestroy(&hp);
	return 0;
}