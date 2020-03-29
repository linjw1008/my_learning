#include <stdio.h>
#include <stdlib.h>
#include <WinSock2.h>

#pragma comment (lib, "ws2_32.lib")

using namespace std;

int main()
{
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);

    printf("wVersion: %d.%d\n", LOBYTE(wsaData.wVersion), HIBYTE(wsaData.wVersion));
    printf("wHighVersion: %d.%d\n", LOBYTE(wsaData.wHighVersion), HIBYTE(wsaData.wHighVersion));
    printf("szDescription: %s\n", wsaData.szDescription);
    printf("szSystemStatus: %s\n", wsaData.szSystemStatus);

    struct hostent* host = gethostbyname("www.taobao.com");
    if(!host)
    {
        puts("Get IP address error!\n");
        puts("Press any key to exit..");
        system("pause");
        exit(0);
    }

    //输出别名
    for (int i = 0; host->h_aliases[i]; i++)
    {
        printf("Aliases %d: %s\n", i + 1, host->h_aliases[i]);
    }

    //输出地址类型    
    printf("Address type: %s\n", (host->h_addrtype == AF_INET) ? "AF_INET" : "AF_INET6");

    //输出IP地址
    for (int i = 0; host->h_addr_list[i]; i++)
    {
        printf("IP addr %d: %s\n", i + 1, inet_ntoa(*(struct in_addr*)host->h_addr_list[i]));
    }
    
    return 0;
}