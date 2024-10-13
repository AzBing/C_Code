#pragma once
#include <iostream>
#include <unistd.h>
#include <string>
#include <cstring>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include "Log.hpp"

enum SockType
{
    socketErr = 2,
    BindErr,
    ListenErr,
};

const int backlog = 10;

class Sock
{
public:
    Sock()
    {}
    ~Sock()
    {}
public:
    void Socket()
    {
        sockfd_ = socket(AF_INET, SOCK_STREAM, 0);
        if(sockfd_ < 0)
        {
            lg(Fatal, "Socker error, %s: %d", strerror(errno), errno);
            exit(socketErr);
        }
    }
    void Bind(uint16_t port)
    {
        sockaddr_in local;
        memset(&local, 0, sizeof(local));
        local.sin_family = AF_INET;
        local.sin_port = htons(port);
        local.sin_addr.s_addr = INADDR_ANY;
        if(bind(sockfd_, (sockaddr*)&local, sizeof(local)) < 0)
        {
            lg(Fatal, "Bind error, %s: %d", strerror(errno), errno);
            exit(BindErr);
        }
    }
    void Listen()
    {
        if(listen(sockfd_, backlog) < 0)
        {
            lg(Fatal, "Listen error, %s: %d", strerror(errno), errno);
            exit(ListenErr);
        }
    }
    int Accept(std::string *clientip, uint16_t *clientport)
    {
        sockaddr_in client;
        socklen_t len = sizeof(client);
        int connfd = accept(sockfd_, (sockaddr*)&client, &len);
        if(connfd < 0)
        {
            lg(Warning, "Accept error, %s: %d", strerror(errno), errno);
            return -1;
        }
        char clientip_[64];
        inet_ntop(AF_INET, &client.sin_addr, clientip_, sizeof(clientip_));
        *clientip = clientip_;
        *clientport = ntohs(client.sin_port);

        return connfd;
    }
    bool Connect(const std::string &ip, const uint16_t &port)
    {
        sockaddr_in peer;
        memset(&peer, 0, sizeof(peer));
        peer.sin_family = AF_INET;
        peer.sin_port = htons(port);
        inet_pton(AF_INET, ip.c_str(), &peer.sin_addr);

        if(connect(sockfd_, (sockaddr*)&peer, sizeof(peer)) < 0)
        {
            std::cout << "Connect error " << ip << ":" << port << std::endl;
            return false;
        }
        return true;
    }
    void Close()
    {
        close(sockfd_);
    }
    int Fd()
    {
        return sockfd_;
    }
private:
    int sockfd_;
};
