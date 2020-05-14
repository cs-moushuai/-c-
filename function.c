#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>

#include "header.h"

//0
Student *read()
{
	FILE *fp = fopen("data", "ab+");
	Student *p, *p_last, *temp, *head = NULL;
	system("cls");
	rewind(fp);
	//清除head为NULL
	while (head != NULL)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
	if (fp == NULL)
	{
		puts("can not open the file!");
		exit(EXIT_FAILURE);
	}
	head = p = (Student *)malloc(sizeof(Student));
	fread(p, sizeof(Student), 1, fp);
	if (feof(fp))
	{
		puts("There is no data in the file!");
		free(head);
		head = NULL;
		system("pause");
		return head;
	}

	while (!feof(fp))
	{
		p_last = p;
		p->next = (Student *)malloc(sizeof(Student));
		p = p->next;
		fread(p, sizeof(Student), 1, fp);
	}
	//处理最后一次数据
	free(p);
	p_last->next = NULL;
	puts("********Data read out!********");
	system("pause");
	fclose(fp);
	return head;
}

//1
Student *add(Student *head)
{
	int flag = 0;
	Student *p = (Student *)malloc(sizeof(Student));
	Student *node, *node_last;

	system("cls");
	puts("add student id,name and grades for the three subjects:");
	scanf("%d %s %lf %lf %lf", &p->id, p->name, &p->score[0], &p->score[1], &p->score[2]);

	p->next = NULL;
	if (head == NULL)
	{
		head = p;
	}
	else
	{
		for (node = head; node != NULL; node = node->next)
		{
			if (p->id < node->id)
			{
				if (flag == 0)
				{
					p->next = head;
					head = p;
				}
				else
				{
					node_last->next = p;
					p->next = node;
				}

				puts("***********data is added!***********");
				system("pause");
				return head;
			}
			else if (p->id == node->id)
			{
				puts("***********node already exists***********");
				system("pause");
				return head;
			}
			flag++;
			node_last = node;
		}
		node_last->next = p;
	}

	puts("***********data is added!***********");
	system("pause");
	return head;
}

//2
void search(Student *head)
{
	int n;
	Student *p = head;

	system("cls");
	printf("Enter the student id number you want to check:");
	scanf("%d", &n);
	//&&前必需判断是否为空,如是后者,p为空的情况id没有值

	while (p != NULL && p->id != n)
		p = p->next;

	if (p != NULL)
	{
		printf("id:%d\nname:%s\ngrades for the three subjects:%g,%g,%g\n", p->id, p->name, p->score[0], p->score[1], p->score[2]);
	}
	else
	{
		puts("Not found!");
	}
	system("pause");
}

//3
void modify(Student *head)
{
	int n;
	Student *p = head;

	system("cls");
	printf("enter student id number you want to change:");
	scanf("%d", &n);

	while (p != NULL && p->id != n)
		p = p->next;
	if (p != NULL)
	{
		puts("Have query to the student!");
		printf("enter name and three scores:");
		scanf("%s %lf %lf %lf", p->name, &p->score[0], &p->score[1], &p->score[2]);
		p->id = n;
		printf("id:%d\nname:%s\ngrades for the three subjects:%g,%g,%g\n", p->id, p->name, p->score[0], p->score[1], p->score[2]);
	}
	else
	{
		puts("Not found!");
	}
	system("pause");
}

//4
Student *deleteNode(Student *head)
{
	int n;
	Student *p = head, *p_last;

	system("cls");
	printf("enter student id number you want to delete:");
	scanf("%d", &n);

	if (p != NULL && p->id == n)
	{
		head = p->next;

		free(p);
		printf("***the student whose id is %d has been deleted***\n", n);
		system("pause");
		return head;
	}
	while (p != NULL && p->id != n)
	{
		p_last = p;
		p = p->next;
	}
	if (p != NULL)
	{
		p_last->next = p->next;

		free(p);
		printf("***the student whose id is %d has been deleted***\n", n);
	}
	else
	{
		puts("Not found!");
	}

	system("pause");
	return head;
}

//5
void print(Student *head)
{
	Student *p;

	system("cls");
	if (head == NULL)
	{
		printf("***No data in List***\n");
	}

	for (p = head; p != NULL; p = p->next)
	{
		printf("id:%d\nname:%s\ngrades for the three subjects:%g,%g,%g\n", p->id, p->name, p->score[0], p->score[1], p->score[2]);
	}

	system("pause");
}

//6
void save(Student *head)
{
	FILE *fp = fopen("data", "wb");
	Student *p = head;

	system("cls");
	rewind(fp);
	printf("storing...@_@\n");

	if (fp == NULL)
	{
		puts("can not open the file!");
		exit(EXIT_FAILURE);
	}

	while (p != NULL)
	{
		fwrite(p, sizeof(Student), 1, fp);
		p = p->next;
	}

	system("pause");
	fclose(fp);
}

//7
void over(Student *head)
{
	Student *p = head, *temp;

	system("cls");
	puts("deleting...@_@");

	while (p != NULL)
	{
		temp = p->next;
		free(p);
		p = temp;
	}

	system("pause");
	exit(EXIT_SUCCESS);
}

void init(void)
{
	system("color 0a");
	printf("***********************************************************************************************************\n");
	printf("*0:Read in student data from the file                        1:Enter a student data                       *\n"
		   "*2:Look for students according to student Numbers            3:Modify student data according to student id*\n"
		   "*4:Delete student data according to student id               5:Display all student data                   *\n"
		   "*6.Save student data to file                                 7:quit                                       *\n");
	printf("***********************************************************************************************************\n");
}
