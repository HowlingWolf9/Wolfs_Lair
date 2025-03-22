/*
ALGORITHM:
STEP 01: Include the necessary header files
STEP 02: Call the execvp() function with the name of a program and arguments
STEP 03: If execvp() fails, print an error message
STEP 04: STOP
*/
//CODE:
#include <stdio.h>
#include <unistd.h>

void main()
{
    char *args[] = {"ls", "-l", NULL};
    execvp("ls", args);
    printf("exec failed\n");
}
/*
OUTPUT:
total 40
-rwxr-xr-x 1 wolf wolf 16088 Feb 24 17:31 4a-fork
-rw-r--r-- 1 wolf wolf   803 Feb 24 17:32 4a-fork.c
-rwxr-xr-x 1 wolf wolf 16056 Mar 22 06:59 4b-exec
-rw-r--r-- 1 wolf wolf   372 Mar 22 06:59 4b-exec.c
*/