#include <stdio.h>

void main()
{
	int num,rev,temp_num,pal=0;
	printf("Enter the number:");
	scanf("%d",&num);
	temp_num=num;
	while (temp_num>0)
	{
		rev=temp_num%10;
		pal=(pal*10)+rev;
		temp_num=temp_num/10;
	}
	if (pal==num)
	{
		printf("It is Palindrome");
	}
	else
	{	
		printf("NOT Palindrome");
	}
}