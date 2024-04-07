#include <stdio.h>

int main()
{
	int num1,num2,temp;
	printf("Enter the first number:");
	scanf("%d",&num1);
	printf("Enter the second number:");
	scanf("%d",&num2);
	temp=num1;
	num1=num2;
	num2=temp;
	printf("Number-1 = %d & Number-2 = %d",num1,num2);
}