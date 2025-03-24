/*
ALGORITHM:
STEP 01: Include the necessary header files
STEP 02: Use open() to open a file
         -  If the file does not exist, create it
STEP 03: Print the file descriptor returned by open()
STEP 04: STOP
*/
//CODE:
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

void main()
{
    int fd = open("sample.txt", O_RDWR | O_CREAT, 0644);
    if (fd == -1)
        printf("Error opening file\n");
    else
    {
        printf("File opened successfully with file descriptor: %d\n", fd);
        close(fd);
    }
}
/*
OUTPUT:
File opened successfully with file descriptor: 3
*/