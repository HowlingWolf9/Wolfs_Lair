/*
ALGORITHM:
STEP 01: START
STEP 02: Input memory block with size and process with size
STEP 03: Initialize all memory blocks as free
STEP 04: Start by picking each process and find maximum block size that can be assigned to current process
STEP 05: STOP
*/
//CODE:
#include <stdio.h>

void main()
{
    int bsize[10], psize[10], bno, pno, flags[10], allocation[10], i, j;
    for (i = 0; i < 10; i++)
    {
        flags[i] = 0;
        allocation[i] = -1;
    }
    printf("Enter the number of blocks: ");
    scanf("%d", &bno);
    printf("Enter the size of each block:\n");
    for (i = 0; i < bno; i++)
        scanf("%d", &bsize[i]);
    printf("Enter the number of processes: ");
    scanf("%d", &pno);
    printf("Enter the size of each process:\n");
    for (i = 0; i < pno; i++)
        scanf("%d", &psize[i]);
    for (i = 0; i < pno; i++)
    {
        int worstIdx = -1;
        int maxDiff = -1;
        for (j = 0; j < bno; j++)
            if (bsize[j] >= psize[i] && bsize[j] - psize[i] > maxDiff)
            {
                worstIdx = j;
                maxDiff = bsize[j] - psize[i];
            }
        if (worstIdx != -1)
        {
            allocation[i] = worstIdx;
            bsize[worstIdx] -= psize[i];
        }
    }
    printf("Process No.\tProcess Size\tBlock\n");
    for (i = 0; i < pno; i++)
    {
        printf("%d\t\t%d\t\t", i + 1, psize[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}
/*
OUTPUT:
Enter the number of blocks: 5
Enter the size of each block:
12
78
46
13
49
Enter the number of processes: 5
Enter the size of each process:
15
59
17
59
42
Process No.     Process Size    Block
1               15              2
2               59              2
3               17              5
4               59              Not Allocated
5               42              3
*/