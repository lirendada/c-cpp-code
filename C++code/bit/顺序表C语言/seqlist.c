#define _CRT_SECURE_NO_WARNINGS
#include "seqlist.h"

void SeqlistInit(Seqlist* pq)
{
	assert(pq);
	pq->a = NULL;
	pq->size = pq->capacity = 0;
}

void SeqlistDestory(Seqlist* pq)
{
	assert(pq);
	free(pq->a);
	pq->a = NULL;
	pq->capacity = pq->size = 0;
}

void SeqlistPrint(Seqlist* pq)
{
	assert(pq);
	for (int i = 0; i < pq->size; i++)
	{
		printf("%d ", pq->a[i]);
	}
	printf("\n");
}

void SeqlistCheckCap(Seqlist* pq)
{
	if (pq->size == pq->capacity)
	{
		int newcapacity = (pq->capacity == 0) ? 7 : pq->capacity * 2;
		Seqdatatype* newA = (Seqdatatype*)realloc(pq->a, sizeof(Seqdatatype) * newcapacity);
		if (newA == NULL)
		{
			printf("增容失败！\n");
			exit(-1);
		}
		pq->a = newA;
		pq->capacity = newcapacity;
	}
}

void SeqlistPushBack(Seqlist* pq, Seqdatatype x)
{
	////第一种方法，自己实现
	//assert(pq);
	//SeqlistCheckCap(pq);
	//pq->a[pq->size] = x;
	//pq->size++;

	//第二种方法就是利用任意位置插入函数来实现特殊情况：pos等于pq->size时候就是尾插
	SeqlistInsert(pq, pq->size, x);
}

void SeqlistPopBack(Seqlist* pq)
{
	////第一种方法是自己实现
	//assert(pq);
	//assert(pq->size > 0);
	//pq->size--;

	//第二种方法就是让任意位置删除的pos等于pq->size-1，就是尾删
	SeqlistErase(pq, pq->size-1);
}

void SeqlistPushFront(Seqlist* pq, Seqdatatype x)
{
	////第一种方法就是自己实现
	//assert(pq);
	//SeqlistCheckCap(pq);
	//int end = pq->size - 1;
	//while (end >= 0)
	//{
	//	pq->a[end + 1] = pq->a[end];
	//	end--;
	//}
	//pq->a[0] = x;
	//pq->size++;

	//第二种方法就是利用任意位置插入函数来实现特殊情况：pos等于0时候就是头插
	SeqlistInsert(pq, 0, x);
}

void SeqlistPopFront(Seqlist* pq)
{
	////第一种方法就是自己实现
	//assert(pq);
	//assert(pq->size > 0);
	//int i = 0;
	//while (i < pq->size - 1)
	//{
	//	pq->a[i] = pq->a[i + 1];
	//	i++;
	//}
	//pq->size--;

	//第二种方法就是让任意位置删除的pos等于0，就是头删
	SeqlistErase(pq, 0);
}

int SeqlistFind(Seqlist* pq, Seqdatatype x)
{
	assert(pq);
	for (int i = 0; i < pq->size; i++)
	{
		if (pq->a[i] == x)
		{
			return i;
		}
	}
	return -1;
}

void SeqlistInsert(Seqlist* pq, int pos, Seqdatatype x)
{
	assert(pq);
	assert(pos >= 0 && pos <= pq->size);
	SeqlistCheckCap(pq);
	int end = pq->size - 1;
	while (end >= pos)
	{
		pq->a[end + 1] = pq->a[end];
		end--;
	}
	pq->a[pos] = x;
	pq->size++;
}

void SeqlistErase(Seqlist* pq, int pos)
{
	assert(pq);
	assert(pos >= 0 && pos < pq->size);
	while (pos < pq->size - 1)
	{
		pq->a[pos] = pq->a[pos + 1];
		pos++;
	}
	pq->size--;
}

void SeqlistModify(Seqlist* pq, int pos, Seqdatatype x)
{
	assert(pq);
	assert(pos >= 0 && pos < pq->size);
	pq->a[pos] = x;
}