

#include <stdio.h>
#include <stdlib.h>

static int a = 0;

void fun();

int main()
{
    static int a = 0;

    float b = 100.0/0.0;
    printf("%f", b);

    //abort();

    printf("hhhh\n");

    //会发生  整除0 故障
    //float c = 100/0;
    //printf("%d", c);

    //system("date");
    
    srand(100);
    printf("%d", rand());
    //srand(100);
    printf("%d", rand());

    char c = 'yes';
    printf("\n%s\n", &c);

    return 0;
}