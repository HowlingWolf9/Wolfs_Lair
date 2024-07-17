#include <stdio.h>

void main()
{
	int elm,pos=0,arr[10]={1,2,7,1,25,3,26,49,69,14};
	printf("Enter the element to search for :");
	scanf("%d",&elm);
	for (int i=0;i<10;i++)
	{
		if (elm==arr[i])
		{
			printf("The element %d is in position %d.\n",elm,i+1);
			pos=i+1;
		}
	}
	if (pos==0)
		printf("The element does not exist in the given array.");
}
	