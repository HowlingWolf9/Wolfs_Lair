#include <stdio.h>

void main()
{
	char string[20],rev[20];
	int cmp=0,len1=-1,len2;
	printf("Enter the string:");
	scanf("%s",&string);
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
	len2=len1;
	while(len1>=0)
	{
		rev[len2-len1]=string[len1];
		len1--;
	}
	while(len2>=0)
	{
		if (rev[len2]==string[len2])
		{
			cmp=0;
		}
		else
		{
			cmp=1;
			break;
		}
		len2--;;
	}
	if (cmp==0)
	{
		printf("%s is a pallindrome",string);
	}
	else
	{
		printf("%s is not a pallindrome",string);
	}
}