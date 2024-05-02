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
		if (elm==arr[i])
		{
			printf("The element is in position %d .\n",i+1);
			pos=i+1;
		}
	if (pos==0)
		printf("The element does not exist.");
}
/* Algorithm
Step1: START
Step2: Initialise pos=0
Step3: Take n as input
Step4: Repeat steps 4 to 5, FOR i=0 when i<n
Step5: 	Take arr[i] as input
Step6: 	Increment i by 1
Step7: Take elm as input 
Step8: Initialise i=0 and repeat steps 8 to 11, FOR i<n
Step9: 	IF (elm==arr[i]), then
Step10: 		Display position
Step11:		Set pos=i+1
Step12:	ENDIF
Step13: IF (pos==0), then
Step14:	Display "The element does not exist"
Step15: STOP
*/