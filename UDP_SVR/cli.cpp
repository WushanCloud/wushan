#include "udpsvr.hpp"

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        std::cout << "No ./cli [ip] [port]" << std::endl;
        return 0;
    }
    std::string svr_ip = argv[1];
    uint16_t svr_port = atoi(argv[2]);
    
    UdpSvr us;
    if (!us.CreateSocket())
    {
        return 0;
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(svr_port);
    addr.sin_addr.s_addr = inet_addr(svr_ip.c_str());

    struct sockaddr_in peeraddr;

    while (true)
    {
        // 发送数据
        std::cout << "you say: ";
        std::string buf;
        std::cin >> buf;
        us.Send(buf, &addr);         
        // 接收数据
        us.Recv(&buf, &peeraddr);
        std::cout << "svr say: " << buf << std::endl;
    }
    us.Close();
    return 0;
}
