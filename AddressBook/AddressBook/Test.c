#include "AddressBook.h"

void TestAddressBook()
{
	AddressBook addressbook;//创建一个通讯录；
	AddressBookInit(&addressbook);
	//AddressInfo info1 = {"高博", "110", 18, Man};
	//AddressBookAdd(&addressbook, &info1);

	//AddressInfo info2 = { "小王", "111", 19, Man };
	//AddressBookAdd(&addressbook, &info2);

	//AddressInfo info3 = { "小李", "111", 19, Man };
	//AddressBookAdd(&addressbook, &info3);
	/*AddressBookSave(&addressbook, "addressfile.bin");
	AddressBookPrint(&addressbook);*/

	AddressBookLoad(&addressbook, "addressfile.bin");
	AddressBookPrint(&addressbook);
}

int main()
{
	menu();
	TestAddressBook();

	return 0;
}