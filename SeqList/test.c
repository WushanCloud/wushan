#include"SeqList.h"

void TestList()
{
	SeqList psL;
	SeqListInit(&psL, 4);

	SeqListPushBack(&psL, 1);
	SeqListPushBack(&psL, 2);
	SeqListPushBack(&psL, 3);
	SeqListPushBack(&psL, 4);
	SeqListPushBack(&psL, 5);
	SeqListPushBack(&psL, 6);
	SeqListPrint(&psL);

	SeqListPopBack(&psL);
	SeqListPrint(&psL);

	SeqListPushFront(&psL, 0);
	SeqListPrint(&psL);
	SeqListPopFront(&psL);
	SeqListPrint(&psL);
	SeqListDestory(&psL);
}

void TestList2()
{
	SeqList psL;
	SeqListInit(&psL, 4);

	SeqListPushBack(&psL, 1);
	SeqListPushBack(&psL, 2);
	SeqListPushBack(&psL, 3);
	SeqListPushBack(&psL, 4);
	SeqListPushBack(&psL, 5);
	SeqListPushBack(&psL, 6);
	SeqListPrint(&psL);

	printf("%d\n",SeqListFind(&psL, 2));

	SeqListInsert(&psL, 3, 9);
	SeqListPrint(&psL);
	SeqListInsert(&psL, 0, 9);
	SeqListPrint(&psL);

	SeqListDestory(&psL);
}
void TestList3()
{
	SeqList psL;
	SeqListInit(&psL, 4);

	SeqListPushBack(&psL, 1);
	SeqListPushBack(&psL, 2);
	SeqListPushBack(&psL, 3);
	SeqListPushBack(&psL, 4);
	SeqListPushBack(&psL, 5);
	SeqListPushBack(&psL, 6);
	SeqListPrint(&psL);

	SeqListErase(&psL,3);
	SeqListPrint(&psL);

	SeqListModify(&psL, 3, 9);
	SeqListPrint(&psL);

	SeqListDestory(&psL);
}
void TestList4()
{
	SeqList psL;
	SeqListInit(&psL, 4);

	SeqListPushBack(&psL, 1);
	SeqListPushBack(&psL, 2);
	SeqListPushBack(&psL, 3);
	SeqListPushBack(&psL, 4);
	SeqListPushBack(&psL, 3);
	SeqListPushBack(&psL, 6);
	SeqListPrint(&psL);

	SeqListRemove(&psL, 3);
	SeqListPrint(&psL);
	SeqListRemove(&psL, 3);
	SeqListPrint(&psL);

	SeqListDestory(&psL);
}
void TestList5()
{
	SeqList psL;
	SeqListInit(&psL, 4);

	SeqListPushBack(&psL, 1);
	SeqListPushBack(&psL, 2);
	SeqListPushBack(&psL, 3);
	SeqListPushBack(&psL, 4);
	SeqListPushBack(&psL, 3);
	SeqListPushBack(&psL, 6);
	SeqListPrint(&psL);

	SeqListRemoveAll(&psL, 3);
	SeqListPrint(&psL);

	SeqListDestory(&psL);
}
int main()
{
	TestList5();
	return 0;
}