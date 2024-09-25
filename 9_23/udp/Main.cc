#include "Udpserver.hpp"
#include <memory>

Log lg;
void Usage(std::string proc)
{
    std::cout << "\n\rUsage: " << proc << " port[1024+]\n" << std::endl;
}

std::string Handler(const std::string &str)
{
    std::string res = "Server get a message: ";
    res += str;
    std::cout << res << std::endl;

    return res;
}

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        Usage(argv[0]);
        exit(0);
    }

    uint16_t port = std::stoi(argv[1]);

    std::unique_ptr<Udpserver> svr(new Udpserver(port));

    svr->Init();
    svr->Run(Handler);


    return 0;
}
