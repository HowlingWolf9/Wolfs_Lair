#include <stdio.h>
#include <string.h>
#include "indexed.h"

#define DISK_SIZE 20

typedef struct {
    char filename;
    int index_block;
    int data_blocks[DISK_SIZE];
    int count;
    int used;
} IndexedFile;

int disk_indexed[DISK_SIZE];
IndexedFile files_indexed[DISK_SIZE];

void init_indexed() {
    memset(disk_indexed, 0, sizeof(disk_indexed));
    memset(files_indexed, 0, sizeof(files_indexed));
}

void create_file_indexed(char filename, int size) {
    int index_block = -1;

    // Find index block
    for (int i = 0; i < DISK_SIZE; i++) {
        if (disk_indexed[i] == 0) {
            index_block = i;
            break;
        }
    }

    if (index_block == -1) {
        printf("No free block for index block of file %c\n", filename);
        return;
    }

    int count = 0;
    int temp_blocks[DISK_SIZE];

    for (int i = 0; i < DISK_SIZE && count < size; i++) {
        if (disk_indexed[i] == 0 && i != index_block) {
            temp_blocks[count++] = i;
        }
    }

    if (count < size) {
        printf("Not enough space for file %c\n", filename);
        return;
    }

    // Find file slot
    int slot = -1;
    for (int i = 0; i < DISK_SIZE; i++) {
        if (!files_indexed[i].used) {
            slot = i;
            break;
        }
    }

    if (slot == -1) {
        printf("Directory full.\n");
        return;
    }

    disk_indexed[index_block] = 1;
    for (int i = 0; i < size; i++) {
        disk_indexed[temp_blocks[i]] = 1;
        files_indexed[slot].data_blocks[i] = temp_blocks[i];
    }

    files_indexed[slot].filename = filename;
    files_indexed[slot].index_block = index_block;
    files_indexed[slot].count = size;
    files_indexed[slot].used = 1;

    printf("File %c created.\n", filename);
}

void delete_file_indexed(char filename) {
    for (int i = 0; i < DISK_SIZE; i++) {
        if (files_indexed[i].used && files_indexed[i].filename == filename) {
            disk_indexed[files_indexed[i].index_block] = 0;
            for (int j = 0; j < files_indexed[i].count; j++)
                disk_indexed[files_indexed[i].data_blocks[j]] = 0;

            files_indexed[i].used = 0;
            printf("File %c deleted.\n", filename);
            return;
        }
    }

    printf("File %c not found.\n", filename);
}

void display_indexed() {
    printf("\nIndexed Allocation:\n");
    printf("Filename\tIndexBlock\n");
    for (int i = 0; i < DISK_SIZE; i++) {
        if (files_indexed[i].used) {
            printf("%c\t\t%d\n", files_indexed[i].filename, files_indexed[i].index_block);
        }
    }
}
