#include"SeqList.h"

void SeqListInit(SeqList* ps, size_t capacity)//初始化
{
	assert(ps && capacity > 0);

	ps->array = (SLDataType*)malloc(capacity * sizeof(SLDataType));
	if (ps->array != NULL)
	{
		for (size_t i = 0; i < capacity; i++)
		{
			ps->array[i] = 0;
		}
		ps->size = 0;
		ps->capicity = capacity;
	}
	
}
void SeqListDestory(SeqList* ps)
{
	assert(ps);

	free(ps->array);
	ps->size = 0;
	ps->capicity = 0;
}

void CheckCapacity(SeqList* ps)
{
	assert(ps);
	if (ps->size == ps->capicity)
	{
		SeqList p;
		(&p)->array;//等于p.array
		p.array = (SLDataType*)realloc(ps->array, 2 * ps->capicity * sizeof(SLDataType));
		if ((&p)->array != NULL)
		{
			ps->array = (&p)->array;
			ps->capicity *= 2;
		}
	}
}
void SeqListPushBack(SeqList* ps, SLDataType x)//尾插
{
	assert(ps);
	CheckCapacity(ps);
	ps->array[ps->size] = x;
	ps->size++;
}
void SeqListPopBack(SeqList* ps)
{
	assert(ps);
	ps->size--;
}
void SeqListPushFront(SeqList* ps, SLDataType x)//头插
{
	assert(ps);
	CheckCapacity(ps);
	for (size_t i = ps->size; i >0; i--)
	{
		ps->array[i] = ps->array[i - 1];
	}
	ps->array[0] = x;
	ps->size++;
}
void SeqListPopFront(SeqList* ps)
{
	assert(ps);
	for (size_t i = 0; i < ps->size-1; i++)
	{
		ps->array[i] = ps->array[i + 1];
	}
	ps->size--;
}

int SeqListFind(SeqList* ps, SLDataType x)
{
	assert(ps);
	for (size_t i = 0; i <= ps->size; i++)
	{
		if (ps->array[i]==x)
		{
			return i;
		}
	}
	return -1;
}
void SeqListInsert(SeqList* ps, size_t pos, SLDataType x)
{
	assert(ps);
	CheckCapacity(ps);
	for (size_t i = ps->size; i > pos; i--)
	{
		ps->array[i] = ps->array[i - 1];
	}
	ps->array[pos] = x;
	ps->size++;
}
void SeqListErase(SeqList* ps, size_t pos)
{
	assert(ps);
	for (size_t i = pos; i <ps->size; i++)
	{
		ps->array[i] = ps->array[i + 1];
	}
	ps->size--;
}
void SeqListRemove(SeqList* ps, SLDataType x)
{
	assert(ps);
	int pos = (int)SeqListFind(ps, x);;
	SeqListErase(ps, pos);
}
void SeqListRemoveAll(SeqList* ps, SLDataType x)
{
	assert(ps);

	int pos = SeqListFind(ps, x);
	while (pos>=0)
	{
		SeqListErase(ps, (size_t)pos);
		pos = SeqListFind(ps, x);
	}
}
void SeqListModify(SeqList* ps, size_t pos, SLDataType x)
{
	assert(ps);
	
	ps->array[pos] = x;

}
void SeqListPrint(SeqList* ps)//输出
{
	for (size_t i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->array[i]);
	}
	printf("\n");
}

void SeqListBubbleSort(SeqList* ps)
{
	int true = 0;
	for (size_t i = ps->size-1; i > 0; i--)
	{
		for (size_t j = 0; j < i; j++)
		{
			if (ps->array[j] > ps->array[j + 1])
			{
				SLDataType tmp = ps->array[j];
				ps->array[j] = ps->array[j + 1];
				ps->array[j + 1] = tmp;
				true = 1;
			}
		}
		if (true == 0)
		{
			break;
		}
	}
}

/*二分法查找*/
int SeqListBinaryFind(SeqList * ps,SLDataType x)
{
	size_t begin = 0, end = ps->size - 1;
	while (begin <= end)
	{
		size_t pos = (begin + end) / 2;
		if (x < ps->array[pos])
		{
			end = pos-1;
		}
		else if (x > ps->array[pos])
		{
			begin = pos+1;
		}
		else
		{
			return pos;
		}
	}
	return -1;
}
//// [)半开半闭的二分查找
//int SeqListBinaryFind(SeqList* ps, SLDataType x)
//{
//	size_t begin = 0, end = ps->size;
//	while (begin < end)
//	{
//		size_t pos = (begin + end) / 2;
//		if (x < ps->array[pos])
//		{
//			end = pos;//[)
//		}
//		else if (x > ps->array[pos])
//		{
//			begin = pos + 1;
//		}
//		else
//		{
//			return pos;
//		}
//	}
//	return -1;
//}