#include <utility>
#include <iostream>

using namespace std::rel_ops;

class A
{
public:
    A(/* args */)
    {

    }
    ~A()
    {

    }

    bool operator== (const A &a) const
    {
        return false;
    }
    bool operator< (const A &a) const
    {
        return true;
    }
};

int main()
{
    A a;
    A b;


    //utility中利用 ==和<定义了!= > >= <=等函数
    if (a != b)
    {
        std::cout << "a >= b" << std::endl;
    }

    return 0;
}