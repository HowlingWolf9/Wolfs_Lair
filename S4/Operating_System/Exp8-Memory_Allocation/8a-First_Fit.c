/*
ALGORITHM:
STEP 01: Start
STEP 02: At first get the number of references and blocks
STEP 03: Allocate the process by if (size of block >= size of process) then allocate the process else move to the next block
STEP 04: Now display the process with the blocks and allocate to respective process
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
        for (j = 0; j < bno; j++)
            if (bsize[j] >= psize[i])
            {
                allocation[i] = j;
                bsize[j] -= psize[i];
                break;
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
3               17              3
4               59              Not Allocated
5               42              5
*/