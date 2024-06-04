#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define max 100
int stack[max];
int top=-1;
int value;
void push(int value)
{
    if(top==max-1)
    {
        printf("Overflow");
    }
    else{
        top++;
        stack[top]=value;
    }
}
int pop()
{
    if(top==-1)
    {
        printf("Underflow");
        return -1;
    }
    else{
        return stack[top--];
    }
}
int postfixevaluation(char exp[])
{
    int i=0;
    int len=strlen(exp);
    for(i=0;i<len;i++)
    {
        if(isdigit(exp[i])||isalpha(exp[i]))
        {
            push(exp[i]-'0');//used to extract he ascii value 
        }
        else{
            int op2=pop();
            int op1=pop();
            switch(exp[i])
            {
                case '+':
                value=op1+op2;
                break;
                case '-':
                value=op1-op2;
                break;
                case '*':
                value=op1*op2;
                break;
                case '/':
                value=op1/op2;
                break;
                case '%':
                value=op1%op2;
                break;
                default:
                printf("Invalid choice\n");
            }
            push(value);
        }
    }
    return (pop());
}
int main()
{
    int val;
    char exp[max];
    printf("Enter the postfix expression\n");
    scanf("%s",exp);
    val= postfixevaluation(exp);
    printf("The calculation of above postfix evaluation is %d",val);
    return 0;
}