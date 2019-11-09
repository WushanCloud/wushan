#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int SLDataType;

typedef struct SeqList
{
	SLDataType* array;  // 指向动态开辟的数组
	size_t size ;       // 有效数据个数 
	size_t capicity ;   // 容量空间的大小
}SeqList;


void SeqListInit(SeqList* ps, size_t capacity); //初始化
void SeqListDestory(SeqList* ps);//销毁

void CheckCapacity(SeqList* ps); //检查容量
void SeqListPushBack(SeqList* ps, SLDataType x);//尾插
void SeqListPopBack(SeqList* ps); 
void SeqListPushFront(SeqList* ps, SLDataType x);//头插
void SeqListPopFront(SeqList* ps);

int SeqListFind(SeqList* ps, SLDataType x);//查找
void SeqListInsert(SeqList* ps, size_t pos, SLDataType x);//位置插入
void SeqListErase(SeqList* ps, size_t pos);//位置删除
void SeqListRemove(SeqList* ps, SLDataType x);//数据删除
void SeqListRemoveAll(SeqList* ps, SLDataType x);//数据全部删除
void SeqListModify(SeqList* ps, size_t pos, SLDataType x);//数据修改
void SeqListPrint(SeqList* ps);//输出

int SeqListBinaryFind(SeqList* ps, SLDataType x);//二分查找