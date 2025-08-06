/*
ALGORITHM:
STEP 01: START
STEP 02: Generate a unique key using function ftok()
STEP 03: Create a shared memory segment using shmget and get an identifier for the shared memory segment
STEP 04: Attach to the shared memory segment created using shmat
STEP 05: Write the data to the reader to the shared memory segment created
STEP 06: Detach from the shared memory segment using shmdt()
STEP 07: STOP
*/
#include <stdio.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <string.h>

void main()
{
    key_t key = ftok("shmfile", 65);
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);
    char *str = (char *)shmat(shmid, NULL, 0);
    printf("Write Data: ");
    gets(str);
    printf("Data written in memory: %s\n", str);
    shmdt(str);
}
/*
OUTPUT:
Write Data: Hello World
Data written in memory: Hello World
*/