#pragma once

#include <iostream>
#include <cstdio>
#include <cstring>
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
using namespace std;

#define N 15 //��ӵ����������
typedef struct Concubine
{
	string wushan_concubine_name = "��";//����
	string wushan_concubine_class;//�ȼ�
	int wushan_concubine_favorability;//�øж�
	bool wushan_concubine_active = false;//�Ƿ��Ծ
}Concubine;
//Concubine* emperor_harem;
Concubine* emperor_harem = new Concubine[N];

string concubine_class[] = {//�ȼ�
	"����","�滪","�ݻ�","����","����","����","�ʹ���"
};
//��������
//�޸����ӵȼ�
//�����乬
//��������

bool emperor_harem_initialize();//�󹬳�ʼ��

void menu();//�˵�
bool increaseConcubine(int* count);//����
bool modificationConcubine();//�޸�
bool deleteConcubine();//ɾ��
bool seekConcubine();//��
void emperor_harem_print(int count);//���
