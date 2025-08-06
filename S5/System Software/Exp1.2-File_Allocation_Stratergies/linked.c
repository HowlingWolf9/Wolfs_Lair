#include <stdio.h>
#include <string.h>
#include "linked.h"

#define DISK_SIZE 20

typedef struct {
    char filename;
    int blocks[DISK_SIZE];
    int count;
    int used;
} LinkedFile;

int disk_linked[DISK_SIZE];
LinkedFile files_linked[DISK_SIZE];

void init_linked() {
    memset(disk_linked, 0, sizeof(disk_linked));
    memset(files_linked, 0, sizeof(files_linked));
}

void create_file_linked(char filename, int size) {
    int found = 0, idx = -1;

    for (int i = 0; i < DISK_SIZE; i++) {
        if (!files_linked[i].used) {
            idx = i;
            break;
        }
    }

    if (idx == -1) {
        printf("Directory full.\n");
        return;
    }

    int count = 0;
    for (int i = 0; i < DISK_SIZE && count < size; i++) {
        if (disk_linked[i] == 0) {
            disk_linked[i] = 1;
            files_linked[idx].blocks[count++] = i;
        }
    }

    if (count < size) {
        // Rollback allocation
        for (int i = 0; i < count; i++) {
            disk_linked[files_linked[idx].blocks[i]] = 0;
        }
        printf("Not enough space for file %c\n", filename);
        return;
    }

    files_linked[idx].filename = filename;
    files_linked[idx].count = size;
    files_linked[idx].used = 1;
    printf("File %c created.\n", filename);
}

void delete_file_linked(char filename) {
    for (int i = 0; i < DISK_SIZE; i++) {
        if (files_linked[i].used && files_linked[i].filename == filename) {
            for (int j = 0; j < files_linked[i].count; j++) {
                disk_linked[files_linked[i].blocks[j]] = 0;
            }
            files_linked[i].used = 0;
            printf("File %c deleted.\n", filename);
            return;
        }
    }

    printf("File %c not found.\n", filename);
}

void display_linked() {
    printf("\nLinked Allocation:\n");
    printf("Filename\tStart\tEnd\n");
    for (int i = 0; i < DISK_SIZE; i++) {
        if (files_linked[i].used) {
            printf("%c\t\t%d\t%d\n", files_linked[i].filename, files_linked[i].blocks[0], files_linked[i].blocks[files_linked[i].count - 1]);
        }
    }
}
