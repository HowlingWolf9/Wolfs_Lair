#include <stdio.h>

void main()
{
	int n,temp;
	printf("Enter No.of Elements:");
	scanf("%d",&n);
	int arr[n];
	for (int i=0;i<n;i++)
	{
		printf("Enter Number %d :",i+1);
		scanf("%d",&arr[i]);
	}
	for (int i=n-1;i>0;i--)
		for(int j=0;j<i;j++)
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}	
	printf("\nSorted Array: ");
	for (int i=0;i<n;i++)
		printf("%d ",arr[i]);
}
/*Algorithm
Step1: START
Step2: Take n as input
Step3: Initialise i=0 and repeat steps 4 to 5, FOR i<n
Step4:	Take arr[i] as input
Step5:	Increment i by 1
Step6: Initialise i=n-1 and repeat steps to , FOR i>0
Step7:	Initialise j=0 and repeat steps to , FOR j<i
Step8:		IF (arr[j]>arr[j+1]), then
Step9:			Set temp=arr[j]
Step10:			Set arr[j]=arr[j+1]
Step11:			Set arr[j+1]=temp
Step12:		ENDIF
Step13:		Increment j by 1
Step14:	Decrement i by 1
Step15: Display "Sorted Array:"
Step16: Initialise i=0 and repeat steps 17 to 18, FOR i<n
Step17:	Display arr[i]
Step18:	Increment i by 1
Step19: STOP
*/