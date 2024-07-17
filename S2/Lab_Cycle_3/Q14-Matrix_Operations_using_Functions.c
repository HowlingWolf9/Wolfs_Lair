#include <stdio.h>

void mread(int mat[3][3])
{
	printf("Enter Matrix :\n");
	for (int i=0;i<3;i++)
		for (int j=0;j<3;j++)
			scanf("%d",&mat[i][j]);
}

void mprint(int mat[3][3])
{
	printf("\n");
	for (int i=0;i<3;i++)
	{
		printf("[\t");
		for (int j=0;j<3;j++)
			printf("%d\t",mat[i][j]);
		printf("]\n");
	}
}

int msum(int mat1[3][3],int mat2[3][3])
{
	int smat[3][3];
	for (int i=0;i<3;i++)
		for (int j=0;j<3;j++)
			smat[i][j]=mat1[i][j]+mat2[i][j];
	mprint(smat);	
}

int mprod(int mat1[3][3],int mat2[3][3])
{
	int pmat[3][3]={0};
	for (int i=0;i<3;i++)
		for (int j=0;j<3;j++)
			for (int m=0;m<3;m++)
				pmat[i][j]+=mat1[m][j]*mat2[i][m];
	mprint(pmat);
}

int mtrans(int mat[3][3])
{
	int tmat[3][3];
	for (int i=0;i<3;i++)
		for (int j=0;j<3;j++)
			tmat[j][i]=mat[i][j];
	mprint(tmat);
}

void main()
{
	int mat1[3][3],mat2[3][3],option;
	printf("Select Matrix Operation:\n1.Addition\n2.Multiplication\n3.Transpose\n::");
	scanf("%d",&option);
	switch (option)
	{
		case 1:
			mread(mat1);
			mread(mat2);
			msum(mat1,mat2);
			break;
		
		case 2:
			mread(mat1);
			mread(mat2);
			mprod(mat1,mat2);
			break;
		
		case 3:
			mread(mat1);
			mtrans(mat1);
			break;
		
		default:
			printf("Unknown Operation.");
			break;
	}	
}