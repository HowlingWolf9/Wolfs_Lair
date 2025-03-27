/*
ALGORITHM:
STEP 01: Include the necessary header files
STEP 02: Open a file using open() using write permissions
STEP 03: Use write() to write data to the file
STEP 04: Print the number of bytes written to the file
STEP 05: Close the file descriptor
STEP 06: STOP
*/
//CODE:
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

void main()
{
    int fd = open("sample.txt", O_WRONLY | O_CREAT, 0644);\
    char buffer[] = "Hello this is a text file";
    size_t byteswritten = write(fd, buffer, sizeof(buffer) - 1);
    if (fd == -1)
        printf("Error opening file\n");
    else
    {
        printf("Number of bytes written : %ld\n", byteswritten);
        close(fd);
    }
}
/*
OUTPUT:
Number of bytes written : 25
*/