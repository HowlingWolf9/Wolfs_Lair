#include <stdio.h>
#include <math.h>

void main()
{
	float a,b,c,x1,x2;
	printf("Enter the coefficients of the the equation:\n");
	printf("a:");
	scanf("%f",&a);
	printf("b:");
	scanf("%f",&b);
	printf("c:");
	scanf("%f",&c);
	x1=(-b+sqrt(b*b-4*a*c))/2*a;
	x2=(-b-sqrt(b*b-4*a*c))/2*a;
	printf("The roots are %.2f & %.2f\n",x1,x2);
}