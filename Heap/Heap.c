#include "Heap.h"

void HeapInit(Heap* hp, HPDataType* a, int n)
{
	//把数组里的数放到堆里面
	hp->_a = (HPDataType*)malloc(sizeof(HPDataType) * n);
	memcpy(hp->_a, a, sizeof(HPDataType) * n);
	hp->_size = n;
	hp->_capacity = n;
	
	//构建堆
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(hp->_a, hp->_size, i);
	}
}

void HeapDestory(Heap* hp)
{
	free(hp->_a);
	hp->_a = NULL;
}

void HeapPush(Heap* hp, HPDataType x)
{
	if (hp->_size == hp->_capacity)
	{
		hp->_capacity *= 2;
		hp->_a = (HPDataType*)realloc(hp->_a,sizeof(HPDataType) * hp->_capacity);
	}
	hp->_a[hp->_size] = x;
	hp->_size++;

	AdjustUp(hp->_a, hp->_size, hp->_a[hp->_size - 1]);
}

//向上调整是把大的往上走
void AdjustUp(HPDataType* a, int n, int child)
{
	int parent = (child - 1) / 2;

	while (parent >= 0)
	{
		if (a[parent] < a[child])
		{
			swap(&a[parent], &a[child]);//交换
			child = parent;
			parent = child / 2;
		}
		else
		{
			break;
		}
	}
	
}

//向下调整就是把最小的放在根部
void AdjustDown(HPDataType* a, int n, int root)
{
	//先计算，设置好双亲结点和孩子结点的下标
	int parent = root;
	int child = root * 2 + 1;//左孩子

	//选择小的孩子和双亲结点比较，然后把双亲结点替换了
	while (child < n)
	{
		//找到小的一个孩子
		if (child + 1 < n && a[child] > a[child + 1])
		{
			child++;
		}

		if (a[child] < a[parent])
		{
			swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapSort(int* a, int n)
{
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}

	int end = n - 1;
	while (end > 0)
	{
		swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}
}

void HeapPrint(Heap* hp)
{
	for (size_t i = 0; i < hp->_size; i++)
	{
		printf("%d ", hp->_a[i]);
	}
	printf("\n");
}

void HeapPop(Heap* hp)
{
	swap(&hp->_a[0], &hp->_a[hp->_size - 1]);
	hp->_size--;
	AdjustDown(hp->_a, hp->_size, 0);
}

HPDataType HeapTop(Heap* hp)
{
	return hp->_a[0];
}

Heap* swap(HPDataType* a, HPDataType* b)
{
	HPDataType x = *a;
	*a = *b;
	*b = x;
	return NULL;
}

int HeapSize(Heap* hp)
{
	return hp->_size;
}

int HeapEmpty(Heap* hp)
{
	return hp->_size == 0 ? 1 : 0;
}
