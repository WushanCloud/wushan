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

void SListPushBack(SListNode** pplist, SLTDataType x)//β��
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
void SListPopBack(SListNode** pplist)//βɾ
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
		SListNode* beforeDel = *pplist;//ָ��Ҫɾ����ǰһ��

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

void SListPushFront(SListNode** pplist, SLTDataType x)//ͷ��
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
void SListPopFront(SListNode** pplist)//ͷɾ
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

//SListNode* SListFind(SList* plist, SLTDataType x) // ��pos�ĺ�����в���
//{
//	return 0;
//}
//void SListInsertAfter(SListNode* pos, SLTDataType x) // ��pos��ǰ����в���
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
	SListNode* cur = plist;//����һ��ָ��ǰ����ָ��
	while (cur != NULL)
	{
		printf("%d-> ", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}
