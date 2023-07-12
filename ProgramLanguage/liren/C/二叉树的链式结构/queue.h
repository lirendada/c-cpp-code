#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
//使用链表实现会好点

//前置声明
struct BinaryTreeNode;

typedef struct BinaryTreeNode* QDataType;

typedef struct QueueNode
{
	QDataType data;
	struct QueueNode* next;
}QueueNode;

typedef struct Queue
{
	QueueNode* head;
	QueueNode* tail;
}Queue;

//队列的初始化和销毁
void QueueInit(Queue* pq);
void QueueDestroy(Queue* pq);

//队列的入列和出列
void QueuePush(Queue* pq, QDataType x);
void QueuePop(Queue* pq);

//返回队列的对头值和队尾值
QDataType QueueFront(Queue* pq);
QDataType QueueBack(Queue* pq);

//判断队列是否为空
bool QueueEmpty(Queue* pq);

//返回队列节点个数
QDataType QueueSize(Queue* pq);