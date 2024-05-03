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
Step 1: START
Step 2: Take n as input
Step 3: Initialise i=0 and repeat steps 4 to 5, FOR i<n
Step 4:	Take arr[i] as input
Step 5:	Increment i by 1
Step 6: Initialise i=n-1 and repeat steps 7 to 14, FOR i>0
Step 7:	Initialise j=0 and repeat steps 8 to 13, FOR j<i
Step 8:		IF (arr[j]>arr[j+1]), then
Step 9:			Set temp=arr[j]
Step 10:			Set arr[j]=arr[j+1]
Step 11:			Set arr[j+1]=temp
Step 12:		ENDIF
Step 13:		Increment j by 1
Step 14:	Decrement i by 1
Step 15: Display "Sorted Array:"
Step 16: Initialise i=0 and repeat steps 17 to 18, FOR i<n
Step 17:	Display arr[i]
Step 18:	Increment i by 1
Step 19: STOP
*/