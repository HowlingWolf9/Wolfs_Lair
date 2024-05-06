/*
Experiment: 26
Date:

AIM: Write a C program to read a string (ending with a $ symbol), store it in an array and count the number of vowels, consonants and spaces in it.

ALGORITHM:
Step 01: START
Step 02: Initialize vowel_arr[10]="AEIOUaeiou", cmp=0, len=0, check=0,vowel=0,cons=0,space=0
Step 03: Take str as input
Step 04: Repeat step 5, WHILE (str[len] != ‘$’)
Step 05: 	Increment len by 1
Step 06: Initialize i=0 and repeat steps 7 to 8, FOR i<len
Step 07: 	Set copy[i]=str[i]
Step 08: 	Increment i by 1
Step 09: Repeat steps 10 to 26, WHILE (len>0)
Step 10: 	IF ((copy[len]>='A' && copy[len]<='Z')||(copy[len]>='a' && copy[len]<='z')), then
Step 11: 		Initialize i=0 and repeat steps 12 to 16, FOR i<10
Step 12: 			IF (copy[len]==vowel_arr[i]), then
Step 13: 				Set check=1
Step 14: 				BREAK the loop and go to step
Step 15: 			ENDIF
Step 16: 			Increment i by 1
Step 17: 		IF (check==1), then
Step 18: 			Increment vowel by 1
Step 19: 			Set check=0
Step 20: 		ELSE
Step 21: 			Increment cons by 1
Step 22: 		ENDIF
Step 23: 	ELSE IF (copy[len]==' ')
Step 24: 		Increment space by 1
Step 25: 	ENDIF
Step 26: 	Decrement len by 1
Step 27: Display vowels,cons and space
Step 28: STOP
*/
//CODE:
#include <stdio.h>

void main()
{
	char str[20],copy[20],vowel_arr[10]="AEIOUaeiou";
	int cmp=0,len=0,check=0,vowel=0,cons=0,space=0;
	printf("Enter the string:");
	scanf("%[^\n]s",str);
	while (str[len]!='$')
		len++;
	for (int i=0;i<len;i++)
		copy[i]=str[i];
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