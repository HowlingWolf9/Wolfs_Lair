#include <stdio.h>

struct employee
{
	int id,salary;
	char name[30];
};

void main()
{
	int n;
	printf("Enter No.of Employees :");
	scanf("%d",&n);
	struct employee e[n];
	for (int i=0;i<n;i++)
	{
		printf("\nEmployee No.%d\n---------------\n",i+1);
		printf("Enter Name :");
		scanf("%s",e[i].name);
		printf("Enter Id :");
		scanf("%d",&e[i].id);
		printf("Enter Salary :");
		scanf("%d",&e[i].salary);
	}
	printf("\nNo.\tName\tId\tSalary\n---\t----\t--\t------\n");
	for (int i=0;i<n;i++)
	{
		printf("%d\t%s\t%d\t%d\n",i+1,e[i].name,e[i].id,e[i].salary);
	}
}
/*Algorithm
Step 01: START
Step 02: Declare a structure named employee with id, salary and name as variables
Step 03: Take n as input
Step 04: Declare variables e[n] of type struct employee 
Step 05: Initialize i=0 and repeat steps 6 to 7, FOR i<n
Step 06: 	Take e[i].name, e[i].id and e[i].salary as input
Step 07: 	Increment i by 1
Step 08: Initialize i=0 and repeat steps 6 to 7, FOR i<n
Step 09: 	Display e[i].name, e[i].id and e[i].salary
Step 10:	Increment i by 1
Step 11: STOP
*/