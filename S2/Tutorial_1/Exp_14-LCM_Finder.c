#include <stdio.h>
void main()
{
	int num1,num2,lcm=2;
	printf("Enter the first number:");
	scanf("%d",&num1);
	printf("Enter the second number:");
	scanf("%d",&num2);
	while(1)
	{
		if (lcm%num1==0 && lcm%num2==0)
		{
			printf("The Least common multiple of %d and %d is %d",num1,num2,lcm);
			break;
		}
		lcm++;
	}
}