/*
ALGORITHM:
STEP 01: START
STEP 02: Input the number of references(n), sequence of references(reference[]), and frame size(fsize)
STEP 03: Create an empty frame of size fsize and set all values to -1
STEP 04: Initialize fault = 0 to track the number of page faults
STEP 05: For each reference, reference[i]:
STEP 05.01: Check if it is already present in the frame:
STEP 05.01.01: If found, it's a hit, move to the next reference
STEP 05.01.02: If not found, it's a fault:
STEP 05.01.02.01: If the frame is not full, place the reference in the first empty frame
STEP 05.01.02.02: If the frame is full:
STEP 05.01.02.02.01: Identify the LRU page (the one with the oldest reference) and replace it with the current reference
STEP 06: Increment the fault count
STEP 07: Calculate the hit ratio = ((n - fault) / n) * 100 and miss ratio = (fault / n) * 100
STEP 08: Print the hit ratio and miss ratio
STEP 09: STOP
*/
//CODE:
#include <stdio.h>
int main(){
    int reference[50], frame[50], fsize, i, j, flag, c = 0, n, fault = 0, lru;
    float miss, hit;
    printf("Enter the No.of References: ");
    scanf("%d", &n);
    printf("Enter the References: ");
    for (i = 0; i < n; i++)
        scanf("%d", &reference[i]);
    printf("Enter the Frame Size: ");
    scanf("%d", &fsize);
    for (i = 0; i < fsize; i++)
        frame[i] = -1;
    for (i = 0; i < n; i++){
        flag = 0;
        for (j = 0; j < fsize; j++){
            if (frame[j] == reference[i]){
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            if (c < fsize)
            {
                frame[c] = reference[i];
                c++;
            }
            else
            {
                int lru_index = -1;
                int oldest_time = -1;
                for (j = 0; j < fsize; j++)
                {
                    int time = -1;
                    for (int k = i - 1; k >= 0; k--)
                        if (reference[k] == frame[j])
                        {
                            time = k;
                            break;
                        }
                    if (time < oldest_time || oldest_time == -1)
                    {
                            oldest_time = time;
                            lru_index = j;
                    }
                }
                frame[lru_index] = reference[i];
            }
            fault++;
        }
    }
    printf("Total No.of Faults: %d\n", fault);
    miss = ((float)fault / n) * 100;
    hit = ((float)(n - fault) / n) * 100;
    printf("Hit Ratio: %.2f%%\n", hit);
    printf("Miss Ratio: %.2f%%\n", miss);
    return 0;
}
/*
OUTPUT:
Enter the No.of References: 14
Enter the References: 7 0 1 2 0 3 0 4 2 3 0 3 2 0                           
Enter the Frame Size: 4
Total No.of Faults: 6
Hit Ratio: 57.14%
Miss Ratio: 42.86%
*/