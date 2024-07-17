/*
AIM: Write a C program, and using structure, read and print data of n students (Name,Roll No. and Marks)

ALGORITHM:
Step 01: START
Step 02: Declare a structure named student with rollno, marks and name as variables
Step 03: Take n as input
Step 04: Declare variables s[n] of type struct student 
Step 05: Initialize i=0 and repeat steps 06 to 07, FOR i<n
Step 06: 	Take s[i].name, s[i].rollno and s[i].marks as input
Step 07: 	Increment i by 1
Step 08: Initialize i=0 and repeat steps 09 to 10, FOR i<n
Step 09: 	Display s[i].name, s[i].rollno and s[i].marks
Step 10: 	Increment i by 1
Step 11: STOP
*/
//CODE:
#include <stdio.h>

struct student
{
	int marks,rollno;
	char name[30];
};

void main()
{
	int n;
	printf("Enter No.of Students: ");
	scanf("%d",&n);
	struct student s[n];
	for (int i=0;i<n;i++)
	{
		printf("\nStudent No.%d\n---------------\n",i+1);
		printf("Enter Name: ");
		scanf("%s",s[i].name);
		printf("Enter Roll No.: ");
		scanf("%d",&s[i].rollno);
		printf("Enter Marks: ");
		scanf("%d",&s[i].marks);
	}
	printf("\nNo.\tName\tNo.\tMarks\n---\t----\t--\t------\n");
	for (int i=0;i<n;i++)
		printf("%d\t%s\t%d\t%d\n",i+1,s[i].name,s[i].rollno,s[i].marks);
}
/*
OUTPUT:
Enter No.of Students: 3

Student No.1
---------------
Enter Name: Philip
Enter Roll No.: 1
Enter Marks: 56

Student No.2
---------------
Enter Name: Suresh
Enter Roll No.: 2
Enter Marks: 91

Student No.3
---------------
Enter Name: Mathayi
Enter Roll No.: 3
Enter Marks: 86

No.     Name    No.     Marks
---     ----    --      ------
1       Philip  1       56
2       Suresh  2       91
3       Mathayi 3       86
*/