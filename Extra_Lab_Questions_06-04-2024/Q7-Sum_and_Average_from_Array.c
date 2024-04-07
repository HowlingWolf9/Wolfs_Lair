#include <stdio.h>

void main()
{
	int n,num;
	float sum=0,avg;
	printf("Enter the number of elements:");
	scanf("%d",&n);
	int arr[n];
	for (int i=0;i<n;i++)
	{
		printf("Enter Number %d:",i+1);
		scanf("%d",&arr[i]);
	}
	for (int j=0;j<n;j++)
		sum=sum+arr[j];
	avg=sum/n;
	printf("Sum = %f\n",sum);
	printf("Average = %f\n",avg);
}