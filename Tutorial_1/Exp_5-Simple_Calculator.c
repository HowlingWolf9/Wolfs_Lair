#include <stdio.h>

void main()
{
	float num1,num2;
	char operator;
	printf("Enter the operator (+,-,*,/) :");
	scanf("%c",&operator);
	printf("Enter the first number:");
	scanf("%f",&num1);
	printf("Enter the second number:");
	scanf("%f",&num2);
	switch(operator)
	{
		case '+':
		printf("%.2f+%.2f=%.2f",num1,num2,(num1+num2));
		break;
		case '-':
		printf("%.2f-%.2f=%.2f",num1,num2,(num1-num2));
		break;
		case '*':
		printf("%.2f*%.2f=%.2f",num1,num2,(num1*num2));
		break;
		case '/':
		printf("%.2f/%.2f=%.2f",num1,num2,(num1/num2));
		break;
		default:
		printf("Invalid Operation");
		break;
	}
}