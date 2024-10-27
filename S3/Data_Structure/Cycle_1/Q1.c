/*
Experiment: 1

AIM: Write a program to perform Linear search on n numbers. Write Linear Search as a function and call it from the function main() by passing the appropriate parameters. 

ALGORITHM: main()
Step 01: START
Step 02: Read the elements into the array, arr[]
Step 03: Call the linearSearch() function
Step 04: END

ALGORITHM: linearSearch()
Step 01: START
Step 02: Initialize the key variable to 0
Step 03: Read the element to be searched, elm
Step 04: Initialize i = 0 and repeat steps 05 to 09 until i < SIZE
Step 05:     IF arr[i] == elm
Step 06:         Print the position of the element
Step 07:         Set key = 1
Step 08:     ENDIF
Step 09:     Increment i by 1
Step 10: IF key == 0
Step 11:     Print the message "Element does not exist"
Step 12: ENDIF
Step 13: STOP
*/
//CODE:
#include <stdio.h>
#define SIZE 5
int arr[SIZE];

int linearSearch()
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
    linearSearch();
}

/*
OUTPUT:
Enter the 5 elements in the array: 1 2 3 4 5
Enter the element to search for: 3
Element is at position 3
*/