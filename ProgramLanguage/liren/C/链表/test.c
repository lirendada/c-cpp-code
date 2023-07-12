#define _CRT_SECURE_NO_WARNINGS
#include "SList.h"

void test1()
{
	SLTNode* plist = NULL;
	SListPrint(plist);

	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 4);
	SListPushFront(&plist, 5);
	SListPrint(plist);

	SListPushBack(&plist, 6);
	SListPushBack(&plist, 7);
	SListPushBack(&plist, 8);
	SListPushBack(&plist, 9);
	SListPushBack(&plist, 10);
	SListPrint(plist);

	SLTNode* pos = SListFind(plist, 10);
	if (pos != NULL)
	{
		pos->data = 6;//同时兼具了修改x的作用
		printf("找到了\n");
	}
	else
		printf("没找到\n");
	SListPrint(plist);

	SListInsertAfter(pos, 2);
	SListPrint(plist);

	SListInsertKnowBefore(&plist, pos, 7);
	SListPrint(plist);

	SListInsertUNKnowBefore(pos, 250);
	SListPrint(plist);

	SListDestroy(&plist);

	/*SListPopBack(&plist); 
	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPrint(plist);*/

	/*SListPopFront(&plist);
	SListPopFront(&plist);
	SListPopFront(&plist);
	SListPopFront(&plist);
	SListPopFront(&plist);
	SListPopFront(&plist);
	SListPopFront(&plist);
	SListPopFront(&plist);
	SListPopFront(&plist);
	SListPopFront(&plist);
	SListPrint(plist);*/
}

int main()
{
	test1();
	return 0;
}