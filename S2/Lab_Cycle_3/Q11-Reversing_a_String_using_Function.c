/*
Experiment: 31
Date: 

AIM: Write a C program to read a string (word), store it in an array and obtain its reverse by using a user defined function.

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

char *strrev(char *string)
{
	char rev[20]={};
	int len1=0,len2;
	while(string[len1]!='\0')
			len1++;
	len2=len1;
	while(len1>0)
	{
		rev[len2-len1]=string[len1-1];
		len1--;
	}
	for (int i = 0; i < len2; i++)
		string[i]=rev[i];
	return string;
}

void main()
{
	char string[20]={};
	printf("Enter the string:");
	scanf("%s",string);
	printf("The reverse of the string is %s",strrev(string));
}