/*
ALGORITHM:
STEP 01: START
STEP 02: Get the number of processes
STEP 03: Get the burst time of each process
STEP 04: Get the priority of each process
STEP 05: Sort the processes based on priority
STEP 06: Calculate the average waiting time and average turnaround time
         - Average Waiting Time = Total Waiting Time / no of processes
         - Average Turnaround Time = Total Turnaround Time / no of processes
STEP 07: Print the Total Waiting Time, Average Waiting Time, Total Turnaround Time, Average Turnaround Time
STEP 08: STOP
*/
//CODE:
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int i, j, n, bt[10], wt[10], tat[10], p[10], compt[10], temp1, temp2;
    float sumwt = 0, sumtat = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("\nProcess %d", i + 1);
        printf("\n----------\n");
        printf("Enter the burst time: ");
        scanf("%d", &bt[i]);
        printf("Enter the priority: ");
        scanf("%d", &p[i]);
    }
    for (i = 0; i < n; i++)
        for (j = i + 1; j < n; j++)
            if (p[i] > p[j])
            {
                temp1 = p[i];
                p[i] = p[j];
                p[j] = temp1;
                temp2 = bt[i];
                bt[i] = bt[j];
                bt[j] = temp2;
            }
    compt[0] = bt[0];
    for (i = 1; i < n; i++)
        compt[i] = bt[i] + compt[i - 1];
    for (i = 0; i < n; i++)
    {
        tat[i] = compt[i];
        wt[i] = tat[i] - bt[i];
        sumwt += wt[i];
        sumtat += tat[i];
    }
    printf("\nTotal Waiting Time: %.2f\n", sumwt);
    printf("Average Waiting Time: %.2f\n", sumwt / n);
    printf("Total Turnaround Time: %.2f\n", sumtat);
    printf("Average Turnaround Time: %.2f\n", sumtat / n);
}
/*
OUTPUT:
Enter the number of processes: 3

Process 1
----------
Enter the burst time: 2
Enter the priority: 3

Process 2
----------
Enter the burst time: 8
Enter the priority: 1

Process 3
----------
Enter the burst time: 5
Enter the priority: 2

Total Waiting Time: 21.00
Average Waiting Time: 7.00
Total Turnaround Time: 36.00
Average Turnaround Time: 12.00
*/