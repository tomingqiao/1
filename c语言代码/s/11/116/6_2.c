#include <stdio.h>
#include <stdlib.h>
struct studnt
{
    long xh;
    char name[81];
    int cj;
} s[10], t;
int main(int argc, char const *argv[])
{
    FILE *f;
    int n;
    char str[81];
    if ((f = fopen("D:\\vscproject\\1\\c���Դ���\\s\\11\\ʵ��2�ļ�\\ʵ��2�ļ�\\��6��\\a1.dat", "ab+")) == NULL)
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
        fwrite(&s[i], sizeof(s[i]), 1, f);
    }
    fseek(f, 0L, 0);
    printf("ѧ����ϢΪ��\n");
    for (int i = 0; i < n; i++)
    {
        fread(&t, sizeof(s[i]), 1, f);
        printf("%d %s %d\n", t.xh, t.name, t.cj);
    }
    if (fclose(f))
    {
        printf("���ܹر��ļ�\n");
        exit(0);
    }
    return 0;
}
