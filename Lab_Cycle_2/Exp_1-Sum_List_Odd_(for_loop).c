#include <stdio.h>

void main()
{
	int n,num,sum=0,i=1;
	printf("Enter the number of elements:");
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		printf("Enter number %d :",i);
		scanf("%d",&num);
		if (num%2!=0)
		{
			sum=sum+num;
		}
	}
	printf("Sum of all Odd numbers = %d\n",sum);
}