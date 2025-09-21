#include <stdio.h>
#include <string.h>
#include "indexed.h"

#define DISK_SIZE 20

typedef struct {
    char fname;
    int idx_blk;
    int d_blks[DISK_SIZE];
    int cnt;
    int usd;
} IndexedFile;

int i_disk[DISK_SIZE];
IndexedFile i_files[DISK_SIZE];

void init_indexed() {
    memset(i_disk, 0, sizeof(i_disk));
    memset(i_files, 0, sizeof(i_files));
}

void create_file_indexed(char fname, int sz) {
    int idx_blk = -1;

    for (int i = 0; i < DISK_SIZE; i++) {
        if (i_disk[i] == 0) {
            idx_blk = i;
            break;
        }
    }

    if (idx_blk == -1) {
        printf("No free block for index block of file %c\n", fname);
        return;
    }

    int blk_cnt = 0;
    int tmp_blks[DISK_SIZE];

    for (int i = 0; i < DISK_SIZE && blk_cnt < sz; i++) {
        if (i_disk[i] == 0 && i != idx_blk) {
            tmp_blks[blk_cnt++] = i;
        }
    }

    if (blk_cnt < sz) {
        printf("Not enough space for file %c\n", fname);
        return;
    }

    int f_slot = -1;
    for (int i = 0; i < DISK_SIZE; i++) {
        if (!i_files[i].usd) {
            f_slot = i;
            break;
        }
    }

    if (f_slot == -1) {
        printf("Directory full.\n");
        return;
    }

    i_disk[idx_blk] = 1;
    for (int i = 0; i < sz; i++) {
        i_disk[tmp_blks[i]] = 1;
        i_files[f_slot].d_blks[i] = tmp_blks[i];
    }

    i_files[f_slot].fname = fname;
    i_files[f_slot].idx_blk = idx_blk;
    i_files[f_slot].cnt = sz;
    i_files[f_slot].usd = 1;

    printf("File %c created.\n", fname);
}

void delete_file_indexed(char fname) {
    for (int i = 0; i < DISK_SIZE; i++) {
        if (i_files[i].usd && i_files[i].fname == fname) {
            i_disk[i_files[i].idx_blk] = 0;
            for (int j = 0; j < i_files[i].cnt; j++)
                i_disk[i_files[i].d_blks[j]] = 0;

            i_files[i].usd = 0;
            printf("File %c deleted.\n", fname);
            return;
        }
    }

    printf("File %c not found.\n", fname);
}

void display_indexed() {
    printf("\nIndexed Allocation:\n");
    printf("Filename\tIndexBlock\n");
    for (int i = 0; i < DISK_SIZE; i++) {
        if (i_files[i].usd) {
            printf("%c\t\t%d\n", i_files[i].fname, i_files[i].idx_blk);
        }
    }
}