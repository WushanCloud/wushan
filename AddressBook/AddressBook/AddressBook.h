#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

enum SEX
{
	Man,
	Woman,
};

typedef struct AddressInfo
{
	char _name[24];
	char _tel[24];
	int  _age;
	enum SEX  _sex;
}AddressInfo;

//#define MAX_SIZE  10000

typedef struct AddressBook
{
	AddressInfo* _AIArray;
	size_t _size;     // 有效数据个数
	size_t _capacity; // 容量
}AddressBook;

void AddressBookInit(AddressBook* pbook);//初始化
void ChackAddressBook(AddressBook * pbook);//检查空间是否满了

void AddressBookAdd(AddressBook* pbook, AddressInfo* pinfo);//增
void AddressBookDel(AddressBook* pbook, const char* name);//删
void AddressBookFindPrint(AddressBook* pbook, const char* name);//查到并输出
int AddressBookFindNum(AddressBook* pbook, const char* name);//查到返回序号
void AddressBookRevise(AddressBook* pbook, const char* name, const char* newname);//按名字修改信息

void AddressBookSave(AddressBook* pbook, const char* filename);
void AddressBookLoad(AddressBook* pbook, const char* filename);
void AddressOnePrint(AddressBook* pbook, int i);//单个打印
void AddressBookPrint(AddressBook* pbook);//打印
void menu();


void AddFopen(char * p1);//写入文件；
void readFILE();//读文件