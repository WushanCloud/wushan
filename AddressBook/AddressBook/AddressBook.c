#include "AddressBook.h"

void AddressBookInit(AddressBook* pbook)
{
	assert(pbook);
	pbook->_size = 0;
	pbook->_capacity = 2;
	pbook->_AIArray = (AddressInfo*)malloc(sizeof(AddressInfo) * 2);
	assert(pbook->_AIArray);
}

void AddressBookAdd(AddressBook* pbook, AddressInfo* pinfo)
{
	assert(pbook);

	if (pbook->_size == pbook->_capacity)
	{
		// 空间满了，进行扩容
		pbook->_AIArray = realloc(pbook->_AIArray, pbook->_capacity * 2 * sizeof(AddressInfo));
		pbook->_capacity *= 2;
	}
	//正常内存存储
	strcpy(pbook->_AIArray[pbook->_size]._name, pinfo->_name);
	strcpy(pbook->_AIArray[pbook->_size]._tel, pinfo->_tel);
	pbook->_AIArray[pbook->_size]._age = pinfo->_age;
	pbook->_AIArray[pbook->_size]._sex = pinfo->_sex;
	pbook->_size++;
}

void AddressBookSave(AddressBook* pbook, const char* filename)
{
	assert(pbook);
	FILE* fp = fopen(filename, "w");
	for (size_t i = 0; i < pbook->_size; ++i)
	{
		fwrite(&(pbook->_AIArray[i]), sizeof(AddressInfo), 1, fp);
	}
	AddressInfo end;
	end._age = -1;
	fwrite(&end, sizeof(AddressInfo), 1, fp);
}

void AddressBookLoad(AddressBook* pbook, const char* filename)
{
	assert(pbook);
	FILE* fp = fopen(filename, "r");
	AddressInfo info;

	while (1)
	{
		fread(&info, sizeof(AddressInfo), 1, fp);
		if (info._age == -1)
		{
			break;
		}
		else
		{
			AddressBookAdd(pbook, &info);
		}
	}
}

void AddressBookDel(AddressBook* pbook, const char* name)
{}

AddressInfo* AddressBookFind(AddressBook* pbook, const char* name)
{
	return NULL;
}

void AddressBookPrint(AddressBook* pbook)
{
	assert(pbook);

	for (size_t i = 0; i < pbook->_size; ++i)
	{
		//printf("======================================\n");
		printf("name:%s\n", pbook->_AIArray[i]._name);
		printf("tel:%s\n", pbook->_AIArray[i]._tel);
		printf("age:%d\n", pbook->_AIArray[i]._age);
		printf("sex:%d\n", pbook->_AIArray[i]._sex);
		//printf("======================================\n");
		printf("\n");

	}
}