#include "AddressBook.h"

void TestAddressBook()
{
	AddressBook addressbook;//����һ��ͨѶ¼��
	AddressBookInit(&addressbook);
	//AddressInfo info1 = {"�߲�", "110", 18, Man};
	//AddressBookAdd(&addressbook, &info1);

	//AddressInfo info2 = { "С��", "111", 19, Man };
	//AddressBookAdd(&addressbook, &info2);

	//AddressInfo info3 = { "С��", "111", 19, Man };
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