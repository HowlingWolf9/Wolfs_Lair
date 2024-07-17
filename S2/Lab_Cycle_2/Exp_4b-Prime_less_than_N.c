#include <stdio.h>

void main()
{
	int num,prime=2,numfac=2;	
	printf("Enter the number:");
	scanf("%d",&num);
	while(prime<num)
	{
		numfac=2;
		for (int i=2;i<=(prime/2);i++)
		{
			if (prime%i==0)
			{
				numfac++;
				break;
			}
		}
		if (numfac==2)
		{
			printf("%d,",prime);
		}
		prime++;
	}
}