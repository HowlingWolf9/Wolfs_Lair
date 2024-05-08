/*
Experiment: 21
Date: 16/04/2024

AIM: Write a C program to read n integers, store them in an array and find their sum and average.

ALGORITHM:
Step 01: START
Step 02: Initialize sum=0
Step 03: Take n as input
Step 04: Initialize i=0 and repeat steps 4 to 5, FOR i<n
Step 05: 	Take arr[i] as input
Step 06: 	Increment i by 1
Step 07: Initialize i=0 repeat steps 7 to 9, FOR i<n
Step 08: 	Increment sum by arr[i]
Step 09: 	Increment i by 1
Step 10: Display sum and (sum/n)
Step 11: STOP
*/
//CODE:
#include <stdio.h>

void main()
{
	int n;
	float sum=0;
	printf("Enter No.of Elements:");
	scanf("%d",&n);
	int arr[n];
	for (int i=0;i<n;i++)
	{
		printf("Enter Number %d :",i+1);
		scanf("%d",&arr[i]);
	}
	for (int i=0;i<n;i++)
		sum+=arr[i];
	printf("Sum=%f\nAverage=%f",sum,(sum/n));
}
/*
OUTPUT:
Enter No.of Elements:5
Enter Number 1 :1
Enter Number 2 :8
Enter Number 3 :3
Enter Number 4 :4
Enter Number 5 :6
Sum=22.000000
Average=4.400000
*/