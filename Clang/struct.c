#include <stdlib.h>
#include <stdio.h>

struct s1
{
    char c1;
    char c2;
    int i1;
};

struct s2
{
    char c1;
    int i1;
};

struct s3
{
    int i1;
    char c1;
    int i2;
    char c2;
};

struct s4
{
    int i1;
    char c1;
    int i2;
    char c2;
    char c3;
};

union u1
{
    int i1;
    char c1;
    float f1;
};

struct s5
{
    char c1 : 1;
    char c2 : 2;
    int i1;
};

struct s6
{
    char c1 : 1;
    int i1;
    char c2 : 2;
};

struct s7
{
    char c1 : 1;
    char  : 0; //强制在下一个字边界对齐
    char c2 : 2;
    int i1;
};

struct s8
{
    char c1 : 1;
    char  : 4; //填充作用
    char c2 : 2;
    int i1;
};

int main()
{
    printf("The size of struct: %d %d %d %d\n", sizeof(struct s1), sizeof(struct s2), sizeof(struct s3), sizeof(struct s4));
    printf("The size of unio: %d\n", sizeof(union u1));
    printf("The size of struct(with bit field): %d %d %d %d\n", sizeof(struct s5), sizeof(struct s6), sizeof(struct s7), sizeof(struct s8));
}