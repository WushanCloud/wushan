#include "udpsvr.hpp"

int main(int argc, char* argv[])
{
    // ./svr [ip] [port]
    if (argc != 3)
    {
        printf("NO ./svr [ip] [port]\n");
        return 0;
    }
    std::string ip = argv[1];
    uint16_t port = atoi(argv[2]);

    UdpSvr us;
    if(!us.CreateSocket())
    {
        return 0;
    }
    if(!us.Bind(ip, port))
    {
        return 0;
    }
    
    // 收发数据
    while (true)
    {
        // 接收数据
        std::string buf;
        struct sockaddr_in peeraddr;// 对端地址信息
        us.Recv(&buf, &peeraddr);

        std::cout << "cli say: " << buf << std::endl;
        // 发送数据
        std::cout << "you say: ";
        std::cin >> buf;
        us.Send(buf, &peeraddr);
    }
    us.Close();

    return 0;
}
