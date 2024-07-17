#include <stdio.h>
void main()
{
	int num,fac=1;
	printf("Enter the number:");
	scanf("%d",&num);
	while(num>0)
	{
		fac=fac*num;
		num--;
	}
	printf("Factorial=%d\n",fac);
}