#include <stdio.h>

void main()
{
	int mat[3][3],tmat[3][3];
	printf("Enter Matrix 1:\n");
	for (int i=0;i<3;i++)
		for (int j=0;j<3;j++)
			scanf("%d",&mat[i][j]);
	for (int i=0;i<3;i++)
		for (int j=0;j<3;j++)
			tmat[j][i]=mat[i][j];
	printf("\n");
	for (int i=0;i<3;i++)
	{
		printf("[\t");
		for (int j=0;j<3;j++)
			printf("%d\t",tmat[i][j]);
		printf("]\n");
	}
}