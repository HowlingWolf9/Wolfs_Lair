#include <stdio.h>

union address
{
	char name[30],hname[20],cname[20],state[20],pincode[6],C_SIZE[100];
};

void main()
{
	union address p1;
	printf("Enter Name :");
	scanf("%s",&p1.name);
	printf("Enter House Name :");
	scanf("%s",&p1.hname);
	printf("Enter City Name :");
	scanf("%s",&p1.cname);
	printf("Enter State :");
	scanf("%s",&p1.state);
	printf("Enter Pincode:");
	scanf("%d",&p1.pincode);
	
	printf("Address : %s, %s, %s, %s, %s",p1.name,p1.hname,p1.cname,p1.state,p1.pincode);
}
