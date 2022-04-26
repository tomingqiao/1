#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
    FILE *f;
    char a[10][81], s[81];
    if ((f = fopen("D:\\vscproject\\1\\c语言代码\\s\\11\\实验2文件\\实验2文件\\第5题\\a.txt", "a+")) == NULL)
    {
        printf("不能打开文件\n");
        exit(0);
    }
    printf("请输入10个单词：");
    for (int i = 0; i < 10; i++)
    {
        scanf("%s", a[i]);
    }
    for (int i = 0; i < 10; i++)
    {
        fprintf(f, " %s", a[i]);
    }
    fseek(f, 0L, 0);
    printf("文件内容为：\n");
    while (!feof(f))
    {
        fscanf(f, "%s", s);
        printf(" %s", s);
    }
    if (fclose(f))
    {
        printf("不能关闭文件\n");
        exit(0);
    }
    return 0;
}
