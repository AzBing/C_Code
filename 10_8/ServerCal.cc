#include "TcpServer.hpp"
#include "Protocol.hpp"
#include "ServerCal.hpp"
#include <unistd.h>

static void Usage(const std::string &proc)
{
    std::cout << "\nUsage: " << proc << " port\n" << std::endl; 
}

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        Usage(argv[0]);
        exit(0);
    }
    uint16_t port = std::stoi(argv[1]);

    ServerCal cal;
    TcpServer *tsvp = new TcpServer(port, std::bind(&ServerCal::Calculator, &cal, std::placeholders::_1));
    tsvp->InitSrever();
    tsvp->Start();

    // Request req(234, 123, '+');
    // std::string s;
    // req.Serialize(&s);
    // s = Encode(s);
    // std::cout << s;

    return 0;
}