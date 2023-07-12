#define _CRT_SECURE_NO_WARNINGS
#include "stack.h"

void StackInit(Stack* pst)
{
	assert(pst);
	pst->a = (STDataType*)malloc(sizeof(STDataType) * 4);
	pst->capacity = 4;
	pst->top = 0;//意味着top指向栈顶数据的下一个
}

void StackDestroy(Stack* pst)
{
	assert(pst);
	free(pst->a);
	pst->a = NULL;
	pst->capacity = pst->top = 0;
}

void StackPush(Stack* pst, STDataType x)
{
	assert(pst);
	//判断是否需要增容
	if (pst->top == pst->capacity)
	{
		STDataType* newcapacity = (STDataType*)realloc(pst->a, sizeof(STDataType) * pst->capacity * 2);
		if (newcapacity != NULL)
		{
			pst->a = newcapacity;
			pst->capacity *= 2;
		}
		else
		{
			printf("realloc fail!\n");
			exit(-1);//结束整个程序
		}
	}
	pst->a[pst->top] = x;
	pst->top++;
}

void StackPop(Stack* pst)
{
	assert(pst);
	assert(!StackEmpty(pst));//判断栈是否为空
	pst->top--;
}

STDataType StackTop(Stack* pst)
{
	assert(pst);
	assert(!StackEmpty(pst));//判断栈是否为空
	return pst->a[pst->top - 1];
}

bool StackEmpty(Stack* pst)
{
	return pst->top == 0;
}

int StackSize(Stack* pst)
{
	assert(pst);
	return pst->top;
}