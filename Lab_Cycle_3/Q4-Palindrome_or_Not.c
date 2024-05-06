/*
Experiment: 24
Date: 01/05/2024

AIM: Write a C program to read a string (word), store it in an array and check whether it is a palindrome word or not.

ALGORITHM:
Step 01: START
Step 02: Initialize cmp=0, len=0
Step 03: Take string as input
Step 04: Repeat step 5, WHILE (string[len] != ‘\0’)
Step 05: 	Increment len by 1
Step 06: Initialize i=len and repeat steps 7 to 8, FOR i>0
Step 07: 	Set rev[len-i] = string[i-1]
Step 08: 	Decrement i by 1
Step 09: Initialize i=0 and repeat steps 10 to 14, FOR i<len
Step 10: 	IF (rev[i] != string[i]), then
Step 11: 		Set cmp=1
Step 12: 		Display “NOT Palindrome”
Step 13: 		BREAK the loop and go to step 15
Step 14:	ENDIF
Step 15: IF (cmp==0)
Step 16: 	Display “Is Palindrome”
Step 17: ENDIF
Step 18: STOP
*/
//CODE:
#include <stdio.h>

void main()
{
	char string[20],rev[20];
	int cmp=0,len=0;
	printf("Enter the string:");
	scanf("%s",&string);
	while (string[len] != '\0')
			len++;
	for (int i = len; i > 0; i--)
		rev[len-i]=string[i-1];
	for (int i = 0; i < len; ++i)
		if (rev[i] != string[i])
		{
			cmp=1;
			printf("NOT Palindrome");
			break;
		}
	if (cmp==0)
		printf("Is Palindrome");
}