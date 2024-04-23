#include <stdio.h>
#include <math.h>

struct coords
	{
		int x,y;
	};
		
void main()
{
	struct coords c1,c2;
	printf("Enter the Co-Ordinates of 1st (x,y) point :");
	scanf("%d%d",&c1.x,&c1.y);
	printf("Enter the Co-Ordinates of 2nd (x,y) point :");
	scanf("%d%d",&c2.x,&c2.y);
	float dist=(sqrt(pow((c2.x-c1.x),2)+pow((c2.y-c1.y),2)));
	printf("The distance between the points = %.3f",dist);
}