#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>
#include <string.h>


typedef int HPDataType;
typedef struct Heap
{
	HPDataType* _a;
	size_t _size;
	size_t _capacity;
}Heap;

void HeapInit(Heap* hp, HPDataType* a, int n); //堆的初始化
void HeapDestory(Heap* hp); //堆的清空
void HeapPush(Heap* hp, HPDataType x);//入堆
void HeapPop(Heap* hp); //出堆 头删
HPDataType HeapTop(Heap* hp); //取堆顶的数据
Heap* swap(HPDataType* a, HPDataType* b);//交换
int HeapSize(Heap* hp); //堆的大小
int HeapEmpty(Heap* hp);//判断堆是否为空
void  AdjustUp(HPDataType* a, int n, int child);//向上调整
void  AdjustDown(HPDataType* a, int n, int root);//向下调整
// 堆排序 
void HeapSort(int* a, int n);
void HeapPrint(Heap* hp);//打印
