#include <stdio.h>
#include "sequential.h"
#include "linked.h"
#include "indexed.h"

int main() {
    int ch, mthd;
    char fname;
    int sz;

    printf("\n1. Sequential\n2. Linked\n3. Indexed\nChoose method: ");
    scanf("%d", &mthd);

    if (mthd == 1) init_sequential();
    else if (mthd == 2) init_linked();
    else if (mthd == 3) init_indexed();
    else {
        printf("Invalid method chosen\n");
        return 1;
    }

    while (1) {
        printf("\nFile Allocation Menu\n");
        printf("1. Create File\n2. Delete File\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        if (ch == 4) break;

        switch (ch) {
            case 1:
                printf("Enter filename (A-Z): ");
                scanf(" %c", &fname);
                printf("Enter file size (blocks): ");
                scanf("%d", &sz);
                if (mthd == 1) create_file_sequential(fname, sz);
                else if (mthd == 2) create_file_linked(fname, sz);
                else create_file_indexed(fname, sz);
                break;
            case 2:
                printf("Enter filename (A-Z): ");
                scanf(" %c", &fname);
                if (mthd == 1) delete_file_sequential(fname);
                else if (mthd == 2) delete_file_linked(fname);
                else delete_file_indexed(fname);
                break;
            case 3:
                if (mthd == 1) display_sequential();
                else if (mthd == 2) display_linked();
                else display_indexed();
                break;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
