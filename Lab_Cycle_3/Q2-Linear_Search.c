/*
Experiment: 22
Date: 01/05/2024

AIM: Write a C program to read n integers, store them in an array and search for an element in the array using an algorithm for Linear Search

ALGORITHM:
Step 01: START
Step 02: Initialize pos=0
Step 03: Take n as input
Step 04: Repeat steps 4 to 5, FOR i=0 when i<n
Step 05: 	Take arr[i] as input
Step 06: 	Increment i by 1
Step 07: Take elm as input 
Step 08: Initialize i=0 and repeat steps 8 to 11, FOR i<n
Step 09: 	IF (elm==arr[i]), then
Step 10: 		Display position
Step 11: 		Set pos=i+1
Step 12: 	ENDIF
Step 13: IF (pos==0), then
Step 14: 	Display "The element does not exist"
Step 15: STOP
*/
//CODE:
#include <stdio.h>

void main()
{
	int n,elm,pos=0;
	printf("Enter No.of Elements:");
	scanf("%d",&n);
	int arr[n];
	for (int i=0;i<n;i++)
	{
		printf("Enter Number %d :",i+1);
		scanf("%d",&arr[i]);
	}
	printf("Enter the element to search for :");
	scanf("%d",&elm);
	for (int i=0;i<n;i++)
		if (elm==arr[i])
		{
			printf("The element is in position %d .\n",i+1);
			pos=i+1;
		}
	if (pos==0)
		printf("The element does not exist.");
}