#include <iostream>
#include <string>
#include <ctime>
#include <cassert>
#include <unistd.h>
#include "Socket.hpp"
#include "Protocol.hpp"

static void Usage(const std::string &proc)
{
    std::cout << "\nUsage: " << proc << " serverip serverport\n"
              << std::endl;
}

// ./clientcal ip port
int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        Usage(argv[0]);
        exit(0);
    }
    std::string serverip = argv[1];
    uint16_t serverport = std::stoi(argv[2]);

    Sock sockfd;
    sockfd.Socket();
    bool r = sockfd.Connect(serverip, serverport);
    if(!r)
    {
        std::cout << "connect failed" << std::endl;
        return -1;
    }

    srand(time(nullptr) ^ getpid());
    int cnt = 1;
    const std::string opers = "+-*/%=-=&^";

    std::string inbuffer_stream;
    while(cnt <= 10)
    {
        std::cout << "===============第" << cnt << "次测试....., " << "===============" << std::endl;
        int x = rand() % 100 + 1;
        usleep(1000);
        int y = rand() % 100;
        usleep(1000);
        char oper = opers[rand() % opers.size()];
        Request req(x, y, oper);
        req.DebugPrint();
        std::string package;
        req.Serialize(&package);

        package = Encode(package);
        std::cout << "这是最新的发出去的请求: \n" << package;
        write(sockfd.Fd(), package.c_str(), package.size());
        
        char buffer[128];
        ssize_t s = read(sockfd.Fd(), buffer, sizeof(buffer));
        if(s > 0)
        {
            buffer[s] = 0;
            inbuffer_stream += buffer;
            std::string content;
            bool r = Decode(inbuffer_stream, &content);
            assert(r);

            Response res;
            r = res.Deserialize(content);
            assert(r);
            
            res.DebugPrint();
        }
        std::cout << "=================================================" << std::endl;
        sleep(1);
        cnt++;
    }

    
    

    sockfd.Close();
    return 0;
}
