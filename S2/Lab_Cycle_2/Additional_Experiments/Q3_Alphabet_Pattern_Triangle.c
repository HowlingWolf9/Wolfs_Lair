#include <stdio.h>

void main()
{
	int n;
	printf("Enter the No.of Lines to be printed:");
	scanf("%d",&n);
	for (int i=0;i< n;i++)
	{
		for (int j=0;j<=i;j++)
			printf("%c ",'A'+j);
		printf("\n");
	}
}