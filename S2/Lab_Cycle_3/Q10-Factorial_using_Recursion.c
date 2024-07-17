/*
Experiment: 30
Date: 

AIM: Write a C program to find the factorial of a given Natural Number n using recursive function

ALGORITHM:
Step 01: START
Step 02: Declare a function fact with return type int and argument (int num)
Step 03: Define fact
Step 04: 	IF (num<=0), then
Step 05: 		RETURN 0
Step 06: 	ELSE IF (num==1), then
Step 07: 		RETURN 1
Step 08: 	ENDIF
Step 09: 	RETURN num*fact(num-1)
Step 10: Take num as input
Step 11: Display fact(num)
Step 12: STOP
*/
//CODE:
#include <stdio.h>

int fact(int num)
{
	if(num<=0)
		return 0;
	else if (num==1)
		return 1;
	return num*fact(num-1);
}

void main()
{
	int num;
	printf("Enter the Number : ");
	scanf("%d",&num);
	printf("The Factorial of %d is %d",num,fact(num));
}