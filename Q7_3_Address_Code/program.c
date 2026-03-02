#include <stdio.h>
#include <string.h>
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
            printf("t%d = %c %c %c\n", temp, exp[i-1], exp[i], exp[i+1]);
            exp[i+1] = '0' + temp;
            temp++;
        }
    }
    // Process +, -
    for(i = 0; exp[i] != '\0'; i++) {
        if(exp[i] == '+' || exp[i] == '-') {
            printf("t%d = %c %c %c\n", temp, exp[i-1], exp[i], exp[i+1]);
            exp[i+1] = '0' + temp;
            temp++;
        }
    }
    // Final assignment
    printf("%c = t%d\n", exp[0], temp-1);
    return 0;
}
    
