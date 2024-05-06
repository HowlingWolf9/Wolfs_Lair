/*
Experiment: 25
Date:

AIM: Write a C program to read two strings (each one ending with a $ symbol), store them in arrays and concatenate them without using library functions.

ALGORITHM:
Step 01: START
Step 02: Initialize len1=0, len2=0
Step 03: Take str1 and str2 as input
Step 04: Repeat step 5, WHILE (str1[len1] != ‘$’)
Step 05: 	Increment len1 by 1
Step 06: Repeat step 7, WHILE (str2[len2] != ‘$’)
Step 07: 	Increment len2 by 1
Step 08: Set clen=len1+len2
Step 09: Initialize i=0 and repeat steps 10 to 11, FOR i<len1
Step 10: 	Set combined[i]=str1[i]
Step 11: 	Increment i by 1
Step 12: Initialize n=0 and repeat steps 10 to 11, FOR i<clen
Step 13: 	Set combined[i]=str2[n]
Step 14: 	Increment i and n by 1
Step 15: Display combined
Step 16: STOP
*/
//CODE:
#include <stdio.h>

void main()
{
	char str1[50],str2[50],combined[100]={};
	int i,n,len1=0,len2=0,clen;
	printf("Enter the first string:");
	scanf("%s",str1);
	printf("Enter the second string:");
	scanf("%s",str2);
	while(str1[len1]!='$')
		len1++;
	while(str2[len2]!='$')
		len2++;
	clen=len1+len2;
	for (i=0;i<len1;i++)
		combined[i]=str1[i];
	for (n=0;i<clen;i++,n++)
		combined[i]=str2[n];
	printf("%s",combined);
}