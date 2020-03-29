//windows下共享内存的实现

#include <windows.h>
#include <iostream>

using namespace std;

#define BUF_SIZE 4096

int main()
{
    //共享数据
    char sharedMemory[] = "This is the shared memory.";

    //创建共享文件句柄
    //该函数用于创建文件映射对象
    //第一个参数若为INVALID_HANDLE_VALUE则直接从系统页面映射
    HANDLE hMapFile = CreateFileMapping(
        INVALID_HANDLE_VALUE,   //物理文件句柄，INVALID_HANDLE_VALUE与物理文件无关，内存映射
        NULL,       //默认的安全描述，表示该句柄不可以被子进程继承
        PAGE_READWRITE,     //文件被映射后，视图的保护属性，可读可写
        0,      //高位文件大小（64位的高32位）
        BUF_SIZE,   //地位文件大小（64位的低32位）
        "ShareMemory"
    );

    // 映射缓存区视图，得到指向共享内存的指针
    //该函数将文件映射对象映射到当前应用程序的地址空间
    LPVOID lpBase = MapViewOfFile(
        hMapFile,
        FILE_MAP_ALL_ACCESS,
        0,
        0,
        BUF_SIZE
    );

    //拷贝数据至共享内存
    strcpy((char*)lpBase, sharedMemory);
    cout << "Data in shareMemory: " << (char*)lpBase << endl;

    //挂起等待其他进程读取数据
    Sleep(20000);

    //解除文件映射
    UnmapViewOfFile(lpBase);
    //关闭句柄
    CloseHandle(hMapFile);

    return 0;
}