#define _CRT_SECURE_NO_WARNINGS
#include "seqlist.h"

void testseq1()
{
	Seqlist s;
	SeqlistInit(&s);

	SeqlistPushBack(&s, 1);
	SeqlistPushBack(&s, 10);
	SeqlistPushBack(&s, 19);
	SeqlistPushFront(&s, 2);
	SeqlistPushFront(&s, 3);
	SeqlistPushFront(&s, 4);
	SeqlistPushFront(&s, 5);
	SeqlistPrint(&s);

	SeqlistPopBack(&s);
	SeqlistPopBack(&s);
	SeqlistPopFront(&s);
	SeqlistPrint(&s);

	SeqlistDestory(&s);
}

void testseq2()
{
	Seqlist s;
	SeqlistInit(&s);

	SeqlistPushBack(&s, 1);
	SeqlistPushBack(&s, 2);
	SeqlistPushBack(&s, 3);
	SeqlistPushBack(&s, 4);
	SeqlistPushBack(&s, 5);
	SeqlistPrint(&s);

	SeqlistInsert(&s, 2, 23);
	SeqlistPrint(&s);

	SeqlistErase(&s, 1);
	SeqlistPrint(&s);

	SeqlistDestory(&s);
}

int main()
{
	testseq1();
	return 0;
}