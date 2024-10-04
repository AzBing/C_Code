#include <iostream>
#include <cstring>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

void Usage(const std::string &proc)
{
    std::cout << "\n\rUsage: " << proc << " serverip serverport\n"
              << std::endl;
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        Usage(argv[0]);
        exit(1);
    }
    std::string serverip = argv[1];
    uint16_t serverport = std::stoi(argv[2]);

    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(serverport);
    inet_pton(AF_INET, serverip.c_str(), &(server.sin_addr));

    while (true)
    {
        int cnt = 10;
        bool isrecnnect = false;

        int sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd < 0)
        {
            std::cerr << "socket error" << std::endl;
            return 1;
        }

        do
        {
            // tcp客户端，系统会进行bind,客户端发起connect的时候，进行自动随机bind
            int n = connect(sockfd, (struct sockaddr *)&server, sizeof(server));
            if (n < 0)
            {
                isrecnnect = true;
                cnt--;

                std::cerr << "connect error..., reconnect: " << cnt << std::endl;
                sleep(1);
            }
            else
            {
                break;
            }
        } while (cnt && isrecnnect);

        if (cnt == 0)
        {
            std::cerr << "connect failed!" << std::endl;
            break;
        }

        std::string message;
        std::cout << "请输入要发送的消息：";
        std::getline(std::cin, message);

        int m = write(sockfd, message.c_str(), message.size());
        if (m < 0)
        {
            std::cerr << "write error..." << std::endl;
            continue;
        }

        char buffer[4096];
        int n = read(sockfd, buffer, sizeof(buffer));
        if (n > 0)
        {
            buffer[n] = '\0';
            std::cout << buffer << std::endl;
        }

        close(sockfd);
    }

    return 0;
}
