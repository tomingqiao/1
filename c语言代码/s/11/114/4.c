#include <stdio.h>
#include <stdlib.h>
struct studnt
{
    long xh;
    char name[81];
    int cj;
} s[10];
int main(int argc, char const *argv[])
{
    FILE *f;
    int n;
    char str[81];
    if ((f = fopen("D:\\vscproject\\1\\c���Դ���\\s\\11\\ʵ��2�ļ�\\ʵ��2�ļ�\\��4��\\a.txt", "a+")) == NULL)
    {
        printf("���ܴ��ļ�\n");
        exit(0);
    }
    printf("������������Ϣ��ѧ��������");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("�������%d��ѧ����Ϣ(ѧ�� ���� �ɼ�)��\n", i + 1);
        scanf("%d %s %d", &s[i].xh, s[i].name, &s[i].cj);
    }
    for (int i = 0; i < n; i++)
    {
        fprintf(f, "%d %s %d\n", s[i].xh, s[i].name, s[i].cj);
    }
    fseek(f, 0L, 0);
    printf("ѧ����ϢΪ��\n");
    while (fgets(str, 81, f) != NULL)
    {
        printf("%s", str);
    }
    if (fclose(f))
    {
        printf("���ܹر��ļ�\n");
        exit(0);
    }
    return 0;
}
