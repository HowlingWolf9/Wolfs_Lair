#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Sym {
    char lab[10], loc[10];
};


int hexToDec(char *h)
{
    int n = 0;
    sscanf(h, "%x", &n);
    return n;
}

void decToHex(int n, char *h)
{
    sprintf(h, "%04X", n);
}

int searchOp(char *opcode)
{
    FILE *fp = fopen("optab.txt", "r");
    char op[10], code[10];
    while (fscanf(fp, "%s %s", op, code) != EOF && strcmp(op, "-"))
        if (!strcmp(op, opcode))
        {
            fclose(fp);
            return 1;
        }
    fclose(fp);
    return 0;
}

int searchSym(char *label)
{
    FILE *fp = fopen("symtab.txt", "r");
    char lab[10], loc[10];
    while (fscanf(fp, "%s %s", lab, loc) != EOF && strcmp(lab, "-"))
        if (!strcmp(lab, label))
        {
            fclose(fp);
            exit(1);
            return 1;
        }
    fclose(fp);
    return 0;
}

void insertSym(char *label, char *loc)
{
    struct Sym symbols[100];
    int count = 0;
    FILE *sym = fopen("symtab.txt", "r");
    while (fscanf(sym, "%s %s", symbols[count].lab, symbols[count].loc) != EOF)
        count++;
    fclose(sym);
    sym = fopen("symtab.txt", "w");
    fprintf(sym, "%s\t%s\n", label, loc);
    for (int i = 0; i < count; i++)
        fprintf(sym, "%s\t%s\n", symbols[i].lab, symbols[i].loc);
    fclose(sym);
}

int main()
{
    FILE *ip = fopen("input.txt", "r");
    FILE *im = fopen("intermediate.txt", "w");
    FILE *len = fopen("length.txt", "w");
    FILE *sym = fopen("symtab.txt", "w");
    fprintf(sym, "-\t-\n");
    fclose(sym);
    char label[20], opcode[20], operand[20], loc[10];
    int start = 0, locctr = 0, old;
    fscanf(ip, "%s %s %s", label, opcode, operand);
    if (!strcmp(opcode, "START"))
    {
        start = hexToDec(operand);
        locctr = start;
        fprintf(im, "-\t%s\t%s\t%s\n", label, opcode, operand);
        fscanf(ip, "%s %s %s", label, opcode, operand);
    }
    while (strcmp(opcode, "END"))
    {
        if (label[0] != '.')
        {
            if (strcmp(label, "-") && !searchSym(label))
            {
                decToHex(locctr, loc);
                insertSym(label, loc);
            }
            old = locctr;
            if (searchOp(opcode) || !strcmp(opcode, "WORD"))
                locctr += 3;
            else if (!strcmp(opcode, "RESW"))
                locctr += 3 * atoi(operand);
            else if (!strcmp(opcode, "RESB"))
                locctr += atoi(operand);
            else if (!strcmp(opcode, "BYTE"))
                locctr += strlen(operand);
            else
            {
                printf("Invalid opcode %s\n", opcode);
                exit(1);
            }
        }
        decToHex(old, loc);
        fprintf(im, "%s\t%s\t%s\t%s\n", loc, label, opcode, operand);
        fscanf(ip, "%s %s %s", label, opcode, operand);
    }
    decToHex(locctr, loc);
    fprintf(im, "%s\t%s\t%s\t%s\n", loc, label, opcode, operand);
    fprintf(len, "%d", locctr - start);
    printf("\nIntermediate file created.\nProgram length = %d\n", locctr - start);
    fclose(ip);
    fclose(im);
    fclose(len);
    return 0;
}