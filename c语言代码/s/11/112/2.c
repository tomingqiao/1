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
    printf("文本文件的行数:%d\n大写字母个数:%d\n小写字母个数:%d\n数字字符个数:%d\n其他字符的个数:%d", i, A, B, C, D);
}
int main(int argc, char const *argv[])
{
    FILE *f;
    f = fopen("D:\\vscproject\\1\\c语言代码\\s\\11\\实验2文件\\实验2文件\\第2题\\a.txt", "r");
    countFile(f);
    return 0;
}
