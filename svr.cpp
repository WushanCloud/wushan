#include "tcpsvr.hpp"

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        printf("No svr [ip] [port]\n");
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

    TcpSvr svr_ts;
    struct sockaddr_in cli_addr;
        if (!ts.Accept(&cli_addr, &svr_ts))
        {
            return 0;
        }
    while (true)
    {

        std::string buf;
        svr_ts.Recv(buf);
        std::cout << "cli say: " << buf << std::endl;

        std::cout << "you say: " ;
        fflush(stdout);
        std::cin >> buf;
        svr_ts.Send(buf);
    }
    
    svr_ts.Close();
    ts.Close();
    
    return 0;
}
