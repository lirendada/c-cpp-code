#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int STDataType;

typedef struct Stack
{
	STDataType* a;
	int top;
	int capacity;
}Stack;

//栈的初始化与销毁
void StackInit(Stack* pst);
void StackDestroy(Stack* pst);
//入栈和出栈
void StackPush(Stack* pst, STDataType x);
void StackPop(Stack* pst);
//返回栈顶的值
STDataType StackTop(Stack* pst);
//判断栈是否为空(空为true,非空为false)
bool StackEmpty(Stack* pst);
//返回栈的元素个数
int StackSize(Stack* pst);