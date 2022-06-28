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
	FILE *f = fopen("D:\\vscproject\\1\\c语言编程\\s\\ssss\\sj.txt", "r");
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
	FILE *f = fopen("D:\\vscproject\\1\\c语言编程\\s\\ssss\\sj.txt", "w");
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
	void menu3(struct personnel * head);
	void menu4(struct personnel * head);
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
		menu3(head);
		break;
	case 4:
		menu4(head);
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
	void Query_data(struct personnel * head);
	void Display_data_by_department(struct personnel * head);
	void Display_data_by_post(struct personnel * head);
	void inquiry34(struct personnel * head);
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
		Query_data(head);
		break;
	case 2:
		Display_data_by_department(head);
		break;
	case 3:
		Display_data_by_post(head);
		break;
	case 4:
		inquiry34(head);
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
		if (p0 == NULL)
		{
			break;
		}
		switch (p0->post)
		{
		case manager:
			printf("请输入第%d个经理员工工资数据信息:(底薪8000)\n", i + 1);
			scanf("%d", &p0->basic_salary);
			break;
		case technician:
			printf("请输入第%d个技术员员工工资数据信息:(工作时间、小时工资100)\n", i + 1);
			scanf("%d %d", &p0->working_hours, &p0->hourly_wage);
			break;
		case Seller:
			printf("请输入第%d个销售员员工工资数据信息:(销售额)\n", i + 1);
			scanf("%d", &p0->sales);
			break;
		case Sales_Manager:
			printf("请输入第%d个销售经理员工工资数据信息:(底薪8000)\n", i + 1);
			scanf("%d", &p0->basic_salary);
			break;
		}
		p0 = p0->next;
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
		if (p->mouthly_slaary == -1)
		{
			switch (p->post)
			{
			case manager:
				if ((p->basic_salary != -1) && (p->length_of_service != -1))
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
				if ((p->sales != -1) && (p->length_of_service != -1))
				{
					p->mouthly_slaary = p->sales * 4 / 100 + p->length_of_service * 35;
				}
				break;
			case Sales_Manager:
				p1 = head;
				while (p1 != NULL)
				{
					if ((strcmp(p1->department, p->department) == 0) && (p1->post == Seller) && (p1->sales != -1))
					{
						saleall = saleall + p1->sales;
					}
					p1 = p1->next;
				}
				if ((p->basic_salary != -1) && (p->length_of_service != -1))
				{
					p->mouthly_slaary = p->basic_salary + saleall * 5 / 1000 + p->length_of_service * 35;
				}
				break;
			}
		}
		p = p->next;
	}
	printf("计算成功\n");
	menu12(head);
}
void Query_data(struct personnel *head)
{
	struct personnel *p1;
	int m = 1, i, n;
	char po[4][20] = {{"manager"}, {"technician"}, {"Seller"}, {"Sales_Manager"}};
	p1 = head;
	printf("*************************************************************************************************************************************************\n");
	printf("\n");
	printf("职工号         姓名           性别           部门           岗位           工龄           工作时间       小时工资       销售额         底薪           当月工资\n");
	for (i = 0; (i < 10) && (p1 != NULL); i++)
	{
		printf("%-15d%-15s%-15s%-15s%-15s%-15d%-15d%-15d%-15d%-15d%-15d\n", p1->number, p1->name, p1->sex, p1->department, po[p1->post], p1->length_of_service, p1->working_hours, p1->hourly_wage, p1->sales, p1->basic_salary, p1->mouthly_slaary);
		p1 = p1->next;
	}
	printf("\n");
	printf("首页(请按1)                   上一页(请按2)                     下一页(请按3)                     最后一页(请按4)                     退出(请按0)\n");
	printf("*************************************************************************************************************************************************\n");
	while (m == 1)
	{
		int o;
		scanf("%d", &o);
		switch (o)
		{
		case 1:
			p1 = head;
			printf("*************************************************************************************************************************************************\n");
			printf("\n");
			printf("职工号   姓名        性别        部门      岗位              工龄            工作时间         小时工资       销售额        底薪          当月工资\n");
			for (i = 1; (i <= 10) && (p1 != NULL); i++)
			{
				printf("%-15d%-15s%-15s%-15s%-15s%-15d%-15d%-15d%-15d%-15d%-15d\n", p1->number, p1->name, p1->sex, p1->department, po[p1->post], p1->length_of_service, p1->working_hours, p1->hourly_wage, p1->sales, p1->basic_salary, p1->mouthly_slaary);
				p1 = p1->next;
			}
			printf("\n");
			printf("首页(请按1)                   上一页(请按2)                     下一页(请按3)                     最后一页(请按4)                     退出(请按0)\n");
			printf("*************************************************************************************************************************************************\n");
			break;
		case 2:
			p1 = head;
			for (n = 1; (n <= (i = i - 20)) && (p1 != NULL); n++)
			{
				p1 = p1->next;
			}
			if (i < 0)
			{
				printf("无上一页\n");
				break;
			}
			n = i + 1;
			i = i + 10;
			printf("*************************************************************************************************************************************************\n");
			printf("\n");
			printf("职工号         姓名           性别           部门           岗位           工龄           工作时间       小时工资       销售额         底薪           当月工资\n");
			for (; (n <= i) && (p1 != NULL); n++)
			{
				printf("%-15d%-15s%-15s%-15s%-15s%-15d%-15d%-15d%-15d%-15d%-15d\n", p1->number, p1->name, p1->sex, p1->department, po[p1->post], p1->length_of_service, p1->working_hours, p1->hourly_wage, p1->sales, p1->basic_salary, p1->mouthly_slaary);
				p1 = p1->next;
			}
			printf("\n");
			printf("首页(请按1)                   上一页(请按2)                     下一页(请按3)                     最后一页(请按4)                     退出(请按0)\n");
			printf("*************************************************************************************************************************************************\n");
			break;
		case 3:
			p1 = head;
			if (i <= 0)
			{
				i = 10;
			}
			for (n = 1; (n <= i) && (p1 != NULL); n++)
			{
				p1 = p1->next;
			}
			if (p1 == NULL)
			{
				printf("无下一页\n");
				break;
			}
			n = i + 1;
			i = i + 10;
			printf("*************************************************************************************************************************************************\n");
			printf("\n");
			printf("职工号         姓名           性别           部门           岗位           工龄           工作时间       小时工资       销售额         底薪           当月工资\n");
			for (; (n <= i) && (p1 != NULL); n++)
			{
				printf("%-15d%-15s%-15s%-15s%-15s%-15d%-15d%-15d%-15d%-15d%-15d\n", p1->number, p1->name, p1->sex, p1->department, po[p1->post], p1->length_of_service, p1->working_hours, p1->hourly_wage, p1->sales, p1->basic_salary, p1->mouthly_slaary);
				p1 = p1->next;
			}
			printf("\n");
			printf("首页(请按1)                   上一页(请按2)                     下一页(请按3)                     最后一页(请按4)                     退出(请按0)\n");
			printf("*************************************************************************************************************************************************\n");
			break;
		case 4:
			int g = 0;
			p1 = head;
			while (p1 != NULL)
			{
				p1 = p1->next;
				g++;
			}
			p1 = head;
			for (n = 1; n <= (i = (g / 10) * 10); n++)
			{
				p1 = p1->next;
			}
			n = i + 1;
			i = i + 10;
			printf("*************************************************************************************************************************************************\n");
			printf("\n");
			printf("职工号         姓名           性别           部门           岗位           工龄           工作时间       小时工资       销售额         底薪           当月工资\n");
			for (; (n <= i) && (p1 != NULL); n++)
			{
				printf("%-15d%-15s%-15s%-15s%-15s%-15d%-15d%-15d%-15d%-15d%-15d\n", p1->number, p1->name, p1->sex, p1->department, po[p1->post], p1->length_of_service, p1->working_hours, p1->hourly_wage, p1->sales, p1->basic_salary, p1->mouthly_slaary);
				p1 = p1->next;
			}
			printf("\n");
			printf("首页(请按1)                   上一页(请按2)                     下一页(请按3)                     最后一页(请按4)                     退出(请按0)\n");
			printf("*************************************************************************************************************************************************\n");
			break;
		case 0:
			m = 2;
			break;
		}
	}
	menu2(head);
}
void Display_data_by_department(struct personnel *head)
{
	char dep[20];
	char po[4][20] = {{"manager"}, {"technician"}, {"Seller"}, {"Sales_Manager"}};
	printf("请输入您要查询部门全部员工信息的部门名称：\n");
	scanf("%s", dep);
	struct personnel *p;
	p = head;
	printf("*************************************************************************************************************************************************\n");
	printf("\n");
	printf("职工号         姓名           性别           部门           岗位           工龄           工作时间       小时工资       销售额         底薪           当月工资\n");
	while (p != NULL)
	{
		if (strcmp(dep, p->department) == 0)
		{
			printf("%-15d%-15s%-15s%-15s%-15s%-15d%-15d%-15d%-15d%-15d%-15d\n", p->number, p->name, p->sex, p->department, po[p->post], p->length_of_service, p->working_hours, p->hourly_wage, p->sales, p->basic_salary, p->mouthly_slaary);
		}
		p = p->next;
	}
	printf("\n");
	printf("*************************************************************************************************************************************************\n");
	menu2(head);
}
void Display_data_by_post(struct personnel *head)
{
	int pos;
	char po[4][20] = {{"manager"}, {"technician"}, {"Seller"}, {"Sales_Manager"}};
	printf("请输入您要查询岗位全部员工信息的岗位名称(用数字代替,经理1,技术员2,销售员3,销售经理4):\n");
	scanf("%d", &pos);
	struct personnel *p;
	p = head;
	printf("*************************************************************************************************************************************************\n");
	printf("\n");
	printf("职工号         姓名           性别           部门           岗位           工龄           工作时间       小时工资       销售额         底薪           当月工资\n");
	while (p != NULL)
	{
		if (p->post == pos - 1)
		{
			printf("%-15d%-15s%-15s%-15s%-15s%-15d%-15d%-15d%-15d%-15d%-15d\n", p->number, p->name, p->sex, p->department, po[p->post], p->length_of_service, p->working_hours, p->hourly_wage, p->sales, p->basic_salary, p->mouthly_slaary);
		}
		p = p->next;
	}
	printf("\n");
	printf("*************************************************************************************************************************************************\n");
	menu2(head);
}
void inquiry34(struct personnel *head)
{
	struct personnel *p = head;
	int n, o;
	char po[4][20] = {{"manager"}, {"technician"}, {"Seller"}, {"Sales_Manager"}};
	printf("根据职工号查询员工信息请按1,根据姓名查询员工信息请按2\n");
	scanf("%d", &o);
	switch (o)
	{
	case 1:
		printf("请输入要查询员工信息的职工号：\n");
		scanf("%d", &n);
		while ((p->number != n) && (p->next != NULL))
		{
			p = p->next;
		}
		if (p->number == n)
		{
			printf("该员工的信息为:职工号：%d,姓名：%s,性别：%s,部门：%s,岗位：%s,工龄：%d,工作时间:%d,小时工资:%d,销售额:%d,低薪:%d,当月工资:%d\n", p->number, p->name, p->sex, p->department, po[p->post], p->length_of_service, p->working_hours, p->hourly_wage, p->sales, p->basic_salary, p->mouthly_slaary);
		}
		else
		{
			printf("没有查询到该职工\n");
		}
		break;
	case 2:
		char names[20];
		printf("请输入要查询员工信息的姓名：\n");
		scanf("%s", names);
		while ((strcmp(names, p->name) != 0) && (p->next != NULL))
		{
			p = p->next;
		}
		if (strcmp(names, p->name) == 0)
		{
			printf("该员工的信息为:职工号：%d,姓名：%s,性别：%s,部门：%s,岗位：%s,工龄：%d,工作时间:%d,小时工资:%d,销售额:%d,低薪:%d,当月工资:%d\n", p->number, p->name, p->sex, p->department, po[p->post], p->length_of_service, p->working_hours, p->hourly_wage, p->sales, p->basic_salary, p->mouthly_slaary);
		}
		else
		{
			printf("没有查询到该职工\n");
		}
		break;
	}
	menu2(head);
}
void menu3(struct personnel *head)
{
	void menu11(struct personnel * head);
	void menu12(struct personnel * head);
	void personnel_sort_all(struct personnel * head);
	void personnel_sort_post(struct personnel * head);
	printf("************************************************\n");
	printf("*                                              *\n");
	printf("*                    排序                      *\n");
	printf("*                                              *\n");
	printf("*                                              *\n");
	printf("*             请选择您要执行的操作             *\n");
	printf("*                                              *\n");
	printf("*             所有员工信息按当月工资           *\n");
	printf("*            从高到低排序并显示(请按1)         *\n");
	printf("*              某个岗位的员工信息按            *\n");
	printf("*        当月工资从高到低排序并显示(请按2)     *\n");
	printf("*              返回上一菜单(请按3)             *\n");
	printf("*                退出系统(请按0)               *\n");
	printf("*                                              *\n");
	printf("************************************************\n");
	int operate;
	scanf("%d", &operate);
	switch (operate)
	{
	case 1:;
		personnel_sort_all(head);
		break;
	case 2:;
		personnel_sort_post(head);
		break;
	case 3:
		mainmenu(head);
		break;
	case 0:
		exit(0);
	}
}
void personnel_sort_all(struct personnel *head)
{
	int max = 0, undermax = 0, n = 0, i = 0, m = 0;
	char po[4][20] = {{"manager"}, {"technician"}, {"Seller"}, {"Sales_Manager"}};
	struct personnel *p, *p0;
	p = head;
	while (p != NULL)
	{
		n++;
		p = p->next;
	}
	printf("*************************************************************************************************************************************************\n");
	printf("\n");
	printf("职工号         姓名           性别           部门           岗位           工龄           工作时间       小时工资       销售额         底薪           当月工资\n");
	for (; i < n;)
	{
		if (i == 0)
		{
			p = head;
			while (p != NULL)
			{
				if (p->mouthly_slaary >= max)
				{
					max = p->mouthly_slaary;
				}
				p = p->next;
			}
			p = head;
			while (p != NULL)
			{
				if (p->mouthly_slaary == max)
				{
					printf("%-15d%-15s%-15s%-15s%-15s%-15d%-15d%-15d%-15d%-15d%-15d\n", p->number, p->name, p->sex, p->department, po[p->post], p->length_of_service, p->working_hours, p->hourly_wage, p->sales, p->basic_salary, p->mouthly_slaary);
					i++;
				}
				p = p->next;
			}
		}
		if (i > 0)
		{
			p = head;
			while (p != NULL)
			{
				if (p->mouthly_slaary >= undermax)
				{
					if (p->mouthly_slaary < max)
					{
						undermax = p->mouthly_slaary;
					}
				}
				p = p->next;
			}
			p = head;
			while (p != NULL)
			{
				if (p->mouthly_slaary == undermax)
				{
					printf("%-15d%-15s%-15s%-15s%-15s%-15d%-15d%-15d%-15d%-15d%-15d\n", p->number, p->name, p->sex, p->department, po[p->post], p->length_of_service, p->working_hours, p->hourly_wage, p->sales, p->basic_salary, p->mouthly_slaary);
					i++;
				}
				p = p->next;
			}
			max = undermax;
			undermax = 0;
		}
	}
	printf("\n");
	printf("*************************************************************************************************************************************************\n");
	menu3(head);
}
void personnel_sort_post(struct personnel *head)
{
	int max = 0, undermax = 0, n = 0, i = 0, m = 0, g;
	char po[4][20] = {{"manager"}, {"technician"}, {"Seller"}, {"Sales_Manager"}};
	struct personnel *p, *p0;
	p = head;
	enum Post pt;
	printf("请输入要排序的岗位(用数字代替,经理1,技术员2,销售员3,销售经理4):\n");
	scanf("%d", &g);
	switch (g)
	{
	case 1:
		pt = manager;
		break;

	case 2:
		pt = technician;
		break;
	case 3:
		pt = Seller;
		break;
	case 4:
		pt = Sales_Manager;
		break;
	}
	while (p != NULL)
	{
		if (p->post == pt)
		{
			n++;
		}
		p = p->next;
	}
	printf("*************************************************************************************************************************************************\n");
	printf("\n");
	printf("职工号         姓名           性别           部门           岗位           工龄           工作时间       小时工资       销售额         底薪           当月工资\n");
	for (; i < n;)
	{
		if (i == 0)
		{
			p = head;
			while (p != NULL)
			{
				if (p->post == pt)
				{
					if (p->mouthly_slaary >= max)
					{
						max = p->mouthly_slaary;
					}
				}
				p = p->next;
			}
			p = head;
			while (p != NULL)
			{
				if (p->post == pt)
				{
					if (p->mouthly_slaary == max)
					{
						printf("%-15d%-15s%-15s%-15s%-15s%-15d%-15d%-15d%-15d%-15d%-15d\n", p->number, p->name, p->sex, p->department, po[p->post], p->length_of_service, p->working_hours, p->hourly_wage, p->sales, p->basic_salary, p->mouthly_slaary);
						i++;
					}
				}
				p = p->next;
			}
		}
		if (i > 0)
		{
			p = head;
			while (p != NULL)
			{
				if (p->post == pt)
				{
					if (p->mouthly_slaary >= undermax)
					{
						if (p->mouthly_slaary < max)
						{
							undermax = p->mouthly_slaary;
						}
					}
				}
				p = p->next;
			}
			p = head;
			while (p != NULL)
			{
				if (p->post == pt)
				{
					if (p->mouthly_slaary == undermax)
					{
						printf("%-15d%-15s%-15s%-15s%-15s%-15d%-15d%-15d%-15d%-15d%-15d\n", p->number, p->name, p->sex, p->department, po[p->post], p->length_of_service, p->working_hours, p->hourly_wage, p->sales, p->basic_salary, p->mouthly_slaary);
						i++;
					}
				}
				p = p->next;
			}
			max = undermax;
			undermax = 0;
		}
	}
	printf("\n");
	printf("*************************************************************************************************************************************************\n");
	menu3(head);
}
void menu4(struct personnel *head)
{
	void mainmenu(struct personnel * head);
	void count_f(struct personnel * head);
	printf("************************************************\n");
	printf("*                                              *\n");
	printf("*                    统计                      *\n");
	printf("*                                              *\n");
	printf("*                                              *\n");
	printf("*             请选择您要执行的操作             *\n");
	printf("*                                              *\n");
	printf("*             统计并显示某个部门的             *\n");
	printf("*       平均工资、最低工资、最高工资(请按1)    *\n");
	printf("*            统计并显示某个部门超出            *\n");
	printf("*        平均工资的人数与员工信息(请按2)       *\n");
	printf("*            统计并显示所有员工中的            *\n");
	printf("*      最低工资和最高工资员工的信息(请按3)     *\n");
	printf("*            统计并显示所有员工超出            *\n");
	printf("*         平均工资的人数与员工信息(请按4)      *\n");
	printf("*              返回上一菜单(请按5)             *\n");
	printf("*                退出系统(请按0)               *\n");
	printf("*                                              *\n");
	printf("************************************************\n");
	count_f(head);
	// int operate;
	// scanf("%d", &operate);
	// switch (operate)
	// {
	// case 1:
	// 	Statistics(head);
	// 	break;
	// case 2:
	// 	Statistics2(head);
	// 	break;
	// case 3:
	// 	DecendOrder(head);
	// 	break;
	// case 4:
	// 	break;
	// case 5:
	// 	mainmenu(head);
	// 	break;
	// case 0:
	// 	exit(0);
	// }
}
// kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk
void count_f(struct personnel *head) //统计
{
	struct personnel *p = NULL;
	char department[20];
	char po[4][20] = {{"manager"}, {"technician"}, {"Seller"}, {"Sales_Manager"}};
	int sel;
	double max = 0, min = 0, ave = 0;
	int count = 0;
	printf("请选择您要执行的操作");
	scanf("%d", &sel);
	switch (sel)
	{
	case 1: //计算部门平均、最低台、最高工资信息
	{
		printf("\n  --请输入部门：");
		scanf("%s", department);
		p = head;
		while (p != NULL)
		{
			if (strcmp(p->department, department) == 0)
			{
				max = min = p->mouthly_slaary; //初始化
				break;						   //找出其部门第一个
			}
			p = p->next;
		}
		p = head; //重新开始，计算max，min，ave
		while (p != NULL)
		{
			if (strcmp(p->department, department) == 0)
			{
				if (p->mouthly_slaary > max)
					max = p->mouthly_slaary;
				if (p->mouthly_slaary < min)
					min = p->mouthly_slaary;
				ave += p->mouthly_slaary;
				count++;
			}
			p = p->next;
		}
		ave /= count; // ave = ave / count;
		printf("\n  --%s部门平均、最低台、最高工资信息如下:\n\n", department);
		printf("  ==========================================================\n");
		printf("  ||                                                      ||\n");
		printf("  ||           平均工资：%-8.2lf                         ||\n", ave);
		printf("  ||           最高工资：%-8.2lf                         ||\n", max);
		printf("  ||           最低工资：%-8.2lf                         ||\n", min);
		printf("  ||                                                      ||\n");
		printf("  ==========================================================\n");
	}

	break;	// break出case1
	case 2: //计算部门超过平均工资员工信息如下
	{
		printf("\n  --请输入部门：");
		scanf("%s", department);
		p = head;
		while (p != NULL) //先计算平均数
		{
			if (strcmp(p->department, department) == 0)
			{
				ave += p->mouthly_slaary;
				count++;
			}
			p = p->next;
		}
		ave /= count;
		printf("<<<<%s一共有%d人>>>>\n", department, count);
		count = 0;
		printf("\n  --%s部门超过平均工资(%.2lf)员工信息如下：\n", department, ave);
		p = head;
		while (p != NULL)
		{
			if ((strcmp(p->department, department) == 0) && (p->mouthly_slaary > ave))
			{
				count++;
				printf("职工号         姓名           性别           部门           岗位           工龄           工作时间       小时工资       销售额         底薪           当月工资\n");

				printf("%-15d%-15s%-15s%-15s%-15s%-15d%-15d%-15d%-15d%-15d%-15d\n", p->number, p->name, p->sex, p->department, po[p->post], p->length_of_service, p->working_hours, p->hourly_wage, p->sales, p->basic_salary, p->mouthly_slaary);
			}
			p = p->next;
		}
		printf("\n  共%d人\n", count);
	}
	break;	// break出case2
	case 3: //计算所有员工平均、最低、最高工资信息
	{
		p = head;
		p = p->next;
		max = min = p->mouthly_slaary;
		while (p != NULL)
		{
			if (p->mouthly_slaary > max || p->mouthly_slaary == max)
				max = p->mouthly_slaary;
			if (p->mouthly_slaary < min || p->mouthly_slaary == min)
				min = p->mouthly_slaary;
			ave += p->mouthly_slaary;
			count++;
			p = p->next;
		}
		ave /= count;
		printf("一共有%d个员工\n", count);
		printf("\n  --所有员工平均、最低、最高工资信息如下：\n");
		printf("  ==========================================================\n");
		printf("  ||                                                      ||\n");
		printf("  ||          平均工资：%-8.2lf                          ||\n", ave);
		printf("  ||          最高工资：%-8.2lf                          ||\n", max);
		printf("  ||          最低工资：%-8.2lf                          ||\n", min);
		printf("  ||                                                      ||\n");
		printf("  ==========================================================\n");
	}
	break;
	case 4: //计算所有超过平均工资员工信息
	{
		p = head;
		p = p->next;
		while (p != NULL)
		{
			count++;
			ave += p->mouthly_slaary;
			p = p->next;
		}
		ave /= count;
		printf("一共有%d名员工!!!\n", count);
		count = 0;
		printf("\n  --超过平均工资%.2lf的员工信息如下：\n", ave);

		p = head;
		while (p != NULL)
		{
			if (p->mouthly_slaary > ave)
			{
				count++;
				printf("职工号         姓名           性别           部门           岗位           工龄           工作时间       小时工资       销售额         底薪           当月工资\n");

				printf("%-15d%-15s%-15s%-15s%-15s%-15d%-15d%-15d%-15d%-15d%-15d\n", p->number, p->name, p->sex, p->department, po[p->post], p->length_of_service, p->working_hours, p->hourly_wage, p->sales, p->basic_salary, p->mouthly_slaary);
			}
			p = p->next;
		}
		printf("\n  共%d人\n", count);
	}
	break;
	case 5:
		mainmenu(head);
		break;
	case 0:
		exit(0);
	}
	menu4(head);
}

// gggggggggggggggggggggggggggggggggggggggggggg
int main(void)
{
	struct personnel *head = NULL;
	head = read_file_data(head);
	mainmenu(head);
	return 0;
}