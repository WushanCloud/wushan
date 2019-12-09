#pragma once

#include<stdio.h>
#include<stdlib.h>

#define N 10

typedef int STDataType;
typedef struct Stack
{
	STDataType* a;
	size_t top;//ջ��
	size_t capacity;
}Stack;

void StackInit(Stack* pst);
void StackDestory(Stack* pst);
void StackPush(Stack* pst, STDataType x);//��
void StackPop(Stack* pst);//ɾ
STDataType StackTop(Stack* pst);

int StackEmpty(Stack* pst);//����1��ʾ�գ�����0��ʾ�ǿ�
size_t StackSize(Stack* pst);//