#include <stdio.h>
float sum(int num[],int n)
{
	float sum=0;
	int i=0;
	for (i=0;i<n;i++)
		sum+=num[i];
	return sum;
}

float avg(int num[],int n)
{
	float avg=(sum(num,n)/n);
	return avg;
}
void main()
{
	int n,i;
	printf("Enter the no.of elements:");
	scanf("%d",&n);
	int num[n];
	printf("Enter the elements:");
	for (i=0;i<n;i++)
		scanf("%d",&num[i]);
	printf("Sum=%f\nAverage=%f",sum(num,n),avg(num,n));
}