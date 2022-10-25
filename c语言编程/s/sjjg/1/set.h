#ifndef SET_H
#define SET_H
#include <stdio.h>
#include <stdlib.h>

typedef int DataType;

 //单链表结点定义
typedef struct Node
{
 	DataType data;    
 	struct Node *next;
}SLNode;

//初始化单链表集合
void linkListInit(SLNode **head);

//释放单链表
void linkListDestroy(SLNode **head); 

//求交集Set1∩Set2  成功返回0，失败返回1
int intersectionOfSet(SLNode *head1,SLNode *head2,SLNode *head3);

//求并集 Set1∪Set2  成功返回0，失败返回1
int unionOfSet(SLNode *head1,SLNode *head2,SLNode *head3);

//求差集 Set1-Set2   成功返回0，失败返回1
int differenceOfSet(SLNode *head1,SLNode *head2,SLNode *head3);

//查找元素，返回元素所在的结点，没有找到返回NULL
SLNode * findInSet(SLNode *head, DataType x);

//对集合进行排序
void sort(SLNode *head);

#endif
