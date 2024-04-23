#include <stdio.h>

void main()
{
	int large,arr[10]={1,2,7,9,25,3,26,49,69,14};
	large=arr[0];
	for (int i=0;i<10;i++)
		if (large<arr[i])
			large=arr[i];
	printf("The largest number is %d",large);
}