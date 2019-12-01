#include"SList.h"


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

void SListEraseAfter(SListNode* pos)//ɾ���������
{
	assert(pos);
	//Ҫɾ��pos���ҵ�pos��ǰһ����㣬��ȡpos��ǰһ������next�򣬵������������Ҳ���pos��ǰһ����㣬���԰�pos����һ������ֵ����pos��ɾ��pos��һ����㣬�ﵽɾ��posλ��Ч��
	if (pos->next != NULL)//��������ڵ㰡���¸��ڵ㲻Ϊ��
	{
		pos->data = pos->next->data;//��pos���¸�����ֵ����pos
		SListNode* del = pos->next;//��¼pos����һ�����λ�ã���Ϊdel
		pos->next = pos->next->next;//��pos���¸�����next���ֵ����pos��next��
		free(del);//�ͷ�del
		del = NULL;//��Ϊ��ָ��
	}
}

void SListRemove(SListNode* plist, SLTDataType x)//ɾ������ֵ���
{
	SListNode* delnode = SListFind(plist, x);//�ҵ�x��λ��
	if (delnode->next!=NULL)//���x��λ�õ��¸���㲻Ϊ��
	{
		SListEraseAfter(delnode);//ֱ��ɾ��x
	}
	else//˵��xΪ���һ����㣬����βɾ
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
	SListNode* cur = plist;//����һ��ָ��ǰ����ָ��
	while (cur != NULL)
	{
		printf("%d-> ", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}
