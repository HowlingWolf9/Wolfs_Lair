#include <stdio.h>

void main()
{
	int num,numfac,sum=0;
	printf("Enter Number :");
	scanf("%d",&num);
	for (int i=1;i<=(num/2);i++)
		if (num%i==0)
			sum+=i;
	if (sum==num)
		printf("Is Perfect");
	else
		printf("NOT Perfect");
}
