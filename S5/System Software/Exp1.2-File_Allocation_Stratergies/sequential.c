#include <stdio.h>
#include <string.h>
#include "sequential.h"

#define DISK_SIZE 20

typedef struct {
    char filename;
    int start;
    int size;
    int used;
} SeqFile;

SeqFile files_seq[DISK_SIZE];
int disk_seq[DISK_SIZE];

void init_sequential() {
    memset(files_seq, 0, sizeof(files_seq));
    memset(disk_seq, 0, sizeof(disk_seq));
}

void create_file_sequential(char filename, int size) {
    for (int i = 0; i <= DISK_SIZE - size; i++) {
        int free = 1;
        for (int j = 0; j < size; j++) {
            if (disk_seq[i + j]) {
                free = 0;
                break;
            }
        }

        if (free) {
            for (int j = 0; j < size; j++)
                disk_seq[i + j] = 1;

            files_seq[i].filename = filename;
            files_seq[i].start = i;
            files_seq[i].size = size;
            files_seq[i].used = 1;
            printf("File %c created.\n", filename);
            return;
        }
    }

    printf("Not enough space for file %c\n", filename);
}

void delete_file_sequential(char filename) {
    for (int i = 0; i < DISK_SIZE; i++) {
        if (files_seq[i].used && files_seq[i].filename == filename) {
            for (int j = 0; j < files_seq[i].size; j++)
                disk_seq[files_seq[i].start + j] = 0;

            files_seq[i].used = 0;
            printf("File %c deleted.\n", filename);
            return;
        }
    }

    printf("File %c not found.\n", filename);
}

void display_sequential() {
    printf("\nSequential Allocation:\n");
    printf("Filename\tStart\tSize\n");
    for (int i = 0; i < DISK_SIZE; i++) {
        if (files_seq[i].used) {
            printf("%c\t\t%d\t%d\n", files_seq[i].filename, files_seq[i].start, files_seq[i].size);
        }
    }
}
