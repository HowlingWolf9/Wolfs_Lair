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
Step1: Initialise pos=0
Step2: Take n as input
Step3: Repeat steps 4 to 5, FOR i=0 when i<n
Step4: 	Take arr[i] as input
Step5: 	Increment i by 1
Step6: Take elm as input 
Step7: Initialise i=0 and repeat steps 8 to 11, FOR i<n
Step8: 	IF (elm==arr[i]), then
Step9: 		Display position
Step10:		Set pos=i+1
Step11:	ENDIF
Step12: IF (pos==0), then
Step13:	Display "The element does not exist"
Step14: STOP
*/