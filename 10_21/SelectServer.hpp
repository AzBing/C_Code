#pragma once

#include <iostream>
#include <sys/select.h>
#include <sys/time.h>
#include "Socket.hpp"

using namespace std;

static const uint16_t defaultport = 8888;
static const int fd_num_max = (sizeof(fd_set) * 8);
int defaultfd = -1;

class SelectServer
{
public:
    SelectServer(uint16_t port = defaultport) : _port(port)
    {
    }
    bool Init()
    {
        _listensock.Socket();
        _listensock.Bind(_port);
        _listensock.Listen();

        return true;
    }
    void Start()
    {
        int listensock = _listensock.Fd();
        for (;;)
        {
            fd_set rfds;
            FD_ZERO(&rfds);
            FD_SET(listensock, &rfds);

            // struct timeval timeout = {1, 0}; // 输入输出，可能要进行周期的重复设置
            struct timeval timeout = {0, 0}; // 输入输出，可能要进行周期的重复设置
            int n = select(listensock + 1, &rfds, nullptr, nullptr, /*&timeout*/ nullptr);
            switch (n)
            {
            case 0:
                cout << "time out, timeout: " << timeout.tv_sec << "." << timeout.tv_usec << endl;
                break;
            case -1:
                cerr << "select error" << endl;
                break;
            default:
                // 有事件就绪了，TODO
                cout << "get a new link!!!!!" << endl;
                break;
            }
        }
    }

private:
    Sock _listensock;
    uint16_t _port;
};