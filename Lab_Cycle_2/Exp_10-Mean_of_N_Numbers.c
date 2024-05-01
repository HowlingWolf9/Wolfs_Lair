#include <stdio.h>

void main()
{
	int n,num,i=0;
	float sum=0;
	printf("Enter the number of elements:");
	scanf("%d",&n);
	while (n>0)
	{
		i++;
		printf("Enter Number %d:",i);
		scanf("%d",&num);
		sum+=num;
		n--;
	}
	printf("Mean = %f\n",(sum/i));
}