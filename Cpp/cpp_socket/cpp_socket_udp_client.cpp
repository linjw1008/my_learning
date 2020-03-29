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

    //设置服务器地址信息
    sockaddr_in servAddr;
    memset(&servAddr, 0, sizeof(servAddr));
    servAddr.sin_family = AF_INET;
    servAddr.sin_addr.s_addr = inet_addr("127.0.0.1");   //自动获取IP地址
    servAddr.sin_port = htons(1234);
    
    //获取用户输入并发送给服务器，然后接收服务器数据
    SOCKADDR fromAddr;  //用于保存服务器地址信息
    int addrLen = sizeof(SOCKADDR);
    while(1)
    {
        char buffer[BUF_SIZE] = {0};
        printf("Input a string: ");
        gets(buffer);
        sendto(sock, buffer, strlen(buffer), 0, (SOCKADDR*)&servAddr, sizeof(servAddr));   
        int strLen = recvfrom(sock, buffer, BUF_SIZE, 0, &fromAddr, &addrLen);
        //buffer[strLen] = 0;
        printf("Message form server %s : %s\n", inet_ntoa(((sockaddr_in*)&fromAddr)->sin_addr), buffer);
    }    

    closesocket(sock);

    WSACleanup();
    
    return 0;
}