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
	printf("��߻������ʵ�ְ����Ϣ:����:%s,����:%d\n",n,m);
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
			printf("���ܳɹ�����洢�飡");
			exit(0);
		}
		p->next=NULL;
		printf("�������%d��Ա�������͹��ʣ�",i);
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
