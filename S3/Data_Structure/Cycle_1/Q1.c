#include <stdio.h>
#define SIZE 5
int arr[SIZE];

int linear_search()
{
    int key=0,elm;
    printf("Enter the element to search for:");
    scanf("%d",&elm);
    for (int i = 0; i < SIZE; i++)
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
    printf("Enter the %d elements in the array:",SIZE);
    for (int i = 0; i < SIZE; i++)
        scanf("%d",&arr[i]);
    linear_search();
}
