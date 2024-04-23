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
	printf("Sum of diagonal elements = %d",sum);
}