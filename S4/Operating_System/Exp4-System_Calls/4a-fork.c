/*
ALGORITHM:
STEP 01: Include the necessary header files
STEP 02: Use the fork() system call to create a new process
STEP 03: Check the return value of fork():
        -   If the value is 0, it is the child process
        -   If the value is greater than 0, it is the parent process
        -   If the value is less than 0, process creation failed
STEP 04: Print the Process for both parent and child
STEP 05: STOP
*/
//CODE:
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

void main()
{
    pid_t pid;
    pid = fork();
    if (pid < 0)
        printf("Process creation failed\n");
    else if (pid == 0)
        printf("Child Process ID : %d\n", getpid());
    else
        printf("Parent Process ID : %d\n", getpid());
}
/*
OUTPUT:
Parent Process ID : 2964
Child Process ID : 2965
*/