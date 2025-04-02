/*
ALGORITHM:
STEP 01: START
STEP 02: Include the necessary header files
STEP 03: Define the list_directory() function
STEP 04: Define the view_file() function
STEP 05: Define the replace_file() function
STEP 06: Define the main() function
STEP 07: Display menu options to the user
STEP 08: Read the user's choice
STEP 09: Call the appropriate function based on the user's choice
STEP 10: STOP
*/
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>

void list_directory() {
    DIR *dir;
    struct dirent *entry;
    struct stat statbuf;

    printf("\nCurrent Directory Contents:\n");
    if ((dir = opendir(".")) == NULL) {
        perror("opendir() error");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        if (stat(entry->d_name, &statbuf) == -1) {
            perror("stat() error");
            continue;
        }

        printf("%s\t\t[%s]\n", entry->d_name, S_ISDIR(statbuf.st_mode) ? "DIR" : "FILE");
    }
    closedir(dir);
}

void view_file() {
    char filename[256];
    printf("\nEnter filename to view: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0';

    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return;
    }

    printf("\n--- %s Contents ---\n", filename);
    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), file)) {
        printf("%s", buffer);
    }
    fclose(file);
}

void replace_file() {
    char filename[256];
    printf("\nEnter filename to replace: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0';

    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Error opening file");
        return;
    }

    printf("\nEnter new content (press Ctrl+D when done):\n");
    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), stdin)) {
        fputs(buffer, file);
    }
    
    clearerr(stdin);

    fclose(file);
    printf("\nFile '%s' updated successfully!\n", filename);
}

int main() {
    int choice;
    
    do {
        list_directory();
        printf("\nFile Operations:\n");
        printf("1. View File\n");
        printf("2. Replace File Contents\n");
        printf("3. Refresh Directory\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        
        char input[10];
        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("\nExiting...\n");
            exit(0);
        }
        
        if (sscanf(input, "%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            continue;
        }

        switch(choice) {
            case 1:
                view_file();
                break;
            case 2:
                replace_file();
                break;
            case 3:
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (1);

    return 0;
}
/*
OUTPUT:

Current Directory Contents:
15-File_Manipulation            [FILE]
15-File_Manipulation.c          [FILE]
sample.txt              [FILE]

File Operations:
1. View File
2. Replace File Contents
3. Refresh Directory
4. Exit
Enter choice: 1

Enter filename to view: sample.txt

--- sample.txt Contents ---
The quick brown fox jumped over a fence

Current Directory Contents:
15-File_Manipulation            [FILE]
15-File_Manipulation.c          [FILE]
sample.txt              [FILE]

File Operations:
1. View File
2. Replace File Contents
3. Refresh Directory
4. Exit
Enter choice: 2

Enter filename to replace: sample.txt

Enter new content (press Ctrl+D when done):
Hello World
File 'sample.txt' updated successfully!

Current Directory Contents:
15-File_Manipulation            [FILE]
15-File_Manipulation.c          [FILE]
sample.txt              [FILE]

File Operations:
1. View File
2. Replace File Contents
3. Refresh Directory
4. Exit
Enter choice: 3

Current Directory Contents:
15-File_Manipulation            [FILE]
15-File_Manipulation.c          [FILE]
sample.txt              [FILE]

File Operations:
1. View File
2. Replace File Contents
3. Refresh Directory
4. Exit
Enter choice: 1

Enter filename to view: sample.tx
Error opening file: No such file or directory

Current Directory Contents:
15-File_Manipulation            [FILE]
15-File_Manipulation.c          [FILE]
sample.txt              [FILE]

File Operations:
1. View File
2. Replace File Contents
3. Refresh Directory
4. Exit
Enter choice: 1   

Enter filename to view: sample.txt

--- sample.txt Contents ---
Hello World
Current Directory Contents:
15-File_Manipulation            [FILE]
15-File_Manipulation.c          [FILE]
sample.txt              [FILE]

File Operations:
1. View File
2. Replace File Contents
3. Refresh Directory
4. Exit
Enter choice: 4
Exiting...
*/