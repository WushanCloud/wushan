#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

struct person//������Ϣ¼
{
    char name[8];//����
	char phone[11];//�绰
	char job[20];//��λ
	char number[11];//�ֻ�
	char type[5];//����
	char email[30];//EMAIL
	char qq[12];//QQ
	char addr[100];//סַ
};
int count=1;
struct person pe[100];

void shuru()//��Ϣ¼��
{
    system("color f0");
    int r;
    while (1)//ѭ������
    {
        printf("���������֣�");scanf("%s",pe[count].name);
        printf("�绰��");scanf("%s",pe[count].phone);
        printf("��λ��");scanf("%s",pe[count].job);
        printf("�ֻ���");scanf("%s",pe[count].number);
        printf("���ࣺ");scanf("%s",pe[count].type);
        printf("EMAIL��");scanf("%s",pe[count].email);
        printf("QQ��");scanf("%s",pe[count].qq);
        printf("סַ��");scanf("%s",pe[count].addr);
        printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",pe[count].name,pe[count].phone,pe[count].job,pe[count].number,pe[count].type,pe[count].email,pe[count].qq,pe[count].addr);
        count++;
        printf("��1�������룬��0����\n");
        scanf("%d",&r);
       if(r==1){system("cls");continue;}//����������ʱ����ѭ��
       else if (r==0)break;//�˳�ѭ��
       else printf("�������\n");system("pause");break;//������ʾ
    }
    system("cls");//��ҳ
    main();//�л���������
}

void shouye()//��ҳ
{
    system("color f0");
	printf("#################          ͨѶ¼����ϵͳ  v1.0   ###################\n");
	printf("#####################################################################\n");
	printf("#                                                                   #\n");
	printf("#           1-----------------��Ϣ¼��-------------------           #\n");
	printf("#                                                                   #\n");
	printf("#           2-----------------��Ϣ��ѯ-------------------           #\n");
	printf("#                                                                   #\n");
	printf("#           3-----------------��Ϣ�鿴-------------------           #\n");
	printf("#                                                                   #\n");
	printf("#           4-----------------��Ϣ�޸�-------------------           #\n");
	printf("#                                                                   #\n");
	printf("#           5-----------------�˳�ϵͳ-------------------           #\n");
	printf("#                                                                   #\n");
	printf("#                                                                   #\n");
	printf("#                                                                   #\n");
	printf("#####################################################################\n");
	printf("#                        �������̴�ѧ      2017��                   #\n");
	printf("#####################################################################\n");
}
void xingmingchaxun()//������ѯ
{
    system("color f0");
    int name0[8];
    int i;
    printf("������Ҫ��ѯ��������");
    scanf("%s",name0);
    for (i=0;i<count;i++)//���нṹ��������ѭ��

    {if (strcmp(name0,pe[i].name)==0)//�������������������һ����ͬʱִ����ʾ
    {
    HeadShow();//�������ͷ
    printf("%-10.8s %6.6s %10.10s %11.4s %9.7s %16.6s%16.6s%30.6 \n","����","�绰","��λ","�ֻ�","����","EMAIL","QQ","סַ");
	printf("-----------------------------------------------------------------------------\n");
	printf("%-10.8s %6.6s %10.10s %11.4s %9.7s %16.6s%16.6s%30.6\n",pe[i].name,pe[i].phone,pe[i].job,pe[i].number,pe[i].type,pe[i].email,pe[i].qq,pe[i].addr);
    break;//�ҵ��������˳�������Ч��
    }
    else if (i==count-1)printf ("���޴���\n");}//��û���ҵ�ʱ�˳�

    system("pause");//ҳ����ͣһ��
    system("cls");
    chaxunyemian();//�ص��ܲ�ѯҳ��
}

void dianhuachaxun()//�绰��ѯ
{
    system("color f0");
    int phone0[11];
    int i;
    printf("������Ҫ��ѯ�ĵ绰��");
    scanf("%s",phone0);
    for (i=0;i<count;i++)
    {
    if (strcmp(phone0,pe[i].phone)==0)
    {
    HeadShow();
    printf("%-10.8s %6.6s %10.10s %11.4s %9.7s %16.6s%16.6s%30.6 \n","����","�绰","��λ","�ֻ�","����","EMAIL","QQ","סַ");
	printf("-----------------------------------------------------------------------------\n");
	printf("%-10.8s %6.6s %10.10s %11.4s %9.7s %16.6s%16.6s%30.6\n",pe[i].name,pe[i].phone,pe[i].job,pe[i].number,pe[i].type,pe[i].email,pe[i].qq,pe[i].addr);
    break;
    }
    else if (i==count-1)printf ("���޴���\n");}

    system("pause");
    system("cls");
    chaxunyemian();
}

void chaxunyemian()//��Ϣ��ѯ
{
    system("color f0");
    int Check_key;
	printf("###################       ͨѶ¼����ϵͳ  v1.0   ####################\n");
	printf("#####################################################################\n");
	printf("#                                                                   #\n");
	printf("#                      1------��������ѯ                            #\n");
	printf("#                                                                   #\n");
	printf("#                      2------���绰�����ѯ                        #\n");
	printf("#                                                                   #\n");
	printf("#                      3------�˳���ѯģ��                            #\n");
	printf("#                                                                   #\n");
	printf("#                                                                   #\n");
	printf("#                                                                   #\n");
	printf("#                                                                   #\n");
	printf("#                                                                   #\n");
	printf("#####################################################################\n");
	printf("#                        �������̴�ѧ      2017��                   #\n");
	printf("#####################################################################\n");

	printf("�����������ţ�");
	scanf("%d",&Check_key);
	if (Check_key==1)
    {
        system("cls");
        xingmingchaxun();
    }
    else if(Check_key==2)
    {
        system("cls");
        dianhuachaxun();
    }
	else if (Check_key==3)
    {
        system("cls");
        main();
    }
}

void HeadShow()
{
    system("color f0");
	printf("#################          ͨѶ¼����ϵͳ  v1.0   ###################\n");
	printf("---------------------------------------------------------------------\n");

}
void AllShow()//��Ϣ�鿴
{
    system("color f0");//��ɫ
    int r,i;//����������ѭ������
	HeadShow();
    printf("%s  %s      %s              %s      %s  %s          %s      %s          \n","����","�绰","��λ","�ֻ�","����","EMAIL","QQ","סַ");
	printf("-----------------------------------------------------------------------------\n");
	for (i=0;i<count;i++)//���нṹ��������ѭ������ʾ���нṹ������
	{printf("%-10.8s %6.6s %10.10s %11.4s %9.7s %16.6s%16.6s%30.6\n",pe[i].name,pe[i].phone,pe[i].job,pe[i].number,pe[i].type,pe[i].email,pe[i].qq,pe[i].addr);
	}
	printf("��0�˳�");
    scanf("%d",&r);
    if (r==0)
    {system("cls");//�˳�
    main();}
    else printf("�������");
}

void xiugai()//��Ϣ�޸�
{
    system("color f0");
    int r;
    int j;
    char name9[8];
    printf("������Ҫ�޸ĵ���ϵ�ˣ�");
    scanf("%s",name9);
    for (j=0;j<count;j++)
    {
        if (strcmp(name9,pe[j].name)==0)//�ҵ�Ҫ�޸ĵ���ʱ����¼j����
        {
        printf("���������֣�");scanf("%s",pe[j].name);
        printf("�绰��");scanf("%s",pe[j].phone);
        printf("��λ��");scanf("%s",pe[j].job);
        printf("�ֻ���");scanf("%s",pe[j].number);
        printf("���ࣺ");scanf("%s",pe[j].type);
        printf("EMAIL��");scanf("%s",pe[j].email);
        printf("QQ��");scanf("%s",pe[j].qq);
        printf("סַ��");scanf("%s",pe[j].addr);
        }//�޸ĵ�j����ϵ�˵���Ϣ
    }
    if (j==count)printf("û������ˣ�");//û���ҵ�
        printf("��0����\n");//�˳�
        scanf("%d",&r);
        if (r==0)
            {
                system("cls");
                xinxixiugai();
            }
else printf("�������\n");
}

/*��Ϣɾ��*/
void Dle()
{
    system("color f0");
    int r;
    int j;
    int n;
    char name9[8];
    printf("������Ҫɾ������ϵ�ˣ�");
    scanf("%s",name9);
    for (j=0;j<count;j++)
    {
        if (strcmp(name9,pe[j].name)==0)//���ҵ�ʱ
        {
            n=j;//��¼��Ҫɾ����������ϵ�˵�λ��
        }
    }

    for (n;n<count;n++)
    {
        pe[n]=pe[n+1];//�ú�һ����ϵ�˵����鸲��ǰһ����
    }count--;//��������һ����֤����ռ����õĽ���
	printf("��0�˳�\n");//�˳�
    scanf("%d",&r);
    if (r==0)
    {system("cls");
    main();}
    else printf("�������");
}

void xinxixiugai()
{
    system("color f0");
int Check_key;
	printf("###################       ͨѶ¼����ϵͳ  v1.0   ####################\n");
	printf("#####################################################################\n");
	printf("#                                                                   #\n");
	printf("#                      1------��Ϣ�޸�                              #\n");
	printf("#                                                                   #\n");
	printf("#                      2------��Ϣɾ��                              #\n");
	printf("#                                                                   #\n");
	printf("#                      3------�˳��޸�ģ��                            #\n");
	printf("#                                                                   #\n");
	printf("#                                                                   #\n");
	printf("#                                                                   #\n");
	printf("#                                                                   #\n");
	printf("#                                                                   #\n");
	printf("#####################################################################\n");
	printf("#                        �������̴�ѧ      2017��                   #\n");
	printf("#####################################################################\n");

	printf("�����������ţ�");
	scanf("%d",&Check_key);
	if(Check_key==1)
    {
        system ("cls");
        xiugai();
    }
    else if (Check_key==2)
    {
        system ("cls");
        Dle();
    }
    else if (Check_key==3)
    {
        system ("cls");
        main();
    }
}
void weiye()//βҳ
{
    system("color f0");
 	printf("####################     ͨѶ¼����ϵͳ  v1.0   #####################\n");
	printf("#####################################################################\n");
	printf("#                                                                   #\n");
	printf("#                                                                   #\n");
	printf("#                                                                   #\n");
	printf("#                                                                   #\n");
	printf("#                                                                   #\n");
	printf("#                            ллʹ�ã�                             #\n");
	printf("#                                                                   #\n");
	printf("#                                                                   #\n");
	printf("#                                                                   #\n");
	printf("#                                                                   #\n");
	printf("#                                                                   #\n");
	printf("#####################################################################\n");
    printf("#                         �������̴�ѧ      2017��                  #\n");
    printf("#####################################################################\n");
}


void main()//����
{
    system("color f0");
    /*printf("\n");
	printf("---------------------------------------------------------------------\n");
	printf("\n");
	printf("\n");
	printf("             <<<<<<<<<<<<<<<<<<��ӭʹ��>>>>>>>>>>>>>>>>>>");
	printf("\n");
	printf("\n");
	printf("---------------------------------------------------------------------\n");
	Sleep(1000);
	system("cls");*/
	int key;
	shouye();
	printf("��������Ҫ�Ĳ���:");
	scanf("%d",&key);
	if(key==1)
    {
        system("cls");
        shuru();
    }else if(key==2)
	{
		system("cls");
		chaxunyemian();
	}
	else if(key==3)
    {
        system("cls");
        AllShow();
    }
    else if(key==4)
    {
        system("cls");
        xinxixiugai();
    }
	else if(key==5)
	{
		system("cls");
		weiye ();
	}

}
