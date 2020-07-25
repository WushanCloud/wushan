#include "tcpsvr.hpp"
#include <pthread.h>
#include <sys/wait.h>

void* ThreadStart(void* argv)
{
    pthread_detach(pthread_self());
    TcpSvr* ts = (TcpSvr*)argv;
    while(1)
    {
        std::string buf;
        ts->Recv(buf);
        printf("cli say: %s\n", buf.c_str());
        printf("you say: ");
        fflush(stdout);
        std::cin >> buf;
        ts->Send(buf);
    }
    delete ts;
    ts->Close();
}

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        printf("No ./svr_pro [ip] [port]\n");
        return 0;
    }
    
    std::string ip = argv[1];
    uint16_t port = atoi(argv[2]);
    

    TcpSvr ts;
    if (!ts.CreateSocket())
    {
        return 0;
    }
    if (!ts.Bind(ip, port))
    {
        return 0;
    }
    if (!ts.Listen())
    {
        return 0;
    }
    while (1)
    {
        TcpSvr* newts = new TcpSvr();
        struct sockaddr_in addr;
        if (!ts.Accept(&addr, newts))
        {
            continue;
        }

        pthread_t tid;
        int ret = pthread_create(&tid, NULL, ThreadStart, (void*)newts);
        if (ret < 0)
        {
            perror("pthread_create");
            return 0;
        }
        
    }
    return 0;
}
