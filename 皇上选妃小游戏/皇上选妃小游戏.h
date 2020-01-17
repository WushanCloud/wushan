#pragma once

#include <iostream>
#include <cstdio>
#include <cstring>
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
using namespace std;

#define N 15 //共拥有妃子上限
typedef struct Concubine
{
	string wushan_concubine_name = "无";//姓名
	string wushan_concubine_class;//等级
	int wushan_concubine_favorability;//好感度
	bool wushan_concubine_active = false;//是否活跃
}Concubine;
//Concubine* emperor_harem;
Concubine* emperor_harem = new Concubine[N];

string concubine_class[] = {//等级
	"贵人","舒华","容华","贵嫔","淑仪","贵妃","皇贵妃"
};
//增加妃子
//修改妃子等级
//打入冷宫
//查找妃子

bool emperor_harem_initialize();//后宫初始化

void menu();//菜单
bool increaseConcubine(int* count);//增加
bool modificationConcubine();//修改
bool deleteConcubine();//删除
bool seekConcubine();//找
void emperor_harem_print(int count);//输出
