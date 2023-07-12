#define _CRT_SECURE_NO_WARNINGS
#include "ListNode.h"

void test1()
{
	ListNode* phead = ListInit();
	ListPushBack(phead, 1);
	ListPushBack(phead, 2);
	ListPushBack(phead, 3);
	ListPushBack(phead, 4);
	ListPushBack(phead, 5);
	ListPrint(phead);

	ListPushFront(phead, 5);
	ListPushFront(phead, 4);
	ListPushFront(phead, 3);
	ListPushFront(phead, 2);
	ListPushFront(phead, 1);
	ListPrint(phead);

	ListPopBack(phead);
	ListPopBack(phead);
	ListPopBack(phead);
	ListPopBack(phead);
	ListPrint(phead);

	ListPopFront(phead);
	ListPopFront(phead);
	ListPopFront(phead);
	ListPrint(phead);

	ListNode* newnode = ListFind(phead, 1);
	if (newnode != NULL)
	{
		ListInsert(newnode, 7);
		ListInsert(newnode, 4);
		ListPrint(phead);
	}
	else
	{
		printf("no found!\n");
	}

	ListDestroy(&phead);//记得是传地址过去
}

int main()
{
	test1();
	return 0;
}