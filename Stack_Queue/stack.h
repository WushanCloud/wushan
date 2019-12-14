#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<malloc.h>

#define N 10

typedef int STDataType;
typedef struct Stack
{
	STDataType* a;
	size_t top;				//栈顶
	size_t capacity;
}Stack;

void StackInit(Stack* pst);					//初始化
void StackDestory(Stack* pst);				//销毁
void StackPush(Stack* pst, STDataType x);	//加
void StackPop(Stack* pst);					//删
STDataType StackTop(Stack* pst);			//取栈顶的数据

int StackEmpty(Stack* pst);					//返回1表示空，返回0表示非空
size_t StackSize(Stack* pst);				//返回数据的个数