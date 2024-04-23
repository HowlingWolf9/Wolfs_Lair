#include <stdio.h>

void main()
{
	int num,i=1,factorial=1;
	printf("Enter the Number:");
	scanf("%d",&num);
	while(i<=num)
	{
		factorial*=i;
		i++;
	}
	printf("The factorial of %d is : %d",num,factorial);
}