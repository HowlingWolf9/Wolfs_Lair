#include <stdio.h>

void main()
{
	int num1,num2,largest;
	printf("Enter the first number:");
	scanf("%d",&num1);
	printf("Enter the second number:");
	scanf("%d",&num2);
	if (num1>num2)
	{
		printf("First number is the largest number");
		largest=num1;
	}
	else
	{
		printf("Second number is the largest number");
		largest=num2;
	}
	if(largest%2==0)
	{
		printf(" and it is even\n");
	}
	else
	{
		printf(" and it is odd\n");
	}
}