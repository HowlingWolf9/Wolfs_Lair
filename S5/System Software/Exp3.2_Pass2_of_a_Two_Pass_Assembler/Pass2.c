#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Sym {
    char lab[10], loc[10];
};

int getOpCode(char *opcode, char *code)
{
    FILE *fp = fopen("optab.txt", "r");
    char op[10], cd[10];
    while (fscanf(fp, "%s %s", op, cd) != EOF)
        if (!strcmp(op, opcode))
        {
            strcpy(code, cd);
            fclose(fp);
            return 1;
        }
    fclose(fp);
    return 0;
}

int getSymValue(char *label, char *value)
{
    FILE *fp = fopen("symtab.txt", "r");
    char lab[10], val[10];
    while (fscanf(fp, "%s %s", lab, val) != EOF)
        if (!strcmp(lab, label))
        {
            strcpy(value, val);
            fclose(fp);
            return 1;
        }
    fclose(fp);
    return 0;
}

int main()
{
    FILE *im = fopen("intermediate.txt", "r");
    FILE *obj = fopen("object.txt", "w");
    FILE *list = fopen("listing.txt", "w");
    FILE *lenf = fopen("length.txt", "r");
    int length;
    fscanf(lenf, "%d", &length);
    char lenstr[10];
    sprintf(lenstr, "%06X", length);
    fclose(lenf);
    char loc[10], label[20], opcode[20], operand[20];
    fscanf(im, "%s %s %s %s", loc, label, opcode, operand);
    char progname[20], startaddr[10];
    strcpy(progname, label);
    strcpy(startaddr, operand);
    if (!strcmp(opcode, "START"))
    {
        fprintf(list, "%s\t%s\t%s\t%s\n", loc, label, opcode, operand);
        fscanf(im, "%s %s %s %s", loc, label, opcode, operand);
    }
    fprintf(obj, "H^%s^%s^%s\n", progname, startaddr, lenstr);
    char textstart[10], textrec[1000] = "";
    int textlen = 0;
    strcpy(textstart, loc);
    while (strcmp(opcode, "END"))
    {
        char objcode[20] = "";
        if (label[0] != '.')
        {
            char opcd[10];
            if (getOpCode(opcode, opcd))
            {
                char addr[10] = "0000";
                if (strcmp(operand, "-"))
                {
                    if (!getSymValue(operand, addr))
                    {
                        printf("Undefined symbol %s\n", operand);
                    }
                }
                sprintf(objcode, "%s%s", opcd, addr);
            }
            else if (!strcmp(opcode, "WORD"))
            {
                int val = atoi(operand);
                sprintf(objcode, "%06X", val);
            }
            else if (!strcmp(opcode, "BYTE"))
            {
                if (operand[0] == 'C')
                {
                    char *s = operand + 2;
                    s[strlen(s) - 1] = 0;
                    for (size_t i = 0; s[i]; i++)
                        sprintf(objcode + strlen(objcode), "%02X", (unsigned char)s[i]);
                }
                else if (operand[0] == 'X')
                {
                    strcpy(objcode, operand + 2);
                    objcode[strlen(objcode) - 1] = 0;
                }
            }
            int objlen = strlen(objcode) / 2;
            if (textlen + objlen > 30)
            {
                fprintf(obj, "T^%s^%02X%s\n", textstart, textlen, textrec);
                strcpy(textstart, loc);
                strcpy(textrec, "");
                textlen = 0;
            }
            strcat(textrec, objcode);
            textlen += objlen;
        }
        fprintf(list, "%s\t%s\t%s\t%s\t%s\n", loc, label, opcode, operand, objcode);
        fscanf(im, "%s %s %s %s", loc, label, opcode, operand);
    }
    if (textlen > 0)
        fprintf(obj, "T^%s^%02X%s\n", textstart, textlen, textrec);
    fprintf(obj, "E^%s\n", startaddr);
    fprintf(list, "%s\t%s\t%s\t%s\n", loc, label, opcode, operand);
    fclose(im);
    fclose(obj);
    fclose(list);
    return 0;
}
