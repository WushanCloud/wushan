#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLTDataType;

typedef struct SListNode {
	SLTDataType data;
	struct SListNode* next;
}SListNode;


//void SListInit(SListNode** pplist);
//void SListDestory(SList* plist);

void SListPushBack(SListNode** pplist, SLTDataType x);//尾插
void SListPopBack(SListNode** pplist);//尾删
SListNode* BuySListNode(SLTDataType x);//创建新结点
void SListPushFront(SListNode** pplist, SLTDataType x);//头插
void SListPopFront(SListNode** pplist);
//SListNode* SListFind(SList* plist, SLTDataType x); // 在pos的后面进行插入
//void SListInsertAfter(SListNode* pos, SLTDataType x); // 在pos的前面进行插入
//void SListEraseAfter(SListNode* pos);
//void SListRemove(SList* plist, SLTDataType x);

void SListPrint(SListNode* plist);
