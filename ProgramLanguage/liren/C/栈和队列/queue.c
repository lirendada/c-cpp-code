#define _CRT_SECURE_NO_WARNINGS
#include "queue.h"

void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = pq->tail = NULL;//这里选择无头结点的
}

void QueueDestroy(Queue* pq)
{
	assert(pq);
	QueueNode* cur = pq->head;
	while (cur != NULL)
	{
		QueueNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->head = pq->tail = NULL;
}

void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newnode == NULL)
	{
		printf("malloc fail!\n");
		exit(-1);
	}
	newnode->next = NULL;
	newnode->data = x;
	//判断一下队列是否为空
	if (pq->tail == NULL)
	{
		pq->tail = pq->head = newnode;
	}
	else
	{
		pq->tail->next = newnode;
		pq->tail = newnode;
	}
}

void QueuePop(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));//判断一下队列是否为空

	//判断一下是否只剩一个节点
	if (pq->head->next == NULL)
	{
		free(pq->head);
		pq->head = pq->tail = NULL;
	}
	else
	{
		QueueNode* next = pq->head->next;
		free(pq->head);
		pq->head = next; 
	}
}

QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));//判断一下队列是否为空

	return pq->head->data;
}

QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));//判断一下队列是否为空

	return pq->tail->data;
}

bool QueueEmpty(Queue* pq)
{
	assert(pq);

	return pq->head == NULL;
}

QDataType QueueSize(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));//判断一下队列是否为空

	QueueNode* cur = pq->head;
	int count = 0;
	while (cur != NULL)
	{
		count++;
		cur = cur->next;
	}
	return count;
}