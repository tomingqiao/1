#include <stdio.h>
#include <stdlib.h>
#include <string.h>
enum Post
{
    manager,      //经理
    technician,   //技术员
    Seller,       //销售员
    Sales_Manager //销售经理
};
struct personnel //员工
{

    int number;            //职工号
    char name[20];         //姓名
    char sex[10];          //性别
    char department[20];   //部门
    enum Post post;        //岗位
    int length_of_service; //工龄
    // int working_hours;     //工作时间
    // int hourly_wage;       //小时工资
    // int sales;             //销售额
    // int basic_salary;      //底薪
    // int mouthly_slaary;    //当月工资
    struct personnel *next;
};
void read_file_data(struct personnel *head)
{
    FILE *f = fopen("D:\\vscproject\\1\\c语言代码\\s\\ssss\\sj.txt", "r");
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
    FILE *f = fopen("D:\\vscproject\\1\\c语言代码\\s\\ssss\\sj.txt", "w");
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
    printf("*           欢迎来到员工工资管理系统           *\n");
    printf("*                                              *\n");
    printf("*                                              *\n");
    printf("*             请选择您要执行的操作             *\n");
    printf("*                                              *\n");
    printf("*              数据维护管理(请按1)             *\n");
    printf("*                查询数据(请按2)               *\n");
    printf("*                  排序(请按3)                 *\n");
    printf("*                  统计(请按4)                 *\n");
    printf("*             保存员工信息到文件(请按5)        *\n");
    printf("*                退出系统(请按0)               *\n");
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
    printf("*                数据维护管理                  *\n");
    printf("*                                              *\n");
    printf("*                                              *\n");
    printf("*             请选择您要执行的操作             *\n");
    printf("*                                              *\n");
    printf("*          基本资料数据的维护管理(请按1)       *\n");
    printf("*           工资数据的维护管理(请按2)          *\n");
    printf("*              返回上一菜单(请按3)             *\n");
    printf("*                退出系统(请按0)               *\n");
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
    printf("*            基本资料数据的维护管理            *\n");
    printf("*                                              *\n");
    printf("*                                              *\n");
    printf("*             请选择您要执行的操作             *\n");
    printf("*                                              *\n");
    printf("*                 添加(请按1)                  *\n");
    printf("*                 修改(请按2)                  *\n");
    printf("*                 删除(请按3)                  *\n");
    printf("*                 查询(请按4)                  *\n");
    printf("*              返回上一菜单(请按5)             *\n");
    printf("*                退出系统(请按0)               *\n");
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

    printf("请输入要添加员工的人数：");
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
        printf("请输入第%d个员工信息:(姓名、性别、部门、岗位(用数字代替,经理1,技术员2,销售员3,销售经理4)、工龄)", i + 1);
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
    char names[20];         //姓名
    char sexs[10];          //性别
    char departments[20];   //部门
    enum Post posts;        //岗位
    int length_of_services; //工龄
    printf("请输入您要修改数据的员工的职工号：");
    scanf("%d", &a);
    struct personnel *p;
    p = head;
    while ((p->number != a) && (p->next != NULL))
        p = p->next;
    printf("该员工的数据为:职工号：%d,姓名：%s,性别：%s,部门：%s,岗位：%s,工龄：%d\n", p->number, p->name, p->sex, p->department, po[p->post], p->length_of_service);
    printf("请输入您要修改的数据：(姓名、性别、部门、岗位(用数字代替,经理1,技术员2,销售员3,销售经理4)、工龄)\n");
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
        printf("没有查询到该职工号所对应的员工");
    menu11(head);
}
int main(void)
{
    struct personnel *head = NULL;
    mainmenu(head);
    return 0;
}