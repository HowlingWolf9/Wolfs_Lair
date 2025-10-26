#include <stdio.h>
#include <string.h>
struct mdt
{
    char lab[10], opc[10], oper[10];
} d[10];
int main()
{
    char label[10], opcode[10], operand[10], newlabel[10], newoperand[10];
    char macroname[10];
    int i, lines;
    FILE *f1, *f2, *f3;
    f1 = fopen("MACIN.txt", "r");
    f2 = fopen("MACOUT.txt", "w");
    f3 = fopen("MDT.txt", "w");
    fscanf(f1, "%s %s %s", label, opcode, operand);
    while (strcmp(opcode, "END") != 0)
    {
        if (strcmp(opcode, "MACRO") == 0)
        {
            strcpy(macroname, label);
            fscanf(f1, "%s%s%s", label, opcode, operand);
            lines = 0;
            while (strcmp(opcode, "MEND") != 0)
            {
                fprintf(f3, "%s\t%s\t%s\n", label, opcode, operand);
                strcpy(d[lines].lab, label);
                strcpy(d[lines].opc, opcode);
                strcpy(d[lines].oper, operand);
                fscanf(f1, "%s%s%s", label, opcode, operand);
                lines++;
            }
        }
        else if (strcmp(opcode, macroname) == 0)
        {
            printf("lines=%d\n", lines);
            for (i = 0; i < lines; i++)
            {
                fprintf(f2, "%s\t%s\t%s\n", d[i].lab, d[i].opc, d[i].oper);
                printf("DLAB=%s\nDOPC=%s\nDOPER=%s\n", d[i].lab, d[i].opc, d[i].oper);
            }
        }
        else
            fprintf(f2, "%s\t%s\t%s\n", label, opcode, operand);
        fscanf(f1, "%s%s%s", label, opcode, operand);
    }
    fprintf(f2, "%s\t%s\t%s\n", label, opcode, operand);
    fclose(f1);
    fclose(f2);
    fclose(f3);
    printf("FINISHED");
    return 0;
}