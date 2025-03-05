/*
AIM: To write a C program to implement FIFO page replacement algorithm.
ALGORITHM:
STEP 01: Start
STEP 02: Input the number of references
STEP 03: Input the reference string
STEP 04: Input the frame size
STEP 05: Initialize an empty frame of size fsize and set all values to -1
STEP 06: Initialize fault = 0 and c = 0
STEP 07: For each reference ( i, from 0 to n - 1):
         a.  Set flag = 0
         b.  For each frame ( j, from 0 to fsize - 1):
                 i.  If the page reference[j] is found  frame[j]:
                    -   Set flag = 1
                    -   Break(Page hit, no replacement needed)
         c.  If flag = 0:
                 i.   Increment fault
                 ii.  Replace frame[c] with reference[i]
                 iii. Update c = (c + 1) % fsize to maintain in FIFO array.
STEP 08: Calculate the miss ratio = (fault / n) * 100 and hit ratio = ((n - fault) / n) * 100
STEP 09: Print the total number of faults, hit ratio, and miss ratio
STEP 10: Stop

*/
//CODE:
#include <stdio.h>
int main(){
    int reference[50], frame[50], fsize, i, j, flag, c = 0, n, fault = 0;
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
        if (flag == 0){
            fault++;
            frame[c] = reference[i];
            c = (c + 1) % fsize;
            
        }
    }
    miss = ((float)fault / n) * 100;
    hit = ((float)(n - fault) / n) * 100;
    printf("Total No.of Faults: %d\n", fault);
    printf("Hit Ratio: %.2f%%\n", hit);
    printf("Miss Ratio: %.2f%%\n", miss);
    return 0;
}
/*
OUTPUT:
Enter the No.of References: 8 
Enter the References: 1 2 3 4 1 2 5 1
Enter the Frame Size: 7
Total No.of Faults: 5
Hit Ratio: 37.50%
Miss Ratio: 62.50%
*/