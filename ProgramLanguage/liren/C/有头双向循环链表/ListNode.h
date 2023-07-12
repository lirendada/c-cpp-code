#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int LTDataType;
typedef struct ListNode
{
	struct ListNode* next;
	struct ListNode* prev;
	LTDataType x;
}ListNode;

ListNode* BuyListNode(LTDataType x);
// 创建返回链表的头结点.
ListNode* ListInit();
// 双向链表销毁
void ListDestroy(ListNode** phead);
// 双向链表尾插
void ListPushBack(ListNode* phead, LTDataType x);
// 双向链表头插
void ListPushFront(ListNode* phead, LTDataType x);
// 双向链表尾删
void ListPopBack(ListNode* phead);
// 双向链表头删
void ListPopFront(ListNode* phead);
// 双向链表查找
ListNode* ListFind(ListNode* phead, LTDataType x);
// 双向链表在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x);
// 双向链表删除pos位置的节点
void ListErase(ListNode* pos);
//空返回1，非空返回0
int ListEmpty(ListNode* phead);
//返回链表的个数
int ListSize(ListNode* phead);
//打印链表
void ListPrint(ListNode* phead);