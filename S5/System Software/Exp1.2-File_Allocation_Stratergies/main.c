// main.c
#include <stdio.h>
#include "sequential.h"
#include "linked.h"
#include "indexed.h"

int main() {
    int choice, method;
    char filename;
    int size;

    init_sequential();
    init_linked();
    init_indexed();

    while (1) {
        printf("\nFile Allocation Menu\n");
        printf("1. Create File\n2. Delete File\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 4) break;

        printf("Choose method:\n1. Sequential\n2. Linked\n3. Indexed\n");
        scanf("%d", &method);

        switch (choice) {
            case 1:
                printf("Enter filename (A-Z): ");
                scanf(" %c", &filename);
                printf("Enter file size (blocks): ");
                scanf("%d", &size);
                if (method == 1) create_file_sequential(filename, size);
                else if (method == 2) create_file_linked(filename, size);
                else create_file_indexed(filename, size);
                break;
            case 2:
                printf("Enter filename (A-Z): ");
                scanf(" %c", &filename);
                if (method == 1) delete_file_sequential(filename);
                else if (method == 2) delete_file_linked(filename);
                else delete_file_indexed(filename);
                break;
            case 3:
                if (method == 1) display_sequential();
                else if (method == 2) display_linked();
                else display_indexed();
                break;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
