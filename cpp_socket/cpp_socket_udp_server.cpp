#include <stdio.h>
#include <winsock2.h>

#pragma comment (lib, "ws2_32.lib")

#define BUF_SIZE    100

int main()
{
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);

    //创建套接字
    SOCKET sock = socket(AF_INET, SOCK_DGRAM, 0);

    //绑定套接字
    sockaddr_in servAddr;
    memset(&servAddr, 0, sizeof(servAddr));
    servAddr.sin_family = AF_INET;
    servAddr.sin_addr.s_addr = htonl(INADDR_ANY);   //自动获取IP地址
    servAddr.sin_port = htons(1234);
    bind(sock, (SOCKADDR*)&servAddr, sizeof(SOCKADDR));

    //接收客户端请求
    SOCKADDR clntAddr;  //用于保存客户端地址信息
    int nSize = sizeof(SOCKADDR);
    char buffer[BUF_SIZE];
    while(1)
    {
        int strLen = recvfrom(sock, buffer, BUF_SIZE, 0, &clntAddr, &nSize);
        sendto(sock, buffer, strLen, 0, &clntAddr, nSize);
    }    

    closesocket(sock);

    WSACleanup();
    
    return 0;
}