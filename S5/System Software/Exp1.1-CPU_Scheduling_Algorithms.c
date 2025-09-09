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
    float ttat = 0;
    float twt = 0;

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
        ttat += p[i].tat;
        twt += p[i].wt;
    }

    printf("\nFCFS Scheduling:\n");
    printf("+-----+----+----+----+-----+----+\n");
    printf("| PID | AT | BT | CT | TAT | WT |\n");
    printf("+-----+----+----+----+-----+----+\n");
    for (int i = 0; i < n; i++) {
        printf("| %3d | %2d | %2d | %2d | %3d | %2d |\n", p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }
    printf("+-----+----+----+----+-----+----+\n");
    printf("Average Turnaround Time: %.2f\n", ttat / n);
    printf("Average Waiting Time: %.2f\n", twt / n);
}

void sjf(struct process p[], int n) {
    int time = 0;
    int comp = 0;
    float ttat = 0;
    float twt = 0;
    int sh;

    while (comp != n) {
        sh = -1;
        for (int i = 0; i < n; i++) {
            if (p[i].at <= time && p[i].rt > 0) {
                if (sh == -1 || p[i].bt < p[sh].bt) {
                    sh = i;
                }
            }
        }

        if (sh == -1) {
            time++;
        } else {
            time += p[sh].bt;
            p[sh].ct = time;
            p[sh].tat = p[sh].ct - p[sh].at;
            p[sh].wt = p[sh].tat - p[sh].bt;
            p[sh].rt = 0;
            comp++;
            ttat += p[sh].tat;
            twt += p[sh].wt;
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
    printf("Average Turnaround Time: %.2f\n", ttat / n);
    printf("Average Waiting Time: %.2f\n", twt / n);
}

void rr(struct process p[], int n, int q) {
    int time = 0;
    int comp = 0;
    float ttat = 0;
    float twt = 0;
    int queue[100], front = -1, rear = -1;
    int in_queue[100] = {0};

    for (int i = 0; i < n; i++) {
        p[i].rt = p[i].bt;
    }

    while (comp != n) {
        for (int i = 0; i < n; i++) {
            if (p[i].at <= time && p[i].rt > 0 && !in_queue[i]) {
                if (front == -1) front = 0;
                rear = (rear + 1) % 100;
                queue[rear] = i;
                in_queue[i] = 1;
            }
        }

        if (front == -1) {
            time++;
        } else {
            int cpi = queue[front];
            if (front == rear) {
                front = rear = -1;
            } else {
                front = (front + 1) % 100;
            }
            in_queue[cpi] = 0;

            if (p[cpi].rt <= q) {
                time += p[cpi].rt;
                p[cpi].rt = 0;
                p[cpi].ct = time;
                p[cpi].tat = p[cpi].ct - p[cpi].at;
                p[cpi].wt = p[cpi].tat - p[cpi].bt;
                comp++;
                ttat += p[cpi].tat;
                twt += p[cpi].wt;
            } else {
                time += q;
                p[cpi].rt -= q;
                for (int i = 0; i < n; i++) {
                    if (p[i].at <= time && p[i].rt > 0 && !in_queue[i]) {
                         if (front == -1) front = 0;
                         rear = (rear + 1) % 100;
                         queue[rear] = i;
                         in_queue[i] = 1;
                    }
                }
                if (front == -1) front = 0;
                rear = (rear + 1) % 100;
                queue[rear] = cpi;
                in_queue[cpi] = 1;
            }
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
    printf("Average Turnaround Time: %.2f\n", ttat / n);
    printf("Average Waiting Time: %.2f\n", twt / n);
}

void ps(struct process p[], int n) {
    int time = 0;
    int comp = 0;
    float ttat = 0;
    float twt = 0;
    int hp;

    while (comp != n) {
        hp = -1;
        for (int i = 0; i < n; i++) {
            if (p[i].at <= time && p[i].rt > 0) {
                if (hp == -1 || p[i].pty < p[hp].pty) {
                    hp = i;
                }
            }
        }

        if (hp == -1) {
            time++;
        } else {
            time += p[hp].bt;
            p[hp].ct = time;
            p[hp].tat = p[hp].ct - p[hp].at;
            p[hp].wt = p[hp].tat - p[hp].bt;
            p[hp].rt = 0;
            comp++;
            ttat += p[hp].tat;
            twt += p[hp].wt;
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
    printf("Average Turnaround Time: %.2f\n", ttat / n);
    printf("Average Waiting Time: %.2f\n", twt / n);
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
        p[i].rt = p[i].bt;
    }

    for (int i = 0; i < n; i++) {
        pc[i] = p[i];
    }

    do {
        printf("\nCPU Scheduling Algorithms:\n");
        printf("1. FCFS\n");
        printf("2. SJF (Non-Preemptive)\n");
        printf("3. Round Robin\n");
        printf("4. Priority (Non-Preemptive)\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        for (int i = 0; i < n; i++) {
            p[i] = pc[i];
        }

        switch (choice) {
            case 1:
                fcfs(p, n);
                break;
            case 2:
                sjf(p, n);
                break;
            case 3:
                printf("Enter time quantum for Round Robin: ");
                scanf("%d", &q);
                rr(p, n, q);
                break;
            case 4:
                ps(p, n);
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
