// ds1.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "set.h"
//从文件中输入数据到集合，数据以0结束
void input(SLNode *head, FILE *file)
{
	int d;
	SLNode *p;
	int r = 0;
	r = fscanf_s(file, "%d", &d);
	while (r != EOF && d != 0)
	{
		if (findInSet(head, d) == NULL)
		{
			p = (SLNode *)malloc(sizeof(SLNode));
			p->data = d;
			p->next = head->next;
			head->next = p;
		}
		r = fscanf_s(file, "%d", &d);
	}
}
//输出集合元素
void output(SLNode *head)
{
	SLNode *p;
	p = head->next;
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
}

int main(int argc, _TCHAR *argv[])
{

	// 打开待处理的文件。读取文件中的内容。
	FILE *file = NULL;
	// char* filename = "input.txt";
	char filename[10] = "input.txt";
	int err = fopen_s(&file, filename, "rt");
	if (err != 0)
	{
		printf("Can not open file \"%s\".\n", filename);
		return 1;
	}

	SLNode *head1;
	SLNode *head2;
	SLNode *head3;
	SLNode *head4;
	SLNode *head5;
	int result = 0;
	linkListInit(&head1);
	linkListInit(&head2);
	linkListInit(&head3);
	linkListInit(&head4);
	linkListInit(&head5);

	input(head1, file);

	input(head2, file);

	printf("set1= { ");
	output(head1);
	printf("}\n");
	printf("set2= { ");
	output(head2);
	printf("}\n");
	result = intersectionOfSet(head1, head2, head3);

	printf("Set1∩Set2= { ");
	sort(head3);
	output(head3);
	printf("}\n");
	result = unionOfSet(head1, head2, head4);

	printf("Set1∪Set2= { ");
	sort(head4);
	output(head4);
	printf("}\n");

	result = differenceOfSet(head1, head2, head5);

	printf("Set1-Set2= { ");
	sort(head5);
	output(head5);
	printf("}");

	linkListDestroy(&head1);
	linkListDestroy(&head2);
	linkListDestroy(&head3);
	linkListDestroy(&head4);
	linkListDestroy(&head5);

	fclose(file);
	return 0;
}
