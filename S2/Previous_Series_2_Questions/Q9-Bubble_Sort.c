#include <stdio.h>

void main()
{
	int temp,arr[10]={1,2,7,9,25,3,26,49,69,14};
	for (int i=9;i>0;i--)
		for(int j=0;j<i;j++)
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}	
	printf("Sorted Array: ");
	for (int i=0;i<10;i++)
		printf("%d ",arr[i]);
}
	