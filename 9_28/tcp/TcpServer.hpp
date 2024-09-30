#pragma once
#include "Log.hpp"
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <unistd.h>
#include <sys/wait.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <signal.h>

Log lg;

const int defaultfd = -1;
const std::string defaultip = "127.0.0.1";

class TcpServer
{
public:
    TcpServer(const uint16_t &port, const std::string &ip = defaultip)
        : listensock_(defaultfd), port_(port), ip_(ip)
    {
    }
    void InitServer()
    {
        listensock_ = socket(AF_INET, SOCK_STREAM, 0);
        if (listensock_ < 0)
        {
            lg(Fatal, "create socket, errno: %d, errstring: %s", errno, strerror(errno));
            exit(2);
        }
        lg(Info, "create socket success, listensock_: %d", listensock_);
        struct sockaddr_in local;
        memset(&local, 0, sizeof(local));
        local.sin_family = AF_INET;
        local.sin_port = htons(port_);
        inet_aton(ip_.c_str(), &(local.sin_addr));
        // local.sin_addr.s_addr = htonl(INADDR_ANY);
        // 绑定
        if (bind(listensock_, (struct sockaddr *)&local, sizeof(local)) < 0)
        {
            lg(Fatal, "bind, errno: %d, errstring: %s", errno, strerror(errno));
            exit(3);
        }
        lg(Info, "bind success");

        // 设置监听状态
        if (listen(listensock_, 5) < 0)
        {
            lg(Fatal, "listen, errno: %d, errstring: %s", errno, strerror(errno));
            exit(4);
        }
        lg(Info, "listen start, listensock_: %d", listensock_);
    }
    void Start()
    {
        // signal(SIGCHLD, SIG_IGN);
        for (;;)
        {
            lg(Info, "tcpserver is running...");
            // 获取新链接
            struct sockaddr_in client;
            socklen_t clientlen = sizeof(client);
            int sockfd = accept(listensock_, (struct sockaddr *)&client, &clientlen);
            if (sockfd < 0)
            {
                lg(Warning, "accept, errno: %d, errstring: %s", errno, strerror(errno));
                continue;
            }

            uint16_t clientport = ntohs(client.sin_port);
            char clientip[32];
            inet_ntop(AF_INET, &client.sin_addr, clientip, sizeof(clientip));
            // 根据新链接来进行通信
            lg(Info, "get a new link..., sockfd: %d, client ip: %s, client port: %d", sockfd, clientip, clientport);

            // 单进程模型
            // Service(sockfd, clientip, clientport);
            // close(sockfd);

            // 多进程模型
            pid_t id = fork();
            if (id == 0)
            {
                // 子进程
                close(listensock_);
                if(fork() > 0) exit(0);
                Service(sockfd, clientip, clientport); // 祖孙进程,子进程退出,托孤给system
                close(sockfd);
                exit(0);
            }
            close(sockfd);
            // 父进程
            pid_t pid = waitpid(-1, nullptr, 0);
            (void)pid;
        }
    }

    void Service(int sockfd, const std::string &clientip, uint16_t &clientport)
    {
        // 测试
        char buffer[4096];
        while (true)
        {
            ssize_t s = read(sockfd, buffer, sizeof(buffer));
            if (s > 0)
            {
                buffer[s] = 0;
                std::cout << "client say# " << buffer << std::endl;
                std::string echo_string = "tcperver echo: ";
                echo_string += buffer;
                write(sockfd, echo_string.c_str(), echo_string.size());
            }
            else if (s == 0)
            {
                lg(Info, "%s,%d quit, server colse sockfd: %d", clientip.c_str(), clientport, sockfd);
                break;
            }
            else
            {
                lg(Warning, "read error, sockfd: %d, client ip: %s, client port: %d", sockfd, clientip.c_str(), clientport);
                break;
            }
        }
    }

    ~TcpServer()
    {
    }

private:
    int listensock_; // 监听套接字
    uint16_t port_;
    std::string ip_;
};