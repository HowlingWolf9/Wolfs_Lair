#include <stdio.h>

void main()
{
	char string[20],copy[20],rev[20];
	int i,cmp=0,len=0;
	printf("Enter the string:");
	scanf("%s",string);
	for (i=0;i<20;i++)
		if (string[i]=='\0')
			break;
		else
			len++;
	for (i=0;i<len;i++)
		copy[i]=string[i];
	for (i=0;i<len;i++)
		rev[i]=string[(len-1)-i];
	for (i=0;i<len;i++)
	{
		if (rev[i]==string[i])
			cmp=0;
		else
		{
			cmp=1;
			break;
		}
	}
	if (cmp==0)
		printf("%s is a pallindrome",string);
	else
		printf("%s is not a pallindrome",string);
}