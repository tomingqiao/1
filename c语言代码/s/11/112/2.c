#include <stdio.h>
#include <stdlib.h>
void countFile(FILE *f)
{
    int i = 0, A = 0, B = 0, C = 0, D = 0;
    char s[100], c;
    while (!feof(f))
    {
        fgets(s, 81, f);
        i++;
    }
    fseek(f, 0L, 0);
    while (!feof(f))
    {
        c = fgetc(f);
        if (c <= 'Z' && c >= 'A')
        {
            A++;
        }
        else if (c <= 'z' && c >= 'a')
        {
            B++;
        }
        else if (c <= '9' && c >= '0')
        {
            C++;
        }
        else
            D++;
    }
    printf("�ı��ļ�������:%d\n��д��ĸ����:%d\nСд��ĸ����:%d\n�����ַ�����:%d\n�����ַ��ĸ���:%d", i, A, B, C, D);
}
int main(int argc, char const *argv[])
{
    FILE *f;
    f = fopen("D:\\vscproject\\1\\c���Դ���\\s\\11\\ʵ��2�ļ�\\ʵ��2�ļ�\\��2��\\a.txt", "r");
    countFile(f);
    return 0;
}
