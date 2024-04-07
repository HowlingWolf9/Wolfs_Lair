#include <stdio.h>

void main()
{
	int num,first=0,second=1,fib=1,pos;
	printf("Enter the number:");
	scanf("%d",&num);
	pos=num;
	if (num<=0)
	{
		printf("The Fibonacci number at postion %d = 0",pos);
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
		printf("The Fibonacci number at postion %d = %d",pos,fib);
	}
}