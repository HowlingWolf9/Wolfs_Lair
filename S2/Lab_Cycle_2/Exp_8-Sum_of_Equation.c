#include <stdio.h>
#include <math.h>

void main()
{
	int x,n;
	float sum=1;
	printf("Enter x:");
	scanf("%d",&x);
	printf("Enter n:");
	scanf("%d",&n);
	for(int i=2;i<n;i+=2)
		sum+=(pow(x,i)/i);
	sum+=(pow(x,n)/n);
	printf("Sum=%f",sum);
}