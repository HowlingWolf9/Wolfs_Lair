#include <stdio.h>

void main()
{
	int num,first=0,second=1,fib=1,pos;
	printf("Enter the number:");
	scanf("%d",&num);
	if (num<=0)
	{
		printf("0");
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
		printf("%d",fib);
	}
}