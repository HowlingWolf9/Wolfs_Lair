#include <stdio.h>

int fact(int num)
{
	if(num<=0)
		return 0;
	else if (num==1)
		return 1;
	return num*fact(num-1);
	
}

void main()
{
	int num;
	printf("Enter the Number : ");
	scanf("%d",&num);
	printf("The Factorial of %d is %d",num,fact(num));
}