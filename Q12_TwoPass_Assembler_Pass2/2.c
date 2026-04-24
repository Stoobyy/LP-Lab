/*
 * Pass 2 of Two-Pass Assembler
 * Reads intermediate.txt + symtab.txt → prints object code (H, T, E records)
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Opcode table: mnemonic → machine code */
#define OPTAB_SIZE 5
char optab_mnem[OPTAB_SIZE][10] = {"LDA", "ADD", "SUB", "STA", "RSUB"};
char optab_code[OPTAB_SIZE][10] = {"00",  "18",  "1C",  "0C",  "4C"};

int main()
{
    FILE *finter, *fsym;
    char label[20], opcode[20], operand[20], progname[20];
    int  loc, len, start;
    int  j;

    /* Symbol table */
    char sym_label[20][20];
    int  sym_addr[20];
    int  sym_count = 0;

    fsym   = fopen("symtab.txt",       "r");
    finter = fopen("intermediate.txt", "r");

    /* Load all symbols from symtab.txt */
    while (fscanf(fsym, "%d %s %x", &j, sym_label[sym_count], &sym_addr[sym_count]) != EOF)
        sym_count++;

    /* Read first line of intermediate */
    fscanf(finter, "%x %d %s %s %s", &loc, &len, label, opcode, operand);

    if (strcmp(opcode, "START") == 0)
    {
        start = strtol(operand, NULL, 16);
        strcpy(progname, label);
        fscanf(finter, "%x %d %s %s %s", &loc, &len, label, opcode, operand);
    }

    /* Header record: H^ProgramName^StartAddress^ProgramLength */
    printf("H^%s^%06X^00001C\n", progname, start);

    /* Text record start */
    printf("T^%06X^13^", start);

    /* Process each line until END */
    while (strcmp(opcode, "END") != 0)
    {
        /* Look up opcode in optab */
        for (int i = 0; i < OPTAB_SIZE; i++)
        {
            if (strcmp(opcode, optab_mnem[i]) == 0)
            {
                /* Find operand address in symbol table */
                int address = 0;
                for (j = 0; j < sym_count; j++)
                {
                    if (strcmp(sym_label[j], operand) == 0)
                    {
                        address = sym_addr[j];
                        break;
                    }
                }
                /* Print: machine_code + 4-digit address */
                printf("%s%04X^", optab_code[i], address);
                break;
            }
        }

        /* BYTE directive: print hex of each character */
        if (strcmp(opcode, "BYTE") == 0)
        {
            for (int i = 2; i < (int)strlen(operand) - 1; i++)
                printf("%02X", operand[i]);
            printf("^");
        }

        /* WORD directive: print 6-digit hex value */
        if (strcmp(opcode, "WORD") == 0)
            printf("%06X^", atoi(operand));

        fscanf(finter, "%x %d %s %s %s", &loc, &len, label, opcode, operand);
    }

    /* End record */
    printf("\nE^%06X\n", start);

    fclose(finter);
    fclose(fsym);

    return 0;
}
