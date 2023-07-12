#define _CRT_SECURE_NO_WARNINGS
#include "ListNode.h"

ListNode* BuyListNode(LTDataType x)
{
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	if (newnode == NULL)
	{
		printf("malloc fail!\n");
		exit(-1);
	}
	newnode->next = NULL;
	newnode->prev = NULL;
	newnode->x = x;
	return newnode;
}

ListNode* ListInit()
{
	ListNode* phead = BuyListNode(0);//头结点默认赋值给它0
	phead->next = phead;
	phead->prev = phead;
	return phead;
}

void ListDestroy(ListNode** phead)
{
	assert(*phead);
	ListNode* cur = (*phead)->next;
	while (cur != *phead)
	{
		ListNode* next = cur->next;
		free(cur);
		cur = next;
	}
	free(*phead);
	*phead = NULL;//传二级指针才能改变原来的指针
}

void ListPrint(ListNode* phead)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d ", cur->x);
		cur = cur->next;
	}
	printf("\n");
}

void ListPushBack(ListNode* phead, LTDataType x)
{
	/*assert(phead);
	ListNode* newnode = BuyListNode(x);
	ListNode* prev = phead->prev;
	prev->next = newnode;
	newnode->prev = prev;
	newnode->next = phead;
	phead->prev = newnode;*/

	ListInsert(phead, x);
}

void ListPushFront(ListNode* phead, LTDataType x)
{
	/*assert(phead);
	ListNode* newnode = BuyListNode(x);
	ListNode* next = phead->next;
	phead->next = newnode;
	newnode->prev = phead;
	newnode->next = next;
	next->prev = newnode;*/

	ListInsert(phead->next, x);
}

void ListPopBack(ListNode* phead)
{
	/*assert(phead);
	assert(phead->next != phead);

	ListNode* del = phead->prev;
	ListNode* prev = del->prev;
	free(del);
	prev->next = phead;
	phead->prev = prev;*/

	ListErase(phead->prev);
}

void ListPopFront(ListNode* phead)
{
	/*assert(phead);
	assert(phead->next != phead);

	ListNode* del = phead->next;
	ListNode* next = del->next;
	free(del);
	phead->next = next;
	next->prev = phead;*/

	ListErase(phead->next);
}

ListNode* ListFind(ListNode* phead, LTDataType x)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->x == x)
			return cur;
		cur = cur->next;
	}
	return NULL;
}

void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode* newnode = BuyListNode(x);
	ListNode* prev = pos->prev;
	newnode->next = pos;
	pos->prev = newnode;
	newnode->prev = prev;
	prev->next = newnode;
}

void ListErase(ListNode* pos)
{
	assert(pos);
	ListNode* prev = pos->prev;
	ListNode* next = pos->next;
	free(pos);
	prev->next = next;
	next->prev = prev;
}

int ListEmpty(ListNode* phead)
{
	assert(phead);
	return phead->next == phead ? 1 : 0;
}

int ListSize(ListNode* phead)
{
	assert(phead);
	ListNode* cur = phead->next;
	int count = 0;
	while (cur != phead)
	{
		cur = cur->next;
		count++;
	}
	return count;
}