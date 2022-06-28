#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct zg
{
    long int num;
    char name[20];
    char sex[20];
    char birth[20];
    char teach[20];
    char zw[20];
    char money[10];
    char ad[20];
    char phone[11];
    struct zg *next;
} s;
void insert(struct zg *s, int n) //输入
{
    int i;
    struct zg *p, *q;
    q = s;
    while (q->next != NULL)
        q = q->next;
    for (i = 0; i < n; i++)
    {
        p = (struct zg *)malloc(sizeof(struct zg));
        printf("请输入第%d位职工号：", i + 1);
        scanf("%ld", &(p->num));
        printf("\n");
        printf("请输入职工姓名：");
        scanf("%s", p->name);
        printf("\n");
        printf("请输入职工性别：");
        scanf("%s", p->sex);
        printf("\n");
        printf("请输入职工生日：");
        scanf("%s", p->birth);
        printf("\n");
        printf("请输入职工学历：");
        scanf("%s", p->teach);
        printf("\n");
        printf("请输入职工职务：");
        scanf("%s", p->zw);
        printf("\n");
        printf("请输入职工工资：");
        scanf("%s", p->money);
        printf("\n");
        printf("请输入职工住址：");
        scanf("%s", p->ad);
        printf("\n");
        printf("请输入职工电话：");
        scanf("%s", p->phone);
        printf("\n");
        p->next = NULL;
        q->next = p;
        q = p;
    }
}
struct zg *find(struct zg *s, long int num1) //查找
{
    struct zg *p;
    int flag = 0;
    p = s->next;
    while (p != NULL)
    {
        if (p->num == num1)
        {
            printf("查找成功！\n");
            flag = 1;
            return p;
        }
        p = p->next;
    }
    if (flag == 0)
    {
        printf("查无此人！\n");
    }
}
void delet(struct zg *s, long int num1) //删除
{
    struct zg *p, *q, *t;
    int flag = 0;
    p = s->next;
    q = s;
    while (p != NULL)
    {
        if (p->num == num1)
        {
            t = p;
            q->next = p->next;
            free(t);
            printf("删除成功!\n");
            flag = 1;
            break;
        }
        q = q->next;
        p = p->next;
    }
    if (flag == 0)
    {
        printf("删除失败！\n");
    }
}
void update(struct zg *s, long int num1) //更新信息
{
    struct zg *p;
    p = find(s, num1);
    printf("1.更新生日：");
    scanf("%s", &(p->birth));
    printf("2.更新学历：");
    scanf("%s", &(p->teach));
    printf("3.更新职务：");
    scanf("%s", &(p->zw));
    printf("4.更新工资：");
    scanf("%s", p->money);
    printf("5.更新电话：");
    scanf("%s", &(p->phone));
    printf("更新成功！\n");
}
void prints(struct zg *s, int l) //输出
{
    int i;
    struct zg *p;
    p = s->next;
    for (i = 0; i < l; i++)
    {
        printf("姓名：");
        puts(p->name);
        printf("性别：");
        puts(p->sex);
        printf("生日：");
        puts(p->birth);
        printf("学历：");
        puts(p->teach);
        printf("职务：");
        puts(p->zw);
        printf("工资：");
        puts(p->money);
        printf("住址：");
        puts(p->ad);
        printf("电话：");
        puts(p->phone);
        printf("\n\n");
        p = p->next;
    }
}
void zhuyemian() //主页面
{
    printf("\t\t\t\t1.插入职工信息\n");
    printf("\t\t\t\t2.删除职工信息\n");
    printf("\t\t\t\t3.更新职工信息\n");
    printf("\t\t\t\t4.查找职工信息\n");
    printf("\t\t\t\t5.打印职工信息\n");
    printf("\t\t\t\t6.保存职工信息\n");
    printf("\t\t\t\t7.退出        \n");
}
void createFile(FILE *fp) //创建
{
    fp = fopen("01.txt", "w");
    if (!fp)
    {
        printf("file open faile!");
        exit(0);
    }
    //	fprintf(fp, "%s           %s           %s           %s           %s           %s           %s           %s           %s\n", "工号", "姓名", "性别", "生日", "学历", "职务", "工资", "住址", "电话");
    fclose(fp);
    printf("创建文本成功!\n");
}
void save(struct zg *s, int n, FILE *fp) //保存
{
    int i;
    struct zg *p, *q;
    p = s->next;
    q = s;
    if ((fp = fopen("D:\\TXTtext\\01.txt", "a")) == NULL)
    {
        printf("保存失败!");
        exit(0);
    }
    for (i = 0; i < n; i++)
    {
        fprintf(fp, " %ld       %s        %s           %s         %s          %s         %s         %s         %s\n", p->num, p->name, p->sex, p->birth, p->teach, p->zw, p->money, p->ad, p->phone);
        q = q->next;
        p = p->next;
    }
    fclose(fp);
    printf("保存成功!\n");
}

void read(struct zg *s, int *l)
{
    FILE *fp;
    long m;
    int i = 0;
    struct zg p, *p1 = NULL, *p2 = NULL;
    if ((fp = fopen("D:\\TXTtext\\01.txt", "ab+")) == NULL)
    {
        printf("不能正常打开文件!\n");
        exit(0);
    }
    //	fprintf(fp, "%s           %s           %s           %s           %s           %s           %s           %s           %s\n", "工号", "姓名", "性别", "生日", "学历", "职务", "工资", "住址", "电话");
    fseek(fp, 0, 2);
    m = ftell(fp);
    rewind(fp);
    if (m == ftell(fp))
    {
        printf("文件中无职工信息！请先添加职工信息。\n");
        return;
    }
    else
    {
        while (m != ftell(fp))
        {
            fscanf(fp, "%ld%s%s%s%s%s%s%s%s\n", &p.num, p.name, p.sex, p.birth, p.teach, p.zw, p.money, p.ad, p.phone);
            if ((p1 = (struct zg *)malloc(sizeof(struct zg))) == NULL)
            {
                printf("不能成功分配空间！\n");
                exit(0);
            }
            *p1 = p;
            p1->next = NULL;
            if (i == 0)
                s->next = p1;
            else
                p2->next = p1;
            p2 = p1;
            i++;
        }
    }
    *l = i;
    fclose(fp);
}

int main()
{
    FILE *fp = NULL;
    int mima = 666;
    int mm;
    int e, n, l = 0;
    long int d;
    printf("请输入管理员密码\n");
    scanf("%d", &mm);
    if (mm == mima)
    {
        printf("密码正确！\n");
    }
    else
    {
        printf("密码错误！系统关闭！\n");
        return 0;
    }
    read(&s, &l);
    zhuyemian();
    while (1)
    {
        scanf("%d", &e);
        switch (e)
        {
        case 1:
            printf("输入人数：");
            scanf("%d", &n);
            getchar();
            l = l + n;
            insert(&s, n);
            system("CLS");
            break;
        case 2:
            printf("请输入要删除员工的员工号：");
            scanf("%ld", &d);
            delet(&s, d);
            l--;
            break;
        case 3:
            printf("输入要更新员工的员工号：");
            scanf("%ld", &d);
            update(&s, d);
            break;
        case 4:
            printf("请输入要查找的员工号：");
            scanf("%ld", &d);
            find(&s, d);
            prints(&s, l);
            break;
        case 5:
            prints(&s, l);
            break;
        case 6:
            createFile(fp);
            save(&s, n, fp);
            break;
        case 7:
            return 0;
        }
        zhuyemian();
    }
    return 0;
}
