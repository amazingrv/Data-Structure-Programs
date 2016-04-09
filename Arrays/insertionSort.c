//insertion sort using a function 
#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void insertionSort(int a[],int size) {
	int i,j,k,temp;
	for(i=1;i<size;i++) {
		temp=a[i];
		j=i-1;
		while(j>=0 && a[j]>temp) {
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=temp;
			
		printf("\nResult after Pass %d -->\n",i);
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
	insertionSort(a,n);
	
	printf("\n\nHere is the sorted array:\n");
	for(i=0;i<n;i++) {
		printf(" %d",a[i]);
	}
	printf("\n\n");
	system("pasue");
	return 0;
}
