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
Step1: START
Step2: initialise sum=0
Step3: Take n as input
Step4: Repeat steps 4 to 5 ,FOR i=0 when i<n
Step5: 	Take arr[i] as input
Step6: 	Increment i by 1
Step7: Repeat steps 7 to 9 ,FOR i=0 when i<n
Step8: 	Increment sum by arr[i]
Step9: 	Increment i by 1
Step10: Display sum and (sum/n)
Step11: STOP
*/