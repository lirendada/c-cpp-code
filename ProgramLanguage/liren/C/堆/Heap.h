#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include<string.h>

typedef int HPDataType;

typedef struct Heap
{
	HPDataType* a;
	int size;
	int capacity;
}Heap;

//堆的构建
void HeapCreate(Heap* hp, HPDataType* a, int n);

//堆的销毁
void HeapDestroy(Heap* hp);

//堆的插入
void HeapPush(Heap* hp, HPDataType x);

//堆的删除
void HeapPop(Heap* hp);

//取堆顶的数据
HPDataType HeapTop(Heap* hp);

//堆的数据个数
int HeapSize(Heap* hp);

//堆的判空
int HeapEmpty(Heap* hp);

//对数组进行堆排序
void HeapSort(HPDataType* a, int n);

//打印堆
void HeapPrint(Heap* hp);

//以大堆为例的向上调整算法
void AdjustBigUp(HPDataType* a, int child);

//以大堆为例的向下调整算法
void AdjustBigDown(HPDataType* a, int n, int parent);

//交换函数
void Swap(HPDataType* p1, HPDataType* p2);

void TestTopk();

void PrintSTopK(int* a, int n, int k);

void PrintBTopK(int* a, int n, int k);