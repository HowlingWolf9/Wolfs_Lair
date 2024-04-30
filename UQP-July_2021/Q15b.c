#include <stdio.h>
void main()
{
	char string[20],rev[20];
	int len1=0,len2;
	printf("Enter the string:");
	scanf("%s",string);
	while (string[len1]!='\0')
		len1++;
	len2=len1;
	while(len1>=0)
	{
		rev[len2-len1]=string[len1-1];
		len1--;
	}
	printf("The reverse of the string is %s",rev);
}
