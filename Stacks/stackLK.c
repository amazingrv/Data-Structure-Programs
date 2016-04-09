//implement stack using singly linked list
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int info;
	struct Node *next;
}stack;

void display(stack*);
void push(stack**,int);
void pop(stack**);
void freeAll(stack**);

int main() {
	stack *top=NULL;
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
					push(&top,item);
					break;
		case 2: 	pop(&top);
					break;
		case 3:		display(top);
					break;
		case 4:		printf("\nExiting....\n");
					freeAll(&top);
					return 0;
		default:	printf("\nWrong choice!\n");
		}
	}

	system("pause");
	return 0;
}

void push(stack **top,int item) {
	stack *ptr = (stack*)calloc(1,sizeof(stack));
	if(ptr==NULL) {
		printf("\nStack is full!\n");
		return;
	}
	ptr->info=item;
	ptr->next=*top;
	*top=ptr;
	printf("\n%d was inserted.\n",item);
}

void pop(stack **top) {
	stack *ptr=*top;
	if(*top==NULL) {
		printf("\nStack is empty!\n");
		return;
	}
	*top=(*top)->next;
	printf("\n%d was deleted.\n",ptr->info);
	free(ptr);
}

void display(stack *top) {
	stack *ptr;
	if(top==NULL) {
		printf("\nStack is empty!\n");
		return;
	}
	printf("\nStack is:\n");
	printf("%d <- Top\n",top->info);
	ptr=top->next;
	while(ptr!=NULL) {
		printf("%d\n",ptr->info);
		ptr=ptr->next;
	}
}

void freeAll(stack **top) {
	stack* ptr=*top;
	if(*top==NULL)
		return;

	printf("\nDeleting List..\n");
	while(ptr!=NULL) {
		ptr=ptr->next;
		free(*top);
		*top=ptr;
	}
	*top=NULL;
}
