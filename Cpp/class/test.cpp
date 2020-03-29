#include <cstring>
#include <iostream>

class A
{
    static const int a = 0;
};

//常量静态成员必须为其定义一个空间
const int A::a;