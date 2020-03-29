
#include "A.h"
#include <stack>



void fun2();

int main()
{
    int a = 1;
    
    fun1(a);

    //如果调用为定义的函数则会报错
    //fun2();



    return 0;
}