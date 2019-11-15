#include "AddressBook.h"

void TestAddressBook()
{
	AddressBook addressbook;//����һ��ͨѶ¼��
	AddressBookInit(&addressbook);
	AddressInfo info1 = {"�߲�", "110", 18, Man};
	AddressBookAdd(&addressbook, &info1);

	AddressInfo info2 = { "С��", "111", 19, Man };
	AddressBookAdd(&addressbook, &info2);

	AddressInfo info3 = { "С��", "111", 19, Man };
	AddressBookAdd(&addressbook, &info3);

	AddressBookPrint(&addressbook);
	AddressBookFindPrint(&addressbook, "С��");
	AddressBookDel(&addressbook, "С��");
	AddressBookPrint(&addressbook);

	AddressBookSave(&addressbook, "addressfile.txt");
	
	AddressBookLoad(&addressbook, "addressfile.bin");
	AddressBookPrint(&addressbook);
}
void test1()
{
	char* hello = "hello,world!";
	char arr[] = { "adsscasdadsa"};
	AddFopen(arr);
	readFILE();
}
int main()
{
	//menu();
	TestAddressBook();
	//test();
	return 0;
}