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
    if ((f = fopen("D:\\vscproject\\1\\c���Դ���\\s\\11\\ʵ��2�ļ�\\ʵ��2�ļ�\\��1��\\a.txt", "r")) == NULL)
    {
        printf("���ܴ��ļ�\n");
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
    printf("���ڵ���90-A����:%d�����ڵ���80-B����:%d�����ڵ���70-C����:%d�����ڵ���60-D����:%d��60����-E����:%d\n", A, B, C, D, E);
    if (fclose(f))
    {
        printf("���ܹر��ļ�\n");
        exit(0);
    }
    return 0;
}
