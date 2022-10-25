#ifndef SET_H
#define SET_H
#include <stdio.h>
#include <stdlib.h>

typedef int DataType;

 //�������㶨��
typedef struct Node
{
 	DataType data;    
 	struct Node *next;
}SLNode;

//��ʼ����������
void linkListInit(SLNode **head);

//�ͷŵ�����
void linkListDestroy(SLNode **head); 

//�󽻼�Set1��Set2  �ɹ�����0��ʧ�ܷ���1
int intersectionOfSet(SLNode *head1,SLNode *head2,SLNode *head3);

//�󲢼� Set1��Set2  �ɹ�����0��ʧ�ܷ���1
int unionOfSet(SLNode *head1,SLNode *head2,SLNode *head3);

//�� Set1-Set2   �ɹ�����0��ʧ�ܷ���1
int differenceOfSet(SLNode *head1,SLNode *head2,SLNode *head3);

//����Ԫ�أ�����Ԫ�����ڵĽ�㣬û���ҵ�����NULL
SLNode * findInSet(SLNode *head, DataType x);

//�Լ��Ͻ�������
void sort(SLNode *head);

#endif
