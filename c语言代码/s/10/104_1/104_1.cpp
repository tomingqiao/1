#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct student
{
	int cj;
	struct student *next;
};
struct student * lis(void)
{
	int i;
	struct student *p,*q,*head;
	q=head=NULL;
	for(i=1;;i++)
	{
		if((p=(struct student *)malloc(sizeof(struct student)))==NULL)
		{
			printf("���ܳɹ�����洢�飡");
			exit(0);
		}
		p->next=NULL;
		printf("�������%dѧ�����ɼ���\n",i);
		scanf("%d",&p->cj);
		if(p->cj==-1)
			break;
		if(i==1)
			head=p;
		else if(i>=2)
			q->next=p;
		q=p;
	}
	return head;
}
struct student * he(struct student *d,struct student *e)
{
	struct student *p1,*p3,*p4,*head;
	p1=d;
	head=e;
	p3=p4=head;
	while((p1->cj>p3->cj)&&(p3->next!=NULL))
	{
		p4=p3;
		p3=p3->next;
			
	}
	if(p3==head)
	{
		p1->next=head;
		head=p1;
	}
	else if(p1->cj>p3->cj)
	{
		p3->next=p1;
		p1->next=NULL;
	}
	else
	{
		p4->next=p1;
		p1->next=p3;
	}
	return head;
}
int main(void)
{
	struct student *list1,*list2,*c,*a;
	int i=0,t=0;
	printf("�밴��������ѧ���ɼ���\n");
	list1=lis();
	printf("��������һ������ѧ���ɼ���\n");
	list2=lis();
	c=list1;
	while(c!=NULL)
	{
		if((a=(struct student *)malloc(sizeof(struct student)))==NULL)
		{
			printf("���ܳɹ�����洢�飡");
			exit(0);
		}
		a->next=NULL;
		a->cj=c->cj;
		list2=he(a,list2);
		c=c->next;
	}
	printf("����ѧ���ɼ�Ϊ��\n");
	c=list2;
	while(c!=NULL)
	{
		printf("%d\n",c->cj);
		c=c->next;
	}
	return 0;
}