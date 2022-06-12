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
    if ((f = fopen("D:\\vscproject\\1\\c语言代码\\s\\11\\实验2文件\\实验2文件\\第6题\\a1.dat", "ab+")) == NULL)
    {
        printf("不能打开文件\n");
        exit(0);
    }
    printf("请输入待添加信息的学生人数：");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("请输入第%d个学生信息(学号 姓名 成绩)：\n", i + 1);
        scanf("%d %s %d", &s[i].xh, s[i].name, &s[i].cj);
    }
    for (int i = 0; i < n; i++)
    {
        fwrite(&s[i], sizeof(s[i]), 1, f);
    }
    fseek(f, 0L, 0);
    printf("学生信息为：\n");
    for (int i = 0; i < n; i++)
    {
        fread(&t, sizeof(s[i]), 1, f);
        printf("%d %s %d\n", t.xh, t.name, t.cj);
    }
    if (fclose(f))
    {
        printf("不能关闭文件\n");
        exit(0);
    }
    return 0;
}
