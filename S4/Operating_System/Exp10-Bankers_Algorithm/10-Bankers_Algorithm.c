/*
ALGORITHM:
STEP 01: START
STEP 02: Input the number of processes and resources
STEP 03: Input the allocation matrix, max matrix, and available resources
STEP 04: Calculate the need matrix
STEP 05: Initialize the work vector with available resources
STEP 06: Repeat the following steps until all processes are finished:
STEP 06.01: Find a process that can be scheduled
STEP 06.02: Schedule the process
STEP 06.03: Update the work vector
STEP 06.04: Update the finish vector
STEP 07: Print the safe sequence
STEP 08: STOP
*/
#include <stdio.h>

int main() {
    int n, m, i, j;
    int alloc[10][10], max[10][10], avail[10];
    int need[10][10], finish[10] = {0}, work[10];
    int safeSeq[10], count = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter number of resources: ");
    scanf("%d", &m);
    printf("Enter allocation matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);
    printf("Enter max matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            scanf("%d", &max[i][j]);
    printf("Enter available resources:\n");
    for(j = 0; j < m; j++)
        scanf("%d", &avail[j]);
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];
    for(j = 0; j < m; j++)
        work[j] = avail[j];
    while(count < n) {
        int found = 0;
        for(i = 0; i < n; i++) {
            if(!finish[i]) {
                int safe = 1;
                for(j = 0; j < m; j++)
                    if(need[i][j] > work[j]) {
                        safe = 0;
                        break;
                    }
                if(safe) {
                    for(j = 0; j < m; j++)
                        work[j] += alloc[i][j];
                    finish[i] = 1;
                    safeSeq[count++] = i;
                    found = 1;
                }
            }
        }
        if(!found) {
            printf("System is in unsafe state!\n");
            return 0;
        }
    }
    printf("System is in safe state.\nSafe sequence: ");
    for(i = 0; i < n; i++)
        printf("P%d ", safeSeq[i]);
    printf("\n");
    return 0;
}
/*
OUTPUT:
Enter number of processes: 5
Enter number of resources: 3
Enter allocation matrix:
0 1 0
2 0 0
3 0 2
2 1 1
0 0 2
Enter max matrix:
7 5 3
3 2 2
9 0 2
2 2 2
4 3 3
Enter available resources:
3 3 2
System is in safe state.
Safe sequence: P1 P3 P4 P0 P2 
*/