/* 
ALGORITHM:
STEP 01: Include the necessary header files
STEP 02: Use opendir() to open a directory
STEP 03: Use readdir() to read the contents of the directory
STEP 04: Print the names of the files in the directory
STEP 05: STOP
*/
#include <stdio.h>
#include <dirent.h>

void main()
{
    DIR *dir = opendir(".");
    if (dir == NULL)
        printf("Error opening directory\n");
    else
    {
        struct dirent *entry;
        while ((entry = readdir(dir)) != NULL)
            printf("%s\n", entry->d_name);
    }
}
/*
OUTPUT:
.
4i-readdir.c
4i-readdir
*/