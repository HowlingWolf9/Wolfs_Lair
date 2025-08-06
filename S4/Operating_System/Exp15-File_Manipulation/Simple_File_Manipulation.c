#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

int main() {
    DIR *dir;
    struct dirent *entry;
    struct stat statbuf;

    // List all files and directories in the current directory 
    //Not Importent
    printf("Contents of current directory:\n");
    if ((dir = opendir(".")) == NULL) {
        perror("opendir() error");
        return 1;
    }

    while ((entry = readdir(dir)) != NULL) {
        // Skip . and .. entries - Not importent
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        // Get file status
        if (stat(entry->d_name, &statbuf) == -1) {
            perror("stat() error");
            continue;
        }

        // Check if it's a directory
        if (S_ISDIR(statbuf.st_mode)) {
            printf("Directory: %s\n", entry->d_name);
        } else {
            printf("File:      %s\n", entry->d_name);
        }
    }
    closedir(dir);

    // Allow user to view a file's contents
    char filename[256];
    printf("\nEnter filename to view contents: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0';  // Remove trailing newline

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("fopen() error");
        return 1;
    }

    printf("\nContents of %s:\n", filename);
    char line[1024];
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }

    fclose(file);
    return 0;
}