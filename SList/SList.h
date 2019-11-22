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
SListNode* SListFind(SListNode* plist, SLTDataType x); // ��ֵ����
void SListInsertAfter(SListNode* pos, SLTDataType x); // ��pos�ĺ�����в���

void SListEraseAfter(SListNode* pos);//ɾ���������
void SListRemove(SListNode* plist, SLTDataType x);//ɾ������ֵ���

void SListPrint(SListNode* plist);
