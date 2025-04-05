/*
AIM:Simulate priority based CPU scheduling algorithm and find average turnaround time and average waiting time

ALGORITHM:

*/
//CODE:
#include <stdio.h>

struct Process
{
    int pid, bt, pty, wt, tat;
}p[10];


void main()
{
    int n, i, j, wt[10], tat[10];
    float twat = 0, ttat = 0;
    struct Process temp;
    
    printf("Enter the no.of Processes: ");
    scanf("%d", &n);

    //Input
    for (i = 0; i < n; i++)
    {
        printf("\nProcess - %d\n", i + 1);
        printf("-----------\n");
        printf("Enter the burst time: ");
        scanf("%d", &p[i].bt);
        printf("Enter the priority: ");
        scanf("%d", &p[i].pty);
        p[i].pid = i + 1;
    }

    //Sorting Based on Priority
    for (i = 0; i < n; i++)
        for (j = 0; j < n - 1; j++)
            if (p[j].pty > p[j+1].pty)
            {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
    
    p[0].wt = 0;
    p[0].tat = p[0].bt;
    ttat = p[0].tat;
    for (i = 1; i < n; i++)
    {
        p[i].wt = p[i - 1].bt + p[i - 1].wt ;
        p[i].tat = p[i].bt + p[i].wt;
        twat += p[i].wt;
        ttat += p[i].tat;
    }

    for (i = 0; i < n; i++)
            printf("\nP%d: BT:%d P:%d WT:%d TAT:%d", p[i].pid, p[i].bt, p[i].pty, p[i].wt, p[i].tat);

    printf("\n\nTotal Waiting Time: %.2f", twat);
    printf("\nTotal Turn-around Time: %.2f", ttat);
    printf("\nAvg. Waiting Time: %.2f", twat/n);
    printf("\nAvg. Turn-around Time: %.2f\n", ttat/n);
}