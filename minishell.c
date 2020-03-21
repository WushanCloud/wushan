#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <malloc.h>

int main()
{
    //先创建一个子进程，让子进程去进行进程替换
    
    while (1)
    {
    printf("dafei:$");
    fflush(stdout);
    int i = 0,j = 0;//个数
    char *arr[100];//命令

    arr[0] = (char *)malloc(sizeof(char) * 100);
    memset(arr[0],0,100);
    char c;
    //while((c = getchar())&& c == ' ');
    while((c = getchar())&& c != '\n')
    {
        if(c == ' ')
        {
            i++;
            j = 0;
            arr[i] = (char *)malloc(sizeof(char) * 100);
            memset(arr[i],0,100);
        }
        else 
        {
            arr[i][j++] = c;
         }
    }
    arr[++i] = NULL;
    int k;
    for( k = 0; k< i;k++)
    {
        printf("%s ",arr[k]);
    }

    pid_t ret = fork();

    if(ret < 0)
    {
        perror("error\n");
    }
    else if (ret == 0)
    {
        //子
        if(arr[0] == NULL)
            return 0;
        
        execvp(arr[0],arr);
        
    }
    else 
    {
        waitpid(ret, NULL, 0);
        printf("dafei:$");

    }
    }
    return 0;

}
