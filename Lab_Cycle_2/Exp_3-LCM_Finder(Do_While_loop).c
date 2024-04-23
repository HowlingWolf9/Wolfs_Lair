#include <stdio.h>

void main()
{
	int num1,num2,lcm;
	printf("Enter the first number:");
	scanf("%d",&num1);
	printf("Enter the second number:");
	scanf("%d",&num2);
	lcm=num1;
	do{
		if (lcm%num1==0 && lcm%num2==0)
		{
			printf("The Least Common Multiple of %d and %d is %d",num1,num2,lcm);
			break;
		}
		lcm++;
	}while(1);
}