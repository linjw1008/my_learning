#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>

//使用socket发送文件

#pragma comment (lib, "ws2_32.lib")

#define BUF_SIZE 1024

int main()
{
    //打开文件
    char *filename = ".\\TEST.txt";
    FILE *fp = fopen(filename, "rb");
    if(fp == NULL)
    {
        printf("Cannot open file, press any key to exit!\n");
        system("pause");
        exit(0); //0表示正常退出
    }

    WSADATA wasData;
    WSAStartup(MAKEWORD(2, 2), &wasData);
    
    //创建套接字
    SOCKET servSock = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in sockAddr;
    memset(&sockAddr, 0, sizeof(sockAddr));
    sockAddr.sin_family = PF_INET;
    sockAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    sockAddr.sin_port = htons(1234);
    bind(servSock, (SOCKADDR*)&sockAddr, sizeof(SOCKADDR));
    
    //监听套接字
    listen(servSock, 20);

    //接收客户端请求，返回客户端套接字
    SOCKADDR clntAddr;
    int nSize = sizeof(SOCKADDR);
    SOCKET clntSock = accept(servSock, (SOCKADDR*)&clntAddr, &nSize);

    //发送整个文件
    //分段发送，直到文件末尾
    char buffer[BUF_SIZE] = {0};
    int nCount;
    while((nCount = fread(buffer, 1, BUF_SIZE, fp)) > 0)
    {
        send(clntSock, buffer, BUF_SIZE, 0);
    }

    //断开输出流，向客户端发送FIN包
    shutdown(clntSock, SD_SEND);
    
    //阻塞，等待客户端接收完毕
    //客户端关闭socket后，会发送FIN，被服务端接收到，停止阻塞
    recv(clntSock, buffer, BUF_SIZE, 0);

    fclose(fp);
    closesocket(clntSock);
    closesocket(servSock);
    
    WSACleanup();

    return 0;
}