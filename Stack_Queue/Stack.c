#include"stack.h"

void StackInit(Stack* pst)//³õÊ¼»¯
{
	assert(pst);
	pst->a = NULL;
	pst->top = pst->capacity = 0;
}

void StackDestory(Stack* pst)
{
	assert(pst);
	free(pst->a);
	pst->a = NULL;
	pst->top = pst->capacity = 0;
}

void StackPush(Stack* pst, STDataType x)
{
	assert(pst);
	if (pst->top == pst->capacity)
	{
		size_t newcapacity = pst->capacity == 0 ? 4 : pst->capacity * 2;
		pst->a = (STDataType*)realloc(pst->a, newcapacity * sizeof(STDataType));
	}
	pst->a[pst->top] = x;
	pst->top++;
}

void StackPop(Stack* pst)
{
	assert(pst && pst->top > 0);
	pst->top--;
}

STDataType StackTop(Stack* pst)
{
	assert(pst);
	return pst->a[pst->top - 1];
}

int StackEmpty(Stack* pst)
{
	assert(pst);
	return pst->top == 0 ? 1 : 0;
}

size_t StackSize(Stack* pst)
{
	assert(pst);
	return pst->top;
}
