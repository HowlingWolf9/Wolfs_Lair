#include <stdio.h>

void main()
{
	char string[20],rev[20];
	int cmp=0,len=0;
	printf("Enter the string:");
	scanf("%s",string);
	for (int i=0;i<20;i++)
	{
		if (string[i]==NULL)
		{
			break;
		}
		else
		{
			len++;
		}
	}
	printf("The length of the string is %d",len);
}