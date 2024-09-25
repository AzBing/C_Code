#pragma once

#include "Log.hpp"
#include <iostream>
#include <string>
#include <string.h>
#include <strings.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <functional>

typedef std::function<std::string(const std::string&)> func_t;

extern Log lg;
enum
{
    SOCKET_ERR = 1,
    BIND_ERR
};
uint16_t defaultport = 8080;
std::string defaultip = "0.0.0.0";
const int size = 1024;

class Udpserver
{
public:
    Udpserver(const uint16_t &port = defaultport, const std::string &ip = defaultip)
        : sockfd_(0),
          port_(port), ip_(ip), isruning_(false)
    {
    }
    void Init()
    {
        // 1.创建udp socket
        sockfd_ = socket(AF_INET, SOCK_DGRAM, 0);
        if (sockfd_ < 0)
        {
            lg(Fatal, "socket create error, sockfd: %d", sockfd_);
            exit(SOCKET_ERR);
        }
        lg(Info, "socket create success, sockfd: %d", sockfd_);
        // 2.绑定端口号bind socket
        struct sockaddr_in local;
        bzero(&local, sizeof(local)); // 清零
        local.sin_family = AF_INET;
        local.sin_port = htons(port_);                  // 需要保证端口号是网络字节序列
        local.sin_addr.s_addr = inet_addr(ip_.c_str()); // string -> uint32_t
        // local.sin_addr.s_addr = INADDR_ANY; // 随机值0

        if (bind(sockfd_, (const struct sockaddr *)&local, sizeof(local)) < 0)
        {
            lg(Fatal, "bind error, errno: %d, err string: %s", errno, strerror(errno));
            exit(BIND_ERR);
        }
        lg(Info, "bind success, errno: %d, err string: %s", errno, strerror(errno));
    }
    void Run(func_t func)
    {
        // 初始化运行状态并定义接收缓冲区
        isruning_ = true;
        char inbuffer[size];
        // 循环接收UDP客户端消息，错误时记录并跳过本次循环
        while (isruning_)
        {
            struct sockaddr_in client; // 客户端
            socklen_t len = sizeof(client);
            ssize_t n = recvfrom(sockfd_, inbuffer, sizeof(inbuffer) - 1, 0, (struct sockaddr *)&client, &len);
            if (n < 0)
            {
                lg(Warning, "recvfrom error, errno: %d, err string: %s", errno, strerror(errno));
                continue;
            }
            // 充当数据处理
            inbuffer[n] = 0;
            std::string info = inbuffer;
            std::string echo_string = func(info);
            // 将处理后的消息发送回客户端
            sendto(sockfd_, echo_string.c_str(), echo_string.size(), 0, (const sockaddr *)&client, len);
        }
    }

    ~Udpserver()
    {
        if (sockfd_ > 0)
            close(sockfd_);
    }

private:
    int sockfd_;     // 网络文件描述符
    std::string ip_; // 服务器IP，任意地址bind
    uint16_t port_;  // 服务器端口号
    bool isruning_;  // 服务器是否在运行
};