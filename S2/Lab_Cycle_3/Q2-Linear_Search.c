/*
Experiment: 22
Date: 01/05/2024

AIM: Write a C program to read n integers, store them in an array and search for an element in the array using an algorithm for Linear Search

ALGORITHM:
Step 01: START
Step 02: Initialize pos=0
Step 03: Take n as input
Step 04: Initialize i=0 and repeat steps 05 to 06, FOR i<n
Step 05: 	Take arr[i] as input
Step 06: 	Increment i by 1
Step 07: Take elm as input 
Step 08: Initialize i=0 and repeat steps 09 to 12, FOR i<n
Step 09: 	IF (elm==arr[i]), then
Step 10: 		Set pos=i+1
Step 11: 		Display pos
Step 12: 	ENDIF
Step 13: IF (pos==0), then
Step 14: 	Display "The element does not exist"
Step 15: ENDIF
Step 16: STOP
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
			pos=i+1;
			printf("The element is in position %d.\n",pos);
		}
	if (pos==0)
		printf("The element does not exist.");
}
/*
OUTPUT:
Enter No.of Elements:5
Enter Number 1 :1
Enter Number 2 :9
Enter Number 3 :1
Enter Number 4 :7
Enter Number 5 :3
Enter the element to search for :1
The element is in position 1.
The element is in position 3.
*/