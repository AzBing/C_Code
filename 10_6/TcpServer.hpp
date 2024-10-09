/*
 * @Author: zhb 812687197@qq.com
 * @Date: 2024-10-08 14:23:24
 * @LastEditors: zhb 812687197@qq.com
 * @LastEditTime: 2024-10-09 15:10:34
 * @FilePath: /zhb/2024/10_6/TcpServer.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#pragma once

#include <functional>
#include <string>
#include "Log.hpp"
#include "Socket.hpp"
#include <signal.h>

using func_t = std::function<std::string(std::string &package)>;

class TcpServer
{
public:
    TcpServer(uint16_t port, func_t callback) : port_(port), callback_(callback)
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
         while (true)
        {
            std::string clientip;
            uint16_t clientport;
            int sockfd = listensock_.Accept(&clientip, &clientport);
            if (sockfd < 0)
                continue;
            lg(Info, "accept a new link, sockfd: %d client ip: %s, clientport: %d", sockfd, clientip.c_str(), clientport);
            // 提供服务
            if (fork() == 0)
            {
                listensock_.Close();
                std::string inbuffer_stream;
                // 数据计算
                while (true)
                {
                    char buffer[1280];
                    ssize_t n = read(sockfd, buffer, sizeof(buffer));
                    if (n > 0)
                    {
                        buffer[n] = 0;
                        inbuffer_stream += buffer;

                        lg(Debug, "debug:\n%s", inbuffer_stream.c_str());

                        std::string info = callback_(inbuffer_stream);
                        if (info.empty())   continue;

                        write(sockfd, info.c_str(), info.size());

                    }
                    else if (n == 0) break;
                    else break;
                }

                exit(0);
            }
            close(sockfd);
        }
    }
    ~TcpServer()
    {}

private:
    uint16_t port_;
    Sock listensock_;
    func_t callback_;
};

