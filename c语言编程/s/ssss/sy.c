#include <stdio.h>
#include <stdlib.h>
#include <string.h>
enum Post
{
    manager,      //����
    technician,   //����Ա
    Seller,       //����Ա
    Sales_Manager //���۾���
};
struct personnel //Ա��
{

    int number;            //ְ����
    char name[20];         //����
    char sex[10];          //�Ա�
    char department[20];   //����
    enum Post post;        //��λ
    int length_of_service; //����
    // int working_hours;     //����ʱ��
    // int hourly_wage;       //Сʱ����
    // int sales;             //���۶�
    // int basic_salary;      //��н
    // int mouthly_slaary;    //���¹���
    struct personnel *next;
};
void read_file_data(struct personnel *head)
{
    FILE *f = fopen("D:\\vscproject\\1\\c���Դ���\\s\\ssss\\sj.txt", "r");
    struct personnel *p1, *p2 = NULL, str;
    int i = 0, n = 0;
    char s[100];
    if (fgetc(f) != EOF)
    {
        int m;
        rewind(f);
        while (!feof(f))
        {
            n++;
            p1 = (struct personnel *)malloc(sizeof(struct personnel));
            fscanf(f, "%d %s %s %s %d %d", &p1->number, p1->name, p1->sex, p1->department, &p1->post, &p1->length_of_service);
            // printf("%d %s %s %s %d %d %d %d %d %d %d\n", p1->number, p1->name, p1->sex, p1->department, p1->post, p1->length_of_service, p1->working_hours, p1->hourly_wage, p1->sales, p1->basic_salary);
        }
        rewind(f);
        for (int a = 0; a < n - 1; a++)
        {
            i++;
            int m;
            p1 = (struct personnel *)malloc(sizeof(struct personnel));
            // fread(p1, sizeof(struct personnel), 1, f);
            fscanf(f, "%d %s %s %s %d %d", &p1->number, p1->name, p1->sex, p1->department, &p1->post, &p1->length_of_service);
            printf("%d %s %s %s %d %d\n", p1->number, p1->name, p1->sex, p1->department, p1->post, p1->length_of_service);
            //  printf("%d", p1->postint);
            // switch (m)
            // {
            // case 1:
            //     p1->post = manager;
            //     break;
            // case 2:
            //     p1->post = technician;
            //     break;
            // case 3:
            //     p1->post = Seller;
            //     break;
            // case 4:
            //     p1->post = Sales_Manager;
            //     break;
            // }
            p1->next = NULL;
            if (i == 1)
            {
                head = p1;
            }
            else
            {
                p2->next = p1;
            }
            p2 = p1;
        }
    }
    fclose(f);
}
void Save_information_to_file(struct personnel *head)
{
    void mainmenu(struct personnel * head);
    FILE *f = fopen("D:\\vscproject\\1\\c���Դ���\\s\\ssss\\sj.txt", "w");
    struct personnel *p1;
    p1 = head;
    while (p1 != NULL)
    {
        // int m;
        // switch (p1->post)
        // {
        // case manager:
        // 	m = 1;
        // 	break;
        // case technician:
        // 	m = 2;
        // 	;
        // 	break;
        // case Seller:
        // 	m = 3;
        // 	break;
        // case Sales_Manager:
        // 	m = 4;
        // 	break;
        // }
        fprintf(f, "%d %s %s %s %d %d\n", p1->number, p1->name, p1->sex, p1->department, p1->post, p1->length_of_service);
        p1 = p1->next;
    }
    fclose(f);
    mainmenu(head);
}
void mainmenu(struct personnel *head)
{
    read_file_data(head);
    void menu1(struct personnel * head);
    printf("************************************************\n");
    printf("*                                              *\n");
    printf("*           ��ӭ����Ա�����ʹ���ϵͳ           *\n");
    printf("*                                              *\n");
    printf("*                                              *\n");
    printf("*             ��ѡ����Ҫִ�еĲ���             *\n");
    printf("*                                              *\n");
    printf("*              ����ά������(�밴1)             *\n");
    printf("*                ��ѯ����(�밴2)               *\n");
    printf("*                  ����(�밴3)                 *\n");
    printf("*                  ͳ��(�밴4)                 *\n");
    printf("*             ����Ա����Ϣ���ļ�(�밴5)        *\n");
    printf("*                �˳�ϵͳ(�밴0)               *\n");
    printf("*                                              *\n");
    printf("************************************************\n");
    int operate;
    scanf("%d", &operate);
    switch (operate)
    {
    case 1:
        menu1(head);
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        Save_information_to_file(head);
        break;
    case 0:
        exit(0);
    }
}
void menu1(struct personnel *head)
{
    void menu11(struct personnel * head);
    printf("************************************************\n");
    printf("*                                              *\n");
    printf("*                ����ά������                  *\n");
    printf("*                                              *\n");
    printf("*                                              *\n");
    printf("*             ��ѡ����Ҫִ�еĲ���             *\n");
    printf("*                                              *\n");
    printf("*          �����������ݵ�ά������(�밴1)       *\n");
    printf("*           �������ݵ�ά������(�밴2)          *\n");
    printf("*              ������һ�˵�(�밴3)             *\n");
    printf("*                �˳�ϵͳ(�밴0)               *\n");
    printf("*                                              *\n");
    printf("************************************************\n");
    int operate;
    scanf("%d", &operate);
    switch (operate)
    {
    case 1:
        menu11(head);
        break;
    case 2:
        break;
    case 3:
        mainmenu(head);
        break;
    case 0:
        exit(0);
    }
}
void menu11(struct personnel *head)
{
    void menu1(struct personnel * head);
    void add11(struct personnel * head);
    void modify11(struct personnel * head);
    printf("************************************************\n");
    printf("*                                              *\n");
    printf("*            �����������ݵ�ά������            *\n");
    printf("*                                              *\n");
    printf("*                                              *\n");
    printf("*             ��ѡ����Ҫִ�еĲ���             *\n");
    printf("*                                              *\n");
    printf("*                 ���(�밴1)                  *\n");
    printf("*                 �޸�(�밴2)                  *\n");
    printf("*                 ɾ��(�밴3)                  *\n");
    printf("*                 ��ѯ(�밴4)                  *\n");
    printf("*              ������һ�˵�(�밴5)             *\n");
    printf("*                �˳�ϵͳ(�밴0)               *\n");
    printf("*                                              *\n");
    printf("************************************************\n");
    int operate;
    scanf("%d", &operate);
    switch (operate)
    {
    case 1:
        add11(head);
        break;
    case 2:
        modify11(head);
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        menu1(head);
        break;
    case 0:
        exit(0);
    }
}
void add11(struct personnel *head) // dddddddddddddddddddddddddddddddd
{
    int r, a = 0, m;
    struct personnel *p0, *p1, *p2;

    printf("������Ҫ���Ա����������");
    scanf("%d", &r);
    p1 = head;
    while (p1 != NULL)
    {
        p2 = p1;
        p1 = p1->next;
        a++;
    }
    for (int i = 0; i < r; i++)
    {
        p1 = head;
        p0 = (struct personnel *)malloc(sizeof(struct personnel));
        printf("�������%d��Ա����Ϣ:(�������Ա𡢲��š���λ(�����ִ���,����1,����Ա2,����Ա3,���۾���4)������)", i + 1);
        a = a + 1;
        scanf(" %s %s %s %d %d", p0->name, p0->sex, p0->department, &m, &p0->length_of_service);
        switch (m)
        {
        case 1:
            p0->post = manager;
            break;
        case 2:
            p0->post = technician;
            break;
        case 3:
            p0->post = Seller;
            break;
        case 4:
            p0->post = Sales_Manager;
            break;
        }
        p0->number = a;
        if (head == NULL)
        {
            head = p0;
            p0->next = NULL;
        }
        else
        {
            while (p1->next != NULL)
            {
                p2 = p1;
                p1 = p1->next;
            }
            if (p1->next == NULL)
            {
                p1->next = p0;
                p0->next = NULL;
            }
        }
    }
    menu11(head);
}
void modify11(struct personnel *head) // aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
{
    int a, c;
    char po[4][20] = {{"manager"}, {"technician"}, {"Seller"}, {"Sales_Manager"}};
    char names[20];         //����
    char sexs[10];          //�Ա�
    char departments[20];   //����
    enum Post posts;        //��λ
    int length_of_services; //����
    printf("��������Ҫ�޸����ݵ�Ա����ְ���ţ�");
    scanf("%d", &a);
    struct personnel *p;
    p = head;
    while ((p->number != a) && (p->next != NULL))
        p = p->next;
    printf("��Ա��������Ϊ:ְ���ţ�%d,������%s,�Ա�%s,���ţ�%s,��λ��%s,���䣺%d\n", p->number, p->name, p->sex, p->department, po[p->post], p->length_of_service);
    printf("��������Ҫ�޸ĵ����ݣ�(�������Ա𡢲��š���λ(�����ִ���,����1,����Ա2,����Ա3,���۾���4)������)\n");
    scanf("%s %s %s %d %d", names, sexs, departments, &c, &length_of_services);
    switch (c)
    {
    case 1:
        p->post = manager;
        break;
    case 2:
        p->post = technician;
        ;
        break;
    case 3:
        p->post = Seller;
        break;
    case 4:
        p->post = Sales_Manager;
        break;
    }
    strcpy(p->name, names);
    strcpy(p->sex, sexs);
    strcpy(p->department, departments);
    p->length_of_service = length_of_services;
    if (p->number != a)
        printf("û�в�ѯ����ְ��������Ӧ��Ա��");
    menu11(head);
}
int main(void)
{
    struct personnel *head = NULL;
    mainmenu(head);
    return 0;
}