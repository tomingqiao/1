#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
    FILE *f1, *f2;
    char c1, c2;
    int i = 0, m = 0, n = 1;
    f1 = fopen("D:\\vscproject\\1\\c���Դ���\\s\\11\\ʵ��2�ļ�\\ʵ��2�ļ�\\��3��\\a1.txt", "r");
    f2 = fopen("D:\\vscproject\\1\\c���Դ���\\s\\11\\ʵ��2�ļ�\\ʵ��2�ļ�\\��3��\\a2.txt", "r");
    while (!feof(f1) || !feof(f2))
    {
        c1 = fgetc(f1);
        c2 = fgetc(f2);
        m++;
        if (c1 != c2)
        {
            i++;
            break;
        }
        if (c1 == '\n')
        {
            n++;
            m = 0;
        }
    }
    if (i == 0)
    {
        printf("YES");
    }
    else
    {
        printf("NO\n");
        printf("�����ļ������״β�ͬ���кź��ַ�λ��:%d,%d", n, m);
    }
    return 0;
}
