#pragma once

typedef struct Student
{
	int id;
	char name[10];
	double score[3];
	struct Student *next;
} Student;

Student *read();
Student *add(Student *head);
void search(Student *head);
void modify(Student *head);
Student *deleteNode(Student *head);
void print(Student *head);
void save(Student *head);
void over(Student *head);
void init(void);
