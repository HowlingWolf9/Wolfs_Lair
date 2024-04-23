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
	printf("\n");
	for (int i=0;i<3;i++)
	{
		printf("[\t");
		for (int j=0;j<3;j++)
			printf("%d\t",smat[i][j]);
		printf("]\n");
	}
}