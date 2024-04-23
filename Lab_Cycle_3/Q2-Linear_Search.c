#include <stdio.h>

void main()
{
	int n,elm,pos=0;
	printf("Enter No.of Elements:");
	scanf("%d",&n);
	int arr[n];
	for (int i=0;i<n;i++)
	{
		printf("Enter Number %d :",i+1);
		scanf("%d",&arr[i]);
	}
	printf("Enter the element to search for :");
	scanf("%d",&elm);
	for (int i=0;i<n;i++)
	{
		if (elm==arr[i])
		{
			printf("The element is in position %d .\n",i+1);
			pos=i+1;
		}
	}
	if (pos==0)
		printf("The element does not exist in the given array.");
}
	