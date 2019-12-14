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
// 队列的结构
typedef struct Queue
{
	QueueNode* front;		//队头
	QueueNode* back;		//队尾
}Queue;

void QueueInit(Queue* pq);// 初始化队列

void QueuePush(Queue* pq, QDataType data);// 队尾入队列

void QueuePop(Queue* pq);// 队头出队列

QDataType QueueFront(Queue* pq);// 获取队列头部元素

QDataType QueueBack(Queue* pq);// 获取队列队尾元素

int QueueSize(Queue* pq);// 获取队列中有效元素个数

int QueueEmpty(Queue* pq);// 检测队列是否为空，如果为空返回非零结果，如果非空返回0

void QueueDestroy(Queue* pq);// 销毁队列