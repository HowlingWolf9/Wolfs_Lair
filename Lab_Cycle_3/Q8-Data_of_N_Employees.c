/*
Experiment: 28
Date: 

AIM: Write a C program, and using structure, read and print data of n employees (Name, Employee Id and Salary)

ALGORITHM:
Step 01: START
Step 02: Declare a structure named employee with id, salary and name as variables
Step 03: Take n as input
Step 04: Declare variables e[n] of type struct employee 
Step 05: Initialize i=0 and repeat steps 6 to 7, FOR i<n
Step 06: 	Take e[i].name, e[i].id and e[i].salary as input
Step 07: 	Increment i by 1
Step 08: Initialize i=0 and repeat steps 6 to 7, FOR i<n
Step 09: 	Display e[i].name, e[i].id and e[i].salary
Step 10: 	Increment i by 1
Step 11: STOP
*/
//CODE:
#include <stdio.h>

struct employee
{
	int id,salary;
	char name[30];
};

void main()
{
	int n;
	printf("Enter No.of Employees: ");
	scanf("%d",&n);
	struct employee e[n];
	for (int i=0;i<n;i++)
	{
		printf("\nEmployee No.%d\n---------------\n",i+1);
		printf("Enter Name: ");
		scanf("%s",e[i].name);
		printf("Enter Id: ");
		scanf("%d",&e[i].id);
		printf("Enter Salary: ");
		scanf("%d",&e[i].salary);
	}
	printf("\nNo.\tName\tId\tSalary\n---\t----\t--\t------\n");
	for (int i=0;i<n;i++)
	{
		printf("%d\t%s\t%d\t%d\n",i+1,e[i].name,e[i].id,e[i].salary);
	}
}
/*
Enter No.of Employees :3

Employee No.1
---------------
Enter Name: Philip
Enter Id: 161189
Enter Salary: 60000

Employee No.2
---------------
Enter Name: Suresh
Enter Id: 166969
Enter Salary: 100000

Employee No.3
---------------
Enter Name: Mathayi
Enter Id: 161149
Enter Salary: 75000

No.     Name    Id      Salary
---     ----    --      ------
1       Philip  161189  60000
2       Suresh  166969  100000
3       Mathayi 161149  75000
*/