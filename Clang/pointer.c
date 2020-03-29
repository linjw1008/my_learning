#include <stddef.h>
#include <stdio.h>
#include <string.h>

int main()
{
    //表示两个指针之间的带符号的差值
    ptrdiff_t   pt;
    //无符号整型
    size_t      st;

    int     *intptr;
    float   *floatptr;
    void    *voidptr;
    //可以
    intptr = voidptr;
    intptr = (int *)floatptr;
    //会有警告，教材中定义为非法
    intptr = floatptr;
    
    int arr1[13] = {1, 2, 3};
    //指向数组的指针
    int (*arr2)[13];
}