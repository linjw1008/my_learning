#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>

//使用socket接收文件

#pragma comment (lib, "ws2_32.lib")

#define BUF_SIZE 1024

int main()
{
    //打开文件
    char filename[100] = {0};
    printf("Input filename to save: ");
    gets(filename);    
    FILE *fp = fopen(filename, "wb");
    if(fp == NULL)
    {
        printf("Cannot open file, press any key to exit!\n");
        system("pause");
        exit(0); //0表示正常退出
    }

    WSADATA wasData;
    WSAStartup(MAKEWORD(2, 2), &wasData);
    
    //创建套接字
    SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in sockAddr;
    memset(&sockAddr, 0, sizeof(sockAddr));
    sockAddr.sin_family = AF_INET;
    sockAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    sockAddr.sin_port = htons(1234);
    connect(sock, (SOCKADDR*)&sockAddr, sizeof(SOCKADDR));
    
    //接收文件
    char buffer[BUF_SIZE] = {0};
    int nCount;
    while((nCount = recv(sock, buffer, BUF_SIZE, 0)) > 0)
    {
        fwrite(buffer, nCount, 1, fp);
        printf("write\n");
    }
    puts("File transfer success!");

    //关闭文件
    fclose(fp);

    //直接关闭套接字
    closesocket(sock);

    WSACleanup();

    return 0;
}