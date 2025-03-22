/*
ALGORITHM:
STEP 01: Include the necessary header files
STEP 02: Open a file using open()
STEP 03: Use close() to close the file descriptor
STEP 04: STOP
*/
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

void main()
{
    int fd = open("sample.txt", O_RDONLY);
    if (fd == -1)
        printf("Error opening file\n");
    else
    {
        close(fd);
        printf("File closed successfully\n");
    }
}
/*
OUTPUT:
File closed successfully
*/