#pragma once
#include <iostream>
#include <pthread.h>

#include "Socket.hpp"
#include "Log.hpp"


#define defaultport 8080

class HttpServer;

class ThreadData
{
public:
    ThreadData(int fd):sockfd(fd)
    {}
public:
    int sockfd;
};


class HttpServer
{
public:
    HttpServer(uint16_t port = defaultport) : port_(port)
    {}
    bool Start()
    {
        listensock_.Socket();
        listensock_.Bind(port_);
        listensock_.Listen();
        for (;;)
        {
            std::string clientip;
            uint16_t clientport;
            int sockfd = listensock_.Accept(&clientip, &clientport);
            if (sockfd < 0)
                continue;
            lg(Info, "get a new connect, sockfd: %d", sockfd);
            pthread_t tid;
            ThreadData *td = new ThreadData(sockfd);
            pthread_create(&tid, nullptr, ThreadRun, td);
        }
    }
    static void HandlerHttp(int sockfd)
    {
        char buffer[10240];
        ssize_t s = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
        if(s > 0)
        {
            buffer[s] = 0;
            std::cout << buffer << std::endl;
            // 返回响应
            std::string test = "Hello World!";
            std::string response_line = "HTTP/1.1 200 OK\r\n";
            std::string response_hender = "Content-Length: ";
            response_hender += std::to_string(test.size());
            response_hender += "\r\n";
            std::string blank_line = "\r\n";

            std::string response = response_line;
            response += response_hender;
            response += blank_line;
            response += test;

            send(sockfd, response.c_str(), response.size(), 0);
        }
        close(sockfd);
    }

    static void *ThreadRun(void *args)
    {
        pthread_detach(pthread_self());
        ThreadData *td = static_cast<ThreadData *>(args);
        HandlerHttp(td->sockfd);

        delete td;
        return nullptr;
    }

    ~HttpServer()
    {}

private:
    Sock listensock_;
    uint16_t port_;
};
