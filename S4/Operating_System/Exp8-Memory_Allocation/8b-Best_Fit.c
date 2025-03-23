/*
ALGORITHM:
STEP 01: Input memory with size and process with size
STEP 02: Initializee all memory blocks as free
STEP 03: Start by picking each process and find minimum block size that can be assigned to current process, i.e. find min(block_size[i], block_size. If found then assign to the current process
STEP 04: If not found then leave that process and keep checking further processes
STEP 05: STOP
*/
//CODE:
#include <stdio.h>

void main()
{
    int bsize[10], psize[10], bno, pno, flags[10], allocation[10], i, j;
    for(i = 0; i < 10; i++)
    {
        flags[i] = 0;
        allocation[i] = -1;
    }
    printf("Enter the number of blocks: ");
    scanf("%d", &bno);
    printf("Enter the size of each block:\n");
    for(i = 0; i < bno; i++)
        scanf("%d", &bsize[i]);
    printf("Enter the number of processes: ");
    scanf("%d", &pno);
    printf("Enter the size of each process:\n");
    for(i = 0; i < pno; i++)
        scanf("%d", &psize[i]);
    for(i = 0; i < pno; i++)
    {
        int bestIdx = -1;
        int minDiff = 9999;
        for(j = 0; j < bno; j++)
            if(bsize[j] >= psize[i] && bsize[j] - psize[i] < minDiff)
            {
                bestIdx = j;
                minDiff = bsize[j] - psize[i];
            }
            if (bestIdx != -1)
        {
            allocation[i] = bestIdx;
            bsize[bestIdx] -= psize[i];
        }
    }
    printf("Process No.\tProcess Size\tBlock\n");
    for(i = 0; i < pno; i++)
    {
        printf("%d\t\t%d\t\t", i + 1, psize[i]);
        if(allocation[i] != -1)
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
1               15              3
2               59              2
3               17              2
4               59              Not Allocated
5               42              5
*/