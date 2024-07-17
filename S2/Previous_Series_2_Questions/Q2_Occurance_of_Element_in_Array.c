#include<stdio.h>

void main()
{
    int count = 0, a;
    int arr[] = {3, 2, 4, 1, 5, 3, 2, 4, 1, 5};
    printf("Enter a number: ");
    scanf("%d", &a);
    for(int i = 0; i < 10; i++)
    {
        if(arr[i] == a)
        {
            count++;
        }
    }
    printf("%d occurs %d times",a,count);
}
