#include <stdio.h>

void main()
{
	char letter;
	int checker=0,i,vowel_arr[10]={65,69,73,79,85,97,101,105,111,117};
	printf("Enter the character:");
	scanf("%c",&letter);
	if ((letter>64 && letter<91)||(letter>96 && letter<123))
	{
		for (i=0;i<10;i++)
		{
			if (letter==vowel_arr[i])
			{
				checker=1;	
			}

		}
		if (checker==1)
		{
			printf("The letter is a Vowel");
		}
		else
		{
			printf("The letter is a Consonant");
		}	
	}
	else
	{
		printf("Not a letter in the English alphabet");
	}
}