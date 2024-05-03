#include <stdio.h>

void main()
{
	int n;
	float sum=0;
	printf("Enter No.of Elements:");
	scanf("%d",&n);
	int arr[n];
	for (int i=0;i<n;i++)
	{
		printf("Enter Number %d :",i+1);
		scanf("%d",&arr[i]);
	}
	for (int i=0;i<n;i++)
		sum+=arr[i];
	printf("Sum=%f\nAverage=%f",sum,(sum/n));
}
/*Algorithm
Step 1: START
Step 2: Initialize sum=0
Step 3: Take n as input
Step 4: Initialize i=0 and repeat steps 4 to 5, FOR i<n
Step 5: 	Take arr[i] as input
Step 6: 	Increment i by 1
Step 7: Initialize i=0 repeat steps 7 to 9, FOR i<n
Step 8: 	Increment sum by arr[i]
Step 9: 	Increment i by 1
Step 10: Display sum and (sum/n)
Step 11: STOP
*/