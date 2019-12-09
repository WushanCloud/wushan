#include"List.h"

void test()
{
	ListNode * list = ListCreate();
	
	ListPushFront(list, 1);
	ListPrint(list);

	ListPopBack(list);
	ListPrint(list);

	ListPushBack(list, 1);
	ListPrint(list);

	ListPopBack(list, 1);
	ListPrint(list);

	ListPushBack(list, 1);
	ListPrint(list);
}

int main()
{
	test();
	return 0;
}