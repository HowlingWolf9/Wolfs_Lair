/*
ALGORITHM:
STEP 01: START
STEP 02: Include the necessary header files
STEP 03: Define constants for maximum number of processes and resources
STEP 04: Define the is_cyclic() function
STEP 05: Define the detect_deadlock() function
STEP 06: Define the request_resources() function
STEP 07: Define the release_resources() function
STEP 08: Define the main() function
STEP 09: Display the allocation and prevented deadlock messages
STEP 10: STOP
*/
#include <stdio.h>
#include <stdbool.h>
#define MAX_PROCESSES 10
#define MAX_RESOURCES 10

int allocation[MAX_PROCESSES][MAX_RESOURCES];
int request[MAX_PROCESSES][MAX_RESOURCES];
bool visited[MAX_PROCESSES];
bool finished[MAX_PROCESSES];
int num_processes, num_resources;

bool is_cyclic(int process) {
    if (visited[process]) 
        return true;
    visited[process] = true;
    
    for (int j = 0; j < num_resources; j++) {
        if (request[process][j] > 0) {
            for (int i = 0; i < num_processes; i++) {
                if (allocation[i][j] > 0 && !finished[i]) {
                    if (is_cyclic(i)) return true;
                }
            }
        }
    }
    visited[process] = false;
    return false;
}

bool detect_deadlock() {
    for (int i = 0; i < num_processes; i++) {
        if (!finished[i]) {
            for (int j = 0; j < num_processes; j++) visited[j] = false;
            if (is_cyclic(i)) return true;
        }
    }
    return false;
}

void request_resource(int p, int r) {
    request[p][r] = 1;
    if (detect_deadlock()) {
        printf("Request denied: Deadlock detected.\n");
        request[p][r] = 0;
    } else {
        allocation[p][r] = 1;
        printf("Request granted: Process %d allocated Resource %d.\n", p, r);
    }
}

void release_resource(int p, int r) {
    if (allocation[p][r]) {
        allocation[p][r] = 0;
        request[p][r] = 0;
        printf("Process %d released Resource %d.\n", p, r);
    }
}

int main() 
{
    printf("Enter the number of processes and resources: ");
    scanf("%d %d", &num_processes, &num_resources);

    int ch;
    int p, r;
    do{
        printf("\n==== YOUR CHOICES ====\n");
        printf("1. Request a resource\n");
        printf("2. Release a resource\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter the process number and resource number: ");
                scanf("%d %d", &p, &r);
                request_resource(p, r);
                break;
            case 2:
                printf("Enter the process number and resource number: ");
                scanf("%d %d", &p, &r);
                release_resource(p, r);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }while(ch != 3);
}
/*
OUTPUT:
Request granted: Process 0 allocated Resource 0.
Request denied: Deadlock detected.
Request denied: Deadlock detected.
Request denied: Deadlock detected.
Process 0 released Resource 0.
Request granted: Process 0 allocated Resource 1.
*/