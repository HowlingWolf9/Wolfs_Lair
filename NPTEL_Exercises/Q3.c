#include <stdio.h>

void main()
{
	int num1,num2,num3;
	printf("Enter the Numbers:");
	scanf("%d%d%d",&num1,&num2,&num3);
	if (num1>num2)
		if (num2>num3)
			printf("%d is the smallest number",num3);
		else
			printf("%d is the smallest number",num2);
	else
		if (num1>num3)
			printf("%d is the smallest number",num3);
		else
			printf("%d is the smallest number",num1);
}