#include "tcpsvr.hpp"

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        printf("No cli [ip] [port]\n");
        return 0;
    }
    std::string ip = argv[1];
    uint16_t port = atoi(argv[2]);

    TcpSvr ts;
    if (!ts.CreateSocket())
    {
        return 0;
    }
    if (!ts.Connect(ip, port))
    {
        return 0;
    }
    
    // 收发数据
    while(true)
    {
        std::cout << "you say: ";
        fflush(stdout);
        std::string buf;
        std::cin >> buf;
        ts.Send(buf);
        ts.Recv(buf);
        std::cout << "svr say: " << buf << std::endl;
    }
    ts.Close();
    return 0;
}
