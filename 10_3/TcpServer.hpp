#pragma once

#include <functional>
#include <signal.h>
#include "Log.hpp"
#include "Socket.hpp"

using func_t = std::function<std::string(std::string &package)>;

class TcpServer
{
public:
    TcpServer()
    {}
    bool InitSrever()
    {
        listensock_.Socket();
        listensock_.Bind(port_);
        listensock_.Listen();
        lg(Info, "init server .... done");
        return true;
    }
    void Start()
    {
        while(true)
        {
            signal(SIGCHLD, SIG_IGN);
            signal(SIGPIPE, SIG_IGN);
            std::string clientip;
            uint16_t clientport;
            int sockfd = listensock_.Accept(&clientip, &clientport);
            if(sockfd < 0)
                continue;
            //
            if(fork() == 0)
            {
                listensock_.Close();

                exit(0);
            }
        }
    }
    ~TcpServer()
    {}
private:
    uint16_t port_;
    Sock listensock_;
    func_t callback_;
};

