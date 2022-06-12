#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include<string.h>
struct worker
{
	char name[10];
	int gz;
	struct worker *next;
};
void max_list(struct worker *list)
{
	struct worker *p;
	int m;
	char n[10];
	p=list;
	m=p->gz;
	while(p!=NULL)
	{
		if(m<(p->gz))
		{
			m=p->gz;
			strcpy(n,p->name);	
		}
		p=p->next;
	}
	printf("最高基本工资的职工信息:姓名:%s,工资:%d\n",n,m);
}
int main(void)
{
	int i;
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
	max_list(list);
	return 0;
}
