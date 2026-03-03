#include <stdio.h>
#include <string.h>
#include <ctype.h>

void printOperand(char c) {
    if(isdigit(c)) printf("t%c", c);
    else printf("%c", c);
}

int main() {
    char exp[100];
    printf("Enter expression:\n");
    scanf("%s", exp);
    int i, temp = 1;
    printf("\nInput: %s\n", exp);
    printf("Three Address Code:\n");
    // Process *, /
    for(i = 0; exp[i] != '\0'; i++) {
        if(exp[i] == '*' || exp[i] == '/') {
            printf("t%d = ", temp); 
            printOperand(exp[i-1]); 
            printf(" %c ", exp[i]); 
            printOperand(exp[i+1]); 
            printf("\n");
            exp[i-1] = '0' + temp; // convert number to string 
            exp[i+1] = '0' + temp;
            temp++;
        }
    }
    // Process +, -
    for(i = 0; exp[i] != '\0'; i++) {
        if(exp[i] == '+' || exp[i] == '-') {
            printf("t%d = ", temp); 
            printOperand(exp[i-1]); 
            printf(" %c ", exp[i]); 
            printOperand(exp[i+1]); 
            printf("\n");
            exp[i-1] = '0' + temp;
            exp[i+1] = '0' + temp;
            temp++;
        }
    }
    // Final assignment
    printf("%c = t%d\n", exp[0], temp-1);
    return 0;
}
    
