/*
AIM: Write a C program to print the sum of diagonal elements of a matrix

ALGORITHM:
Step 01: START
Step 02: Initialize 3 matrices
Step 03: Input matrix elements to first two matrices
Step 04: Calculate the sum of respective elements of first two matrices and assign them to the thirds matrice in the respective positions
Step 05: Display the third array
Step 06: STOP
*/
//CODE:
#include <stdio.h>

void main()
{
	int mat1[3][3],mat2[3][3],smat[3][3];
	printf("Enter Matrix 1:\n");
	for (int i=0;i<3;i++)
		for (int j=0;j<3;j++)
			scanf("%d",&mat1[i][j]);
	printf("Enter Matrix 2:\n");
	for (int i=0;i<3;i++)
		for (int j=0;j<3;j++)
			scanf("%d",&mat2[i][j]);
	for (int i=0;i<3;i++)
		for (int j=0;j<3;j++)
			smat[i][j]=mat1[i][j]+mat2[i][j];
	printf("\nSum of Matrices:\n");
	for (int i=0;i<3;i++)
	{
		printf("[\t");
		for (int j=0;j<3;j++)
			printf("%d\t",smat[i][j]);
		printf("]\n");
	}
}
/*
OUTPUT:
Enter Matrix 1:
1 2 3
4 5 6
7 8 9
Enter Matrix 2:
9 8 7
6 5 4
3 2 1

Sum of Matrices:
[       10      10      10      ]
[       10      10      10      ]
[       10      10      10      ]
*/