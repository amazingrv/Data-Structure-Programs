//selection sort using a function 
#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int minimum(int a[],int k,int size) {
	int min=a[k],loc=k,j;
	
	for(j=k+1;j<size;j++) {
		if(min>a[j]) {
			min=a[j];
			loc=j;
		}
	}
	return loc;
}

void selectionSort(int a[],int size) {
	int i,loc,temp,k;
	
	for(i=0;i<size;i++) {
		loc=minimum(a,i,size);
		temp=a[i];
		a[i]=a[loc];
		a[loc]=temp;
				
		printf("\nResult after Pass %d -->\n",i+1);
		for(k=0;k<size;k++) {
			printf(" %d",a[k]);
		}
	}
}

int main() 
{
	int a[MAX] = {0},n=0,i;
	system("cls");
	
	printf("\nEnter the number of elemenets: ");
	scanf("%d",&n);
	
	printf("\nEnter the array:\n");
	for(i=0;i<n;i++) {
		scanf("%d",&a[i]);
	}
	selectionSort(a,n);
	
	printf("\n\nHere is the sorted array:\n");
	for(i=0;i<n;i++) {
		printf(" %d",a[i]);
	}
	printf("\n\n");
	system("pause");
	return 0;
}
