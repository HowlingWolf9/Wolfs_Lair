#include <stdio.h>

int main()
{
	int num,numfac=2;
	printf("Enter the number:");
	scanf("%d",&num);
	for (int i=2;i<=(num/2);i++)
	{
		if (num%i==0)
		{
			numfac++;
		}
	}
	if (numfac!=2 || num<=1)
	{
		printf("%d is not a prime number",num);
	}
	else
	{
		printf("%d is a prime number",num);
	}
}