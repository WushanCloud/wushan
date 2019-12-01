#pragma once
#include<stdio.h>
#include<assert.h>
#include<malloc.h>

typedef int ListDataType;
typedef struct ListNode
{
	ListDataType data;
	struct ListNode* prev;
	struct ListNode* next;
}ListNode;

ListNode* ListCreate();// 创建返回链表的头结点. 
ListNode* BuyListNode(ListDataType x);
void ListDestory(ListNode* plist); // 双向链表销毁 

void ListPrint(ListNode* plist); // 双向链表打印 

void ListPushBack(ListNode* plist, ListDataType x);// 双向链表尾插 
void ListPopBack(ListNode* plist); // 双向链表尾删 

void ListPushFront(ListNode* plist, ListDataType x); // 双向链表头插
void ListPopFront(ListNode* plist); // 双向链表头删 
ListNode* ListFind(ListNode* plist, ListDataType x); // 双向链表查找 
void ListInsert(ListNode* pos, ListDataType x); // 双向链表在pos的前面进行插入 
void ListErase(ListNode* pos);// 双向链表删除pos位置的节点 