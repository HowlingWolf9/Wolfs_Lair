#include <stdio.h>
#include <string.h>

void main()
{
	char str1[30],str2[30];
	scanf("%s",str1);
	scanf("%s",str2);
	if (!strcmp(str1,str2))
		printf("Both are Same.");
	else
		printf("Both are Different.");
}