#include <stdio.h>

void main()
{
	char string1[20],string2[20];
	int cmp=0,len=-1;
	printf("Enter the first string:");
	scanf("%s",&string1);
	printf("Enter the second string:");
	scanf("%s",&string2);
	for (int i=0;i<20;i++)
	{
		if (string1[i]==NULL)
		{
			break;
		}
		else
		{
			len++;
		}
	}
	while(len>=0)
	{
		if (string1[len]==string2[len])
		{
			cmp=0;
		}
		else
		{
			cmp=1;
			break;
		}
		len--;
	}
	if (cmp==0)
	{
		printf("They are equal");
	}
	else
	{
		printf("They are different");
	}
}