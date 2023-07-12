#include "SList.h"

SLTNode* BuySLTNode(SLTDataType x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode != NULL)
	{
		newnode->data = x;
		newnode->next = NULL;
		return newnode;
	}
	else
	{
		printf("空间不够！\n");
		exit(-1);
	}
}

//销毁单链表
void SListDestroy(SLTNode** pplist)
{
	assert(pplist);

	SLTNode* cur = *pplist;
	while (cur)
	{
		SLTNode* next = cur->next;
		free(cur);
		cur = next;
	}
	*pplist = NULL;
}

void SListPrint(SLTNode* plist)
{
	SLTNode* cur = plist;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

void SListPushFront(SLTNode** pplist, SLTDataType x)
{
	SLTNode* newnode = BuySLTNode(x);
	newnode->next = *pplist;
	*pplist = newnode;
}

void SListPushBack(SLTNode** pplist, SLTDataType x)
{
	SLTNode* newnode = BuySLTNode(x);
	if (*pplist == NULL)
	{
		*pplist = newnode;
	}
	else
	{
		SLTNode* tail = *pplist;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
}

void SListPopBack(SLTNode** pplist)
{
	if (*pplist == NULL)
	{
		return;
	}
	else if ((*pplist)->next == NULL)
	{
		free(*pplist);
		(*pplist) = NULL;
	}
	else
	{
		SLTNode* tail = *pplist;
		SLTNode* prev = NULL;
		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		tail = NULL;
		prev->next = NULL;
	}
}

void SListPopFront(SLTNode** pplist)
{
	if (*pplist == NULL)
	{
		return;
	}
	//这种累赘一点，多了个判断，其实可以一步到位
	/*else if ((*pplist)->next == NULL)
	{
		free(*pplist);
		*pplist = NULL;
	}
	else
	{
		SLTNode* head = *pplist;
		(*pplist) = (*pplist)->next;
		free(head);
		head = NULL;
	}*/

	else
	{
		SLTNode* next = (*pplist)->next;
		free(*pplist);
		*pplist = next;
	}
}

SLTNode* SListFind(SLTNode* plist, SLTDataType x)
{
	SLTNode* cur = plist;
	while (cur != NULL)
	{
		while (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

void SListInsertAfter(SLTNode* pos, SLTDataType x)
{
	assert(pos);
	SLTNode* newnode = BuySLTNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

void SListInsertKnowBefore(SLTNode** pplist, SLTNode* pos, SLTDataType x)
{
	assert(pos);
	SLTNode* newnode = BuySLTNode(x);
	if (*pplist == pos)
	{
		newnode->next = *pplist;
		*pplist = newnode;
	}
	else
	{
		SLTNode* cur = *pplist;
		newnode->next = pos;
		while (cur->next != pos)
		{
			cur = cur->next;
		}
		cur->next = newnode;
	}
}

void SListInsertUNKnowBefore(SLTNode* pos, SLTDataType x)
{
	SListInsertAfter(pos, x);
	SLTDataType tmp = pos->data;
	SLTNode* next = pos->next;
	pos->data = next->data;
	next->data = tmp;
}

void SListEraseAfter(SLTNode* pos)
{
	assert(pos);
	if (pos->next == NULL)
	{
		return;
	}
	else
	{
		SLTNode* next1 = pos->next;
		pos->next = next1->next;
		free(next1);
	}
}

