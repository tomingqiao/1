#include <stdio.h>
#include <stdlib.h>
struct student
{
    long xh;
    char name[10];
    int cj;
} s[10];

int main(int argc, char const *argv[])
{
    FILE *f;
    int i = 0;
    if ((f = fopen("D:\\vscproject\\1\\c语言代码\\s\\11\\实验2文件\\实验2文件\\第1题\\a.txt", "r")) == NULL)
    {
        printf("不能打开文件\n");
        exit(0);
    }
    fscanf(f, "% d % s % d", &s[0].xh, s[0].name, &s[0].cj);
    printf("% d % s % d", s[0].xh, s[0].name, s[0].cj);
    if (fclose(f))
    {
        printf("不能关闭文件\n");
        exit(0);
    }
    return 0;
}
