#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define max 100
int top = -1;
char stack[max];

void push(char c)
{
    if (top == max - 1)
    {
        printf("Overflow");
    }
    else
    {
        top++;
        stack[top] = c;
    }
}
char pop()
{
    if (top == -1)
    {
        printf("Underflow");
        return -1;
    }
    else
    {
        return stack[top--];
    }
}
int precedence(char c)
{
    switch (c)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return 0;
    }
}

void infixtopostfix(char infix[])
{
    char postfix[max];
    int i = 0, j = 0; // i for scanning infix and j for psotfix addition
    while (infix[i] != '\0')
    {
        if (isalpha(infix[i]) || isalnum(infix[i]))
        {
            postfix[j] = infix[i];
            i++;
            j++;
        }
        else if (infix[i] == '(')
        {
            push(infix[i]);
            i++;
        }
        else if (infix[i] == ')')
        {
            while (stack[top] != '(')
            {
                postfix[j] = pop();
                j++;
            }
            pop();
            i++;
        }
        else
        {
            while (top != -1 && precedence(infix[i]) <= precedence(stack[top]))
            {
                postfix[j] = pop();
                j++;
            }
            push(infix[i]);
            i++;
        }
    }
    while (top != -1)
    {
        postfix[j] = pop();
        j++;
    }
    postfix[j] = '\0';
    printf("%s is the postfix expression \n", postfix);
}

int main()
{
    char infix[max];
    printf("Enter the infix expression\n");
    scanf("%s", infix);
    infixtopostfix(infix);
    return 0;
}