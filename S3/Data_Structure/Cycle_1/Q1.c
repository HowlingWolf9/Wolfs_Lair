#include <stdio.h>
int linear_search(int *arr, int n)
{
    int key=0,elm;
    printf("Enter the element to search for:");
    scanf("%d",&elm);
    for (int i = 0; i < n; i++)
        if (arr[i]==elm)
        {
            printf("Element is at position %d\n",i+1);
            key=1;
        }
    if (key==0)
        printf("Element does not exist");
}
void main()
{
    int n;
    printf("Enter the No.of Elements:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the %d elements in the array:");
    for (int i = 0; i < n; i++)
        scanf("%d",&arr[i]);
    linear_search(arr, n);
}