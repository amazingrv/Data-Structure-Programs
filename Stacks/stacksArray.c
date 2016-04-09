//implement stack using array.
#include <stdio.h>
#include <conio.h>
#define MAX 10

void push(int stack[],int *top,int item) {
	if(*top==MAX-1) {
		printf("\nStack is full!\n");
		return ;
	}
	
	(*top)++;
	stack[*top]=item;
	printf("\n%d was inserted.\n",item);
}

void pop(int stack[],int *top) {
	if(*top==-1) {
	printf("\nStack is Empty!\n");
		return ;
	}
	
	printf("\n%d was deleted.\n",stack[*top]);
	(*top)--;
}

void display(int stack[], int top) {
	int i;
	if(top==-1) {
		printf("\nStack is empty!\n");
		return;
	}
	printf("\nStack from Top ->\n");
	for(i=top; i>=0; i--)
		printf("%d\n",stack[i]);
}

int main()
{
	int s[MAX],top=-1;
	system("cls");

	while(1) {
		int item=-1,choice=-1;
		printf("\n::Stack Operations::\n");
		printf("1. Insert into Stack.\n");
		printf("2. Delete from Stack\n");
		printf("3. Display Stack\n");
		printf("4. Exit\n");
		printf("\nEnter your choice: ");
		scanf("%d",&choice);
		
		switch(choice) {
		case 1: 	printf("\nEnter element to insert: ");
					scanf("%d",&item);
					push(s,&top,item);
					break;
		case 2: 	pop(s,&top);
					break;
		case 3:		display(s,top);
					break;
		case 4:		printf("\nExiting....\n");
					return 0;
		default:	printf("\nWrong choice!\n");
		}
	}

	system("pause");
	return 0;
}
