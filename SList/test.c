#include"SList.h"

void test()//����β��βɾ
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
void test2()//����ͷ��ͷɾ
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
}
int main()
{
	test();
	return 0;
}