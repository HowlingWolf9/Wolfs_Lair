#include <stdio.h>

void main()
{
	char string[20],copy[20];
	int i,cmp=0,len=0,check=0,vowel=0,cons=0,space=0,vowel_arr[10]={'A','E','I','O','U','a','e','i','o','u'};
	printf("Enter the string:");
	scanf("%[^\n]s",string);
	for (i=0;i<20;i++)
		if (string[i]=='$')
			break;
		else
			len++;
	for (i=0;i<len;i++)
		copy[i]=string[i];
	while(len>=0)
	{
		if ((copy[len]>='A' && copy[len]<='Z')||(copy[len]>='a' && copy[len]<='z'))
		{
			for (int i=0;i<10;i++)
				if (copy[len]==vowel_arr[i])
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
		else if(copy[len]==' ')
		    space++;  
		len--;
	}
	printf("The word contains %d vowels, %d consonants and %d spaces ",vowel,cons,space);
}
