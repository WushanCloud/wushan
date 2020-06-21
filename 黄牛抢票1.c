#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/syscall.h>
#define MAXTHREAD 4

pthread_mutex_t lock;

//总票数
int g_val = 100;

void* main_thread(void* arg)
{
    while(1)
    {
        pthread_mutex_lock(&lock);
        if (g_val > 0)
        {
            g_val--;
            printf("i am %p, i have num is %d\n", pthread_self(), g_val+1);
            sleep(1);
        }
        else
        {
            pthread_mutex_unlock(&lock);
            break;
        }
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

int main()
{
    //保存线程标识符的数组
    pthread_t addr[MAXTHREAD];
    
    //初始化锁
    pthread_mutex_init(&lock, NULL);

    //创建线程对临界值进行操作
    int i;
    for (i = 0; i < MAXTHREAD; i++)
    {
       int ret = pthread_create(&addr[i], NULL, main_thread, NULL); 
       if(ret < 0)
       {
           perror("pthread_create");
           return 0;
       }
    }
    
    for (i = 0; i < MAXTHREAD; i++)
    {
        pthread_join(addr[i], NULL);
    }

    //释放锁资源
    pthread_mutex_destroy(&lock);

    return 0;
}
