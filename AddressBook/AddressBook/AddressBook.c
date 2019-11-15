#include "AddressBook.h"

void AddressBookInit(AddressBook* pbook)//初始化一个通讯录
{
	assert(pbook);
	pbook->_size = 0;
	pbook->_capacity = 2;
	pbook->_AIArray = (AddressInfo*)malloc(sizeof(AddressInfo) * 2);
	assert(pbook->_AIArray);
}
void ChackAddressBook(AddressBook* pbook)//检查空间是否满了
{
	assert(pbook);
	if (pbook->_size == pbook->_capacity)
	{
		AddressInfo* newBook;
		newBook = (AddressInfo*)realloc(pbook->_AIArray, pbook->_capacity + 2 * sizeof(AddressInfo));
		if (newBook != NULL)
		{
			pbook->_AIArray = newBook;
			pbook->_capacity += 2;
			newBook = NULL;
		}
		else
		{
			printf("内存已满，无法存入更多信息！\n");
		}
	}
}
void AddressBookAdd(AddressBook* pbook, AddressInfo* pinfo)
{
	assert(pbook);

	ChackAddressBook(pbook);
	//正常内存存储
	if (pbook->_AIArray != NULL)
	{
		strcpy(pbook->_AIArray[pbook->_size]._name, pinfo->_name);
		strcpy(pbook->_AIArray[pbook->_size]._tel, pinfo->_tel);
		pbook->_AIArray[pbook->_size]._age = pinfo->_age;
		pbook->_AIArray[pbook->_size]._sex = pinfo->_sex;
		pbook->_size++;
	}
}
void AddressBookDel(AddressBook* pbook, const char* name)//删
{
	assert(pbook);
	if (AddressBookFindNum(pbook, name) != -1)//说明有这个人
	{
		for (size_t i = AddressBookFindNum(pbook, name); i < pbook->_size-1; i++)
		{
			pbook->_AIArray[i] = pbook->_AIArray[i + 1];
		}
		pbook->_size--;
	}
	else
	{
		printf("该用户不存在\n");
	}

}
int AddressBookFindNum(AddressBook* pbook, const char* name)//找
{
	assert(pbook);
	for (size_t i = 0; i < pbook->_size; i++)
	{
		if (strcmp(name, &(pbook->_AIArray[i])) == 0)
		{
			return i;//找到后返回位置
		}
	}
	return -1;//没找到返回-1
}
void AddressBookRevise(AddressBook* pbook, const char* name, const char* newname)
{
	assert(pbook);
	int num = AddressBookFindNum(pbook, name);
	if (num != -1)
	{
		;
	}
}
void AddressBookFindPrint(AddressBook* pbook, const char* name)//找
{
	assert(pbook);
	for (size_t i = 0; i < pbook->_size; i++)
	{
		if (strcmp(name, &(pbook->_AIArray[i])) == 0)
		{
			AddressOnePrint(pbook, i);
		}
		else
		{
			printf("该用户不存在\n");
		}
	}
	
}

void AddressBookSave(AddressBook* pbook, const char* filename)
{
	assert(pbook);
	FILE* fp = fopen(filename, "w+");
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
	FILE* fp = fopen(filename, "r+");
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
void AddressOnePrint(AddressBook* pbook, int i)
{
	printf("name:%s\n", pbook->_AIArray[i]._name);
	printf("tel:%s\n", pbook->_AIArray[i]._tel);
	printf("age:%d\n", pbook->_AIArray[i]._age);
	printf("sex:%d\n", pbook->_AIArray[i]._sex);
	printf("\n");
}

void AddressBookPrint(AddressBook* pbook)
{
	assert(pbook);

	for (size_t i = 0; i < pbook->_size; ++i)
	{
		AddressOnePrint(pbook, i);
	}
}
void menu()
{
	printf("1.显示联系人\n");
	printf("2.添加联系人\n");
	printf("3.修改联系人\n");
	printf("4.查询联系人\n");
	printf("5.删除联系人\n");

	printf("0.exit\n");
}

void AddFopen(char * p1)
{
	
	FILE* fp = NULL;
	fp = fopen("D:\\Git\\wushan\\AddressBook\\AddressBook\\test1.txt", "w+");
	fputs(p1, fp);
	fclose(fp);
}

void readFILE()
{
	char arr[100];
	FILE* fp = NULL;
	fp = fopen("D:\\Git\\wushan\\AddressBook\\AddressBook\\test1.txt", "r");
	fgets(arr, 100, fp);
	printf("%s\n", arr);
}
