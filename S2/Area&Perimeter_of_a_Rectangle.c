#include <stdio.h>

int main()
{
	int length,width,area,perimeter;
	printf("Enter the length of the rectangle:");
	scanf("%d",&length);
	printf("Enter the width of the rectangle:");
	scanf("%d",&width);
	area=length*width;
	perimeter=(length+width)*2;
	printf("Area=%d\nPerimeter=%d",area,perimeter);
}