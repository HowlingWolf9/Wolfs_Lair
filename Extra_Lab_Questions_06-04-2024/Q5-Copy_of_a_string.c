#include <stdio.h>

void main()
{
	char string[20],copy[20];
	int i,len=0;
	printf("Enter the string:");
	scanf("%s",string);
	for (i=0;i<20;i++)
		if (string[i]=='\0')
			break;
		else
			len++;
	for (i=0;i<len;i++)
		copy[i]=string[i];
	printf("The Copy of the string is %s",copy);
}