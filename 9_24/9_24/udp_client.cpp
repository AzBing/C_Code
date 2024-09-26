#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <WinSock2.h>
#include <Windows.h>

#pragma warning(disable:4996)
#pragma comment(lib, "ws2_32.lib")

uint16_t serverport = 8888;
std::string serverip = "1.92.125.210";

int main()
{
    std::cout << "hello client" << std::endl;
	WSADATA wsd;
	WSAStartup(MAKEWORD(2, 2), &wsd);

    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(serverport);
    server.sin_addr.s_addr = inet_addr(serverip.c_str());

    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0)
    {
        std::cout << "socker error" << std::endl;
        return 1;
    }

    std::string message;
    char buffer[1024];
    while (true)
    {
        std::cout << "Please Enter$ ";
        std::getline(std::cin, message);
        sendto(sockfd, message.c_str(), (int)message.size(), 0, (struct sockaddr*)&server, sizeof(server));

        struct sockaddr_in temp;
        int len = sizeof(temp);
        int s = recvfrom(sockfd, buffer, 1023, 0, (sockaddr*)&temp, &len);

        if (s > 0)
        {
            buffer[s] = 0;
            std::cout << buffer << std::endl;
        }
    }

    closesocket(sockfd);
    WSACleanup();
	return 0;
}
