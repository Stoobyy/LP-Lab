#include <stdio.h>
#include <string.h>

int main() {
    char exp[100];
    printf("Enter expression:\n");
    scanf("%s", exp);
    printf("\nInput: %s\n", exp);
    printf("Three Address Code:\n");

    char operands[20][10];
    char operators[20];
    int nOperands = 0, nOps = 0;
    int temp = 1;

    // Parse: skip "X=" at start, split into operands and operators
    int i, j = 0, k;
    for (i = 2; exp[i]; i++) {
        if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') {
            operands[nOperands][j] = '\0';
            nOperands++;
            operators[nOps++] = exp[i];
            j = 0;
        } else {
            operands[nOperands][j++] = exp[i];
        }
    }
    operands[nOperands][j] = '\0';
    nOperands++;

    // Process * and / first (higher precedence)
    for (i = 0; i < nOps; i++) {
        if (operators[i] == '*' || operators[i] == '/') {
            printf("t%d = %s %c %s\n", temp, operands[i], operators[i], operands[i + 1]);
            sprintf(operands[i], "t%d", temp++);
            // Remove used operand and operator
            for (k = i + 1; k < nOperands - 1; k++)
                strcpy(operands[k], operands[k + 1]);
            nOperands--;
            for (k = i; k < nOps - 1; k++)
                operators[k] = operators[k + 1];
            nOps--;
            i--;
        }
    }

    // Process + and -
    for (i = 0; i < nOps; i++) {
        printf("t%d = %s %c %s\n", temp, operands[i], operators[i], operands[i + 1]);
        sprintf(operands[i], "t%d", temp++);
        for (k = i + 1; k < nOperands - 1; k++)
            strcpy(operands[k], operands[k + 1]);
        nOperands--;
        for (k = i; k < nOps - 1; k++)
            operators[k] = operators[k + 1];
        nOps--;
        i--;
    }

    printf("%c = t%d\n", exp[0], temp - 1);
    return 0;
}
