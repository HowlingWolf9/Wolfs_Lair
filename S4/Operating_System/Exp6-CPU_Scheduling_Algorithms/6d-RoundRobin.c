/*
ALGORITHM:
STEP 01: START
STEP 02: Get the number of processes
STEP 03: Get the burst time of each process
STEP 04: Get the time slice
STEP 05: Execute each process until reach the time slice or burst time
STEP 06: Time of reaching process's burst time is its turnaround time
STEP 07: Time waits to start the execution is waiting time of each process
STEP 08: Calculate the average waiting time and average turnaround time
         -Average Waiting Time = Total Waiting Time / Number of Processes
         -Average Turnaround Time = Total Turnaround Time / Number of Processes
STEP 09: Display the average waiting time, average turnaround time, total waiting time and total turnaround time
STEP 10: STOP
*/
//CODE:
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int i, j, n, time, remain, flag = 0, ts, at[10], bt[10], rt[10];
    float sumwat = 0, sumtat = 0;
    printf("Enter Total Process: ");
    scanf("%d", &n);
    remain = n;
    for( i = 0; i < n; i++)
    {
        printf("\nProcess %d\n", i+1);
        printf("----------\n");
        printf("Enter Arrival Time: ");
        scanf("%d", &at[i]);
        printf("Enter Burst Time: ");
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
    }
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (at[j] > at[j + 1])
            {
                int temp = at[j];
                at[j] = at[j + 1];
                at[j + 1] = temp;
                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;
                temp = rt[j];
                rt[j] = rt[j + 1];
                rt[j + 1] = temp;
            }
    printf("\nEnter Time-Slice: ");
    scanf("%d", &ts);
    for (time = 0, i = 0; remain != 0;)
    {
        if (rt[i] <= ts && rt[i] > 0)
        {
            time += rt[i];
            rt[i] = 0;
            flag = 1;
        }
        else if (rt[i] > 0)
        {
            rt[i] -= ts;
            time += ts;
        }
        if (rt[i] == 0 && flag == 1)
        {
            remain--;
            sumwat += time - at[i] - bt[i];
            sumtat += time - at[i];
            flag = 0;
        }
        if (i == n - 1)
            i = 0;
        else if (i + 1 < n && (at[i + 1] <= time || rt[i + 1] > 0))
            i++;
        else
            i = 0;
    }
    printf("\nTotal Waiting Time= %.2f\n", sumwat);
    printf("Average Waiting Time= %.2f\n", sumwat/n);
    printf("Total Turnaround Time= %.2f\n", sumtat);
    printf("Average Turnaround Time= %.2f\n", sumtat/n);
}
/*
OUTPUT:
Enter Total Process: 3

Process 1
----------
Enter Arrival Time: 1
Enter Burst Time: 4

Process 2
----------
Enter Arrival Time: 2
Enter Burst Time: 9

Process 3
----------
Enter Arrival Time: 0
Enter Burst Time: 6

Enter Time-Slice: 4

Total Waiting Time= 19.00
Average Waiting Time= 6.33
Total Turnaround Time= 38.00
Average Turnaround Time= 12.67
*/