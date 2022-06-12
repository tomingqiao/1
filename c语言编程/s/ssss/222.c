#include <stdio.h>
#include <stdlib.h>
#include <string.h>
enum Post
{
	manager,	  //经理
	technician,	  //技术员
	Seller,		  //销售员
	Sales_Manager //销售经理
};
struct personnel //员工
{

	int number;			   //职工号
	char name[20];		   //姓名
	char sex[10];		   //性别
	char department[20];   //部门
	enum Post post;		   //岗位
	int length_of_service; //工龄
	int working_hours;	   //工作时间
	int hourly_wage;	   //小时工资
	int sales;			   //销售额
	int basic_salary;	   //底薪
	int mouthly_slaary;	   //当月工资
	struct personnel *next;
};
struct personnel *read_file_data(struct personnel *head)
{
	FILE *f = fopen("D:\\vscproject\\1\\c语言代码\\s\\ssss\\sj.txt", "r");
	struct personnel *p1, *p2 = NULL;
	int i = 0, n = 0;
	char s[100];
	if (fgetc(f) != EOF)
	{
		rewind(f);
		while (!feof(f))
		{
			i++;
			p1 = (struct personnel *)malloc(sizeof(struct personnel));
			fscanf(f, "%d %s %s %s %d %d %d %d %d %d %d\n", &p1->number, p1->name, p1->sex, p1->department, &p1->post, &p1->length_of_service, &p1->working_hours, &p1->hourly_wage, &p1->sales, &p1->basic_salary, &p1->mouthly_slaary);
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
	return head;
}
void Save_information_to_file(struct personnel *head)
{
	void mainmenu(struct personnel * head);
	FILE *f = fopen("D:\\vscproject\\1\\c语言代码\\s\\ssss\\sj.txt", "w");
	struct personnel *p1;
	p1 = head;
	while (p1 != NULL)
	{
		fprintf(f, "%d %s %s %s %d %d %d %d %d %d %d\n", p1->number, p1->name, p1->sex, p1->department, p1->post, p1->length_of_service, p1->working_hours, p1->hourly_wage, p1->sales, p1->basic_salary, p1->mouthly_slaary);
		p1 = p1->next;
	}
	fclose(f);
	mainmenu(head);
}
void mainmenu(struct personnel *head)
{
	void menu1(struct personnel * head);
	void menu2(struct personnel * head);
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
		menu2(head);
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
	void menu12(struct personnel * head);
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
		menu12(head);
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
	void delete13(struct personnel * head);
	void inquiry14(struct personnel * head);
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
		delete13(head);
		break;
	case 4:
		inquiry14(head);
		break;
	case 5:
		menu1(head);
		break;
	case 0:
		exit(0);
	}
}
void menu12(struct personnel *head)
{
	void menu1(struct personnel * head);
	void enter21(struct personnel * head);
	void modify22(struct personnel * head);
	void delete23(struct personnel * head);
	void inquiry24(struct personnel * head);
	void calculate(struct personnel * head);
	printf("************************************************\n");
	printf("*                                              *\n");
	printf("*              工资数据的维护管理              *\n");
	printf("*                                              *\n");
	printf("*                                              *\n");
	printf("*             请选择您要执行的操作             *\n");
	printf("*                                              *\n");
	printf("*                 输入(请按1)                  *\n");
	printf("*                 修改(请按2)                  *\n");
	printf("*                 删除(请按3)                  *\n");
	printf("*                 查询(请按4)                  *\n");
	printf("*                 计算(请按5)                  *\n");
	printf("*              返回上一菜单(请按6)             *\n");
	printf("*                退出系统(请按0)               *\n");
	printf("*                                              *\n");
	printf("************************************************\n");
	int operate;
	scanf("%d", &operate);
	switch (operate)
	{
	case 1:
		enter21(head);
		break;
	case 2:
		modify22(head);
		break;
	case 3:
		delete23(head);
		break;
	case 4:
		inquiry24(head);
		break;
	case 5:
		calculate(head);
		break;
	case 6:
		menu1(head);
		break;
	case 0:
		exit(0);
	}
}
void menu2(struct personnel *head)
{
	void menu1(struct personnel * head);
	printf("************************************************\n");
	printf("*                                              *\n");
	printf("*                  查询数据                    *\n");
	printf("*                                              *\n");
	printf("*                                              *\n");
	printf("*             请选择您要执行的操作             *\n");
	printf("*                                              *\n");
	printf("*         分页显示全部员工的信息(请按1)        *\n");
	printf("*       按部门显示本部门全部员工信息(请按2)    *\n");
	printf("*        分类显示4种岗位的员工信息(请按3)      *\n");
	printf("*       根据工号或者姓名查询员工信息(请按4)    *\n");
	printf("*              返回上一菜单(请按5)             *\n");
	printf("*                退出系统(请按0)               *\n");
	printf("*                                              *\n");
	printf("************************************************\n");
	int operate;
	scanf("%d", &operate);
	switch (operate)
	{
	case 1:

		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		mainmenu(head);
		break;
	case 0:
		exit(0);
	}
}
void add11(struct personnel *head)
{
	int r, a = 0, m;
	struct personnel *p0, *p1, *p2;

	printf("请输入要添加员工的人数：\n");
	scanf("%d", &r);
	p1 = head;
	while (p1 != NULL)
	{
		p1 = p1->next;
		a++;
	}
	for (int i = 0; i < r; i++)
	{
		p1 = head;
		p0 = (struct personnel *)malloc(sizeof(struct personnel));
		printf("请输入第%d个员工信息:(姓名、性别、部门、岗位(用数字代替,经理1,技术员2,销售员3,销售经理4)、工龄)\n", i + 1);
		a = a + 1;
		scanf(" %s %s %s %d %d", p0->name, p0->sex, p0->department, &m, &p0->length_of_service);
		p0->basic_salary = -1;
		p0->mouthly_slaary = -1;
		p0->hourly_wage = -1;
		p0->sales = -1;
		p0->working_hours = -1;
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
void modify11(struct personnel *head)
{
	int a, c;
	char po[4][20] = {{"manager"}, {"technician"}, {"Seller"}, {"Sales_Manager"}};
	char names[20];			//姓名
	char sexs[10];			//性别
	char departments[20];	//部门
	enum Post posts;		//岗位
	int length_of_services; //工龄
	printf("请输入您要修改数据的员工的职工号：\n");
	scanf("%d", &a);
	struct personnel *p;
	p = head;
	while ((p->number != a) && (p->next != NULL))
		p = p->next;
	if (p->number == a)
	{
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
	}
	else if (p->number != a)
		printf("没有查询到该职工号所对应的员工\n");
	menu11(head);
}
void delete13(struct personnel *head)
{
	struct personnel *p1 = head, *p2 = head;
	int n;
	printf("请输入要删除员工的职工号：\n");
	scanf("%d", &n);
	while ((p1->number != n) && (p1->next != NULL))
	{
		p2 = p1;
		p1 = p1->next;
	}
	if (p1->number == n)
	{
		if (head == p1)
		{
			head = p1->next;
		}
		else
		{
			p2->next = p1->next;
		}
		free(p1);
	}
	else
	{
		printf("无该职工\n");
	}
	menu11(head);
}
void inquiry14(struct personnel *head)
{
	struct personnel *p = head;
	int n;
	char po[4][20] = {{"manager"}, {"technician"}, {"Seller"}, {"Sales_Manager"}};
	printf("请输入要查询员工基本数据的职工号：\n");
	scanf("%d", &n);
	while ((p->number != n) && (p->next != NULL))
	{
		p = p->next;
	}
	if (p->number == n)
	{
		printf("该员工的基本数据为:职工号：%d,姓名：%s,性别：%s,部门：%s,岗位：%s,工龄：%d\n", p->number, p->name, p->sex, p->department, po[p->post], p->length_of_service);
	}
	else
	{
		printf("没有查询到该职工\n");
	}
	menu11(head);
}
void enter21(struct personnel *head)
{
	int r, m;
	struct personnel *p0;
	printf("请输入要输入员工工资数据的人数：\n");
	scanf("%d", &r);
	p0 = head;
	while (p0 != NULL)
	{
		if ((p0->working_hours == -1) && (p0->basic_salary == -1) && (p0->hourly_wage == -1) && (p0->sales == -1))
		{
			break;
		}
		p0 = p0->next;
	}
	for (int i = 0; i < r; i++)
	{
		switch (p0->post)
		{
		case manager:
			printf("请输入第%d个经理员工工资数据信息:(底薪)\n", i + 1);
			scanf("%d", &p0->basic_salary);
			break;
		case technician:
			printf("请输入第%d个技术员员工工资数据信息:(工作时间、小时工资)\n", i + 1);
			scanf("%d %d", &p0->working_hours, &p0->hourly_wage);
			break;
		case Seller:
			printf("请输入第%d个销售员员工工资数据信息:(销售额)\n", i + 1);
			scanf("%d", &p0->sales);
			break;
		case Sales_Manager:
			printf("请输入第%d个销售经理员工工资数据信息:(底薪)\n", i + 1);
			scanf("%d", &p0->basic_salary);
			break;
		}
	}
	menu12(head);
}
void modify22(struct personnel *head)
{
	int a, c;
	printf("请输入您要修改数据的员工的职工号：\n");
	scanf("%d", &a);
	struct personnel *p;
	p = head;
	while ((p->number != a) && (p->next != NULL))
		p = p->next;
	if (p->number == a)
	{
		switch (p->post)
		{
		case manager:
			printf("该经理员工工资数据信息(底薪):%d\n", p->basic_salary);
			printf("请输入您要修改的工资数据信息:(底薪)\n");
			scanf("%d", &p->basic_salary);
			break;
		case technician:
			printf("该技术员员工工资数据信息(工作时间、小时工资):%d,%d\n", p->working_hours, p->hourly_wage);
			printf("请输入您要修改的工资数据信息:(工作时间、小时工资)\n");
			scanf("%d %d", &p->working_hours, &p->hourly_wage);
			break;
		case Seller:
			printf("该销售员员工信息(销售额):%d\n", p->sales);
			printf("请输入您要修改的工资数据信息:(销售额)\n");
			scanf("%d", &p->sales);
			break;
		case Sales_Manager:
			printf("该销售经理员工信息(底薪):%d\n", p->basic_salary);
			printf("请输入您要修改的工资数据信息:(底薪)\n");
			scanf("%d", &p->basic_salary);
			break;
		}
	}
	else if (p->number != a)
		printf("没有查询到该职工号所对应的员工\n");
	menu12(head);
}
void delete23(struct personnel *head)
{
	struct personnel *p = head;
	int n;
	printf("请输入要删除员工工资数据的职工号：\n");
	scanf("%d", &n);
	while ((p->number != n) && (p->next != NULL))
	{
		p = p->next;
	}
	if (p->number == n)
	{
		p->basic_salary = -1;
		p->mouthly_slaary = -1;
		p->hourly_wage = -1;
		p->sales = -1;
		p->working_hours = -1;
		printf("删除成功\n");
	}
	else
	{
		printf("没有查询到该职工\n");
	}
	menu12(head);
}
void inquiry24(struct personnel *head)
{
	int a, c;
	printf("请输入您要查询工资数据的员工的职工号：\n");
	scanf("%d", &a);
	struct personnel *p;
	p = head;
	while ((p->number != a) && (p->next != NULL))
		p = p->next;
	if (p->number == a)
	{
		switch (p->post)
		{
		case manager:
			printf("该经理员工工资数据信息(底薪、当月工资):%d,%d\n", p->basic_salary, p->mouthly_slaary);
			break;
		case technician:
			printf("该技术员员工工资数据信息(工作时间、小时工资、当月工资):%d,%d,%d\n", p->working_hours, p->hourly_wage, p->mouthly_slaary);
			break;
		case Seller:
			printf("该销售员员工信息(销售额):%d,%d\n", p->sales, p->mouthly_slaary);
			break;
		case Sales_Manager:
			printf("该销售经理员工信息(底薪):%d,%d\n", p->basic_salary, p->mouthly_slaary);
			break;
		}
	}
	else if (p->number != a)
		printf("没有查询到该职工号所对应的员工\n");
	menu12(head);
}
void calculate(struct personnel *head)
{
	struct personnel *p, *p1;
	p = head;
	int saleall = 0;
	while (p != NULL)
	{
		switch (p->post)
		{
		case manager:
			if ((p->basic_salary != -1) && (p->length_of_service = -1))
			{
				p->mouthly_slaary = p->basic_salary + p->length_of_service * 35;
			}
			break;
		case technician:
			if ((p->working_hours != -1) && (p->hourly_wage != -1) && (p->length_of_service != -1))
			{
				p->mouthly_slaary = p->working_hours * p->hourly_wage + p->length_of_service * 35;
			}
			break;
		case Seller:
			if ((p->sales != -1) && (p->length_of_service = -1))
			{
				p->mouthly_slaary = p->sales * 4 / 100 + p->length_of_service * 35;
			}
			break;
		case Sales_Manager:
			p1 = head;
			while (p1 != NULL)
			{
				if ((strcmp(p1->department, p->department) == 0) && (p1->post == Seller))
				{
					saleall = saleall + p1->sales;
				}
			}
			if ((p->basic_salary != -1) && (p->length_of_service = -1))
			{
				p->mouthly_slaary = p->basic_salary + saleall * 5 / 1000 + p->length_of_service * 35;
			}
			break;
		}
	}
	printf("计算成功\n");
	menu12(head);
}
int main(void)
{
	struct personnel *head = NULL;
	head = read_file_data(head);
	mainmenu(head);
	return 0;
}