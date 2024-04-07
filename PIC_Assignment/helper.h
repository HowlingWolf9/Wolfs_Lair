#include <stdio.h>

int fact(int num)
{
	int fact=1;
	while(num>0)
	{
		fact=fact*num;
		num--;
	}
	return fact;
}

void prime(int num)
{
	int numfact=2;
	for (int i=2;i<=(num/2);i++)
	{
		if (num%i==0)
		{
			numfact++;
		}
	}
	if (numfact!=2 || num<=1)
	{
		printf("%d is not a prime number\n",num);
	}
	else
	{
		printf("%d is a prime number\n",num);
	}
}

void oddoreven(int num)
{
	if (num==0)
	{
		printf("%d is neither odd nor even\n",num);
	}
	else if (num%2==0)
	{
		printf("%d is an even number\n",num);
	}
	else
	{
		printf("%d is an odd number\n",num);
	}
}

int fibonacci(int num)
{
	int first=0,second=1,fib=1,pos;
	pos=num;
	if (num<=0)
	{
		return 0;
	}
	else
	{
		while(num>2)
		{
			fib=second+first;
			first=second;
			second=fib;
			num--;
		}
		return fib;
	}
}

void primeton(int num)
{
	int prime=2,numfact=2;
	printf("Prime numbers upto %d :",num);
	while(num>0)
	{
		numfact=2;
		for (int i=2;i<=(prime/2);i++)
		{
			if (prime%i==0)
			{
				numfact++;
				break;
			}
		}
		if (numfact==2)
		{
			printf("%d,",prime);
			num--;
		}
		prime++;
	}
}