#include <stdio.h>
int main()
{
	int a=10,b=3,c=2,d=4,result;
	result=a+a*-b/c%d+c*d;
	printf("%d",result);
	return 0;
}