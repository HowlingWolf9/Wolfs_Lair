#include <stdio.h>

void main()
{
	int n,num,sum=0,i=1;
	printf("Enter the number of elements:");
	scanf("%d",&n);
	while (n>0)
	{
		printf("Enter number %d :",i);
		scanf("%d",&num);
		if (num%2==0)
		{
			sum=sum+num;
		}
		n--;
		i++;
	}
	printf("Sum of all Even numbers = %d\n",sum);
}