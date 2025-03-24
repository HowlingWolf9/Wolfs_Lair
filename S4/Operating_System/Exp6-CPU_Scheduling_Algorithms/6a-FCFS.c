/*
ALGORITHM:
STEP 01: START
STEP 02: Inside the structure declare the variable pid, btime, wtime, ttime
STEP 03: Declare the variable i,n as integer, totwtime and totttime as 0
STEP 04: Get the value of n and assign pid as 1 and get the value of p[i].btime
STEP 05: Assign p[0].wtime as 0 and p[0].btime to p[0].ttime. Inside the loop calculate the waiting time and turnaround time of each
STEP 06: Calculate the average waiting time and average turnaround time
         - Average Waiting Time = Total Waiting Time / no of processes
         - Average Turnaround Time = Total Turnaround Time / no of processes
STEP 07: Print the Gaant Chart, Total Waiting Time, Average Waiting Time, Total Turnaround Time, Average Turnaround Time
STEP 08: STOP
*/
//CODE:
#include <stdio.h>
#include <stdlib.h>

struct fcfs
{
    int pid;
    int btime;
    int wtime;
    int ttime;
}p[10];

void main()
{
    int i, n;
    int totwtime = 0, totttime = 0;
    printf("In FCFS Scheduling....\n");
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the burst time for process %d: ", i + 1);
        scanf("%d", &p[i].btime);
        p[i].pid = i + 1;
    }
    p[0].wtime = 0;
    p[0].ttime = p[0].btime;
    for (i = 0; i < n; i++)
    {
        p[i].wtime = p[i - 1].wtime + p[i - 1].btime;
        p[i].ttime = p[i].wtime + p[i].btime;
        totttime += p[i].ttime;
        totwtime += p[i].wtime;
    }
    printf("\nGaant Chart:\n");
    printf("Process\t|Burst Time\t|Waiting Time\t|Turnaround Time|\n");
    for (i = 0; i < n; i++)
        printf("%d\t|%d\t\t|%d\t\t|%d\t\t|\n", p[i].pid, p[i].btime, p[i].wtime, p[i].ttime);
    printf("\nTotal Waiting Time: %d\n", totwtime);
    printf("Average Waiting Time: %.2f\n", (float)totwtime / n);
    printf("Total Turnaround Time: %d\n", totttime);
    printf("Average Turnaround Time: %.2f\n", (float)totttime / n);
}
/*
OUTPUT:
In FCFS Scheduling....
Enter the number of processes: 3
Enter the burst time for process 1: 3
Enter the burst time for process 2: 27
Enter the burst time for process 3: 3

Gaant Chart:
Process |Burst Time     |Waiting Time   |Turnaround Time|
1       |3              |0              |3              |
2       |27             |3              |30             |
3       |3              |30             |33             |

Total Waiting Time: 33
Average Waiting Time: 11.00
Total Turnaround Time: 66
Average Turnaround Time: 22.00
*/