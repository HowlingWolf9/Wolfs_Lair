#include <stdio.h>

void main()
{
	float num;
	printf("Enter the Number:");
	scanf("%f",&num);
	if (num==0)
		printf("The number is 0.");
	else if (num<0)
		printf("Negative number.");
	else
		printf("Positive number.");
}