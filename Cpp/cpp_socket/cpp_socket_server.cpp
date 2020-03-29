#include <stdio.h>
#include <WinSock2.h>

#pragma comment (lib, "ws2_32.lib")

#define BUF_SIZE    100

using namespace std;

int main()
{
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);

    printf("wVersion: %d.%d\n", LOBYTE(wsaData.wVersion), HIBYTE(wsaData.wVersion));
    printf("wHighVersion: %d.%d\n", LOBYTE(wsaData.wHighVersion), HIBYTE(wsaData.wHighVersion));
    printf("szDescription: %s\n", wsaData.szDescription);
    printf("szSystemStatus: %s\n", wsaData.szSystemStatus);


    //创建套接字，返回SOCKET类型的句柄
    SOCKET serv_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    //绑定端口地址
    sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serv_addr.sin_port = htons(1234);
    bind(serv_sock, (SOCKADDR *)&serv_addr, sizeof(serv_addr));

    //进入监听状态
    listen(serv_sock, 20);

    //接收客户端请求
    SOCKADDR clnt_addr;
    int nSize = sizeof(SOCKADDR);
    char buffer[BUF_SIZE] = {0};
    while(1)
    {
        SOCKET clnt_sock = accept(serv_sock, (SOCKADDR *)&clnt_addr, &nSize);
        int strLen = recv(clnt_sock, buffer, BUF_SIZE, 0); //接收客户端数据
        send(clnt_sock, buffer, strLen, 0); //将数据原样返回

        closesocket(clnt_sock); // 关闭客户端的套接字
        memset(buffer, 0, BUF_SIZE);    //重置缓冲区
    }

    //关闭套接字   
    closesocket(serv_sock);

    //终止DLL的使用
    WSACleanup();

    return 0;
}