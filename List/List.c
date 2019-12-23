#include "List.h"

ListNode* ListCreate()// 创建返回链表的头结点. 
{
	ListNode* newhead = (ListNode *)malloc(sizeof(ListNode));
	if (newhead != NULL)
	{
		newhead->data = NULL;
		newhead->next = newhead;
		newhead->prev = newhead;
	}
	return newhead;
}

ListNode* BuyListNode(ListDataType x)
{
	assert(x);
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	if (newnode != NULL)
	{
		newnode->data = x;
		newnode->next = NULL;
		newnode->prev = NULL;
	}
	else
	{
		printf(" New node Create Break Down!");
		return NULL;
	}
	return newnode;
}


void ListDestory(ListNode* plist)
{
}

void ListPrint(ListNode* plist)
{
	ListNode* plistcur = plist->next;
	while (plistcur != plist)
	{
		printf("%d->", plistcur->data);
		plistcur = plistcur->next;
	}
	printf("head\n");
}

void ListPushBack(ListNode* plist, ListDataType x)
{
	ListNode* newnode = BuyListNode(x);
	ListNode* prev = plist->prev;
	newnode->next = plist;
	newnode->prev = prev;
	prev->next = newnode;
	plist->prev = newnode;
}

void ListPopBack(ListNode* plist)//删法一
{
	ListNode* del = plist->prev;
	del->prev->next = del->next;
	plist->prev = del->prev;
	free(del);
}

void ListPushFront(ListNode* plist, ListDataType x)
{
	ListNode* newnode = BuyListNode(x);
	newnode->next = plist->next;
	newnode->prev = plist;

	plist->next = newnode;
	newnode->next->prev = newnode;
}

void ListPopFront(ListNode* plist)//删法二
{
	if(plist->next != plist)
	if (plist->next != plist->prev)//剩余结点大于1个
	{
		ListNode* del = plist->next;
		plist->next = del->next;
		del->prev = plist;
		free(del);
	}
	else//说明只剩一个结点
	{
		ListNode* del = plist->next;
		plist->next = plist;
		plist->prev = plist;
		free(del);
	}
}

ListNode* ListFind(ListNode* plist, ListDataType x)
{
	assert(plist);
	ListNode* next = plist->next;

	while (next)
	{
		if (next->data == x)
		{
			return next;
		}
		else
		{
			next = next->next;
		}
	}
	return NULL;
}

void ListInsert(ListNode* pos, ListDataType x)
{
	ListNode* node = pos->prev;
	ListNode* newnode = BuyListNode(x);
	newnode->next = pos;
	newnode->prev = node;
	node->next = newnode;
	pos->prev = newnode;
}

void ListErase(ListNode* pos)
{
	ListNode* del = pos;
	del->prev->next = del->next;
	del->next->prev = del->prev;
	free(del);
}
