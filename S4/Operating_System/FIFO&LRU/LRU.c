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
        if (flag == 0){
            if (c < fsize){
                frame[c] = reference[i];
                c++;
            }
            else{
                int lru_index = -1;
                int oldest_time = -1;
                for (j = 0; j < fsize; j++){
                    int time = -1;
                    for (int k = i - 1; k >= 0; k--){
                        if (reference[k] == frame[j]){
                            time = k;
                            break;
                        }
                    }
                    if (time < oldest_time || oldest_time == -1){
                        oldest_time = time;
                        lru_index = j;
                    }
                    frame[lru_index] = reference[i];
                }
                fault++;
            }
        }
    }
    miss = ((float)fault / n) * 100;
    hit = ((float)(n - fault) / n) * 100;
    printf("Total No.of Faults: %d\n", fault);
    printf("Hit Ratio: %.2f%%\n", hit);
    printf("Miss Ratio: %.2f%%\n", miss);
    return 0;
}