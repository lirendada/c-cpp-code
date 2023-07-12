#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLTDataType;

//1、单向 + 无头 + 不循环
typedef struct SListNode
{
	int data;
	struct SLTNode* next;
}SLTNode;

SLTNode* BuySLTNode(SLTDataType x);
void SListDestroy(SLTNode** pplist);

void SListPrint(SLTNode* plist);
void SListPushFront(SLTNode** pplist, SLTDataType x);
void SListPushBack(SLTNode** pplist, SLTDataType x);

void SListPopFront(SLTNode** pplist);
void SListPopBack(SLTNode** pplist);

SLTNode* SListFind(SLTNode* plist, SLTDataType x);

//只要求学会后插，因为前插在单链表中不是很重要
//且前插可以转化为后插一个结点后将两个结点的值交换即可
void SListInsertAfter(SLTNode* pos, SLTDataType x);
void SListInsertKnowBefore(SLTNode**pplist,SLTNode* pos, SLTDataType x);//知头结点版本
void SListInsertUNKnowBefore( SLTNode* pos, SLTDataType x);//不知道头节点的版本

void SListEraseAfter(SLTNode* pos);
