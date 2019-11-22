#include"SList.h"

void test()//²âÊÔÎ²²åÎ²É¾
{
	SListNode* plist = NULL;
	SListPushBack(&plist ,1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPrint(plist);

	SListPopBack(&plist);
	SListPrint(plist);
	SListPopBack(&plist);
	SListPrint(plist);
	SListPopBack(&plist);
	SListPrint(plist);

}
void test2()//²âÊÔÍ·²åÍ·É¾
{
	SListNode * plist = NULL;
	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPrint(plist);

	SListPopFront(&plist);
	SListPrint(plist);
	SListPopFront(&plist);
	SListPrint(plist);
	SListPopFront(&plist);
	SListPrint(plist);

}
void test3()
{
	SListNode* plist = NULL;
	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPrint(plist);

	SListNode* plist1 = SListFind(plist,2);
	printf("%d", plist1->data);
}
void test4()
{
	SListNode* plist = NULL;
	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPrint(plist);

	SListInsertAfter(SListFind(plist, 2), 3);
	SListPrint(plist);
}
void test5()
{
	SListNode* plist = NULL;
	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPrint(plist);

	//SListEraseAfter(SListFind(plist, 1));
	//SListPrint(plist);
	SListRemove(plist, 1);
	SListPrint(plist);
}
int main()
{
	test5();
	return 0;
}