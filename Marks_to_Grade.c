#include <stdio.h>

void main()
{
	int marks;
	char name[20],grade;
	printf("Enter your name:");
	scanf("%s",&name);
	printf("Enter your marks:");
	scanf("%d",&marks);
	if(marks<=100 && marks>=85)
	{
		grade='S';
	}
	else if(marks<=84 && marks>=75)
	{
		grade='A';
	}
	else if(marks<=74 && marks>=65)
	{
		grade='B';
	}
	else if(marks<=64 && marks>=55)
	{
		grade='C';
	}
	else if(marks<=55 && marks>=45)
	{
		grade='P';
	}
	else
	{
		grade='F';
	}
	printf("Name\tMarks\tGrade\n");
	printf("----\t-----\t-----\n");
	printf("%s\t%d\t%c",name,marks,grade);
}