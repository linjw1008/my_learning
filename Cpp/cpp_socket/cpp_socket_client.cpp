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

    
    sockaddr_in sock_addr;
    memset(&sock_addr, 0, sizeof(sock_addr));
    sock_addr.sin_family = AF_INET;
    sock_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    sock_addr.sin_port = htons(1234);
    
    char bufSend[BUF_SIZE] = {0};
    char bufRecv[BUF_SIZE] = {0};
    
    while(1)
    {
        //创建套接字
        //需要重新创建，因为服务端调用closesocket会关闭服务端的socket，并且会通知客户端连接已经断开，服务端也会清空socket
        SOCKET sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        connect(sock, (SOCKADDR *)&sock_addr, sizeof(SOCKADDR));
        //获取用户输入并发送给服务器
        printf("Input a string: ");
        gets(bufSend);
        send(sock, bufSend, strlen(bufSend), 0);

        //接收服务器传回的数据
        recv(sock, bufRecv, BUF_SIZE, 0);
        
        //输出服务器传回的数据
        printf("Message from server:%s\n", bufRecv);

        memset(bufSend, 0, BUF_SIZE);
        memset(bufRecv, 0, BUF_SIZE);

        //关闭套接字   
        closesocket(sock);
    }

    WSACleanup();

    system("pause");

    return 0;
}