#include <stdio.h>
#include <math.h>

void main()
{
	int s1,s2,s3;
	printf("Enter the lengths of three sides:");
	scanf("%d%d%d",&s1,&s2,&s3);
	int s=(s1+s2+s3)/2;
	int area=sqrt(s*(s-s1)*(s-s2)*(s-s3));
	if(area<=0)
		printf("Triangle is not possible");
	else if (s1==s2 && s2==s3)
		printf("Equilateral Triangle");
	else if (s1==s2 || s2==s3)
		printf("Isosceles Triangle");
	else if (((s1*s1)+(s2*s2))==(s3*s3) || ((s1*s1)-(s2*s2))==(s3*s3))
		printf("Right-angle Triangle");
	else 
		printf("Scalene Triangle");
}