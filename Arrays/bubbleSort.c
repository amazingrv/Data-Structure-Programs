//bubble sort using a function 
#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void bubbleSort(int a[],int size) {
	int i,j,k;
	for(i=0;i<size-1;i++) {
		for(j=0;j<size-i-1;j++) {
			//Ascending sort 
			if(a[j]>a[j+1]) {
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
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
	bubbleSort(a,n);
	
	printf("\n\nHere is the sorted array:\n");
	for(i=0;i<n;i++) {
		printf(" %d",a[i]);
	}
	printf("\n\n");
	system("pause");
	return 0;
}
