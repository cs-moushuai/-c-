#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "header.h"

int main(void)
{
	char ch;
	Student *head = NULL;

	while (1)
	{
		fflush(stdin);
		system("cls");
		init();

		ch = getch();
		switch (ch)
		{
		case '0':
			head = read();
			break;
		case '1':
			head = add(head);
			break;
		case '2':
			search(head);
			break;
		case '3':
			modify(head);
			break;
		case '4':
			head = deleteNode(head);
			break;
		case '5':
			print(head);
			break;
		case '6':
			save(head);
			break;
		case '7':
			over(head);
			break;
		}
	}
	return 0;
}
