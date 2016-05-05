/*
	program to input data from file and store it in another file
	using basic bubble sort
*/
#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int* a,int size) {
	int i,j;
	for(i=0;i<size-1;i++)
		for(j=0;j<size-i-1;j++)
			if(a[j]>a[j+1]) {
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
}

int main() 
{
	FILE *infile,*outfile;
	char filename[100];
	long pos=0;
	
	int size=0,value=0,i=0;
	int *data;
	system("cls");
	
	printf("\nEnter a filename to open: ");
	gets(filename);
	
	if ((infile = fopen (filename, "r")) == NULL)
    {
    	printf("\nCannot open file for reading..\n");
		return 1;
    }
	
	fseek(infile,0,SEEK_END);
	pos = ftell(infile);
	
	size = pos /sizeof(int);
	data = (int *)malloc(size*sizeof(int));
	
	rewind(infile);
	printf("\nReading data now..\n");
	while (!feof(infile) && fscanf (infile, "%d", &value) && i < size )
    {
    	data[i] = value;
    	i++;
    }
	fclose(infile);
	
	printf("\nSorting started..\n");
	bubbleSort(data,size);
	
	printf("\nData sorted. Now saving as \'output.txt\' ..\n");
	
	outfile = fopen("output.txt","w+");
	
	for(i=0;i<size;i++)
		fprintf(outfile,"%d\n",data[i]);
	printf("\nData saved.\n");
	
	rewind(outfile);
	
	printf("\nReading data now..\n");
	i=0;
	while (!feof(outfile) && fscanf (outfile, "%d", &value) && i < size ) {
    	printf("%d\n",value);
    	i++;
    }
	fclose(outfile);
	
	printf("\nProcessing Complete.\n");
	system("pause");
	
	return 0;
}
