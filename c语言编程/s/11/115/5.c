#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
    FILE *f;
    char a[10][81], s[81];
    if ((f = fopen("D:\\vscproject\\1\\c���Դ���\\s\\11\\ʵ��2�ļ�\\ʵ��2�ļ�\\��5��\\a.txt", "a+")) == NULL)
    {
        printf("���ܴ��ļ�\n");
        exit(0);
    }
    printf("������10�����ʣ�");
    for (int i = 0; i < 10; i++)
    {
        scanf("%s", a[i]);
    }
    for (int i = 0; i < 10; i++)
    {
        fprintf(f, " %s", a[i]);
    }
    fseek(f, 0L, 0);
    printf("�ļ�����Ϊ��\n");
    while (!feof(f))
    {
        fscanf(f, "%s", s);
        printf(" %s", s);
    }
    if (fclose(f))
    {
        printf("���ܹر��ļ�\n");
        exit(0);
    }
    return 0;
}
