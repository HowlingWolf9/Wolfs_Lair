#include <stdio.h>
#include "helper.h"

void main()
{
	int num;
	printf("Enter the number:");
	scanf("%d",&num);
	printf("Factorial of %d : %d\n",num,fact(num));
	prime(num);
	oddoreven(num);
	printf("The Fibonacci number at postion %d = %d\n",num,fibonacci(num));
	primeton(num);
}