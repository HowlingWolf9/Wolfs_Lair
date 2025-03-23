/*
ALGORITHM:
STEP 01: Include the necessary header files
STEP 02: Call getpid() to get the process ID
STEP 03: Print the process ID
STEP 04: STOP
*/
//CODE:
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

void main()
{
    pid_t pid = getpid();
    printf("Process ID : %d\n", pid);
}
/*
OUTPUT:
Process ID : 5682
*/