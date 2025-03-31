/*
ALGORITHM:
STEP 01: START
STEP 02: Include the necessary header files
STEP 03: Initialize the variables
STEP 04: Input the initial head position, maximum cylinder value, and number of requests
STEP 05: Input the I/O queue requests
STEP 06: Sort the I/O queue requests in ascending order
STEP 07: Calculate the total seek time and average seek time
STEP 08: Print the order of requests served and total seek time
STEP 09: STOP
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int ioq[20], i, j, n, ihead, temp, scan, tot, max;
    float seek = 0, avgs;
    
    printf("In C-SCAN Disk Scheduling....\n");
    printf("Enter the number of requests: ");
    scanf("%d", &n);
    printf("Enter the initial head position: ");
    scanf("%d", &ihead);
    printf("Enter the maximum cylinder value: ");
    scanf("%d", &max);
    
    ioq[0] = ihead;
    ioq[1] = 0;
    ioq[2] = max;
    n += 3;
    
    printf("Enter the I/O queue requests:\n");
    for (i = 3; i < n; i++) {
        scanf("%d", &ioq[i]);
    }
    
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (ioq[j] > ioq[j + 1]) {
                temp = ioq[j];
                ioq[j] = ioq[j + 1];
                ioq[j + 1] = temp;
            }
        }
    }
    
    for (i = 0; i < n; i++) {
        if (ioq[i] == ihead) {
            scan = i;
            break;
        }
    }
    
    printf("\nOrder of requests served:\n");
    int prev = ioq[scan];
    printf("%d (start)\n", prev);
    
    for (i = scan + 1; i < n; i++) {
        tot = ioq[i] - prev;
        seek += abs(tot);
        printf("%d -> %d\n", ioq[i], tot);
        prev = ioq[i];
    }
    
    if (scan > 0) {
        tot = max - 0;
        seek += tot;
        printf("%d -> %d (jump)\n", 0, tot);
        prev = 0;
        
        for (i = 1; i < scan; i++) {
            tot = ioq[i] - prev;
            seek += abs(tot);
            printf("%d -> %d\n", ioq[i], tot);
            prev = ioq[i];
        }
    }
    
    avgs = seek / (n - 3);
    
    printf("\nTotal seek time: %.2f\n", seek);
    printf("Average seek time: %.2f\n", avgs);
    
    return 0;
}
/*
OUTPUT:
In C-SCAN Disk Scheduling....
Enter the number of requests: 8
Enter the initial head position: 50
Enter the maximum cylinder value: 199
Enter the I/O queue requests:
176 79 34 60 92 11 41 114

Order of requests served:
50 (start)
60 -> 10
79 -> 19
92 -> 13
114 -> 22
176 -> 62
199 -> 23
0 -> 199 (jump)
11 -> 11
34 -> 23
41 -> 7

Total seek time: 389.00
Average seek time: 48.62
*/