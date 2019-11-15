#include "AddressBook.h"

void TestAddressBook()
{
	AddressBook addressbook;//创建一个通讯录；
	AddressBookInit(&addressbook);
	AddressInfo info1 = {"高博", "110", 18, Man};
	AddressBookAdd(&addressbook, &info1);

	AddressInfo info2 = { "小王", "111", 19, Man };
	AddressBookAdd(&addressbook, &info2);

	AddressInfo info3 = { "小李", "111", 19, Man };
	AddressBookAdd(&addressbook, &info3);

	AddressBookPrint(&addressbook);
	AddressBookFindPrint(&addressbook, "小王");
	AddressBookDel(&addressbook, "小王");
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