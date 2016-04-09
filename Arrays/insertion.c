#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void insertelement(int a[],int* size,int item,int pos) {
	int i;
	for(i=(*size)-1; i>=pos-1; i--) {
		a[i+1]=a[i];
	}
	a[pos-1]=item;
	(*size)+=1;
	printf("\nElement insert Success.\n");
}


int main() 
{
	int a[MAX] = {0},n=0,i;
	char ch='n';
	system("cls");
	
	printf("\nEnter the number of elemenets: ");
	scanf("%d",&n);
	
	printf("\nEnter the array:\n");
	for(i=0;i<n;i++) {
		scanf("%d",&a[i]);
	}
	
	printf("\nEntered array is: \n");
	for(i=0;i<n;i++) {
		printf(" %d",a[i]);
	}

	do {
		int data=0,pos=-1;
		if(n==MAX) {
			printf("\nNo More Space Left to Insert element.");
			break;
		}
		
		printf("\n\nEnter an element to insert: ");
		scanf("%d",&data);
		printf("\nEnter a position: ");
		scanf("%d",&pos);
		
		if(pos<1) {
			printf("\nPosition is invalid!\nInserting at beginning.\n");
			pos=1;
		}	
		else if(pos>=n) {
			printf("\nPosition is invalid!\nInserting at end.\n");
			pos=n;
		}
		insertelement(a,&n,data,pos);
		
		printf("\nChanged array is: \n");
		for(i=0;i<n;i++) {
			printf(" %d",a[i]);
		}
		
		fflush(stdin);
		printf("\n\nWant to Insert more? (Y/N): ");
		scanf("%c",&ch);		
	}while(ch=='y'||ch=='Y');
	
	printf("\n");
	system("pause");
	return 0;
}