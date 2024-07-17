#include <stdio.h>

int main()
{
	float p_amnt,roi,numyear,end_amount;
	printf("Enter the intial deposit amount:");
	scanf("%f",&p_amnt);
	printf("Enter the rate of intrest:");
	scanf("%f",&roi);
	printf("Enter the number of years of deposit:");
	scanf("%f",&numyear);
	end_amount=(p_amnt*(1+((roi/100)*numyear)));
	printf("The end amount is = %.2f",end_amount);
}