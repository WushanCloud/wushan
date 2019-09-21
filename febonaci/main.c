#include <stdio.h>
#include <stdlib.h>

//实现求第N个斐波那契数
//1 1 2 3 5 8 13 21

int febolaci1(int n)//使用递归的方法
{
    if(n == 1 || n == 2)
    {
        return 1;
    }
    else if(n > 2)
    {
        return febolaci1(n - 1) + febolaci1(n - 2);
    }
}

int febolaci2(int n)//非递归，循环写
{
    int f1 = 1;
    int f2 = 1;
    int f3 = 0;
    int i = 1;
    if(n == 1 || n == 2)
    {
        return 1;
    }
    else
    for (i = 3;i <= n; i++)
    {
        f3 = f1 + f2;
        f1 = f2;
        f2 = f3;
    }
    return f3;
}

int main()
{
    int n=0;
    printf("输入要求的第N个数\n");
    scanf("%d",&n);
    printf("%d",febolaci1(n));//递归
    printf("%d",febolaci2(n));//非递归
    return 0;
}
