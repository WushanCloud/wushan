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

ListNode* ListCreate();// �������������ͷ���. 
ListNode* BuyListNode(ListDataType x);
void ListDestory(ListNode* plist); // ˫���������� 

void ListPrint(ListNode* plist); // ˫�������ӡ 

void ListPushBack(ListNode* plist, ListDataType x);// ˫������β�� 
void ListPopBack(ListNode* plist); // ˫������βɾ 

void ListPushFront(ListNode* plist, ListDataType x); // ˫������ͷ��
void ListPopFront(ListNode* plist); // ˫������ͷɾ 
ListNode* ListFind(ListNode* plist, ListDataType x); // ˫��������� 
void ListInsert(ListNode* pos, ListDataType x); // ˫��������pos��ǰ����в��� 
void ListErase(ListNode* pos);// ˫������ɾ��posλ�õĽڵ� 