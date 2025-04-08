#include <stdio.h>

int lfu(int freq[], int time[], int f) {
    int minFreq = freq[0], pos = 0;
    for (int i = 1; i < f; i++) {
        if (freq[i] < minFreq || (freq[i] == minFreq && time[i] < time[pos])) {
            minFreq = freq[i];
            pos = i;
        }
    }
    return pos;
}

int main() {
    int ref[50], frame[10], freq[10], time[10];
    int n, f, pos, counter = 0, hit, fault = 0;

    printf("Enter the size of reference string: ");
    scanf("%d", &n);

    printf("Enter the reference string: ");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &ref[i]);
    }

    printf("Enter frame size: ");
    scanf("%d", &f);

    // Initialize frames
    for (int i = 0; i < f; i++) 
    {
        frame[i] = -1;
        freq[i] = 0;
        time[i] = 0;
    }

    for (int i = 0; i < n; i++) 
    {
        hit = 0;
        for (int j = 0; j < f; j++) 
        {
            if (frame[j] == ref[i]) 
            {
                hit = 1;
                freq[j]++;
                time[j] = ++counter;
                break;
            }
        }

        if (!hit) 
        {
            pos = -1;
            for (int j = 0; j < f; j++) 
            {
                if (frame[j] == -1) 
                {
                    pos = j;
                    break;
                }
            }

            if (pos == -1)
            {
                pos = lfu(freq, time, f);
            }

            frame[pos] = ref[i];
            freq[pos] = 1;
            time[pos] = ++counter;
            fault++;
        }

        // Print the frame changes
        printf("For %d:\t", ref[i]);
        for (int j = 0; j < f; j++)
            if (frame[j] != -1)
                printf("| %d ", frame[j]);
            else
                printf("| - ");
        printf("|\t");
        if (hit == 0)
            printf("Miss\n");
        else
            printf("Hit\n");
    }

    printf("\nTotal Page Faults: %d\n", fault);
    printf("Total Page Hits: %d\n", n - fault);

    return 0;
}
