//类静态成员

#include <iostream>

using namespace std;

class Box
{
public:
    static int createCount;
    Box()
    {
        createCount++;
        cout << "Box's constructor called. " << endl;
    }

};

int Box::createCount = 0;

int main(void)
{
    Box b1;
    cout << "createCount: " << Box::createCount << endl;

    Box b2;
    cout << "createCount: " << Box::createCount << endl;
    
    Box b3;
    cout << "createCount: " << Box::createCount << endl;

    system("pause");

    return 0;
}