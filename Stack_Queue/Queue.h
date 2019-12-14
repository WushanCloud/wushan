#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<malloc.h>
typedef int QDataType;

typedef struct QListNode
{
	QDataType data;
	struct QListNode* next;
}QueueNode;
// ���еĽṹ
typedef struct Queue
{
	QueueNode* front;		//��ͷ
	QueueNode* back;		//��β
}Queue;

void QueueInit(Queue* pq);// ��ʼ������

void QueuePush(Queue* pq, QDataType data);// ��β�����

void QueuePop(Queue* pq);// ��ͷ������

QDataType QueueFront(Queue* pq);// ��ȡ����ͷ��Ԫ��

QDataType QueueBack(Queue* pq);// ��ȡ���ж�βԪ��

int QueueSize(Queue* pq);// ��ȡ��������ЧԪ�ظ���

int QueueEmpty(Queue* pq);// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0

void QueueDestroy(Queue* pq);// ���ٶ���