#include <stdio.h>

int main()
{
	int i,temp=0,fib=1;
	printf("Enter the length of the Fibonocci series:");
	scanf("%d",&i);
	for (int j=1;j<=i;j++)
	{
		fib=fib+temp;
		printf("%d,",fib);
		temp=fib;
	}
	return 0;
}