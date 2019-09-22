#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

#define MINENUM 80 //��ʼ10����
void menu()
{
    printf("***********************\n");
    printf("********1.Play*********\n");
    printf("********0.exit*********\n");
    printf("***********************\n");
}
//�ȴ���2������ 11*11 һ�����ף�һ�����׵���Ϣ
//��ʼ������
void InitBoard(char board[][COLS], int rows, int cols, char set)
{
    int i = 0;
    int j = 0;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            board[i][j] = set;
        }
    }
}
//��ӡ����
void ShowBoard(char board[][COLS], int rows, int cols)
{
    int i = 0;
    int j = 0;
    printf("====================\n");
    for (i = 0; i < rows-1; i++)
    {
        printf("%d ",i);//�б�ʶ
    }
    printf("\n");
    for (i = 1; i < rows-1; i++)//��ӡ�ڲ�
    {
        printf("%d ",i);//�б�ʶ
        for (j = 1; j < cols-1; j++)
        {
            printf("%c ",board[i][j]);
        }
        printf("\n");
    }
    printf("====================\n");

}
//������
void SetMine(char mine[][COLS], int row, int col)
{
    int count = MINENUM;//����
    int x = 0;
    int y = 0;
    while (count != 0)
    {
        x = rand()%row+1;
        y = rand()%col+1;
        if(mine[x][y] == '0')
        {
            mine[x][y] = '1';
            count--;
        }
    }

}

void FindMine(char mineInfo[][COLS], char mine[][COLS], int row, int col)//����
{
    int x = 0;
    int y = 0;
    int count = 0;
    while (count < row*col - MINENUM)//�´���<�հ״�
    {
        printf("������������꣺");
        scanf("%d%d",&x,&y);
        if(x >= 1 && x <= 9 && y >= 1 && y <= 9)
        {
            if(mine[x][y] == '1')
            {
                printf("�㱻ը����\n");
                break;
            }
            else if(mine[x][y] == '0')
            {
                //�ҵ��Ա�8��λ���м�����
                //����ǰλ����Ϊ����
                //count++
                int temp = 0;
                if(mine[x-1][y-1] == '1')
                    temp++;
                if(mine[x-1][y] == '1')
                    temp++;
                if(mine[x-1][y+1] == '1')
                    temp++;
                if(mine[x][y-1] == '1')
                    temp++;
                if(mine[x][y+1] == '1')
                    temp++;
                if(mine[x+1][y-1] == '1')
                    temp++;
                if(mine[x+1][y] == '1')
                    temp++;
                if(mine[x+1][y+1] == '1')
                    temp++;
                mineInfo[x][y] = '0'+ temp;

                count++;
            }
        }
        else
        {
            printf("���겻�Ϸ�\n");
        }
        ShowBoard(mineInfo,ROWS,COLS);
    }
    printf("��ϲ��Ӯ�ˣ�\n");
}

void Game()
{
    char mineInfo[ROWS][COLS];//����
    char mine[ROWS][COLS];//��

    InitBoard(mineInfo,ROWS,COLS,'*');//��ʼ��Ϊ*��
    InitBoard(mine,ROWS,COLS,'0');//��ʼ��Ϊ0

    ShowBoard(mineInfo,ROWS,COLS);//��ʾ����
    SetMine(mine,ROW,COL);//������
    ShowBoard(mine,ROWS,COLS);//��ʾ��
    FindMine(mineInfo,mine,ROW,COL);//����

}
int main()
{
    int key;
    srand( (unsigned int) time(NULL));//�������
    do
    {
        menu();
        printf("��������Ĳ�����");
        scanf("%d",&key);
        switch(key)
        {
            case 1:
                Game();
                break;
            case 0:
                break;
            default:
                break;
        }
    }while(key);

    return 0;
}
