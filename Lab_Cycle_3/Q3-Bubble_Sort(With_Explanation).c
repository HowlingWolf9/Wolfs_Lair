#include <stdio.h>

void main()
{
	int n,temp;
	printf("Enter No.of Elements:");
	scanf("%d",&n);
	int arr[n];
	for (int i=0;i<n;i++)
	{
		printf("Enter Number %d :",i+1);
		scanf("%d",&arr[i]);
	}
	for (int i=n-1;i>0;i--)
	{
		printf("----------------------------------\n");
		for(int j=0;j<i;j++)
		{	
			for (int k=0;k<n;k++)
				printf("%d\t",arr[k]);
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
				printf("\n");	
				for(int s=1;s<=j;s++)
					printf("\t");
				printf("-->");
			}
			else
			{
				printf("\n");
				for(int s=1;s<=j;s++)
					printf("\t");
				printf("No Change");
			}
			printf("\n");
		}
	}
	printf("\nSorted Array: ");
	for (int i=0;i<n;i++)
		printf("%d ",arr[i]);
}
	