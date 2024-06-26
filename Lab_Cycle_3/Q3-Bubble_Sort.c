/*
Experiment: 23
Date: 01/05/2024

AIM: Write a C program to read n integers, store them in an array and sort the elements in the array using Bubble Sort

ALGORITHM:
Step 01: START
Step 02: Take n as input
Step 03: Initialize i=0 and repeat steps 04 to 05, FOR i<n
Step 04: 	Take arr[i] as input
Step 05: 	Increment i by 1
Step 06: Initialize i=n-1 and repeat steps 07 to 14, FOR i>0
Step 07: 	Initialize j=0 and repeat steps 08 to 13, FOR j<i
Step 08: 		IF (arr[j]>arr[j+1]), then
Step 09: 			Set temp=arr[j]
Step 10: 			Set arr[j]=arr[j+1]
Step 11: 			Set arr[j+1]=temp
Step 12: 		ENDIF
Step 13: 		Increment j by 1
Step 14: 	Decrement i by 1
Step 15: Display "Sorted Array:"
Step 16: Initialize i=0 and repeat steps 17 to 18, FOR i<n
Step 17: 	Display arr[i]
Step 18: 	Increment i by 1
Step 19: STOP
*/
//CODE:
#include <stdio.h>

void main()
{
	int n,temp;
	printf("Enter No.of Elements:");
	scanf("%d",&n);
	int arr[n];
	for (int i=0;i<n;i++)
	{
		printf("Enter Number %d :",i+1);
		scanf("%d",&arr[i]);
	}
	for (int i=n-1;i>0;i--)
		for(int j=0;j<i;j++)
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}	
	printf("\nSorted Array: ");
	for (int i=0;i<n;i++)
		printf("%d ",arr[i]);
}
/*
OUTPUT:
Enter No.of Elements:5
Enter Number 1 :1
Enter Number 2 :8
Enter Number 3 :5
Enter Number 4 :4
Enter Number 5 :2

Sorted Array: 1 2 4 5 8
*/