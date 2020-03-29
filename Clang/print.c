#include <stdio.h>

int test[5];

int main()
{
    printf("%4.1f\n", 4.1);

    //八进制表示一个字符
    char c = '\231';
    //十六进制表示一个字符
    char d = '\x32';

    printf("%c\n %c\n", c, d);

    enum a
    {
        a1,
        a2 = 17,
        a3
    };

    printf("%d %d %x\n", a1, a2, a3);

    printf("%d\n", sizeof(test));

    char *string = "hello, world";

    printf(":%s:\n", string);
    //打印不小于10的宽度
    printf(":%10s:\n", string);
    //指定精度，打印最大10个字符、最大浮点数小数点后的位数、整型最少输出的数字数目等
    printf(":%.10s:\n", string);
    printf(":%-10s:\n", string);
    printf(":%.15s:\n", string);
    printf(":%-15s:\n", string);
    printf(":%15.10s:\n", string);
    printf(":%-15.10s:\n", string);
    printf(string);
}
