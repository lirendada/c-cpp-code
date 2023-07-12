#define _CRT_SECURE_NO_WARNINGS
#include "stack.h"
#include "queue.h"

void teststack()
{
	Stack st;
	StackInit(&st);

	StackPush(&st, 1);
	StackPush(&st, 2);
	printf("%d ", StackTop(&st));
	StackPop(&st);

	StackPush(&st, 3);
	printf("%d ", StackTop(&st));
	StackPop(&st);

	StackPush(&st, 4);
	StackPush(&st, 5);
	while (!StackEmpty(&st))
	{
		printf("%d ", StackTop(&st));
		StackPop(&st);
	}

	StackDestroy(&st);
}

void testqueue()
{
	Queue q;
	QueueInit(&q);

	QueuePush(&q, 1);
	printf("%d ", QueueFront(&q));
	QueuePop(&q);

	QueuePush(&q, 2);
	printf("%d ", QueueFront(&q));
	QueuePop(&q);

	QueuePush(&q, 3);
	QueuePush(&q, 4);
	while (!QueueEmpty(&q))
	{
		printf("%d ", QueueFront(&q));
		QueuePop(&q);
	}

	QueueDestroy(&q);
}

int main()
{
	//teststack();
	testqueue();
	return 0;
}