#include <stdio.h>

int main()
{
	float temp_fahr,temp_cel;
	printf("Enter the temperature in Fahrenheit:");
	scanf("%f",&temp_fahr);
	temp_cel=((temp_fahr-32)*5/9);
	printf("Temperature in Celsius is %.2f",temp_cel);
}