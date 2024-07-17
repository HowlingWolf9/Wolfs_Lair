#include <stdio.h>

void main()
{
	int n,num,largest=0,i=1;
	printf("Enter the number of elements:");
	scanf("%d",&n);
	while (n>0)
	{
		printf("Enter number %d :",i);
		scanf("%d",&num);
		if (num>largest)
		{
			largest=num;
		}
		n--;
		i++;
	}
	printf("The greatest number is %d\n",largest);
}