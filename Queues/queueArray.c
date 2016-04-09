//program to perform operations on array circular queue
#include <stdio.h>
#include <stdlib.h>
#define MAX 5

void enqueue(int *queue,int *front,int *rear, int item);
void dequeue(int *queue,int *front,int *rear);
void display(int *queue, int front, int rear);

int main() {
	int q[MAX],front=-1,rear=-1;
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
					enqueue(q,&front,&rear,item);
				}
				break;
		case 2: dequeue(q,&front,&rear);
				break;
		case 3: display(q,front,rear);
				break;
		case 4: printf("\nExiting....\n");
				return 0;
		default: printf("\nWrong Choice!\n");
		}
	}

	system("pause");
	return 0;
}

void enqueue(int *queue,int *front,int *rear, int item) {
	if((*front==0 && *rear==MAX-1) || (*front==*rear+1)) {
		printf("\nQueue is full!\n");
		return;
	}
	
	if(*front==-1)
		*front=*rear=0;
	else if(*rear==MAX-1)
		*rear=1;
	else
		*rear+=1;
	queue[*rear]=item;
	printf("\n%d was Inserted.\n",item);
}

void dequeue(int *queue,int *front,int *rear) {
	if(*front==-1) {
		printf("\nQueue is Empty!\n");
		return;
	}
	
	printf("\n%d was deleted.\n",queue[*front]);
	if(*front == *rear)
		*front=*rear=-1;
	else if(*front==MAX-1)
		*front=1;
	else
		*front+=1;
}

void display(int *queue, int front, int rear) {
	int i;
	if(front==-1) {
		printf("\nQueue is Empty!\n");
		return;
	}
	
	printf("\nQueue is as follows->\n");
	for(i=front;i<=rear;i++) {
		if(i==MAX)
			i=0;
		printf(" %d",queue[i]);
	}
	printf("\n");
}
