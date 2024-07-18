/*
AIM: Write a C program to print the sum of diagonal elements of a matrix

ALGORITHM:
Step 01: START
Step 02: Initialize a matrix and a variable with value 0
Step 03: Input matrix elements
Step 04: Calculate the sum of diagonal elements by incrementing the value of variable by same row and column element
Step 05: Display the variable
Step 06: STOP
*/
//CODE:
#include <stdio.h>

void main()
{
	int mat[3][3],sum=0;
	printf("Enter Matrix :\n");
	for (int i=0;i<3;i++)
		for (int j=0;j<3;j++)
			scanf("%d",&mat[i][j]);
	for (int i=0;i<3;i++)
		sum+=mat[i][i];
	printf("\nSum=%d",sum);
}
/*
OUTPUT:
Enter Matrix :
1 2 3
4 5 6
7 8 9

Sum=15
*/