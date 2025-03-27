/*
ALGORITHM:
STEP 01: Include the necessary header files
STEP 02: Open a file using open()
STEP 03: Use read() to read the content of the file
STEP 04: Print the content read from the file
STEP 05: Close the file descriptor
STEP 06: STOP
*/
//CODE:
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

void main()
{
    int fd =  open("sample.txt", O_RDONLY);
    if (fd == -1)
        printf("Error opening file\n");
    else
    {
        char buffer[128];
        size_t bytesRead = read(fd, buffer, sizeof(buffer) - 1);
        if (bytesRead == -1)
            printf("Error reading file\n");
        else
        {
            buffer[bytesRead] = '\0';
            printf("Content of the file:\n%s\n", buffer);
        }
        close(fd);
    }
}
/*
OUTPUT:
Content of the file:
Hello this is a text file
*/