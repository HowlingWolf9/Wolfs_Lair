/*
ALGORITHM:
STEP 01: START
STEP 02: Get the number of requests
STEP 03: Get the requests
STEP 04: Get the initial head position
STEP 05: Initialize total seek time to 0
STEP 06: For each request, calculate the distance from the current head position
         - Add the distance to total seek time
         - Move the head to the current request
STEP 07: Print the sequence of requests and total seek time
STEP 08: STOP         
*/
#include <stdio.h>
#include <stdlib.h>

void fcfsDiskScheduling(int requests[], int numRequests, int head) {
    int totalSeekTime = 0;
    int current = head;

    printf("Sequence: %d", current);

    for (int i = 0; i < numRequests; i++) {
        int distance = abs(current - requests[i]);
        totalSeekTime += distance;
        current = requests[i];

        printf(" -> %d", current);
    }

    printf("\nTotal Seek Time: %d\n", totalSeekTime);
}

int main() {
    int requests[] = {98, 183, 37, 122, 14, 124, 65, 67};
    int numRequests = sizeof(requests) / sizeof(requests[0]);
    int head = 53;

    fcfsDiskScheduling(requests, numRequests, head);

    return 0;
}
/*
OUTPUT:
Sequence: 53 -> 98 -> 183 -> 37 -> 122 -> 14 -> 124 -> 65 -> 67
Total Seek Time: 640
*/