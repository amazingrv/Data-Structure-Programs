//doubly linked list using multiple functions
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int info;
	struct Node *next;
	struct Node *prev;
}list;

void menu(void);
void createList(list**,list**);
void traverseList(list*,list*);
list* searchInList(list*,int);
void insertAtBeg(list**,list**,int);
void insertAfterData(list*,list**,int,int);
void insertAtEnd(list**,list**,int);
void deleteNode(list**,list**,int);
void freeAll(list**,list**);

int main()
{
	list *begin=NULL,*end=NULL;
	system("cls");
	do
	{
		int choice=0;
		int data=0,item=0;
		system("cls");
		menu();
		printf("\nEnter Your Choice: ");
		scanf("%d",&choice);
		switch(choice) {
		case 1:		createList(&begin,&end);
					break;
		case 2:		traverseList(begin,end);
					break;
		case 3:		printf("\nEnter data to search: ");
					scanf("%d",&data);
					searchInList(begin,data);
					break;
		case 4:		printf("\nEnter data to insert: ");
					scanf("%d",&data);
					insertAtBeg(&begin,&end,data);
					break;
		case 5:		printf("\nEnter data to search: ");
					scanf("%d",&item);
					printf("\nEnter data to insert: ");
					scanf("%d",&data);
					insertAfterData(begin,&end,item,data);
					break;
		case 6:		printf("\nEnter data to insert: ");
					scanf("%d",&data);
					insertAtEnd(&begin,&end,data);
					break;
		case 7:		printf("\nEnter data to delete: ");
					scanf("%d",&item);
					deleteNode(&begin,&end,item);
					break;
		case 8: 	printf("\nExiting...\n");
					freeAll(&begin,&end);
					printf("\nThank You.\n");
					system("pause");
					return 0;
		default:	printf("\nTry again...\n"); 
		}
		system("pause");
	}while(1);
}

void menu() {
	printf("\n....Awesome List Creation....\n");
	printf("\n -------::MENU::-------\n");
	printf(" 1 - Create Primary List\n");
	printf(" 2 - Display List\n");
	printf(" 3 - Search in List\n");
	printf(" 4 - Insert at Beginning\n");
	printf(" 5 - Insert After Data\n");
	printf(" 6 - Insert at End\n");
	printf(" 7 - Delete a Node\n");
	printf(" 8 - End Program\n");
	printf("\n ----------------------\n");	
}

void createList(list **begin,list **end) {
	int count=0,i;
	list* ptr=NULL;
	
	if(*begin!=NULL) {
		printf("\nPrimary list is Already Created!\n\nAborting...\n");
		return;
	}
	printf("\nHow many Nodes you want to Create? ");
	scanf("%d",&count);
	if(count<0) {
		printf("\nCount cannot be negative!\nSorry!\n");
		system("pause");
		return;
	}
	for(i=1;i<=count;i++) {
		int data=0;
		printf("\nEnter data for Node %d: ",i);
		scanf("%d",&data);
			
		if(*begin==NULL) {
			*begin=(list*)calloc(1,sizeof(list));			
			if(*begin==NULL) {
				printf("\nCannot create Node..\n");
				return;
			}	
			ptr=*begin;
			ptr->prev=NULL;
		}
		else {
			ptr->next=(list*)calloc(1,sizeof(list));
			if(ptr->next==NULL) {
				printf("\nCannot create Node..\n");
				return;
			}
			(ptr->next)->prev=ptr;
			ptr=ptr->next;
		}
		ptr->info=data;
		ptr->next=NULL;
		printf("(1) Node Created.\n");
	}
	*end=ptr;
	printf("\nPrimary Linked List Created with (%d) Nodes.\n",count);
}

void traverseList(list *begin,list *end) {
	int count=1;
	list *ptr;
	if(begin==NULL) {
		printf("\nNo Nodes to traverse!\n\n");
		return;
	}
	printf("\nLinked List is as follows:\n\n");
	printf(" %d ",begin->info);
	for(ptr=begin->next;ptr!=NULL;ptr=ptr->next) {
		printf("-> %d ",ptr->info);
		count++;
	}	
	printf("\n\n(%d) Nodes traversed.\n",count);		

	count=1;
	if(end==NULL) {
		printf("\nReverse links are damaged!\n\n");
		return;
	}
	printf("\nReverse List is as follows:\n\n");
	printf(" %d ",end->info);
	for(ptr=end->prev;ptr!=NULL;ptr=ptr->prev) {
		printf("-> %d ",ptr->info);
		count++;
	}
	printf("\n\n(%d) Nodes traversed.\n",count);		
}

list* searchInList(list *begin,int item) {
	int count=1;
	list *ptr=begin;
	
	if(begin==NULL) {
		printf("\nList empty!\nSearch cannot continue!\n");
		return NULL;
	}
	while((ptr->next!=NULL)&&(ptr->info!=item)) {
		ptr=ptr->next;
		count++;
	}
	if(ptr->info==item) {
		printf("\nThe Data (%d) matches at Node (%d).\n",item,count);
		return ptr;
	}
	else {
		printf("\nNo Match for Data found!\n");
	}
	return NULL;
}

void insertAtBeg(list **begin,list **end,int item) {
	list *newNode=NULL;	
	printf("\nCreating Node...\n");
	newNode=(list*)calloc(1,sizeof(list));
	
	if(newNode==NULL) {
		printf("\nNode insertion failed!\n");
		return;
	}
	newNode->info=item;
	newNode->next=NULL;
	newNode->prev=NULL;
		
	if(*begin==NULL) {
		*begin=newNode;
		*end=*begin;
	}
	else {
		newNode->next=*begin;
		(*begin)->prev=newNode;
		*begin=newNode;
	}
	printf("\n(1) Node inserted.\n");
}

void insertAfterData(list *begin,list **end,int item,int data) {
	list* ptr=searchInList(begin,item);
	list* newNode=NULL;
	if(ptr==NULL) {
		printf("\nNode Insertion failed!");
		return;
	}
	newNode=(list*)calloc(1,sizeof(list));
	if(newNode==NULL) {
		printf("\nNode Insertion Failed!\n");
		return;
	}
	
	newNode->info=data;
	newNode->next=NULL;
	newNode->prev=NULL;
	if(ptr->next!=NULL) {
		newNode->next=ptr->next;
		(ptr->next)->prev=newNode;
		ptr->next=newNode;
		newNode->prev=ptr;
	}
	else {
		ptr->next=newNode;
		newNode->prev=ptr;
		*end=newNode;
	}
	printf("\n(1) Node inserted.\n");	
}

void insertAtEnd(list **begin,list **end,int item) {
	list *newNode=NULL, *ptr=NULL;	
	printf("\nCreating Node...\n");
	newNode=(list*)calloc(1,sizeof(list));
	
	if(newNode==NULL) {
		printf("\nNode insertion failed!\n");
		return;
	}
	newNode->info=item;
	newNode->next=NULL;
	newNode->prev=NULL;
		
	if(*begin==NULL) {
		*begin=newNode;
		*end=*begin;
	}
	else {
		for(ptr=*begin;ptr->next!=NULL;ptr=ptr->next);
		ptr->next=newNode;
		newNode->prev=ptr;
		*end=newNode;	
	}
	printf("\n(1) Node inserted.\n");	
}

void deleteNode(list **begin,list **end,int item) {
	list *ptr=searchInList(*begin,item);
	if(ptr==NULL) {
		printf("\nNothing to Delete.\n");
		return;
	}
	
	if(ptr==(*begin)) {
		*begin=ptr->next;
		(*begin)->prev=NULL;
	}
	else if(ptr->next!=NULL) {
		(ptr->next)->prev = ptr->prev;
		(ptr->prev)->next = ptr->next;
	}
	else {
		(ptr->prev)->next=NULL;
		*end=ptr->prev;
	}
	free(ptr);
	printf("\n(1) Node deleted.\n");
}

void freeAll(list **begin,list **end) {
	int count=0;
	list *ptr;
	if(*begin==NULL) {
		printf("\nNo List to delete!\n");
		return;
	}	
	
	printf("\nDeleting List..\n");
	ptr=(*begin);
	while(ptr!=NULL) {
		ptr=ptr->next;
		free(*begin);
		++count;
		*begin=ptr;
	}
	*end=NULL;
	printf("\n(%d) Node Deleted.\n",count);
}
