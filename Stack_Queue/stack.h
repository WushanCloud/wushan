#pragma once

#include<stdio.h>
#include<stdlib.h>

#define N 10

typedef int STDataType;
typedef struct Stack
{
	STDataType* a;
	size_t top;//栈顶
	size_t capacity;
}Stack;

void StackInit(Stack* pst);
void StackDestory(Stack* pst);
void StackPush(Stack* pst, STDataType x);//加
void StackPop(Stack* pst);//删
STDataType StackTop(Stack* pst);

int StackEmpty(Stack* pst);//返回1表示空，返回0表示非空
size_t StackSize(Stack* pst);//