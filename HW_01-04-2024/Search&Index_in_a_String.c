#include <stdio.h>

int index(char *string,char letter)
{
	int len=0,ind=-1,i=0;
	while (string[len]!=NULL)
	{
		len++;
	}
	len--;
	while (i<=len)
	{
		if (string[i]==letter)
		{
			printf("%c At %d\n",letter,i+1);
		}
		i++;
	}
}
void main()
{
	char string[30],letter;
	printf("Enter the string:");
	scanf("%[^\n]s",&string);
	printf("Enter the letter:");
	scanf(" %c",&letter);
	index(string,letter);
}