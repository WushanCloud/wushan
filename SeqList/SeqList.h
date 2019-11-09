#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int SLDataType;

typedef struct SeqList
{
	SLDataType* array;  // ָ��̬���ٵ�����
	size_t size ;       // ��Ч���ݸ��� 
	size_t capicity ;   // �����ռ�Ĵ�С
}SeqList;


void SeqListInit(SeqList* ps, size_t capacity); //��ʼ��
void SeqListDestory(SeqList* ps);//����

void CheckCapacity(SeqList* ps); //�������
void SeqListPushBack(SeqList* ps, SLDataType x);//β��
void SeqListPopBack(SeqList* ps); 
void SeqListPushFront(SeqList* ps, SLDataType x);//ͷ��
void SeqListPopFront(SeqList* ps);

int SeqListFind(SeqList* ps, SLDataType x);//����
void SeqListInsert(SeqList* ps, size_t pos, SLDataType x);//λ�ò���
void SeqListErase(SeqList* ps, size_t pos);//λ��ɾ��
void SeqListRemove(SeqList* ps, SLDataType x);//����ɾ��
void SeqListRemoveAll(SeqList* ps, SLDataType x);//����ȫ��ɾ��
void SeqListModify(SeqList* ps, size_t pos, SLDataType x);//�����޸�
void SeqListPrint(SeqList* ps);//���

int SeqListBinaryFind(SeqList* ps, SLDataType x);//���ֲ���