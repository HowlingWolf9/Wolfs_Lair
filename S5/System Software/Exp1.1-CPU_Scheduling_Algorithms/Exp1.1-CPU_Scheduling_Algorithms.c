#include <stdio.h>

struct process {
    int pid;
    int at;
    int bt;
    int pty;
    int ct;
    int tat;
    int wt;
    int rt;
};

void fcfs(struct process p[], int n) {
    int time = 0;
    float total_tat = 0;
    float total_wt = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].at > p[j + 1].at) {
                struct process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (time < p[i].at) {
            time = p[i].at;
        }
        p[i].ct = time + p[i].bt;
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
        time = p[i].ct;
        total_tat += p[i].tat;
        total_wt += p[i].wt;
    }
    printf("\nFCFS Scheduling:\n");
    printf("+-----+----+----+----+-----+----+\n");
    printf("| PID | AT | BT | CT | TAT | WT |\n");
    printf("+-----+----+----+----+-----+----+\n");
    for (int i = 0; i < n; i++) {
        printf("| %3d | %2d | %2d | %2d | %3d | %2d |\n", p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }
    printf("+-----+----+----+----+-----+----+\n");
    printf("Average Turnaround Time: %.2f\n", total_tat / n);
    printf("Average Waiting Time: %.2f\n", total_wt / n);
}

void sjf(struct process p[], int n) {
    int time = 0, comp = 0;
    float total_tat = 0, total_wt = 0;
    while (comp != n) {
        int shortest_job_idx = -1;
        int shortest_burst = 99999;
        for (int i = 0; i < n; i++) {
            if (p[i].at <= time && p[i].rt > 0 && p[i].bt < shortest_burst) {
                shortest_burst = p[i].bt;
                shortest_job_idx = i;
            }
        }
        if (shortest_job_idx == -1) {
            time++;
        } else {
            int idx = shortest_job_idx;
            time += p[idx].bt;
            p[idx].ct = time;
            p[idx].tat = p[idx].ct - p[idx].at;
            p[idx].wt = p[idx].tat - p[idx].bt;
            p[idx].rt = 0;
            comp++;
            total_tat += p[idx].tat;
            total_wt += p[idx].wt;
        }
    }
    printf("\nSJF (Non-Preemptive) Scheduling:\n");
    printf("+-----+----+----+----+-----+----+\n");
    printf("| PID | AT | BT | CT | TAT | WT |\n");
    printf("+-----+----+----+----+-----+----+\n");
    for (int i = 0; i < n; i++) {
        printf("| %3d | %2d | %2d | %2d | %3d | %2d |\n", p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }
    printf("+-----+----+----+----+-----+----+\n");
    printf("Average Turnaround Time: %.2f\n", total_tat / n);
    printf("Average Waiting Time: %.2f\n", total_wt / n);
}

void rr(struct process p[], int n, int q) {
    int time = 0, comp = 0;
    float total_tat = 0, total_wt = 0;
    int queue[100], front = 0, rear = 0;
    int is_in_queue[100] = {0};
    int min_at = 9999;
    for(int i=0; i<n; i++) {
        if(p[i].at < min_at) {
            min_at = p[i].at;
        }
    }
    time = min_at;
    while(comp < n) {
        for (int i = 0; i < n; i++) {
            if (p[i].at <= time && p[i].rt > 0 && !is_in_queue[i]) {
                queue[rear++] = i;
                is_in_queue[i] = 1;
            }
        }
        if (front == rear) {
            time++;
            continue;
        }
        int cpi = queue[front++];
        int run_time = (p[cpi].rt <= q) ? p[cpi].rt : q;
        time += run_time;
        p[cpi].rt -= run_time;
        for (int i = 0; i < n; i++) {
            if (p[i].at <= time && p[i].rt > 0 && !is_in_queue[i]) {
                queue[rear++] = i;
                is_in_queue[i] = 1;
            }
        }
        if (p[cpi].rt == 0) {
            comp++;
            p[cpi].ct = time;
            p[cpi].tat = p[cpi].ct - p[cpi].at;
            p[cpi].wt = p[cpi].tat - p[cpi].bt;
            total_tat += p[cpi].tat;
            total_wt += p[cpi].wt;
        } else {
            queue[rear++] = cpi;
        }
    }
    printf("\nRound Robin Scheduling (Quantum: %d):\n", q);
    printf("+-----+----+----+----+-----+----+\n");
    printf("| PID | AT | BT | CT | TAT | WT |\n");
    printf("+-----+----+----+----+-----+----+\n");
    for (int i = 0; i < n; i++) {
        printf("| %3d | %2d | %2d | %2d | %3d | %2d |\n", p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }
    printf("+-----+----+----+----+-----+----+\n");
    printf("Average Turnaround Time: %.2f\n", total_tat / n);
    printf("Average Waiting Time: %.2f\n", total_wt / n);
}

void ps(struct process p[], int n) {
    int time = 0, comp = 0;
    float total_tat = 0, total_wt = 0;
    while (comp != n) {
        int highest_pty_idx = -1;
        int highest_pty = 99999;
        for (int i = 0; i < n; i++) {
            if (p[i].at <= time && p[i].rt > 0 && p[i].pty < highest_pty) {
                highest_pty = p[i].pty;
                highest_pty_idx = i;
            }
        }
        if (highest_pty_idx == -1) {
            time++;
        } else {
            int idx = highest_pty_idx;
            time += p[idx].bt;
            p[idx].ct = time;
            p[idx].tat = p[idx].ct - p[idx].at;
            p[idx].wt = p[idx].tat - p[idx].bt;
            p[idx].rt = 0;
            comp++;
            total_tat += p[idx].tat;
            total_wt += p[idx].wt;
        }
    }
    printf("\nPriority (Non-Preemptive) Scheduling:\n");
    printf("+-----+----+----+----------+----+-----+----+\n");
    printf("| PID | AT | BT | Priority | CT | TAT | WT |\n");
    printf("+-----+----+----+----------+----+-----+----+\n");
    for (int i = 0; i < n; i++) {
        printf("| %3d | %2d | %2d | %8d | %2d | %3d | %2d |\n", p[i].pid, p[i].at, p[i].bt, p[i].pty, p[i].ct, p[i].tat, p[i].wt);
    }
    printf("+-----+----+----+----------+----+-----+----+\n");
    printf("Average Turnaround Time: %.2f\n", total_tat / n);
    printf("Average Waiting Time: %.2f\n", total_wt / n);
}

int main() {
    int n, choice, q;
    struct process p[100], pc[100];
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &p[i].at);
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &p[i].bt);
        printf("Enter priority for process %d: ", i + 1);
        scanf("%d", &p[i].pty);
    }
    do {
        for (int i = 0; i < n; i++) {
            pc[i] = p[i];
            pc[i].rt = pc[i].bt;
            pc[i].ct = 0;
            pc[i].tat = 0;
            pc[i].wt = 0;
        }
        printf("\nCPU Scheduling Algorithms:\n");
        printf("1. FCFS\n");
        printf("2. SJF (Non-Preemptive)\n");
        printf("3. Round Robin\n");
        printf("4. Priority (Non-Preemptive)\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                fcfs(pc, n);
                break;
            case 2:
                sjf(pc, n);
                break;
            case 3:
                printf("Enter time quantum for Round Robin: ");
                scanf("%d", &q);
                rr(pc, n, q);
                break;
            case 4:
                ps(pc, n);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 5);
    return 0;
}