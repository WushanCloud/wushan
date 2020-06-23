#include <iostream>
#include <queue>
#include <pthread.h>
#include <cstdio>

#define CAPACITY 4
#define PRODUCERCOUNT 2
#define CONSUMERCOUNT 2


template <class T>
class ProducerConsumer
{
    public:
        ProducerConsumer(size_t Capacity = CAPACITY)
        {
            Capacity_m = Capacity;
            // 初始化锁
            pthread_mutex_init(&mutex_m, NULL);
            // 初始化条件变量
            pthread_cond_init(&Producer_cond_m, NULL);
            pthread_cond_init(&Consumer_cond_m, NULL);
        }
        ~ProducerConsumer()
        {
            pthread_mutex_destroy(&mutex_m);
            pthread_cond_destroy(&Producer_cond_m);
            pthread_cond_destroy(&Consumer_cond_m);
        }

        // 生产者输入数据，通知消费者来消费数据
        void Push(T& data)
        {
            pthread_mutex_lock(&mutex_m);
            // 生产者在生产满时进入阻塞队列
            while(isFull())
            {
                pthread_cond_wait(&Producer_cond_m, &mutex_m);
            }
            data_m.push(data);
            pthread_mutex_unlock(&mutex_m);
            pthread_cond_signal(&Consumer_cond_m);
        }
        // 消费者取出数据
        void Pop(T* data)
        {
            pthread_mutex_lock(&mutex_m);
            // 消费者在有数据时进行消费，无数据时进入阻塞队列
            while(data_m.size() == 0)
            {
                pthread_cond_wait(&Consumer_cond_m, &mutex_m);
            }
            *data = data_m.front();
            data_m.pop();
            pthread_mutex_unlock(&mutex_m);
            pthread_cond_signal(&Producer_cond_m);
        }
    private:
        bool isFull()
        {
            if (data_m.size() == Capacity_m)
                return true;
            return false;
        }
    private:
        // 队列
        std::queue<T> data_m;
        // 队列最大容量
        size_t Capacity_m;
        // 互斥锁
        pthread_mutex_t mutex_m;
        // 条件变量
        pthread_cond_t Producer_cond_m;
        pthread_cond_t Consumer_cond_m;

};

void* Pro_start(void* arg)
{
    ProducerConsumer<int> * pc = (ProducerConsumer<int>*) arg;
    int data = 0;
    while(1)
    {
        pc->Push(data);
        std::cout << "i am Producer" << pthread_self() << ", i give " << data << std::endl;
        data++;
    }
    return NULL;
}
void* Con_start(void* arg)
{
    ProducerConsumer<int> * pc = (ProducerConsumer<int>*) arg;
    int data;
    while(1)
    {
        pc->Pop(&data);
        std::cout << "i am Consumer" << pthread_self() << ", i have " << data << std::endl;
    }
    return NULL;
}
int main()
{
    ProducerConsumer<int> *pc = new ProducerConsumer<int>;

    pthread_t* p_tid = new pthread_t[PRODUCERCOUNT];
    pthread_t* c_tid = new pthread_t[CONSUMERCOUNT];

    //创建生产者线程
    for(size_t i = 0; i < PRODUCERCOUNT; i++)
    {
        int ret = pthread_create(&p_tid[i], NULL, Pro_start, pc);
        if (ret < 0)
        {
            perror("pthread_create");
            return 0;
        }
    }

    // 创建消费者线程
    for(size_t i = 0; i < CONSUMERCOUNT; i++)
    {
        int ret = pthread_create(&c_tid[i], NULL, Con_start, pc);
        if (ret < 0)
        {
            perror("pthread_create");
            return 0;
        }
    }

    //分离生产者线程
    for(size_t i = 0; i < PRODUCERCOUNT; i++)
    {
        pthread_join(p_tid[i], NULL);
    }
    
    //分离消费者线程
    for(size_t i = 0; i < CONSUMERCOUNT; i++)
    {
        pthread_join(c_tid[i], NULL);
    }
    
    delete pc;
    pc = NULL;
    return 0;
}
