#include <stdio.h>
#include <string.h>
#include "linked.h"

#define DISK_SIZE 20

typedef struct {
    char fname;
    int blks[DISK_SIZE];
    int cnt;
    int usd;
} LinkedFile;

int l_disk[DISK_SIZE];
LinkedFile l_files[DISK_SIZE];

void init_linked() {
    memset(l_disk, 0, sizeof(l_disk));
    memset(l_files, 0, sizeof(l_files));
}

void create_file_linked(char fname, int sz) {
    int f_idx = -1;

    for (int i = 0; i < DISK_SIZE; i++) {
        if (!l_files[i].usd) {
            f_idx = i;
            break;
        }
    }

    if (f_idx == -1) {
        printf("Directory full.\n");
        return;
    }

    int blk_cnt = 0;
    for (int i = 0; i < DISK_SIZE && blk_cnt < sz; i++) {
        if (l_disk[i] == 0) {
            l_disk[i] = 1;
            l_files[f_idx].blks[blk_cnt++] = i;
        }
    }

    if (blk_cnt < sz) {
        for (int i = 0; i < blk_cnt; i++) {
            l_disk[l_files[f_idx].blks[i]] = 0;
        }
        printf("Not enough space for file %c\n", fname);
        return;
    }

    l_files[f_idx].fname = fname;
    l_files[f_idx].cnt = sz;
    l_files[f_idx].usd = 1;
    printf("File %c created.\n", fname);
}

void delete_file_linked(char fname) {
    for (int i = 0; i < DISK_SIZE; i++) {
        if (l_files[i].usd && l_files[i].fname == fname) {
            for (int j = 0; j < l_files[i].cnt; j++) {
                l_disk[l_files[i].blks[j]] = 0;
            }
            l_files[i].usd = 0;
            printf("File %c deleted.\n", fname);
            return;
        }
    }

    printf("File %c not found.\n", fname);
}

void display_linked() {
    printf("\nLinked Allocation:\n");
    printf("Filename\tStart\tEnd\n");
    for (int i = 0; i < DISK_SIZE; i++) {
        if (l_files[i].usd) {
            printf("%c\t\t%d\t%d\n", l_files[i].fname, l_files[i].blks[0], l_files[i].blks[l_files[i].cnt - 1]);
        }
    }
}