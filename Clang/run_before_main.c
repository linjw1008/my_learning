#include <stdio.h>

__attribute((constructor)) void before()
{
    printf("run before main!\n");
}

__attribute((destructor)) void after()
{
    printf("run after main!\n");
}

int main()
{
    printf("run in main!\n");

    return 0;
}