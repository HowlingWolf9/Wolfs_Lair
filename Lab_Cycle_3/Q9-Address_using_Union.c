/*
Experiment: 29

AIM: Write a C program, and declare a union containing 5 string variables (Name, House Name, City Name, State and Pincode) each with a length of C_SIZE (user defined constant). Then, read and display the address of a person using a variable of the union.

ALGORITHM:
Step 01: START
Step 02: Define C_SIZE as 50
Step 03: Declare a union named address with name, house, city, state and pin as variables
Step 04: Declare variable p1 of type union address 
Step 05: Take p1.name as input
Step 06: Display p1.name
Step 07: Take p1.house as input
Step 08: Display p1.house
Step 09: Take p1.city as input
Step 10: Display p1.city
Step 11: Take p1.state as input
Step 12: Display p1.state
Step 13: Take p1.pin as input
Step 14: Display p1.pin
Step 15: STOP
*/
//CODE:
#include <stdio.h>
#include <string.h>

#define C_SIZE 50

union address
{
	char name[C_SIZE],house[C_SIZE],city[C_SIZE],state[C_SIZE];
	int pin;
};

void main()
{
	union address p1;
	char addr[100];
	printf("Enter Name: ");
	scanf("%s",p1.name);
	printf("Name: %s\n",p1.name);
	printf("Enter House Name: ");
	scanf("%s",p1.house);
	printf("House Name: %s\n",p1.house);
	printf("Enter City Name: ");
	scanf("%s",p1.city);
	printf("City: %s\n",p1.city);
	printf("Enter State: ");
	scanf("%s",p1.state);
	printf("State: %s\n",p1.state);
	printf("Enter Pincode: ");
	scanf("%d",&p1.pin);
	printf("Pincode: %d\n",p1.pin);
}