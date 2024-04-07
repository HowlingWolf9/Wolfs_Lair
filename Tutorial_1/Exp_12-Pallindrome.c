#include <stdio.h>

void main()
{
	int num,rev,temp_num,pal=0;
	printf("Enter the number:");
	scanf("%d",&num);
	temp_num=num;
	while (num>0)
	{
		rev=num%10;
		pal=(pal*10)+rev;
		num=num/10;
	}
	if (pal==temp_num)
	{
		printf("%d is a pallindrome",temp_num);
	}
	else
	{	
		printf("%d is not a pallindrome",temp_num);
	}
}