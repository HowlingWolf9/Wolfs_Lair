/*
Experiment: 27
Date:

AIM: Write a C program to read two input each representing the distances between two points in the Euclidean space, store these in structure variables and add the two distance values.

ALGORITHM:
Step 01: START
Step 02: Declare a structure named coords with x and y as variables
Step 03: Declare variables c1 and c2 of type struct coords
Step 04: Take c1.x and c1.y input 
Step 05: Take c2.x and c2.y input
Step 06: Set dist=√(((c2.x-c1.x)^2)+((c2.y-c1.y)^2))
Step 07: Display dist
Step 08: STOP
*/
//CODE:
#include <stdio.h>
#include <math.h>

struct coords
{
	int x,y;
};
		
void main()
{
	struct coords c1,c2;
	printf("Enter the Co-Ordinates of 1st  point (x,y): ");
	scanf("%d%d",&c1.x,&c1.y);
	printf("Enter the Co-Ordinates of 2nd  point (x,y): ");
	scanf("%d%d",&c2.x,&c2.y);
	float dist=(sqrt(pow((c2.x-c1.x),2)+pow((c2.y-c1.y),2)));
	printf("The distance between the points = %.3f",dist);
}
/*
OUTPUT:
Enter the Co-Ordinates of 1st  point (x,y): 4 5
Enter the Co-Ordinates of 2nd  point (x,y): 5 4
The distance between the points = 1.414
*/