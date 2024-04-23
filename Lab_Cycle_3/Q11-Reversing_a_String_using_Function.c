#include <stdio.h>

char *strrev(char *string)
{
	char rev[20];
	int len1=-1,len2;
	for (int i=0;i<20;i++)
	{
		if (string[i]=='\0')
		{
			break;
		}
		else
			len1++;
	}
	len2=len1;
	while(len1>=0)
	{
		rev[len2-len1]=string[len1];
		len1--;
	}
	string=rev;
	return string;
}

void main()
{
	char string[20];
	int len1=-1,len2;
	printf("Enter the string:");
	scanf("%s",string);
	printf("The reverse of the string is %s",strrev(string));
}