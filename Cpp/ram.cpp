#include <string>
#include <iostream>

using namespace std;

class testRam
{
private:
    /* data */
public:
    testRam(/* args */);
    ~testRam();
};


int main ()
{
    //对于简单的基本数据类型，以下两种delete效果一样
    int *tmp = new int[5];
    delete []tmp;
    delete tmp;

    //对于对象数组则不一样，因为有析构函数
    testRam *tmp1 = new testRam[5];
    //释放申请的空间，但是只调用对象数组的第一个对象的析构函数
    delete tmp1;
    //调用全部对象的析构函数
    delete []tmp1;


    cout << tmp[1] << endl;

    return 0;
}