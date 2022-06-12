#include <stdio.h>
#include <stdlib.h>
struct student
{
    long xh;
    char name[100];
    int cj;
} s[10];
int main(int argc, char const *argv[])
{
    FILE *f;
    int i = 0, A = 0, B = 0, C = 0, D = 0, E = 0;
    char str[50];
    if ((f = fopen("D:\\vscproject\\1\\c语言代码\\s\\11\\实验2文件\\实验2文件\\第1题\\a.txt", "r")) == NULL)
    {
        printf("不能打开文件\n");
        exit(0);
    }
    while (!feof(f))
    {
        fscanf(f, "%d%s%d", &s[i].xh, s[i].name, &s[i].cj);
        printf("%d  %s  %d\n", s[i].xh, s[i].name, s[i].cj);
        if (s[i].cj >= 90)
        {
            A++;
        }
        if (s[i].cj >= 80 && s[i].cj < 90)
        {
            B++;
        }
        if (s[i].cj >= 70 && s[i].cj < 80)
        {
            C++;
        }
        if (s[i].cj >= 60 && s[i].cj < 70)
        {
            D++;
        }
        if (s[i].cj < 60)
        {
            E++;
        }
        i++;
    }
    printf("大于等于90-A人数:%d，大于等于80-B人数:%d，大于等于70-C人数:%d，大于等于60-D人数:%d，60以下-E人数:%d\n", A, B, C, D, E);
    if (fclose(f))
    {
        printf("不能关闭文件\n");
        exit(0);
    }
    return 0;
}
