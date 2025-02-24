/*AIM: Write a C program to create a process in Linux
ALGORITHM:
STEP 01: START
STEP 02: Call fork() to create a child process
STEP 03: Assign fork() to a pid(data type:pid_t)
STEP 04: If fork() returns 0:
        -   Print "Child Process"
STEP 05: Else if fork() returns a positive value:
        -   Print "Parent Process"
STEP 06: Else Print "Fork Failed"
STEP 07: STOP
*/
//CODE:
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

void main()
{
    pid_t x = fork();
    if (x == 0)
        printf("Child Process created with Process ID = %d\n", getpid());
    else if (x > 0)
        printf("Parent Process ID = %d\n", getpid());
    else
        printf("Fork Failed\n");
}
/*
OUTPUT:
Parent Process ID = 5366
Child Process created with Process ID = 5367
*/