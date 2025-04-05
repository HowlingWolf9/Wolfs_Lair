/*
ALGORITHM:
STEP 01: START
STEP 02: Generate a unique key using ftok()
STEP 03: Create a shared memory using shmget and get an identifier for the shared memory segment
STEP 04: Attach to the shared memory segment using shmat
STEP 05: Enter the data to the reader to the shared memory segment created
STEP 06: Detach from the shared memory segment using shmdt()
STEP 07: To destroy the shared memory call shmctl()
STEP 08: STOP
*/
#include <stdio.h>
#include <sys/shm.h>
#include <sys/ipc.h>

void main()
{
    key_t key = ftok("shmfile", 65);
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);
    char *str = (char *)shmat(shmid, (void *)0, 0);
    printf("Data read from memory: %s\n", str);
    shmdt(str);
    shmctl(shmid, IPC_RMID, NULL);
}
/*
OUTPUT:
Data read from memory: Hello World
*/