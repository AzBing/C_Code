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
    

    sockfd.Close();
    return 0;
}
