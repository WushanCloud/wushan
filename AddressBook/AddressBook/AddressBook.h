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
	size_t _size;     // ��Ч���ݸ���
	size_t _capacity; // ����
}AddressBook;

void AddressBookInit(AddressBook* pbook);//��ʼ��
void ChackAddressBook(AddressBook * pbook);//���ռ��Ƿ�����

void AddressBookAdd(AddressBook* pbook, AddressInfo* pinfo);//��
void AddressBookDel(AddressBook* pbook, const char* name);//ɾ
void AddressBookFindPrint(AddressBook* pbook, const char* name);//�鵽�����
int AddressBookFindNum(AddressBook* pbook, const char* name);//�鵽�������
void AddressBookRevise(AddressBook* pbook, const char* name, const char* newname);//�������޸���Ϣ

void AddressBookSave(AddressBook* pbook, const char* filename);
void AddressBookLoad(AddressBook* pbook, const char* filename);
void AddressOnePrint(AddressBook* pbook, int i);//������ӡ
void AddressBookPrint(AddressBook* pbook);//��ӡ
void menu();


void AddFopen(char * p1);//д���ļ���
void readFILE();//���ļ�