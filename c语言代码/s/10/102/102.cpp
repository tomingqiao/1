#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
struct worker
{
	char name[10];
	int gz;
	struct worker *next;
};
void count_lis(struct worker *list,double a)
{
	struct worker *p;
	int m=0;
	p=list;
	while(p!=NULL)
	{
		if(a<(p->gz))
		{
			m++;
		}
		p=p->next;
	}
	printf("����ƽ���������ʵ�����:%d,ƽ����������:%f\n",m,a);
}
int main(void)
{
	int i;
	double a=0;
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
		a=a+p->gz;
		if(i==1)
			list=p;
		else
			q->next=p;
		q=p;
		if(p->gz==0)
			break;
	}
	a=a/(i-1);
	count_lis(list,a);
	return 0;
}
