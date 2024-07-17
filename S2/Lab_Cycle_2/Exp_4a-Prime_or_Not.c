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
			break;
		}
	}
	if (numfac!=2 || num<=1)
	{
		printf("NOT Prime");
	}
	else
	{
		printf("Its Prime",num);
	}
}