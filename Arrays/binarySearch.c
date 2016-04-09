//binary search using a function
#include <stdio.h>
#include <stdlib.h>

int binarySearch(int a[],int size,int item) {
	int beg,end,mid;
	beg=0,end=size-1;
	mid=(beg+end)/2;
	while ((beg<=end) && a[mid]!=item) {
		if(item < a[mid])
			end=mid-1;
		else
			beg=mid+1;
		mid=(beg+end)/2;  
	}
	if (beg>end)
		return -1;
 	else
		return mid+1;
}

int main()
{
	int a[100],i,num,item,loc=-1;
	system("cls");
	printf("Enter array size:");
	scanf("%d",&num);
	
	printf("\n Enter array elements:");
	for(i=0;i<num;i++)
		scanf("%d",&a[i]);
	   
	printf("\nEnter element to search:");  
	scanf("%d",&item);
	
	loc=binarySearch(a,num,item);
	if(loc!=-1)
		printf("\nElement found at postion: %d\n",loc);
	else
		printf("\nElement not found.\n");
	
	system("pause");
	return 0; 
}
