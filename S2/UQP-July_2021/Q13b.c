#include <stdio.h>

void main() 
{
    int n, searchNum, i, found = 0;
    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);
	int numbers[n];
    printf("Enter %d elements:\n",n);
    for (i = 0; i < n; i++)
        scanf("%d", &numbers[i]);
    printf("Enter the number to search: ");
    scanf("%d", &searchNum);
    for (i = 0; i < n; i++) 
        if (numbers[i] == searchNum)
		{
            printf("%d is present at index %d.\n", searchNum, i);
            found = 1;
            break;
        }
    if (!found) 
	{
        printf("%d is not present in the list. Inserting at the end.\n", searchNum);
        numbers[n] = searchNum;
        n++;
    }
    printf("Updated list:\n");
    for (i = 0; i < n; i++)
        printf("%d ", numbers[i]);
    printf("\n");
}