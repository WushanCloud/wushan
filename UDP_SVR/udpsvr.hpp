#pragma once
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

class UdpSvr
{
public:
    UdpSvr()
    {
        sock_ = -1;
    }
    
    ~UdpSvr()
    {

    }
    
    //1.Socket 创建socket套接字描述符
    bool CreateSocket()
    {
        //socket 创建 （使用IPv4, 数据包类型套接字，UDP协议）;
        sock_ = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
        if (sock_ < 0)
        {
            perror("socket");
            return false;
        }
        return true;
    }

    //2.Bind 绑定地址信息
    bool Bind(std::string& ip, uint16_t port)
    {
        struct sockaddr_in addr;
        // 地址域，按ipv4地址解析
        addr.sin_family = AF_INET;
        // 填充端口
        addr.sin_port = htons(port);
        // 填充ip地址
        addr.sin_addr.s_addr = inet_addr(ip.c_str()); // inet_addr 1.将点分十进制的ip转换为uint_32  2.将主机字节序转换为网络字节序。

        // 绑定地址信息 （套接字描述符，地址信息，地址信息长度）
        int ret =  bind(sock_, (struct sockaddr*)&addr, sizeof(addr));
        if (ret < 0)
        {
            perror("bind");
            return false;
        }
        return true;
    }
    
    //3.Send 发送数据  (要发送的数据， 目的地址)
    bool Send(std::string& data, struct sockaddr_in* dest_addr)
    {
        // 发送接口 （套接字描述符，发送的数据，发送的大小，阻塞发送，目的地址，地址信息长度）
        int SendSize = sendto(sock_, data.c_str(), data.size(), 0, (struct sockaddr*)dest_addr, sizeof(struct sockaddr_in));
        // 返回值
        if (SendSize < 0)
        {
            perror("sendto");
            return false;
        }
        return true;
    }

    //4.Recv 接收数据  ((出参)要接收的数据，数据来源的地址)
    bool Recv(std::string* buf, struct sockaddr_in* src_addr)
    {
        char tmp[1024];
        memset(tmp, '\0', sizeof(tmp));
        socklen_t socklen = sizeof(struct sockaddr_in);
        // 接收接口 （socket描述符，接收位置，可接受大小，阻塞接收，源地址，原地址大小）
        ssize_t RecvSize = recvfrom(sock_, tmp, sizeof(tmp)-1, 0, (struct sockaddr*)src_addr, &socklen);
        if (RecvSize < 0)
        {
            perror("recvfrom");
            return false;
        }
        (*buf).assign(tmp, RecvSize);
        return true;
    }

    //5.Close 关闭socket描述符
    void Close()
    {
        close(sock_);
        sock_ = -1;
    }
private:    
    int sock_;      // socket描述符操作句柄
};
