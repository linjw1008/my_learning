//变长参数表示例

#include <stdarg.h>
#include <stdio.h>

void myprintf(char *fmt, ...)
{

    va_list ap;
    char *p, *sval;
    int ival;
    double dval;

    va_start(ap, fmt);  //把ap指针指向第一个未命名的参数，将最后一个有名参数作为起点
    for (p = fmt; *p; p++)
    {
        if (*p != '%')
        {
            putchar(*p);
            continue;
        }

        switch (*++p)
        {
        case 'd':
            ival = va_arg(ap, int);   //获取int类型的参数，并将ap指向下一个参数
            printf("%d", ival);
            break;
        case 'f':
            dval = va_arg(ap, double);   //获取下一个double类型的参数
            printf("%f", dval);
            break;
        case 's':
            for (sval = va_arg(ap, char *); *sval; sval++)
                putchar(*sval);
            break;
        default:
            putchar(*p);
            break;
            break;
        }
    }
    va_end(ap); //进行一些清理工作
}


int main()
{
    myprintf("int: %d, double: %f, string: %s\n", 123, 321.123, "this is a string");
}