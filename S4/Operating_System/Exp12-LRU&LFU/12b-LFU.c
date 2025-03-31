/*
ALGORITHM:
STEP 01: START
STEP 02: Get the number of references
STEP 03: Get the references
STEP 04: Get the frame size
STEP 05: Initialize the frame with -1 and frequency with 0
STEP 06: For each reference, check if it is already in the frame
        - If yes, increment the frequency
        - If no, check for an empty frame
            - If empty, insert the page and set frequency to 1
            - If no empty frame, find the page with minimum frequency and replace it
STEP 07: Increment the fault count
STEP 08: Calculate the hit and miss ratio
        - Hit Ratio = (Total References - Faults) / Total References * 100
        - Miss Ratio = Faults / Total References * 100
STEP 09: Print the total number of faults, hit ratio, and miss ratio
STEP 10: STOP
*/

#include <stdio.h>

#define MAX_FRAMES 50
#define MAX_REFERENCES 50

typedef struct {
    int page;
    int frequency;
} Frame;

void main() {
    int reference[MAX_REFERENCES], n, fsize, i, j, fault = 0;
    float miss, hit;
    Frame frame[MAX_FRAMES];
    
    printf("Enter the No.of References: ");
    scanf("%d", &n);
    
    printf("Enter the References: ");
    for (i = 0; i < n; i++)
        scanf("%d", &reference[i]);
    
    printf("Enter the Frame Size: ");
    scanf("%d", &fsize);
    
    for (i = 0; i < fsize; i++) {
        frame[i].page = -1;
        frame[i].frequency = 0;
    }
    
    for (i = 0; i < n; i++) {
        int page = reference[i];
        int flag = 0;
        
        for (j = 0; j < fsize; j++) {
            if (frame[j].page == page) {
                frame[j].frequency++;
                flag = 1;
                break;
            }
        }
        
        if (flag == 0) {
            int min_index = 0;
            
            for (j = 0; j < fsize; j++) {
                if (frame[j].page == -1) {
                    min_index = j;
                    break;
                }
            }
            
            if (frame[min_index].page != -1) {
                int min_freq = frame[0].frequency;
                min_index = 0;
                
                for (j = 1; j < fsize; j++) {
                    if (frame[j].frequency < min_freq) {
                        min_freq = frame[j].frequency;
                        min_index = j;
                    }
                }
            }
            
            frame[min_index].page = page;
            frame[min_index].frequency = 1;
            fault++;
        }
    }
    
    printf("Total No.of Faults: %d\n", fault);
    miss = ((float)fault / n) * 100;
    hit = ((float)(n - fault) / n) * 100;
    printf("Hit Ratio: %.2f%%\n", hit);
    printf("Miss Ratio: %.2f%%\n", miss);
    
}
/*
OUTPUT:
Enter the No.of References: 7
Enter the References: 1 2 3 4 2 1 5
Enter the Frame Size: 3
Total No.of Faults: 6
Hit Ratio: 14.29%
Miss Ratio: 85.71%
*/
