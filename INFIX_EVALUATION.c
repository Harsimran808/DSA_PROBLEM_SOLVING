#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define max 100
int operand[max];
char opr[max];
int topA = -1;
int topB = -1;
void pushoperand(int value)
{
    if(topA==max-1)
    {
        printf("Overflow");
        
    }
    topA++;
    operand[topA] = value;
}
int popoperand()
{
    if(topA==-1)
    {
        printf("Underflow");
        exit(1);
    }
    return operand[topA--];
}
void pushopr(char c)
{
    if(topB==max-1)
    {
        printf("Overflow");
    }
    topB++;
    opr[topB] = c;
}
char popopr()
{
    if(topB==-1)
    {
        printf("Underflow");
        exit(1);
    }
    return opr[topB--];
}
int precedence(char d)
{
    if (d == '+' || d == '-')
    {
        return 1;
    }
    else if (d == '*' || d == '/' || d == '%')
    {
        return 2;
    }
    else if (d == '^')
    {
        return 3;
    }
    else
    {
        return 0;
    }
}
int operation(char d, int op1, int op2)
{
    switch (d)
    {
    case '+':
        return op1 + op2;
       
    case '-':
        return op1 - op2;
        
    case '*':
        return op1 * op2;
        
    case '/':
        return op1 / op2;
        
    case '%':
        return op1 % op2;
        
    default:
        printf("Invalid choice");
    }
}
int infixevaluation(char exp[])
{
    int len;
    len = strlen(exp);
    int i;
    for (i = 0; i < len; i++)
    {
        if (isdigit(exp[i])||isalnum(exp[i]))
        {
            pushoperand(exp[i] - '0');
        }
        else if (exp[i] == '(')
        {
            pushopr(exp[i]);
        }
        else if (exp[i] == ')')
        {
            while (topB!=-1 && opr[topB] != '(')
            {
                char op = popopr();
                int op2 = popoperand();
                int op1 = popoperand();
                pushoperand(operation(op, op1, op2));
            }
            popopr();
        }
        else
        {
            while (topB != -1 && precedence(opr[topB]) >= precedence(exp[i]))
            {
                char op = popopr();
                int op2 = popoperand();
                int op1 = popoperand();
                pushoperand(operation(op, op1, op2));
            }
            pushopr(exp[i]);
        }
    }
    while (topB != -1)
    {
        char op = popopr();
        int op2 = popoperand();
        int op1 = popoperand();
        pushoperand(operation(op, op1, op2));
    }
    return popoperand();
}
int main()
{
    char exp[max];
    printf("Enter the expression: ");
    scanf("%s", exp);
    int result = infixevaluation(exp);
    printf("The result is: %d\n", result);
}