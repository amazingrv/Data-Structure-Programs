//linear search using a function
#include <stdio.h>
#include <stdlib.h>

int linearSearch(int a[],int size,int item) {
	int loc=-1,i;
	for(i=0;i<size;i++) {
		if(a[i]==item) {
			loc=i+1;
			break;
		}
	}
	
	return loc;
}

int main()
{
	int a[100],i,num,item,loc=-1;
	system("cls");
	printf("Enter array size: ");
	scanf("%d",&num);
	
	printf("\nEnter array elements: ");
	for(i=0;i<num;i++)
	   scanf("%d",&a[i]);
	   
	printf("\nEnter element to search: ");  
	scanf("%d",&item);
	
	loc=linearSearch(a,num,item);
	
	if(loc!=-1)
		printf("\nElement found at postion: %d\n",loc);
	else
		printf("\nElement not found.\n");
	
	system("pause");
	return 0;	 
}
