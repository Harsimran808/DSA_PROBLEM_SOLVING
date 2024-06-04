#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int top=-1;
#define MAX 100

void push(char stack[], char c) {
    if (top == MAX - 1) {
        printf("Overflow\n");
        exit(1);
    }
    stack[++top] = c;
}

char pop(char stack[]) {
    if (top == -1) {
        printf("Underflow\n");
        exit(1);
    }
    return stack[top--];
}

void prefixtoinfix(char prefix[]) {
    int i, len;
    char stack[MAX];
    char temp[MAX];
    

    len = strlen(prefix);
    for (i = len - 1; i >= 0; i--) {
        if (isalnum(prefix[i])) {
            push(stack, prefix[i]);
        } else {
            char a = pop(stack);
            char b = pop(stack);
            sprintf(temp, "(%c %c %c)", a, prefix[i], b);
            strcat(stack, temp);
        }
    }

    printf("Infix expression: %s\n", stack);
}

int main() {
    char prefix[MAX];
    printf("Enter the prefix expression: ");
    scanf("%s", prefix);
    prefixtoinfix(prefix);
    return 0;
}