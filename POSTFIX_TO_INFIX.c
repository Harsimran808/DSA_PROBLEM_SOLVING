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

void postfixtoinfix(char postfix[]) {
    int i, len;
    char stack[MAX];
    char temp[MAX];
    

    len = strlen(postfix);
    for (i = 0; i <len; i++) {
        if (isalnum(postfix[i])) {
            push(stack, postfix[i]);
        } else {
            char b = pop(stack);
            char a = pop(stack);
            sprintf(temp, "(%c %c %c)", a, postfix[i], b);
            strcat(stack, temp);
        }
    }

    printf("Infix expression: %s\n", stack);
}

int main() {
    char postfix[MAX];
    printf("Enter the postfix expression: ");
    scanf("%s", postfix);
    postfixtoinfix(postfix);
    return 0;
}