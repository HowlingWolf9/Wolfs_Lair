#include <stdio.h>
int main()
{
	int n,x=0,y;
	printf("Enter an integer: ");
	scanf("%d",&n);
	while (n!=0)
	{
		y=n%10;
		x=x-y;
		n=n/10;
	}
	printf("Output is = %d",x);
	return 0;
}