#include <stdio.h>

void main()
{
	char string[20],copy[20];
	int cmp=0,len1=-1;
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
			len1++;
		}
	}
	while(len1>=0)
	{
		copy[len1]=string[len1];
		len1--;
	}
	printf("The Copy of the string is %s",copy);
}