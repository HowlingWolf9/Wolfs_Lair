#include <stdio.h>

void main()
{
	int vowel=0,cons=0,len=20,vowel_arr[10]={'A','E','I','O','U','a','e','i','o','u'},check=0;
	char word[20];
	printf("Enter the word:");
	scanf("%s",&word);
	while(len>=0)
	{
		if ((word[len]>='A' && word[len]<='Z')||(word[len]>='a' && word[len]<='z'))
		{
			for (int i=0;i<10;i++)
				if (word[len]==vowel_arr[i])
				{
					check=1;
					break;	
				}
			if (check==1)
			{
				vowel++;
				check=0;
			}
			else
				cons++;
		}
		len--;
	}
	printf("The word contains %d vowels and %d consonants",vowel,cons);
}