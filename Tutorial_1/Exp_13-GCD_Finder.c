#include <stdio.h>

void main()
{
	int num1,num2,lowest,i=1,gcd=1;
	printf("Enter the first number:");
	scanf("%d",&num1);
	printf("Enter the second number:");
	scanf("%d",&num2);
	if (num1>num2)
	{
		lowest=num2;
	}
	else
	{
		lowest=num1;
	}
	while(i<=lowest)
	{
		if (num1%i==0 && num2%i==0)
		{
			gcd=i;
		}
		i++;
	}
	printf("The Greatest Common Divisor of %d and %d is %d",num1,num2,gcd);
}