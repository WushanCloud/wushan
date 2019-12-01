#include"SList.h"


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

SListNode* SListFind(SListNode* plist, SLTDataType x)
{
	assert(plist);

	SListNode* findnode = plist;
	while (findnode != NULL)
	{
		if (findnode->data == x)
		{
			return findnode;
		}
		else
		{
			findnode = findnode->next;
		}
	}
	return NULL;
}

void SListInsertAfter(SListNode* pos, SLTDataType x)
{
	assert(pos);
	
	SListNode* newnode = BuySListNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

void SListEraseAfter(SListNode* pos)//删除所给结点
{
	assert(pos);
	//要删除pos得找到pos的前一个结点，获取pos的前一个结点的next域，但是所给条件找不到pos的前一个结点，所以把pos的下一个结点的值传给pos，删除pos下一个结点，达到删除pos位的效果
	if (pos->next != NULL)//如果所给节点啊的下个节点不为空
	{
		pos->data = pos->next->data;//把pos的下个结点的值传给pos
		SListNode* del = pos->next;//记录pos的下一个结点位置，记为del
		pos->next = pos->next->next;//把pos的下个结点的next域的值传给pos的next域
		free(del);//释放del
		del = NULL;//设为空指针
	}
}

void SListRemove(SListNode* plist, SLTDataType x)//删除给定值结点
{
	SListNode* delnode = SListFind(plist, x);//找到x的位置
	if (delnode->next!=NULL)//如果x的位置的下个结点不为空
	{
		SListEraseAfter(delnode);//直接删除x
	}
	else//说明x为最后一个结点，进行尾删
	{
		SListNode* delfront = plist;
		while (delfront->next->next != NULL)
		{
			delfront = delfront->next;
		}
		delnode = delfront->next;
		delfront->next = NULL;
		free(delnode);
		delnode = NULL;
	}
}


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
