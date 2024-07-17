#include <stdio.h>

void main()
{
	char string1[50],string2[50],combined[100]={};
	int i,n,len1=0,len2=0,clen;
	printf("Enter the first string:");
	scanf("%s",&string1);
	printf("Enter the second string:");
	scanf("%s",&string2);
	for (i=0;i<20;i++)
		if (string1[i]=='\0')
			break;
		else
			len1++;
	for (i=0;i<20;i++)
		if (string2[i]=='\0')
			break;
		else
			len2++;
	clen=len1+len2;
	for (i=0;i<len1;i++)
		combined[i]=string1[i];
	for (i,n=0;i<clen;i++,n++)
		combined[i]=string2[n];
	printf("%s",combined);
}