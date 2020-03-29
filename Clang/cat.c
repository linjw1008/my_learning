#include <stdio.h>
//模拟cat命令，将多个文件连接起来

void filecopy(FILE *ifp, FILE *ofp)
{
    int c;
    while ((c = getc(ifp)) != EOF)
    {
        putc(c, ofp);
    }
}

//不指定返回类型名，默认为int
main(int argc, char **argv)
{
    FILE *fp;

    //没有指定文件名
    if (argc == 1)
    {
        filecopy(stdin, stdout);
    }
    else
    {
        while (--argc > 0)
        {
            if ((fp = fopen(*++argv, "r")) == NULL)
            {
                printf("cat: can't open %s\n", *argv);
                return 1;
            }
            else
            {
                filecopy(fp, stdout);
                fclose(fp); //关闭文件，释放文件指针供其他文件使用
            }
        }
    }
    return 0;
}