#include <stdio.h>
#include <string.h>
#include "sequential.h"

#define DISK_SIZE 20

typedef struct {
    char fname;
    int st;
    int sz;
    int usd;
} SeqFile;

SeqFile s_files[DISK_SIZE];
int s_disk[DISK_SIZE];

void init_sequential() {
    memset(s_files, 0, sizeof(s_files));
    memset(s_disk, 0, sizeof(s_disk));
}

void create_file_sequential(char fname, int sz) {
    for (int i = 0; i <= DISK_SIZE - sz; i++) {
        int is_free = 1;
        for (int j = 0; j < sz; j++) {
            if (s_disk[i + j]) {
                is_free = 0;
                break;
            }
        }

        if (is_free) {
            for (int j = 0; j < sz; j++)
                s_disk[i + j] = 1;

            s_files[i].fname = fname;
            s_files[i].st = i;
            s_files[i].sz = sz;
            s_files[i].usd = 1;
            printf("File %c created.\n", fname);
            return;
        }
    }

    printf("Not enough space for file %c\n", fname);
}

void delete_file_sequential(char fname) {
    for (int i = 0; i < DISK_SIZE; i++) {
        if (s_files[i].usd && s_files[i].fname == fname) {
            for (int j = 0; j < s_files[i].sz; j++)
                s_disk[s_files[i].st + j] = 0;

            s_files[i].usd = 0;
            printf("File %c deleted.\n", fname);
            return;
        }
    }

    printf("File %c not found.\n", fname);
}

void display_sequential() {
    printf("\nSequential Allocation:\n");
    printf("Filename\tStart\tSize\n");
    for (int i = 0; i < DISK_SIZE; i++) {
        if (s_files[i].usd) {
            printf("%c\t\t%d\t%d\n", s_files[i].fname, s_files[i].st, s_files[i].sz);
        }
    }
}