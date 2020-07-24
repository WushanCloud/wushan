#include "tcpsvr.hpp"
#include <signal.h>
#include <sys/wait.h>

void sigcb(int signo)
{
        (void)signo;
            while(1)
            {
                        waitpid(-1, NULL, WNOHANG);
                            
            }

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
    
    signal(SIGCHLD, sigcb);

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
        TcpSvr newts;
        struct sockaddr_in addr;
        if (!ts.Accept(&addr, &newts))
        {
            continue;
        }
        int pid = fork();
        if (pid < 0)
        {
            perror("fork");
            return 0;
        }
        else if(pid == 0)
        {
            while(1)
            {
                std::string buf;
                newts.Recv(buf);
                printf("client did say: %s\n", buf.c_str());
                printf("please return msg to client:");
                fflush(stdout);
                std::cin >> buf;
                newts.Send(buf);

            }
            newts.Close();
            exit(1);
                                                        
        }
        else
        {
            newts.Close();                            
        }            
    }
    return 0;
}
