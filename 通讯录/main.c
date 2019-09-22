#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

struct person//个人信息录
{
    char name[8];//名字
	char phone[11];//电话
	char job[20];//单位
	char number[11];//手机
	char type[5];//分类
	char email[30];//EMAIL
	char qq[12];//QQ
	char addr[100];//住址
};
int count=1;
struct person pe[100];

void shuru()//信息录入
{
    system("color f0");
    int r;
    while (1)//循环输入
    {
        printf("请输入名字：");scanf("%s",pe[count].name);
        printf("电话：");scanf("%s",pe[count].phone);
        printf("单位：");scanf("%s",pe[count].job);
        printf("手机：");scanf("%s",pe[count].number);
        printf("分类：");scanf("%s",pe[count].type);
        printf("EMAIL：");scanf("%s",pe[count].email);
        printf("QQ：");scanf("%s",pe[count].qq);
        printf("住址：");scanf("%s",pe[count].addr);
        printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",pe[count].name,pe[count].phone,pe[count].job,pe[count].number,pe[count].type,pe[count].email,pe[count].qq,pe[count].addr);
        count++;
        printf("按1继续输入，按0结束\n");
        scanf("%d",&r);
       if(r==1){system("cls");continue;}//当条件满足时继续循环
       else if (r==0)break;//退出循环
       else printf("输入错误！\n");system("pause");break;//错误提示
    }
    system("cls");//换页
    main();//切换到主函数
}

void shouye()//首页
{
    system("color f0");
	printf("#################          通讯录管理系统  v1.0   ###################\n");
	printf("#####################################################################\n");
	printf("#                                                                   #\n");
	printf("#           1-----------------信息录入-------------------           #\n");
	printf("#                                                                   #\n");
	printf("#           2-----------------信息查询-------------------           #\n");
	printf("#                                                                   #\n");
	printf("#           3-----------------信息查看-------------------           #\n");
	printf("#                                                                   #\n");
	printf("#           4-----------------信息修改-------------------           #\n");
	printf("#                                                                   #\n");
	printf("#           5-----------------退出系统-------------------           #\n");
	printf("#                                                                   #\n");
	printf("#                                                                   #\n");
	printf("#                                                                   #\n");
	printf("#####################################################################\n");
	printf("#                        西安工程大学      2017级                   #\n");
	printf("#####################################################################\n");
}
void xingmingchaxun()//姓名查询
{
    system("color f0");
    int name0[8];
    int i;
    printf("请输入要查询的姓名：");
    scanf("%s",name0);
    for (i=0;i<count;i++)//进行结构体数量的循环

    {if (strcmp(name0,pe[i].name)==0)//当输入的名字与数组中一项相同时执行显示
    {
    HeadShow();//美化框架头
    printf("%-10.8s %6.6s %10.10s %11.4s %9.7s %16.6s%16.6s%30.6 \n","姓名","电话","单位","手机","分类","EMAIL","QQ","住址");
	printf("-----------------------------------------------------------------------------\n");
	printf("%-10.8s %6.6s %10.10s %11.4s %9.7s %16.6s%16.6s%30.6\n",pe[i].name,pe[i].phone,pe[i].job,pe[i].number,pe[i].type,pe[i].email,pe[i].qq,pe[i].addr);
    break;//找到后立即退出，提升效率
    }
    else if (i==count-1)printf ("查无此人\n");}//当没有找到时退出

    system("pause");//页面暂停一下
    system("cls");
    chaxunyemian();//回到总查询页面
}

void dianhuachaxun()//电话查询
{
    system("color f0");
    int phone0[11];
    int i;
    printf("请输入要查询的电话：");
    scanf("%s",phone0);
    for (i=0;i<count;i++)
    {
    if (strcmp(phone0,pe[i].phone)==0)
    {
    HeadShow();
    printf("%-10.8s %6.6s %10.10s %11.4s %9.7s %16.6s%16.6s%30.6 \n","姓名","电话","单位","手机","分类","EMAIL","QQ","住址");
	printf("-----------------------------------------------------------------------------\n");
	printf("%-10.8s %6.6s %10.10s %11.4s %9.7s %16.6s%16.6s%30.6\n",pe[i].name,pe[i].phone,pe[i].job,pe[i].number,pe[i].type,pe[i].email,pe[i].qq,pe[i].addr);
    break;
    }
    else if (i==count-1)printf ("查无此人\n");}

    system("pause");
    system("cls");
    chaxunyemian();
}

void chaxunyemian()//信息查询
{
    system("color f0");
    int Check_key;
	printf("###################       通讯录管理系统  v1.0   ####################\n");
	printf("#####################################################################\n");
	printf("#                                                                   #\n");
	printf("#                      1------按姓名查询                            #\n");
	printf("#                                                                   #\n");
	printf("#                      2------按电话号码查询                        #\n");
	printf("#                                                                   #\n");
	printf("#                      3------退出查询模块                            #\n");
	printf("#                                                                   #\n");
	printf("#                                                                   #\n");
	printf("#                                                                   #\n");
	printf("#                                                                   #\n");
	printf("#                                                                   #\n");
	printf("#####################################################################\n");
	printf("#                        西安工程大学      2017级                   #\n");
	printf("#####################################################################\n");

	printf("请输入操作序号：");
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
	printf("#################          通讯录管理系统  v1.0   ###################\n");
	printf("---------------------------------------------------------------------\n");

}
void AllShow()//信息查看
{
    system("color f0");//颜色
    int r,i;//条件变量，循环变量
	HeadShow();
    printf("%s  %s      %s              %s      %s  %s          %s      %s          \n","姓名","电话","单位","手机","分类","EMAIL","QQ","住址");
	printf("-----------------------------------------------------------------------------\n");
	for (i=0;i<count;i++)//进行结构体数量的循环，显示所有结构体数组
	{printf("%-10.8s %6.6s %10.10s %11.4s %9.7s %16.6s%16.6s%30.6\n",pe[i].name,pe[i].phone,pe[i].job,pe[i].number,pe[i].type,pe[i].email,pe[i].qq,pe[i].addr);
	}
	printf("按0退出");
    scanf("%d",&r);
    if (r==0)
    {system("cls");//退出
    main();}
    else printf("输入错误！");
}

void xiugai()//信息修改
{
    system("color f0");
    int r;
    int j;
    char name9[8];
    printf("请输入要修改的联系人：");
    scanf("%s",name9);
    for (j=0;j<count;j++)
    {
        if (strcmp(name9,pe[j].name)==0)//找到要修改的人时，记录j的数
        {
        printf("请输入名字：");scanf("%s",pe[j].name);
        printf("电话：");scanf("%s",pe[j].phone);
        printf("单位：");scanf("%s",pe[j].job);
        printf("手机：");scanf("%s",pe[j].number);
        printf("分类：");scanf("%s",pe[j].type);
        printf("EMAIL：");scanf("%s",pe[j].email);
        printf("QQ：");scanf("%s",pe[j].qq);
        printf("住址：");scanf("%s",pe[j].addr);
        }//修改第j个联系人的信息
    }
    if (j==count)printf("没有这个人！");//没有找到
        printf("按0结束\n");//退出
        scanf("%d",&r);
        if (r==0)
            {
                system("cls");
                xinxixiugai();
            }
else printf("输入错误！\n");
}

/*信息删除*/
void Dle()
{
    system("color f0");
    int r;
    int j;
    int n;
    char name9[8];
    printf("请输入要删除的联系人：");
    scanf("%s",name9);
    for (j=0;j<count;j++)
    {
        if (strcmp(name9,pe[j].name)==0)//当找到时
        {
            n=j;//记录下要删除的这人联系人的位置
        }
    }

    for (n;n<count;n++)
    {
        pe[n]=pe[n+1];//用后一个联系人的数组覆盖前一个人
    }count--;//数组数减一，保证数组空间运用的紧凑
	printf("按0退出\n");//退出
    scanf("%d",&r);
    if (r==0)
    {system("cls");
    main();}
    else printf("输入错误！");
}

void xinxixiugai()
{
    system("color f0");
int Check_key;
	printf("###################       通讯录管理系统  v1.0   ####################\n");
	printf("#####################################################################\n");
	printf("#                                                                   #\n");
	printf("#                      1------信息修改                              #\n");
	printf("#                                                                   #\n");
	printf("#                      2------信息删除                              #\n");
	printf("#                                                                   #\n");
	printf("#                      3------退出修改模块                            #\n");
	printf("#                                                                   #\n");
	printf("#                                                                   #\n");
	printf("#                                                                   #\n");
	printf("#                                                                   #\n");
	printf("#                                                                   #\n");
	printf("#####################################################################\n");
	printf("#                        西安工程大学      2017级                   #\n");
	printf("#####################################################################\n");

	printf("请输入操作序号：");
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
void weiye()//尾页
{
    system("color f0");
 	printf("####################     通讯录管理系统  v1.0   #####################\n");
	printf("#####################################################################\n");
	printf("#                                                                   #\n");
	printf("#                                                                   #\n");
	printf("#                                                                   #\n");
	printf("#                                                                   #\n");
	printf("#                                                                   #\n");
	printf("#                            谢谢使用！                             #\n");
	printf("#                                                                   #\n");
	printf("#                                                                   #\n");
	printf("#                                                                   #\n");
	printf("#                                                                   #\n");
	printf("#                                                                   #\n");
	printf("#####################################################################\n");
    printf("#                         西安工程大学      2017级                  #\n");
    printf("#####################################################################\n");
}


void main()//主体
{
    system("color f0");
    /*printf("\n");
	printf("---------------------------------------------------------------------\n");
	printf("\n");
	printf("\n");
	printf("             <<<<<<<<<<<<<<<<<<欢迎使用>>>>>>>>>>>>>>>>>>");
	printf("\n");
	printf("\n");
	printf("---------------------------------------------------------------------\n");
	Sleep(1000);
	system("cls");*/
	int key;
	shouye();
	printf("请输入需要的操作:");
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
