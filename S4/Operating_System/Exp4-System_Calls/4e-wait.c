/*
ALGORITHM:
STEP 01: Include the necessary header files
STEP 02: Use fork() to create a child process
STEP 03: In the parent use wait() to wait for the child to terminate
STEP 04: Print the Process ID of the parent and child
STEP 05: STOP
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

void main()
{
    pid_t pid = fork();
    if (pid == 0)
        printf("Child Process ID : %d\n", getpid());
    else
    {
        wait(NULL);
        printf("Parent Process ID : %d\n", getpid());
    }
}
/*
OUTPUT:
Child Process ID : 10176
Parent Process ID : 10175
*/