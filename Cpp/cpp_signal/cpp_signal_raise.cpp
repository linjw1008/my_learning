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
    int i = 0;
    signal(SIGINT, signalHandler);

    while(++i)
    {
        cout << "Sleep..." << endl;
        if(i == 3)
        {
            //生成信号
            raise(SIGINT);
        }
        Sleep(1000);
    }
    return 0;
}