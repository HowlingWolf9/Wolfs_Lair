#include <stdio.h>

void main()
{
	int n,elm,pos=0;
	printf("Enter No.of Elements:");
	scanf("%d",&n);
	int arr[n];
	for (int i=0;i<n;i++)
	{
		printf("Enter Number %d :",i+1);
		scanf("%d",&arr[i]);
	}
	printf("Enter the element to search for :");
	scanf("%d",&elm);
	for (int i=0;i<n;i++)
	{
		if (elm==arr[i])
		{
			printf("The element is in position %d .\n",i+1);
			pos=i+1;
		}
	}
	if (pos==0)
		printf("The element does not exist in the given array.");
}
/* Algorithm
Step1: Initialise pos=0
Step2: Take n as input
Step3: Repeat steps to , FOR i=0 when i<n
Step4: 	Take arr[i] as input
Step5: 	Increment i by 1
Step6: Take elm as input 
Step7: 