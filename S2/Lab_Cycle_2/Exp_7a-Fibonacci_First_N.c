#include <stdio.h>

void main()
{
	int num,first=0,second=1,fib=1;
	printf("Enter N:");
	scanf("%d",&num);
	printf("%d",first);
	while(num>1)
	{
		printf(",%d",fib);
		fib=second+first;
		first=second;
		second=fib;
		num--;
	}
}