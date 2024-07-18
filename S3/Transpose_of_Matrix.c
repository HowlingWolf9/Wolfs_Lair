/*
AIM: Write a C program to print the sum of diagonal elements of a matrix

ALGORITHM:
Step 01: START
Step 02: Initialize two matrices
Step 03: Input matrix elements of first matrix
Step 04: Assign same elements of first matrix to second matrix by swapping row and column positions respectively
Step 05: Display the second matrix
Step 06: STOP
*/
//CODE:
#include <stdio.h>

void main()
{
	int mat[3][3],tmat[3][3];
	printf("Enter Matrix :\n");
	for (int i=0;i<3;i++)
		for (int j=0;j<3;j++)
			scanf("%d",&mat[i][j]);
	for (int i=0;i<3;i++)
		for (int j=0;j<3;j++)
			tmat[i][j]=mat[j][i];
	printf("\nTranspose:\n");
	for (int i=0;i<3;i++)
	{
		printf("[\t");
		for (int j=0;j<3;j++)
			printf("%d\t",tmat[i][j]);
		printf("]\n");
	}
}
/*
OUTPUT:
Enter Matrix :
1 2 3
4 5 6
7 8 9

Transpose:
[       1       4       7       ]
[       2       5       8       ]
[       3       6       9       ]
*/