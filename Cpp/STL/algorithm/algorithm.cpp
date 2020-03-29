#include <algorithm>
#include <iostream>

using namespace std;

bool myCmp(int a, int b)
{
    return a < b;
}

int main()
{
    int a = 10, b = 20;

    //可以自定义比较函数或者仿函数
    cout << min(a, b, myCmp) << endl;
    cout << max(a, b) << endl;

    swap(a, b);
    cout << min(a, b, myCmp) << endl;
    cout << max(a, b) << endl;


    return 0;
}

