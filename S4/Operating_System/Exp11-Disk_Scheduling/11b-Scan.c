/*
ALGORITHM:
STEP 01: START
STEP 02: Read number of disk requests, the initial head position and the disk requests from the user
STEP 03: Sort the disk requests in ascending order
STEP 04: Determine the starting index for the scan based on the initial head position
STEP 05: Scan in forward direction
STEP 05.01: Iterate over the disk requests from starting index to the end
STEP 05.01.01: Print disk request value
STEP 05.01.02: Update total seek time by adding absolute difference between current head position and disk request value
STEP 05.01.03: Update current head position to disk request value
STEP 06: Handle the edge case of reaching the end of the disk in forward direction
STEP 07: Scan in reverse direction
STEP 07.01: Iterate over the disk request sequence from rotating index to the beginning
STEP 07.01.01: Print disk request value
STEP 07.01.02: Update total seek time by adding absolute difference between current head position and disk request value
STEP 08: Print total seek time
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