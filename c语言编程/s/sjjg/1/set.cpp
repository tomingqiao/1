#include "stdafx.h"
#include "set.h"



//初始化单链表集合
void linkListInit(SLNode **head){
	*head = (SLNode *)malloc(sizeof(SLNode));
	(*head)->next = NULL;

}



//释放单链表
void linkListDestroy(SLNode **head){
	if (head == NULL)
		return;
	SLNode* p = (*head)->next;
	SLNode* p1 = NULL;
	while (p != NULL){
		p1 = p->next;
		free(p);
		p = p1;
	}
	free(*head);
	*head = NULL;
}


//求交集Set1∩Set2  成功返回0，失败返回1，失败的信息打印到字符串errMessage，例如sprintf(errMessage,"单链表h1或h2为空！\n");
int intersectionOfSet(SLNode *head1, SLNode *head2, SLNode *head3) {

	//填充代码
	SLNode *p,*q,*m,*n;
	p=head1;
	q=head2;
	m=head3;
	while(m->next!=NULL){
		m=m->next;
	}
	
	while(q->next!=NULL){

		while(p->next!=NULL){
			if(p->data==q->data){
				n=(SLNode *)malloc(sizeof(SLNode));
				n->next=NULL;
				n->data=q->data;
				m->next=n;
				m=m->next;
			}
			p=p->next;
		}
		q=q->next;
	}
	return 0;
}


//求并集 Set1∪Set2  成功返回0，失败返回1，失败的信息打印到字符串errMessage，例如sprintf(errMessage,"单链表h1或h2为空！\n");
int unionOfSet(SLNode *head1, SLNode *head2, SLNode *head3){

	//填充代码
	SLNode *p,*q,*m,*n;
	p=head1;
	q=head2;
	m=head3;
	while(m->next!=NULL){
		m=m->next;
	}
	while(p->next!=NULL){
		n=(SLNode *)malloc(sizeof(SLNode));
		n->next=NULL;
		n->data=p->data;	
		m->next=n;
		m=m->next;
		p=p->next;
	}
	int i=0;
	p=head1;
	while(q->next!=NULL){
		while(p->next!=NULL){
			if(p->data==q->data){
				i++;
			}
			p=p->next;
		}
		if(i==0){
		n=(SLNode *)malloc(sizeof(SLNode));
				n->next=NULL;
				n->data=q->data;
				m->next=n;
				m=m->next;
		}
		i=0;
		q=q->next;
		p=head1;
	}
	return 0;
}


//求差集 Set1-Set2   成功返回0，失败返回1，失败的信息打印到字符串errMessage，例如sprintf(errMessage,"单链表h1或h2为空！\n");
int differenceOfSet(SLNode *head1, SLNode *head2, SLNode *head3) {

	//填充代码
	SLNode *p,*q,*m,*n;
	p=head1;
	q=head2;
	m=head3;
	while(m->next!=NULL){
		m=m->next;
	}
	while(p->next!=NULL){
		n=(SLNode *)malloc(sizeof(SLNode));
		n->next=NULL;
		n->data=p->data;	
		m->next=n;
		m=m->next;
		p=p->next;
	}
	int i=0;
	p=head1;
	m=head3;
	while(q->next!=NULL){
		while(m->next->next!=NULL){
			if(m->next->data==q->data){
				m->next=m->next->next;
			}
			m=m->next;
		}
		q=q->next;
		m=head3;
	}
	return 0;

}
//查找元素，返回元素所在的结点，没有找到返回NULL
SLNode * findInSet(SLNode *head, DataType x) {
	SLNode* p = head->next;
	while (p != NULL){
		if (p->data == x)
			return p;
		p = p->next;
	}
	return NULL;
}

//对集合进行排序
void sort(SLNode *head)
{
	SLNode *curr, *pre, *p, *q;
	p = head->next;
	head->next = NULL;
	while (p != NULL){
		curr = head->next;
		pre = head;
		while (curr != NULL && curr->data <= p->data){
			pre = curr;
			curr = curr->next;
		}
		q = p;
		p = p->next;
		q->next = pre->next;
		pre->next = q;
	}

}
