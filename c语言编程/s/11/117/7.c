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
    int i = 0, j = 0, n, a;
    while (!feof(f1))
    {
        fscanf(f1, "%d %s %d", &s1[i].xh, s1[i].name, &s1[i].cj);
        i++;
    }
    while (!feof(f2))
    {
        fscanf(f2, "%d %s %d", &s2[j].xh, s2[j].name, &s2[j].cj);
        j++;
    }
    n = i + j;
    j = i = 0;
    for (int m = 0; m < n; m++)
    {
        a = m;
        if (s1[i].cj <= s2[j].cj)
        {
            s3[m] = s1[i];
            i++;
            continue;
        }
        if (s1[i].cj > s2[j].cj)
        {
            s3[m] = s2[j];
            j++;
            continue;
        }
    }
    if (s1[i].cj >= s2[j].cj)
    {
        s3[a] = s1[i];
    }
    else
    {
        s3[a] = s2[j];
    }
    for (int m = 0; m < n; m++)
    {
        printf("%d %s %d\n", s3[m].xh, s3[m].name, s3[m].cj);
    }
    for (int m = 0; m < n; m++)
    {
        fwrite(&s3[m], sizeof(s3[m]), 1, f3);
    }
}
int main(int argc, char const *argv[])
{
    FILE *f1, *f2, *f3;
    f1 = fopen("D:\\vscproject\\1\\c语言代码\\s\\11\\实验2文件\\实验2文件\\第7题\\a1.dat", "rb");
    f2 = fopen("D:\\vscproject\\1\\c语言代码\\s\\11\\实验2文件\\实验2文件\\第7题\\a2.dat", "rb");
    f3 = fopen("D:\\vscproject\\1\\c语言代码\\s\\11\\实验2文件\\实验2文件\\第7题\\a3.dat", "ab+");
    mergeFile(f1, f2, f3);
    fclose(f1);
    fclose(f2);
    fclose(f3);
    return 0;
}
