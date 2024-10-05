#include "TcpServer.hpp"
#include "Protocol.hpp"
#include <unistd.h>

int main()
{

    Request req(234, 123, '+');
    std::string s;
    req.Serialize(&s);
    s = Encode(s);
    std::cout << s;

    return 0;
}