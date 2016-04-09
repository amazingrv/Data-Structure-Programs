#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void deleteElement(int a[],int* size,int pos) {
	int i,item=0;
	item=a[pos-1];
	for(i=pos-1;i<(*size)-1;i++) {
		a[i]=a[i+1];
	}
	(*size)-=1;
	printf("\nElement %d was deleted Successfully.\n",item);
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
		int pos=-1;
		if(n==0) {
			printf("\nNo More elements left to delete.");
			break;
		}
		
		printf("\nEnter a position: ");
		scanf("%d",&pos);
		if(pos<1){
			printf("\nPosition is invalid!\nDeleteing at start.\n");
			pos=1;
		}
		else if(pos>n){
			printf("\nPosition is invalid!\nDeleteing at end.\n");
			pos=n;
		}
		deleteElement(a,&n,pos);
		
		printf("\nChanged array is: \n");
		for(i=0;i<n;i++) {
			printf(" %d",a[i]);
		}
		
		fflush(stdin);
		printf("\n\nWant to delete more? (Y/N): ");
		scanf("%c",&ch);
	}while(ch=='y'||ch=='Y');
	
	printf("\n");
	system("pause");
	return 0;
}