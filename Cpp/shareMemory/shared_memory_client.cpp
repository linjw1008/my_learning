//windows下共享内存的实现

#include <windows.h>
#include <iostream>

using namespace std;

#define BUF_SIZE 4096

int main()
{
    //打开共享的文件对象
    HANDLE hMapFile = OpenFileMapping(
        FILE_MAP_ALL_ACCESS,
        NULL,
        "ShareMemory"
    );

    if (hMapFile)
    {
        //映射为指针
        LPVOID lpBase = MapViewOfFile(
            hMapFile,
            FILE_MAP_ALL_ACCESS,
            0,
            0,
            0
        );

        char readBuffer[BUF_SIZE] = {0};
        //拷贝数据
        strcpy(readBuffer, (char*)lpBase);

        cout << "Data read from memory: " << (char*)lpBase << endl;

        //解除映射
        UnmapViewOfFile(lpBase);
        //关闭内存映射文件对象句柄
        CloseHandle(hMapFile);
    }
    else
    {
        cout << "打开共享内存失败" << endl;
    }

    return 0;
}