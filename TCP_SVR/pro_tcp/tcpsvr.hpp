#include <iostream>
#include <cstdio>
#include <unistd.h>
#include <cstdlib>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string>
#include <cstring>

class TcpSvr
{
public:
    TcpSvr()
    {
        sockfd_ = -1;
    }
    ~TcpSvr()
    {

    }
    // 创建套接字
    bool CreateSocket()
    {
        sockfd_ = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        if (sockfd_ < 0)
        {
            perror("socket");
            return false;
        }
        return true;
    }

    // 绑定地址信息
    bool Bind(std::string& ip, uint16_t port)
    {
        // 组织地址信息
        struct sockaddr_in addr;
        addr.sin_family = AF_INET;
        addr.sin_addr.s_addr = inet_addr(ip.c_str());
        addr.sin_port = htons(port);

        int ret = bind(sockfd_, (struct sockaddr*)&addr, sizeof(addr));
        if (ret < 0)
        {
            perror("bind");
            return false;
        }
        return true;
    }

    // 监听接口
    bool Listen(int backlog = 5)
    {
        int ret = listen(sockfd_, backlog);
        if (ret < 0)
        {
            perror("listen");
            return false;
        }
        return true;
    }

    // 获取连接
    bool Accept(struct sockaddr_in* peeraddr, TcpSvr* ts)
    {
        socklen_t socklen = sizeof(struct sockaddr_in);
        int serverfd = accept(sockfd_,(struct sockaddr*)peeraddr, &socklen);
        if (serverfd < 0)
        {
            perror("accept");
            return false;
        }
        ts->sockfd_ = serverfd;
        return true;
    }

    // 发起连接
    bool Connect(std::string& ip, uint16_t port)
    {
        struct sockaddr_in addr;
        addr.sin_family = AF_INET;
        addr.sin_addr.s_addr = inet_addr(ip.c_str());
        addr.sin_port = htons(port);

        int ret = connect(sockfd_, (struct sockaddr*)&addr, sizeof(addr));
        if (ret < 0)
        {
            perror("connect");
            return false;
        }
        return true;
    }
    
    // 发送数据
    bool Send(std::string& data)
    {
        int sendsize = send(sockfd_, data.c_str(), data.size(), 0);
        if (sendsize < 0)
        {
            perror("send");
            return false;
        }
        return true;
    }
    
    // 接受数据
    bool Recv(std::string& data)
    {
        char buf[1024];
        memset(buf, '\0', sizeof(buf));
        int recvsize = recv(sockfd_, buf, sizeof(buf)-1, 0);
        if (recvsize < 0)
        {
            perror("recv");
            return false;
        }
        else if (recvsize == 0)
        {
            printf("peer shutdown !!!\n");
            return false;
        }
        data = buf;
        return true;
    }
    
    // 关闭套接字
    void Close()
    {
        close(sockfd_);
        sockfd_ = -1;
    }

private:
    int sockfd_;
};
