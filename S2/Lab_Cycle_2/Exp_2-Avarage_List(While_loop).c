#include <stdio.h>

void main()
{
	int n=0,num;
	float sum=0;
	printf("Enter numbers:\n");
	while (1)
	{
		scanf("%d",&num);
		if (num==0)
			break;
		else
		{
			sum=sum+num;
			n++;
		}
	}
	printf("Average = %f\n",(sum/n));
}