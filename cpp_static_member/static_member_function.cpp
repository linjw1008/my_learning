//静态成员函数

#include <iostream>

using namespace std;

class Box
{
public:
    static int CreateCount;
    static int getCreateCount();
    Box()
    {
        CreateCount++;
        cout << "The CreateCount is " << CreateCount << endl;
    }
};

int Box::CreateCount = 0;

int Box::getCreateCount()
{
    return Box::CreateCount;
}

int main(void)
{
    cout << "The CreateCount: " << Box::getCreateCount() << endl;

    Box b1;
    cout << "The CreateCount: " << b1.getCreateCount() << endl;
    Box b2;
    cout << "The CreateCount: " << Box::getCreateCount() << endl;
    Box b3;
    cout << "The CreateCount: " << b3.getCreateCount() << endl;

    system("pause");

    return 0;
}