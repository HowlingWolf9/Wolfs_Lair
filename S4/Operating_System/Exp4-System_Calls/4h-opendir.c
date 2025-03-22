/*
ALGORITHM:
STEP 01: Include the necessary header files
STEP 02: Use opendir() to open a directory
STEP 03: Check if the directory is opened successfully
STEP 04: STOP
*/
#include <stdio.h>
#include <dirent.h>

void main()
{
    DIR *dir =  opendir(".");
    if (dir == NULL)
        printf("Error opening directory\n");
    else
    {
        printf("Directory opened successfully\n");
        closedir(dir);
    }
}
/*
OUTPUT:
Directory opened successfully
*/