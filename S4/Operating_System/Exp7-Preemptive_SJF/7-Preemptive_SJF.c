/*
ALGORITHM:
STEP 01: START
STEP 02: Get the number of processes 
STEP 03: Get the burst time and arrival time of each process
STEP 04: Sort the processes based on arrival time
STEP 05: Assign remaining time of each process as burst time
STEP 06: For each unit time, executr the process with minimum remaining time
STEP 07: For each process, calculate the waiting time and turnaround time
         - waiting time = current time - arrival time - burst time
         - turnaround time = current time - arrival time
STEP 08: Calculate the average waiting time and average turnaround time
         - Average Waiting Time = Total Waiting Time / no of processes
         - Average Turnaround Time = Total Turnaround Time / no of processes
STEP 09: Print gannt chart, Total Waiting Time, Average Waiting Time, Total Turnaround Time, Average Turnaround Time
STEP 10: STOP

*/
#include <stdio.h>
#include <stdlib.h>

struct sjf {
    int pid;
    int btime;
    int wtime;
    int ttime;
    int atime;
    int completed;
    int remaining_btime;
};

void main() {
    int i, j, n, time = 0, completed_processes = 0;
    int totwtime = 0, totttime = 0;
    printf("In Preemptive SJF Scheduling....\n");
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct sjf p[n];
    for (i = 0; i < n; i++) {
        printf("\nProcess %d:\n", i + 1);
        printf("----------\n");
        printf("Enter the arrival time: ");
        scanf("%d", &p[i].atime);
        printf("Enter the burst time: ");
        scanf("%d", &p[i].btime);
        p[i].pid = i + 1;
        p[i].completed = 0;
        p[i].remaining_btime = p[i].btime;
    }

    printf("\nGantt Chart:\n");
    printf("Time\t|Process\n");

    while (completed_processes < n) {
        int shortest_job = -1;
        int min_btime = 9999; 

        for (i = 0; i < n; i++) {
            if (p[i].atime <= time && p[i].completed == 0) {
                if (p[i].remaining_btime < min_btime) {
                    min_btime = p[i].remaining_btime;
                    shortest_job = i;
                }
            }
        }

        if (shortest_job == -1) {
            printf("%d\t|Idle\n", time);
            time++;
            continue;
        }

        p[shortest_job].remaining_btime--;
        printf("%d\t|P%d\n", time, p[shortest_job].pid);
        time++;

        if (p[shortest_job].remaining_btime == 0) {
            p[shortest_job].completed = 1;
            completed_processes++;
            p[shortest_job].ttime = time - p[shortest_job].atime;
            p[shortest_job].wtime = p[shortest_job].ttime - p[shortest_job].btime;

            totwtime += p[shortest_job].wtime;
            totttime += p[shortest_job].ttime;
        }
    }

    printf("\nProcess\t|Arrival Time\t|Burst Time\t|Waiting Time\t|Turnaround Time|\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t|%d\t\t|%d\t\t|%d\t\t|%d\t\t|\n", p[i].pid, p[i].atime, p[i].btime, p[i].wtime, p[i].ttime);
    }

    printf("\nTotal Waiting Time: %d\n", totwtime);
    printf("Average Waiting Time: %.2f\n", (float)totwtime / n);
    printf("Total Turnaround Time: %d\n", totttime);
    printf("Average Turnaround Time: %.2f\n", (float)totttime / n);
}
/*
OUTPUT:
In Preemptive SJF Scheduling....
Enter the number of processes: 4

Process 1:
----------
Enter the arrival time: 0
Enter the burst time: 6

Process 2:
----------
Enter the arrival time: 1
Enter the burst time: 3

Process 3:
----------
Enter the arrival time: 2
Enter the burst time: 4

Process 4:
----------
Enter the arrival time: 4
Enter the burst time: 5

Gantt Chart:
Time    |Process
0       |P1
1       |P2
2       |P2
3       |P2
4       |P3
5       |P3
6       |P3
7       |P3
8       |P1
9       |P1
10      |P1
11      |P1
12      |P1
13      |P4
14      |P4
15      |P4
16      |P4
17      |P4

Process |Arrival Time   |Burst Time     |Waiting Time   |Turnaround Time|
P1      |0              |6              |7              |13             |
P2      |1              |3              |0              |3              |
P3      |2              |4              |2              |6              |
P4      |4              |5              |9              |14             |

Total Waiting Time: 18
Average Waiting Time: 4.50
Total Turnaround Time: 36
Average Turnaround Time: 9.00
*/