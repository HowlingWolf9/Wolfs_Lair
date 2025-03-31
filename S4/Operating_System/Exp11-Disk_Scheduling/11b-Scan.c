/*
ALGORITHM:
STEP 01: START
STEP 02: Include the necessary header files
STEP 03: Initialize the variables
STEP 04: Input the initial head position and number of requests
STEP 05: Input the I/O queue requests
STEP 06: Sort the I/O queue requests in ascending order
STEP 07: Calculate the total seek time and average seek time
STEP 08: Print the order of requests served and total seek time
STEP 09: STOP
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int ioq[20], i, j, n, ihead, temp, scan, tot;
    float seek = 0, avgs;
    printf("In SCAN Disk Scheduling....\n");
    printf("Enter the number of requests: ");
    scanf("%d", &n);
    printf("Enter the initial head position: ");
    scanf("%d", &ihead);
    ioq[0] = ihead;
    ioq[1] = 0;
    n += 2;
    printf("Enter the I/O queue requests:\n");
    for (i = 2; i < n; i++)
        scanf("%d", &ioq[i]);
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (ioq[j] > ioq[j + 1]) {
                temp = ioq[j];
                ioq[j] = ioq[j + 1];
                ioq[j + 1] = temp;
            }
    for (i = 0; i < n; i++)
        if (ioq[i] == ihead) {
            scan = i;
            break;
        }
    printf("\nOrder of requests served:\n");
    for (i = scan; i >= 0; i--) {
        if (i > 0) {
            tot = ioq[i] - ioq[i - 1];
            printf("%d -> %d\n", ioq[i], tot);
        } else {
            printf("%d -> %d\n", ioq[i], ioq[i]);
        }
    }
    if (scan + 1 < n) {
        tot = ioq[scan + 1] - ioq[0];
        printf("%d -> %d\n", ioq[scan + 1], tot);
        for (i = scan + 2; i < n; i++) {
            tot = ioq[i] - ioq[i - 1];
            printf("%d -> %d\n", ioq[i], tot);
        }
    }
    seek = (ioq[scan] - ioq[0]) + (ioq[n - 1] - ioq[0]);
    avgs = seek / (n - 2);
    printf("\nTotal seek time: %.2f\n", seek);
    printf("Average seek time: %.2f\n", avgs);
    return 0;
}
/*
OUTPUT:
In SCAN Disk Scheduling....
Enter the number of requests: 8
Enter the initial head position: 50
Enter the I/O queue requests:
176 79 34 60 92 11 41 114

Order of requests served:
50 -> 9
41 -> 7
34 -> 23
11 -> 11
0 -> 0
60 -> 60
79 -> 19
92 -> 13
114 -> 22
176 -> 62

Total seek time: 226.00
Average seek time: 28.25
*/