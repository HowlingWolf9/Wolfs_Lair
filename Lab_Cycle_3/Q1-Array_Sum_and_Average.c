#include <stdio.h>

void main()
{
	int n;
	float sum;
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
Step1: START
Step2: Take n as input
Step3: Repeat steps 4 to 5 ,FOR i=0 when i<n
Step4: 	Take arr[i] as input
Step5: 	Increment i by 1
Step6: Repeat steps 7 to 9 ,FOR i=0 when i<n
Step7: 	Increment sum by arr[i]
Step8: 	Increment i by 1
Step9: Display sum and (sum/n)
Step10: STOP
*/