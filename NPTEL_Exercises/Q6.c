#include <stdio.h>

void main()
{
	int n,sum=0;
	printf("Enter N:");
	scanf("%d",&n);
	for (int i=2;i<=n;i+=2)
		sum+=i;
	printf("Sum = %d",sum);
}