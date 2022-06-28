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
void insert(struct zg *s, int n) //����
{
    int i;
    struct zg *p, *q;
    q = s;
    while (q->next != NULL)
        q = q->next;
    for (i = 0; i < n; i++)
    {
        p = (struct zg *)malloc(sizeof(struct zg));
        printf("�������%dλְ���ţ�", i + 1);
        scanf("%ld", &(p->num));
        printf("\n");
        printf("������ְ��������");
        scanf("%s", p->name);
        printf("\n");
        printf("������ְ���Ա�");
        scanf("%s", p->sex);
        printf("\n");
        printf("������ְ�����գ�");
        scanf("%s", p->birth);
        printf("\n");
        printf("������ְ��ѧ����");
        scanf("%s", p->teach);
        printf("\n");
        printf("������ְ��ְ��");
        scanf("%s", p->zw);
        printf("\n");
        printf("������ְ�����ʣ�");
        scanf("%s", p->money);
        printf("\n");
        printf("������ְ��סַ��");
        scanf("%s", p->ad);
        printf("\n");
        printf("������ְ���绰��");
        scanf("%s", p->phone);
        printf("\n");
        p->next = NULL;
        q->next = p;
        q = p;
    }
}
struct zg *find(struct zg *s, long int num1) //����
{
    struct zg *p;
    int flag = 0;
    p = s->next;
    while (p != NULL)
    {
        if (p->num == num1)
        {
            printf("���ҳɹ���\n");
            flag = 1;
            return p;
        }
        p = p->next;
    }
    if (flag == 0)
    {
        printf("���޴��ˣ�\n");
    }
}
void delet(struct zg *s, long int num1) //ɾ��
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
            printf("ɾ���ɹ�!\n");
            flag = 1;
            break;
        }
        q = q->next;
        p = p->next;
    }
    if (flag == 0)
    {
        printf("ɾ��ʧ�ܣ�\n");
    }
}
void update(struct zg *s, long int num1) //������Ϣ
{
    struct zg *p;
    p = find(s, num1);
    printf("1.�������գ�");
    scanf("%s", &(p->birth));
    printf("2.����ѧ����");
    scanf("%s", &(p->teach));
    printf("3.����ְ��");
    scanf("%s", &(p->zw));
    printf("4.���¹��ʣ�");
    scanf("%s", p->money);
    printf("5.���µ绰��");
    scanf("%s", &(p->phone));
    printf("���³ɹ���\n");
}
void prints(struct zg *s, int l) //���
{
    int i;
    struct zg *p;
    p = s->next;
    for (i = 0; i < l; i++)
    {
        printf("������");
        puts(p->name);
        printf("�Ա�");
        puts(p->sex);
        printf("���գ�");
        puts(p->birth);
        printf("ѧ����");
        puts(p->teach);
        printf("ְ��");
        puts(p->zw);
        printf("���ʣ�");
        puts(p->money);
        printf("סַ��");
        puts(p->ad);
        printf("�绰��");
        puts(p->phone);
        printf("\n\n");
        p = p->next;
    }
}
void zhuyemian() //��ҳ��
{
    printf("\t\t\t\t1.����ְ����Ϣ\n");
    printf("\t\t\t\t2.ɾ��ְ����Ϣ\n");
    printf("\t\t\t\t3.����ְ����Ϣ\n");
    printf("\t\t\t\t4.����ְ����Ϣ\n");
    printf("\t\t\t\t5.��ӡְ����Ϣ\n");
    printf("\t\t\t\t6.����ְ����Ϣ\n");
    printf("\t\t\t\t7.�˳�        \n");
}
void createFile(FILE *fp) //����
{
    fp = fopen("01.txt", "w");
    if (!fp)
    {
        printf("file open faile!");
        exit(0);
    }
    //	fprintf(fp, "%s           %s           %s           %s           %s           %s           %s           %s           %s\n", "����", "����", "�Ա�", "����", "ѧ��", "ְ��", "����", "סַ", "�绰");
    fclose(fp);
    printf("�����ı��ɹ�!\n");
}
void save(struct zg *s, int n, FILE *fp) //����
{
    int i;
    struct zg *p, *q;
    p = s->next;
    q = s;
    if ((fp = fopen("D:\\TXTtext\\01.txt", "a")) == NULL)
    {
        printf("����ʧ��!");
        exit(0);
    }
    for (i = 0; i < n; i++)
    {
        fprintf(fp, " %ld       %s        %s           %s         %s          %s         %s         %s         %s\n", p->num, p->name, p->sex, p->birth, p->teach, p->zw, p->money, p->ad, p->phone);
        q = q->next;
        p = p->next;
    }
    fclose(fp);
    printf("����ɹ�!\n");
}

void read(struct zg *s, int *l)
{
    FILE *fp;
    long m;
    int i = 0;
    struct zg p, *p1 = NULL, *p2 = NULL;
    if ((fp = fopen("D:\\TXTtext\\01.txt", "ab+")) == NULL)
    {
        printf("�����������ļ�!\n");
        exit(0);
    }
    //	fprintf(fp, "%s           %s           %s           %s           %s           %s           %s           %s           %s\n", "����", "����", "�Ա�", "����", "ѧ��", "ְ��", "����", "סַ", "�绰");
    fseek(fp, 0, 2);
    m = ftell(fp);
    rewind(fp);
    if (m == ftell(fp))
    {
        printf("�ļ�����ְ����Ϣ���������ְ����Ϣ��\n");
        return;
    }
    else
    {
        while (m != ftell(fp))
        {
            fscanf(fp, "%ld%s%s%s%s%s%s%s%s\n", &p.num, p.name, p.sex, p.birth, p.teach, p.zw, p.money, p.ad, p.phone);
            if ((p1 = (struct zg *)malloc(sizeof(struct zg))) == NULL)
            {
                printf("���ܳɹ�����ռ䣡\n");
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
    printf("���������Ա����\n");
    scanf("%d", &mm);
    if (mm == mima)
    {
        printf("������ȷ��\n");
    }
    else
    {
        printf("�������ϵͳ�رգ�\n");
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
            printf("����������");
            scanf("%d", &n);
            getchar();
            l = l + n;
            insert(&s, n);
            system("CLS");
            break;
        case 2:
            printf("������Ҫɾ��Ա����Ա���ţ�");
            scanf("%ld", &d);
            delet(&s, d);
            l--;
            break;
        case 3:
            printf("����Ҫ����Ա����Ա���ţ�");
            scanf("%ld", &d);
            update(&s, d);
            break;
        case 4:
            printf("������Ҫ���ҵ�Ա���ţ�");
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
