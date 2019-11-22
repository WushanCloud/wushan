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
SListNode* SListFind(SListNode* plist, SLTDataType x); // 按值查找
void SListInsertAfter(SListNode* pos, SLTDataType x); // 在pos的后面进行插入

void SListEraseAfter(SListNode* pos);//删除所给结点
void SListRemove(SListNode* plist, SLTDataType x);//删除给定值结点

void SListPrint(SListNode* plist);
