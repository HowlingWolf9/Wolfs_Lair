#include <stdio.h>
#include <math.h>

void main()
{
	int radius;
	printf("Enter the radius of the Circle:");
	scanf("%d",&radius);
	float area=pow(radius,2)*3.14;
	printf("Area of a circle = %.2f",area);
}