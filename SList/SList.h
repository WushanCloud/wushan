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

void SListPushBack(SListNode** pplist, SLTDataType x);//β��
void SListPopBack(SListNode** pplist);//βɾ
SListNode* BuySListNode(SLTDataType x);//�����½��
void SListPushFront(SListNode** pplist, SLTDataType x);//ͷ��
void SListPopFront(SListNode** pplist);
//SListNode* SListFind(SList* plist, SLTDataType x); // ��pos�ĺ�����в���
//void SListInsertAfter(SListNode* pos, SLTDataType x); // ��pos��ǰ����в���
//void SListEraseAfter(SListNode* pos);
//void SListRemove(SList* plist, SLTDataType x);

void SListPrint(SListNode* plist);
