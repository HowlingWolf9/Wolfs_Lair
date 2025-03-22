/*
ALGORITHM:
STEP 01: Include the necessary header files
STEP 02: Use stat() to get the file status
STEP 03: Print the file information like size and permission
STEP 04: STOP
*/
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

void main()
{
    struct stat fileStat;
    if (stat("sample.txt", &fileStat) < 0)
        printf("Error getting file status\n");
    else
    {
        printf("File Size: %ld bytes\n", fileStat.st_size);
        printf("Permission: %o\n", fileStat.st_mode);
    }
}
/*
OUTPUT:
File Size: 6 bytes
Permission: 100644
*/