#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#if 0
char str[10];
int index = 0;
void E();			//E->TX;
void X();			//X->+TX | e
void T();			//T->FY
void Y();			//Y->*FY | e
void F();			//F->(E) | i
int main()
{
	int len;
	int m;
	printf("������Ҫ���ԵĴ�����");
	scanf("%d", &m);
	while (m--)
	{
		printf("�������������ʽ��");
		scanf("%s", str);
		len = strlen(str);
		str[len] = '#';
		str[len + 1] = '\0';
		E();
		printf("��ȷ��䣡\n");
		strcpy(str, "");
		index = 0;
	}
	system("pause");
	return 0;
}
void E()
{
	T();
	X();
}
void X()
{
	if (str[index] == '+')
	{
		index++;
		T();
		X();
	}
}
void T()
{
	F();
	Y();
}
void Y()
{
	if (str[index] == '*')
	{
		index++;
		F();
		Y();
	}
}
void F()
{
	if (str[index] == 'i')
	{
		index++;
	}
	else if (str[index] == '(')
	{
		index++;
		E();
		if (str[index] == ')')
		{
			index++;
		}
		else {
			printf("\n����ʧ��!\n");
			exit(0);
		}
	}
	else {
		printf("����ʧ��!\n");
		exit(0);
	}
}
#endif