#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
struct worker
{
	char name[10];
	int gz;
	struct worker *next;
};
void del_list(struct worker *list,int a)
{
	struct worker *p,*q,*y;
	int m=0,i;
	y=list;
	while(y->next!=NULL)
	{
		if(y->gz==a)
			m++;
		y=y->next;
	}
	for(i=1;i<=m;i++)
	{
		p=q=list;
		while((p->gz!=a)&&(p->next!=NULL))
		{
			q=p;
			p=p->next;	
		}
		if(p->gz==a)
		{
			if(p==list)
			list=p->next;
			else
				q->next=p->next;
		}
	}
	while(list->next!=NULL)
	{

		printf("姓名:%s,工资:%d\n",list->name,list->gz);
		list=list->next;
	}
}
int main(void)
{
	int i,a;
	struct worker *list,*p,*q;
	list=q=NULL;
	for(i=1;;i++)
	{
		if((p=(struct worker *)malloc(sizeof(struct worker)))==NULL)
		{
			printf("不能成功分配存储块！");
			exit(0);
		}
		p->next=NULL;
		printf("请输入第%d个员工姓名和工资：",i);
		scanf("%s%d",p->name,&p->gz);
		if(i==1)
			list=p;
		else
			q->next=p;
		q=p;
		if(p->gz==0)
			break;
	}
	printf("请输入要删除的工资数目：");
	scanf("%d",&a);
	del_list(list,a);
	return 0;
}
