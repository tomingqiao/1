#include <stdio.h>
#include <stdlib.h>
#include <string.h>
enum Post
{
	manager,	  //����
	technician,	  //����Ա
	Seller,		  //����Ա
	Sales_Manager //���۾���
};
struct personnel //Ա��
{

	int number;			   //ְ����
	char name[20];		   //����
	char sex[10];		   //�Ա�
	char department[20];   //����
	enum Post post;		   //��λ
	int length_of_service; //����
	int working_hours;	   //����ʱ��
	int hourly_wage;	   //Сʱ����
	int sales;			   //���۶�
	int basic_salary;	   //��н
	int mouthly_slaary;	   //���¹���
	struct personnel *next;
};
struct personnel *read_file_data(struct personnel *head)
{
	FILE *f = fopen("D:\\vscproject\\1\\c���Ա��\\s\\ssss\\sj.txt", "r");
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
	FILE *f = fopen("D:\\vscproject\\1\\c���Ա��\\s\\ssss\\sj.txt", "w");
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
	printf("*              �������ݵ�ά������              *\n");
	printf("*                                              *\n");
	printf("*                                              *\n");
	printf("*             ��ѡ����Ҫִ�еĲ���             *\n");
	printf("*                                              *\n");
	printf("*                 ����(�밴1)                  *\n");
	printf("*                 �޸�(�밴2)                  *\n");
	printf("*                 ɾ��(�밴3)                  *\n");
	printf("*                 ��ѯ(�밴4)                  *\n");
	printf("*                 ����(�밴5)                  *\n");
	printf("*              ������һ�˵�(�밴6)             *\n");
	printf("*                �˳�ϵͳ(�밴0)               *\n");
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
	printf("*                  ��ѯ����                    *\n");
	printf("*                                              *\n");
	printf("*                                              *\n");
	printf("*             ��ѡ����Ҫִ�еĲ���             *\n");
	printf("*                                              *\n");
	printf("*         ��ҳ��ʾȫ��Ա������Ϣ(�밴1)        *\n");
	printf("*       ��������ʾ������ȫ��Ա����Ϣ(�밴2)    *\n");
	printf("*        ������ʾ4�ָ�λ��Ա����Ϣ(�밴3)      *\n");
	printf("*       ���ݹ��Ż���������ѯԱ����Ϣ(�밴4)    *\n");
	printf("*              ������һ�˵�(�밴5)             *\n");
	printf("*                �˳�ϵͳ(�밴0)               *\n");
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

	printf("������Ҫ���Ա����������\n");
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
		printf("�������%d��Ա����Ϣ:(�������Ա𡢲��š���λ(�����ִ���,����1,����Ա2,����Ա3,���۾���4)������)\n", i + 1);
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
	char names[20];			//����
	char sexs[10];			//�Ա�
	char departments[20];	//����
	enum Post posts;		//��λ
	int length_of_services; //����
	printf("��������Ҫ�޸����ݵ�Ա����ְ���ţ�\n");
	scanf("%d", &a);
	struct personnel *p;
	p = head;
	while ((p->number != a) && (p->next != NULL))
		p = p->next;
	if (p->number == a)
	{
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
	}
	else if (p->number != a)
		printf("û�в�ѯ����ְ��������Ӧ��Ա��\n");
	menu11(head);
}
void delete13(struct personnel *head)
{
	struct personnel *p1 = head, *p2 = head;
	int n;
	printf("������Ҫɾ��Ա����ְ���ţ�\n");
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
		printf("�޸�ְ��\n");
	}
	menu11(head);
}
void inquiry14(struct personnel *head)
{
	struct personnel *p = head;
	int n;
	char po[4][20] = {{"manager"}, {"technician"}, {"Seller"}, {"Sales_Manager"}};
	printf("������Ҫ��ѯԱ���������ݵ�ְ���ţ�\n");
	scanf("%d", &n);
	while ((p->number != n) && (p->next != NULL))
	{
		p = p->next;
	}
	if (p->number == n)
	{
		printf("��Ա���Ļ�������Ϊ:ְ���ţ�%d,������%s,�Ա�%s,���ţ�%s,��λ��%s,���䣺%d\n", p->number, p->name, p->sex, p->department, po[p->post], p->length_of_service);
	}
	else
	{
		printf("û�в�ѯ����ְ��\n");
	}
	menu11(head);
}
void enter21(struct personnel *head)
{
	int r, m;
	struct personnel *p0;
	printf("������Ҫ����Ա���������ݵ�������\n");
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
			printf("�������%d������Ա������������Ϣ:(��н8000)\n", i + 1);
			scanf("%d", &p0->basic_salary);
			break;
		case technician:
			printf("�������%d������ԱԱ������������Ϣ:(����ʱ�䡢Сʱ����100)\n", i + 1);
			scanf("%d %d", &p0->working_hours, &p0->hourly_wage);
			break;
		case Seller:
			printf("�������%d������ԱԱ������������Ϣ:(���۶�)\n", i + 1);
			scanf("%d", &p0->sales);
			break;
		case Sales_Manager:
			printf("�������%d�����۾���Ա������������Ϣ:(��н8000)\n", i + 1);
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
	printf("��������Ҫ�޸����ݵ�Ա����ְ���ţ�\n");
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
			printf("�þ���Ա������������Ϣ(��н):%d\n", p->basic_salary);
			printf("��������Ҫ�޸ĵĹ���������Ϣ:(��н)\n");
			scanf("%d", &p->basic_salary);
			break;
		case technician:
			printf("�ü���ԱԱ������������Ϣ(����ʱ�䡢Сʱ����):%d,%d\n", p->working_hours, p->hourly_wage);
			printf("��������Ҫ�޸ĵĹ���������Ϣ:(����ʱ�䡢Сʱ����)\n");
			scanf("%d %d", &p->working_hours, &p->hourly_wage);
			break;
		case Seller:
			printf("������ԱԱ����Ϣ(���۶�):%d\n", p->sales);
			printf("��������Ҫ�޸ĵĹ���������Ϣ:(���۶�)\n");
			scanf("%d", &p->sales);
			break;
		case Sales_Manager:
			printf("�����۾���Ա����Ϣ(��н):%d\n", p->basic_salary);
			printf("��������Ҫ�޸ĵĹ���������Ϣ:(��н)\n");
			scanf("%d", &p->basic_salary);
			break;
		}
	}
	else if (p->number != a)
		printf("û�в�ѯ����ְ��������Ӧ��Ա��\n");
	menu12(head);
}
void delete23(struct personnel *head)
{
	struct personnel *p = head;
	int n;
	printf("������Ҫɾ��Ա���������ݵ�ְ���ţ�\n");
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
		printf("ɾ���ɹ�\n");
	}
	else
	{
		printf("û�в�ѯ����ְ��\n");
	}
	menu12(head);
}
void inquiry24(struct personnel *head)
{
	int a, c;
	printf("��������Ҫ��ѯ�������ݵ�Ա����ְ���ţ�\n");
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
			printf("�þ���Ա������������Ϣ(��н�����¹���):%d,%d\n", p->basic_salary, p->mouthly_slaary);
			break;
		case technician:
			printf("�ü���ԱԱ������������Ϣ(����ʱ�䡢Сʱ���ʡ����¹���):%d,%d,%d\n", p->working_hours, p->hourly_wage, p->mouthly_slaary);
			break;
		case Seller:
			printf("������ԱԱ����Ϣ(���۶�):%d,%d\n", p->sales, p->mouthly_slaary);
			break;
		case Sales_Manager:
			printf("�����۾���Ա����Ϣ(��н):%d,%d\n", p->basic_salary, p->mouthly_slaary);
			break;
		}
	}
	else if (p->number != a)
		printf("û�в�ѯ����ְ��������Ӧ��Ա��\n");
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
	printf("����ɹ�\n");
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
	printf("ְ����         ����           �Ա�           ����           ��λ           ����           ����ʱ��       Сʱ����       ���۶�         ��н           ���¹���\n");
	for (i = 0; (i < 10) && (p1 != NULL); i++)
	{
		printf("%-15d%-15s%-15s%-15s%-15s%-15d%-15d%-15d%-15d%-15d%-15d\n", p1->number, p1->name, p1->sex, p1->department, po[p1->post], p1->length_of_service, p1->working_hours, p1->hourly_wage, p1->sales, p1->basic_salary, p1->mouthly_slaary);
		p1 = p1->next;
	}
	printf("\n");
	printf("��ҳ(�밴1)                   ��һҳ(�밴2)                     ��һҳ(�밴3)                     ���һҳ(�밴4)                     �˳�(�밴0)\n");
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
			printf("ְ����   ����        �Ա�        ����      ��λ              ����            ����ʱ��         Сʱ����       ���۶�        ��н          ���¹���\n");
			for (i = 1; (i <= 10) && (p1 != NULL); i++)
			{
				printf("%-15d%-15s%-15s%-15s%-15s%-15d%-15d%-15d%-15d%-15d%-15d\n", p1->number, p1->name, p1->sex, p1->department, po[p1->post], p1->length_of_service, p1->working_hours, p1->hourly_wage, p1->sales, p1->basic_salary, p1->mouthly_slaary);
				p1 = p1->next;
			}
			printf("\n");
			printf("��ҳ(�밴1)                   ��һҳ(�밴2)                     ��һҳ(�밴3)                     ���һҳ(�밴4)                     �˳�(�밴0)\n");
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
				printf("����һҳ\n");
				break;
			}
			n = i + 1;
			i = i + 10;
			printf("*************************************************************************************************************************************************\n");
			printf("\n");
			printf("ְ����         ����           �Ա�           ����           ��λ           ����           ����ʱ��       Сʱ����       ���۶�         ��н           ���¹���\n");
			for (; (n <= i) && (p1 != NULL); n++)
			{
				printf("%-15d%-15s%-15s%-15s%-15s%-15d%-15d%-15d%-15d%-15d%-15d\n", p1->number, p1->name, p1->sex, p1->department, po[p1->post], p1->length_of_service, p1->working_hours, p1->hourly_wage, p1->sales, p1->basic_salary, p1->mouthly_slaary);
				p1 = p1->next;
			}
			printf("\n");
			printf("��ҳ(�밴1)                   ��һҳ(�밴2)                     ��һҳ(�밴3)                     ���һҳ(�밴4)                     �˳�(�밴0)\n");
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
				printf("����һҳ\n");
				break;
			}
			n = i + 1;
			i = i + 10;
			printf("*************************************************************************************************************************************************\n");
			printf("\n");
			printf("ְ����         ����           �Ա�           ����           ��λ           ����           ����ʱ��       Сʱ����       ���۶�         ��н           ���¹���\n");
			for (; (n <= i) && (p1 != NULL); n++)
			{
				printf("%-15d%-15s%-15s%-15s%-15s%-15d%-15d%-15d%-15d%-15d%-15d\n", p1->number, p1->name, p1->sex, p1->department, po[p1->post], p1->length_of_service, p1->working_hours, p1->hourly_wage, p1->sales, p1->basic_salary, p1->mouthly_slaary);
				p1 = p1->next;
			}
			printf("\n");
			printf("��ҳ(�밴1)                   ��һҳ(�밴2)                     ��һҳ(�밴3)                     ���һҳ(�밴4)                     �˳�(�밴0)\n");
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
			printf("ְ����         ����           �Ա�           ����           ��λ           ����           ����ʱ��       Сʱ����       ���۶�         ��н           ���¹���\n");
			for (; (n <= i) && (p1 != NULL); n++)
			{
				printf("%-15d%-15s%-15s%-15s%-15s%-15d%-15d%-15d%-15d%-15d%-15d\n", p1->number, p1->name, p1->sex, p1->department, po[p1->post], p1->length_of_service, p1->working_hours, p1->hourly_wage, p1->sales, p1->basic_salary, p1->mouthly_slaary);
				p1 = p1->next;
			}
			printf("\n");
			printf("��ҳ(�밴1)                   ��һҳ(�밴2)                     ��һҳ(�밴3)                     ���һҳ(�밴4)                     �˳�(�밴0)\n");
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
	printf("��������Ҫ��ѯ����ȫ��Ա����Ϣ�Ĳ������ƣ�\n");
	scanf("%s", dep);
	struct personnel *p;
	p = head;
	printf("*************************************************************************************************************************************************\n");
	printf("\n");
	printf("ְ����         ����           �Ա�           ����           ��λ           ����           ����ʱ��       Сʱ����       ���۶�         ��н           ���¹���\n");
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
	printf("��������Ҫ��ѯ��λȫ��Ա����Ϣ�ĸ�λ����(�����ִ���,����1,����Ա2,����Ա3,���۾���4):\n");
	scanf("%d", &pos);
	struct personnel *p;
	p = head;
	printf("*************************************************************************************************************************************************\n");
	printf("\n");
	printf("ְ����         ����           �Ա�           ����           ��λ           ����           ����ʱ��       Сʱ����       ���۶�         ��н           ���¹���\n");
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
	printf("����ְ���Ų�ѯԱ����Ϣ�밴1,����������ѯԱ����Ϣ�밴2\n");
	scanf("%d", &o);
	switch (o)
	{
	case 1:
		printf("������Ҫ��ѯԱ����Ϣ��ְ���ţ�\n");
		scanf("%d", &n);
		while ((p->number != n) && (p->next != NULL))
		{
			p = p->next;
		}
		if (p->number == n)
		{
			printf("��Ա������ϢΪ:ְ���ţ�%d,������%s,�Ա�%s,���ţ�%s,��λ��%s,���䣺%d,����ʱ��:%d,Сʱ����:%d,���۶�:%d,��н:%d,���¹���:%d\n", p->number, p->name, p->sex, p->department, po[p->post], p->length_of_service, p->working_hours, p->hourly_wage, p->sales, p->basic_salary, p->mouthly_slaary);
		}
		else
		{
			printf("û�в�ѯ����ְ��\n");
		}
		break;
	case 2:
		char names[20];
		printf("������Ҫ��ѯԱ����Ϣ��������\n");
		scanf("%s", names);
		while ((strcmp(names, p->name) != 0) && (p->next != NULL))
		{
			p = p->next;
		}
		if (strcmp(names, p->name) == 0)
		{
			printf("��Ա������ϢΪ:ְ���ţ�%d,������%s,�Ա�%s,���ţ�%s,��λ��%s,���䣺%d,����ʱ��:%d,Сʱ����:%d,���۶�:%d,��н:%d,���¹���:%d\n", p->number, p->name, p->sex, p->department, po[p->post], p->length_of_service, p->working_hours, p->hourly_wage, p->sales, p->basic_salary, p->mouthly_slaary);
		}
		else
		{
			printf("û�в�ѯ����ְ��\n");
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
	printf("*                    ����                      *\n");
	printf("*                                              *\n");
	printf("*                                              *\n");
	printf("*             ��ѡ����Ҫִ�еĲ���             *\n");
	printf("*                                              *\n");
	printf("*             ����Ա����Ϣ�����¹���           *\n");
	printf("*            �Ӹߵ���������ʾ(�밴1)         *\n");
	printf("*              ĳ����λ��Ա����Ϣ��            *\n");
	printf("*        ���¹��ʴӸߵ���������ʾ(�밴2)     *\n");
	printf("*              ������һ�˵�(�밴3)             *\n");
	printf("*                �˳�ϵͳ(�밴0)               *\n");
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
	printf("ְ����         ����           �Ա�           ����           ��λ           ����           ����ʱ��       Сʱ����       ���۶�         ��н           ���¹���\n");
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
	printf("������Ҫ����ĸ�λ(�����ִ���,����1,����Ա2,����Ա3,���۾���4):\n");
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
	printf("ְ����         ����           �Ա�           ����           ��λ           ����           ����ʱ��       Сʱ����       ���۶�         ��н           ���¹���\n");
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
	printf("*                    ͳ��                      *\n");
	printf("*                                              *\n");
	printf("*                                              *\n");
	printf("*             ��ѡ����Ҫִ�еĲ���             *\n");
	printf("*                                              *\n");
	printf("*             ͳ�Ʋ���ʾĳ�����ŵ�             *\n");
	printf("*       ƽ�����ʡ���͹��ʡ���߹���(�밴1)    *\n");
	printf("*            ͳ�Ʋ���ʾĳ�����ų���            *\n");
	printf("*        ƽ�����ʵ�������Ա����Ϣ(�밴2)       *\n");
	printf("*            ͳ�Ʋ���ʾ����Ա���е�            *\n");
	printf("*      ��͹��ʺ���߹���Ա������Ϣ(�밴3)     *\n");
	printf("*            ͳ�Ʋ���ʾ����Ա������            *\n");
	printf("*         ƽ�����ʵ�������Ա����Ϣ(�밴4)      *\n");
	printf("*              ������һ�˵�(�밴5)             *\n");
	printf("*                �˳�ϵͳ(�밴0)               *\n");
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
void count_f(struct personnel *head) //ͳ��
{
	struct personnel *p = NULL;
	char department[20];
	char po[4][20] = {{"manager"}, {"technician"}, {"Seller"}, {"Sales_Manager"}};
	int sel;
	double max = 0, min = 0, ave = 0;
	int count = 0;
	printf("��ѡ����Ҫִ�еĲ���");
	scanf("%d", &sel);
	switch (sel)
	{
	case 1: //���㲿��ƽ�������̨����߹�����Ϣ
	{
		printf("\n  --�����벿�ţ�");
		scanf("%s", department);
		p = head;
		while (p != NULL)
		{
			if (strcmp(p->department, department) == 0)
			{
				max = min = p->mouthly_slaary; //��ʼ��
				break;						   //�ҳ��䲿�ŵ�һ��
			}
			p = p->next;
		}
		p = head; //���¿�ʼ������max��min��ave
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
		printf("\n  --%s����ƽ�������̨����߹�����Ϣ����:\n\n", department);
		printf("  ==========================================================\n");
		printf("  ||                                                      ||\n");
		printf("  ||           ƽ�����ʣ�%-8.2lf                         ||\n", ave);
		printf("  ||           ��߹��ʣ�%-8.2lf                         ||\n", max);
		printf("  ||           ��͹��ʣ�%-8.2lf                         ||\n", min);
		printf("  ||                                                      ||\n");
		printf("  ==========================================================\n");
	}

	break;	// break��case1
	case 2: //���㲿�ų���ƽ������Ա����Ϣ����
	{
		printf("\n  --�����벿�ţ�");
		scanf("%s", department);
		p = head;
		while (p != NULL) //�ȼ���ƽ����
		{
			if (strcmp(p->department, department) == 0)
			{
				ave += p->mouthly_slaary;
				count++;
			}
			p = p->next;
		}
		ave /= count;
		printf("<<<<%sһ����%d��>>>>\n", department, count);
		count = 0;
		printf("\n  --%s���ų���ƽ������(%.2lf)Ա����Ϣ���£�\n", department, ave);
		p = head;
		while (p != NULL)
		{
			if ((strcmp(p->department, department) == 0) && (p->mouthly_slaary > ave))
			{
				count++;
				printf("ְ����         ����           �Ա�           ����           ��λ           ����           ����ʱ��       Сʱ����       ���۶�         ��н           ���¹���\n");

				printf("%-15d%-15s%-15s%-15s%-15s%-15d%-15d%-15d%-15d%-15d%-15d\n", p->number, p->name, p->sex, p->department, po[p->post], p->length_of_service, p->working_hours, p->hourly_wage, p->sales, p->basic_salary, p->mouthly_slaary);
			}
			p = p->next;
		}
		printf("\n  ��%d��\n", count);
	}
	break;	// break��case2
	case 3: //��������Ա��ƽ������͡���߹�����Ϣ
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
		printf("һ����%d��Ա��\n", count);
		printf("\n  --����Ա��ƽ������͡���߹�����Ϣ���£�\n");
		printf("  ==========================================================\n");
		printf("  ||                                                      ||\n");
		printf("  ||          ƽ�����ʣ�%-8.2lf                          ||\n", ave);
		printf("  ||          ��߹��ʣ�%-8.2lf                          ||\n", max);
		printf("  ||          ��͹��ʣ�%-8.2lf                          ||\n", min);
		printf("  ||                                                      ||\n");
		printf("  ==========================================================\n");
	}
	break;
	case 4: //�������г���ƽ������Ա����Ϣ
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
		printf("һ����%d��Ա��!!!\n", count);
		count = 0;
		printf("\n  --����ƽ������%.2lf��Ա����Ϣ���£�\n", ave);

		p = head;
		while (p != NULL)
		{
			if (p->mouthly_slaary > ave)
			{
				count++;
				printf("ְ����         ����           �Ա�           ����           ��λ           ����           ����ʱ��       Сʱ����       ���۶�         ��н           ���¹���\n");

				printf("%-15d%-15s%-15s%-15s%-15s%-15d%-15d%-15d%-15d%-15d%-15d\n", p->number, p->name, p->sex, p->department, po[p->post], p->length_of_service, p->working_hours, p->hourly_wage, p->sales, p->basic_salary, p->mouthly_slaary);
			}
			p = p->next;
		}
		printf("\n  ��%d��\n", count);
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