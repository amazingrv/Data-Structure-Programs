//program to perform insert and delete on linked queue
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int info;
	struct Node *next;
}queue;

void enqueue(queue**,queue**,int item);
void dequeue(queue**,queue**);
void display(queue*);
void freeAll(queue**,queue**);

int main() {
	queue *front=NULL,*rear=NULL;
	system("cls");
	
	while(1) {
		int choice=0,item=-1;
		printf("\n::Queue Operations::\n");
		printf("1. Insert in Queue\n");
		printf("2. Delete from Queue\n");
		printf("3. Display Queue\n");
		printf("4. Exit\n");
		printf("Enter Your choice: ");
		scanf("%d",&choice);
		
		switch(choice) {
		case 1: {
					printf("\nEnter the value to insert: ");
					scanf("%d",&item);
					enqueue(&front,&rear,item);
				}
				break;
		case 2: dequeue(&front,&rear);
				break;
		case 3: display(front);
				break;
		case 4: printf("\nExiting....\n");
				freeAll(&front,&rear);
				return 0;
		default: printf("\nWrong Choice!\n");
		}
	}

	system("pause");
	return 0;	
}

void enqueue(queue **front,queue **rear,int item) {
	queue *newNode=(queue*)calloc(1,sizeof(queue));
	if(newNode==NULL) {
		printf("\nQueue is full!\n");
		return;
	}
	
	newNode->info=item;
	newNode->next=NULL;
	
	if(*front==NULL)
		*front=*rear=newNode;
	else {
		(*rear)->next=newNode;
		*rear=newNode;
	}
	printf("\n%d was inserted.\n",(*rear)->info);
}

void dequeue(queue **front, queue **rear) {
	queue *ptr=*front;
	if(*front==NULL) {
		printf("\nQueue is empty!\n");
		return;
	}
	
	if(*front==(*rear))
		*front=*rear=NULL;
	else
		*front=(*front)->next;
		
	printf("\n%d was deleted.\n",ptr->info);
	free(ptr);
}

void display(queue *front) {
	queue *ptr=front;
	if(front==NULL) {
		printf("\nQueue is Empty!\n");
		return;
	}
	
	printf("\nQueue is as follows ->\n %d ",ptr->info);
	for(ptr=ptr->next;ptr!=NULL;ptr=ptr->next)
		printf("-> %d ",ptr->info);
	printf("\n");
}

void freeAll(queue **front, queue **rear) {
	queue* ptr=*front;
	if(*front==NULL) {
		return;
	}	
	printf("\nDeleting remaining queue..\n");
	while(ptr!=NULL) {
		ptr=ptr->next;
		free(*front);
		*front=ptr;
	}
	*front=*rear=NULL;
}
