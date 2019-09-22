#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

#define MINENUM 80 //初始10格雷
void menu()
{
    printf("***********************\n");
    printf("********1.Play*********\n");
    printf("********0.exit*********\n");
    printf("***********************\n");
}
//先创建2个数组 11*11 一个存雷，一个存雷的信息
//初始化棋盘
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
//打印棋盘
void ShowBoard(char board[][COLS], int rows, int cols)
{
    int i = 0;
    int j = 0;
    printf("====================\n");
    for (i = 0; i < rows-1; i++)
    {
        printf("%d ",i);//行标识
    }
    printf("\n");
    for (i = 1; i < rows-1; i++)//打印内层
    {
        printf("%d ",i);//列标识
        for (j = 1; j < cols-1; j++)
        {
            printf("%c ",board[i][j]);
        }
        printf("\n");
    }
    printf("====================\n");

}
//设置雷
void SetMine(char mine[][COLS], int row, int col)
{
    int count = MINENUM;//雷数
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

void FindMine(char mineInfo[][COLS], char mine[][COLS], int row, int col)//找雷
{
    int x = 0;
    int y = 0;
    int count = 0;
    while (count < row*col - MINENUM)//猜次数<空白处
    {
        printf("请输入你的坐标：");
        scanf("%d%d",&x,&y);
        if(x >= 1 && x <= 9 && y >= 1 && y <= 9)
        {
            if(mine[x][y] == '1')
            {
                printf("你被炸死了\n");
                break;
            }
            else if(mine[x][y] == '0')
            {
                //找到旁边8个位置有几个雷
                //将当前位置置为雷数
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
            printf("坐标不合法\n");
        }
        ShowBoard(mineInfo,ROWS,COLS);
    }
    printf("恭喜你赢了！\n");
}

void Game()
{
    char mineInfo[ROWS][COLS];//棋盘
    char mine[ROWS][COLS];//雷

    InitBoard(mineInfo,ROWS,COLS,'*');//初始化为*号
    InitBoard(mine,ROWS,COLS,'0');//初始化为0

    ShowBoard(mineInfo,ROWS,COLS);//显示棋盘
    SetMine(mine,ROW,COL);//设置雷
    ShowBoard(mine,ROWS,COLS);//显示雷
    FindMine(mineInfo,mine,ROW,COL);//找雷

}
int main()
{
    int key;
    srand( (unsigned int) time(NULL));//随机种子
    do
    {
        menu();
        printf("请输入你的操作：");
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
