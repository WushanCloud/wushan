#include <stdio.h>
#include <stdlib.h>

//ʵ�����N��쳲�������
//1 1 2 3 5 8 13 21

int febolaci1(int n)//ʹ�õݹ�ķ���
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

int febolaci2(int n)//�ǵݹ飬ѭ��д
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
    printf("����Ҫ��ĵ�N����\n");
    scanf("%d",&n);
    printf("%d",febolaci1(n));//�ݹ�
    printf("%d",febolaci2(n));//�ǵݹ�
    return 0;
}
