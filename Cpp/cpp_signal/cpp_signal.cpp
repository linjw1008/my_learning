#include <iostream>
#include <csignal>
#include <windows.h>

using namespace std;

void signalHandler(int signum)
{
    cout << "Interrupt signal " << signum << " received.\n";
    exit(signum);
}

int main()
{
    //注册SIGINT信号处理函数
    signal(SIGINT, signalHandler);

    while (1)
    {
        cout << "Sleep..." << endl;
        Sleep(1000);
    }
    
    return 0;
}

