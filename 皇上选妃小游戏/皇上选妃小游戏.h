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
	string wushan_concubine_class = "��";//�ȼ�
	int wushan_concubine_favorability = 100;//�øж�
	bool wushan_concubine_active = false;//�Ƿ��Ծ
}Concubine;
//Concubine* emperor_harem;
Concubine* emperor_harem = new Concubine[N];

string concubine_class[] = {//�ȼ�
	"����","�滪","�ݻ�","����","����","����","�ʹ���","�ʺ�"
};
string concubine_name[] = {//��ʼ����
	"���Ľ�","������","����ӱ","����","�ɹ�"
};
int dates[4] = { 1,1,1,1 };//��Ϸʱ�䣬������������
//��������
//�޸����ӵȼ�
//�����乬
//��������

bool emperor_harem_initialize(int * count);//�󹬳�ʼ��
void data_count();//ʱ�������
void data_read();//��ȡ��Ϸʱ��

void menu();//�˵�
bool increaseConcubine(int* count);//����
bool modificationConcubine();//�޸�
bool deleteConcubine();//ɾ��
bool seekConcubine();//��
void emperor_harem_print(int count);//���
