#include"SList.h"

//void SListInit(SListNode** pplist)
//{
//	plist->_head->next = NULL;
//}
//void SListDestory(SList* plist)
//{
//
//}

SListNode* BuySListNode(SLTDataType x)
{
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	assert(newnode);
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}

void SListPushBack(SListNode** pplist, SLTDataType x)//尾插
{
	SListNode* newnode = BuySListNode(x);
	if (*pplist == NULL)
	{
		*pplist = newnode;
	}
	else
	{
		SListNode* endNode = *pplist;
		while (endNode->next != NULL)
		{
			endNode = endNode->next;
		}
		endNode->next = newnode;
	}
}
void SListPopBack(SListNode** pplist)//尾删
{
	SListNode* delnode = *pplist;
	if (delnode->next == NULL)
	{
		free(delnode);
		delnode = NULL;
		*pplist = NULL;
	}
	else
	{
		SListNode* beforeDel = *pplist;//指向要删除的前一个

		while (delnode->next != NULL)
		{
			beforeDel = delnode;
			delnode = beforeDel->next;
		}
		free(delnode);
		delnode = NULL;
		beforeDel->next = NULL;
	}
	
}

void SListPushFront(SListNode** pplist, SLTDataType x)//头插
{
	SListNode* newnode = BuySListNode(x);
	if (*pplist == NULL)
	{
		*pplist = newnode;
	}
	else
	{
		SListNode* scendnode = *pplist;
		*pplist = newnode;
		newnode->next = scendnode;
	}
}
void SListPopFront(SListNode** pplist)//头删
{
	if (*pplist == NULL)
	{
		return ;
	}
	else
	{
		SListNode* delnode = *pplist;
		*pplist = delnode->next;
		free(delnode);
		delnode = NULL;
	}
}

//SListNode* SListFind(SList* plist, SLTDataType x) // 在pos的后面进行插入
//{
//	return 0;
//}
//void SListInsertAfter(SListNode* pos, SLTDataType x) // 在pos的前面进行插入
//{
//
//}
//void SListEraseAfter(SListNode* pos)
//{
//
//}
//void SListRemove(SList* plist, SLTDataType x) {
//
//}

void SListPrint(SListNode* plist)
{
	SListNode* cur = plist;//申请一个指向当前结点的指针
	while (cur != NULL)
	{
		printf("%d-> ", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}
