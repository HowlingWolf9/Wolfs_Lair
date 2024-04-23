#include <stdio.h>

void main()
{
	int n;
	float sum;
	printf("Enter No.of Elements:");
	scanf("%d",&n);
	int arr[n];
	for (int i=0;i<n;i++)
	{
		printf("Enter Number %d :",i+1);
		scanf("%d",&arr[i]);
	}
	for (int i=0;i<n;i++)
		sum+=arr[i];
	printf("Sum=%f\nAverage=%f",sum,(sum/n));
}