#include <stdio.h>

int main()
{
	int num,numfac=2,prime=2,opt;
	printf("Enter the number:");
	scanf("%d",&num);
	printf("1.Prime or NOT\n2.Prime less than N\nSelect(1 or 2):");
	scanf("%d",&opt);
	switch(opt)
	{
		case 1:
		for (int i=2;i<=(num/2);i++)
			if (num%i==0)
			{
				numfac++;
				break;
			}
		if (numfac!=2 || num<=1)
			printf("NOT Prime");
		else
			printf("Its Prime",num);
		break;
		
		case 2:
		while(prime<num)
		{
			numfac=2;
			for (int i=2;i<=(prime/2);i++)
				if (prime%i==0)
				{
					numfac++;
					break;
				}
			if (numfac==2)
				printf("%d,",prime);
			prime++;
		}
		break;
	
		default:
		printf("Invalid Operation");
		break;
	}
}	