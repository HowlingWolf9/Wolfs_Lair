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

void main() 
{
    int reference[MAX_REFERENCES], n, fsize, i, j, fault = 0;
    float miss, hit;
    Frame frame[MAX_FRAMES];
    
    // Input the number of references
    printf("Enter the No.of References: ");
    scanf("%d", &n);
    
    // Input the references
    printf("Enter the References: ");
    for (i = 0; i < n; i++)
        scanf("%d", &reference[i]);
    
    // Input the frame size
    printf("Enter the Frame Size: ");
    scanf("%d", &fsize);
    
    // Initialize the frame
    for (i = 0; i < fsize; i++)
    {
        frame[i].page = -1;
        frame[i].frequency = 0;
    }
    
    // Process the references
    for (i = 0; i < n; i++) 
    {
        int page = reference[i];
        int flag = 0;
        
        // Check if the page is already in the frame
        for (j = 0; j < fsize; j++) 
        {
            if (frame[j].page == page) 
            {
                frame[j].frequency++;
                flag = 1;
                break;
            }
        }
        
        // If the page is not in the frame, find the page with minimum frequency
        if (flag == 0) 
        {
            int min_index = 0;

            // Find the first empty frame
            for (j = 0; j < fsize; j++) 
            {
                if (frame[j].page == -1) 
                {
                    min_index = j;
                    break;
                }
            }
            
            // If no empty frame, find the page with minimum frequency
            if (frame[min_index].page != -1) 
            {
                int min_freq = frame[0].frequency;
                min_index = 0;
                
                // Find the page with minimum frequency
                for (j = 1; j < fsize; j++) 
                {
                    if (frame[j].frequency < min_freq) 
                    {
                        min_freq = frame[j].frequency;
                        min_index = j;
                    }
                }
            }
            
            // Replace the page
            frame[min_index].page = page;
            frame[min_index].frequency = 1;
            fault++;
        }
        
        // Print the frame changes
        printf("Iteration %d:\t", i + 1);
        for (j = 0; j < fsize; j++)
            if (frame[j].page != -1)
                printf("| %d ", frame[j].page);
            else
                printf("| - ");
        printf("|\t");
        if (flag == 0)
            printf("Miss\n");
        else
            printf("Hit\n");
    }
    
    // Print the total number of faults
    printf("Total No.of Faults: %d\n", fault);

    // Calculate the hit and miss ratio
    miss = ((float)fault / n) * 100;
    hit = ((float)(n - fault) / n) * 100;
    
    // Print the hit and miss ratio
    printf("Hit Ratio: %.2f%%\n", hit);
    printf("Miss Ratio: %.2f%%\n", miss);
    
}
/*
OUTPUT:
Enter the No.of References: 16
Enter the References: 7 0 2 4 3 1 4 7 2 0 4 3 0 3 2 7
Enter the Frame Size: 3
Iteration 1:    | 7 | - | - |   Miss
Iteration 2:    | 7 | 0 | - |   Miss
Iteration 3:    | 7 | 0 | 2 |   Miss
Iteration 4:    | 4 | 0 | 2 |   Miss
Iteration 5:    | 3 | 0 | 2 |   Miss
Iteration 6:    | 1 | 0 | 2 |   Miss
Iteration 7:    | 4 | 0 | 2 |   Miss
Iteration 8:    | 7 | 0 | 2 |   Miss
Iteration 9:    | 7 | 0 | 2 |   Hit
Iteration 10:   | 7 | 0 | 2 |   Hit
Iteration 11:   | 4 | 0 | 2 |   Miss
Iteration 12:   | 3 | 0 | 2 |   Miss
Iteration 13:   | 3 | 0 | 2 |   Hit
Iteration 14:   | 3 | 0 | 2 |   Hit
Iteration 15:   | 3 | 0 | 2 |   Hit
Iteration 16:   | 7 | 0 | 2 |   Miss
Total No.of Faults: 11
Hit Ratio: 31.25%
Miss Ratio: 68.75%
*/
