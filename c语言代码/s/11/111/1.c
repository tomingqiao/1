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
    if ((f = fopen("D:\\vscproject\\1\\c���Դ���\\s\\11\\ʵ��2�ļ�\\ʵ��2�ļ�\\��1��\\a.txt", "r")) == NULL)
    {
        printf("���ܴ��ļ�\n");
        exit(0);
    }
    fscanf(f, "% d % s % d", &s[0].xh, s[0].name, &s[0].cj);
    printf("% d % s % d", s[0].xh, s[0].name, s[0].cj);
    if (fclose(f))
    {
        printf("���ܹر��ļ�\n");
        exit(0);
    }
    return 0;
}
