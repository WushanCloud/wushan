#include"List.h"

void test()
{
	ListNode * list = ListCreate();
	
	ListPushBack(list, 1);
	ListPushBack(list, 2);
	ListPushBack(list, 3);
	ListPushBack(list, 4);
	ListPrint(list);

	ListInsert(ListFind(list, 3), 9);
	ListPrint(list);
}

int main()
{
	test();
	return 0;
}