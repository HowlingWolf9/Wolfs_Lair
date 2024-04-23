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
		scanf("%s",&e[i].name);
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