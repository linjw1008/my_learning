// 函数指针
#pragma warning(disable  : 4996)

#include <stdio.h>

int max(int x, int y)
{
    return x > y ? x : y;
}

int main(void)
{
    //定义函数指针
    int (*p)(int, int) = & max;
    int a, b, c, d;

    printf("输入3个数字：");
    scanf("%d %d %d", &a, &b, &c);

    d = p(p(a, b), c);

    printf("Max: %d \n", d);

	system("pause");

    return 0;

}