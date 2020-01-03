#include "Heap.h"

void test1()
{
	Heap Hp;
	HPDataType arr[] = { 2,5,4,6,3,6,4,2,5 };
	int len = sizeof(arr) / sizeof(arr[0]);
	HeapInit(&Hp, arr, len);
	HeapPrint(&Hp);

	HeapPop(&Hp);
	HeapPrint(&Hp);

	HeapPush(&Hp, 1);
	HeapPrint(&Hp);

}

int main()
{
	test1();
	return 0;
}
