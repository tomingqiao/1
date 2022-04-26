#include <stdio.h>
#include <stdlib.h>
struct student
{
    long xh;
    char name[100];
    int cj;
} s1[10], s2[10], s3[20], s;
void mergeFile(FILE *f1, FILE *f2, FILE *f3)
{
    int i = 0, j = 0, n;
    while (!feof(f1))
    {
        fread(&s1[i], sizeof(s1[i]), 1, f1);
        i++;
    }
    while (!feof(f2))
    {
        fread(&s2[i], sizeof(s2[i]), 1, f2);
        j++;
    }
    n = i + j + 2;
    j = i = 0;
    for (int m = 0; m < n; m++)
    {
        if (s1[i].cj <= s2[j].cj)
        {
            s3[m] = s1[i];
            i++;
        }
        if (s1[i].cj >= s2[j].cj)
        {
            s3[m] = s2[j];
            j++;
        }
    }
    for (int m = 0; m < n; m++)
    {
        printf()
    }
}
int main(int argc, char const *argv[])
{
    FILE *f1, *f2, *f3;
    f1 = fopen("D:\\vscproject\\1\\c语言代码\\s\\11\\实验2文件\\实验2文件\\第7题\\a1.dat", "rb");
    f2 = fopen("D:\\vscproject\\1\\c语言代码\\s\\11\\实验2文件\\实验2文件\\第7题\\a2.dat", "rb");
    f3 = fopen("D:\\vscproject\\1\\c语言代码\\s\\11\\实验2文件\\实验2文件\\第7题\\a1.dat", "ab+");
    mergeFile(f1, f2, f3);
    fclose(f1);
    fclose(f2);
    fclose(f3);
    return 0;
}
