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
int prefixevaluation(char exp[])
{
    int i=0;
    int len=strlen(exp);
    for(i=len-1;i>=0;i--)
    {
        if(isdigit(exp[i])||isalpha(exp[i]))
        {
            push(exp[i]-'0');//used to extract he ascii value 
        }
        else{
            int op1=pop();
            int op2=pop();
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
    printf("Enter the prefix expression\n");
    scanf("%s",exp);
    val=prefixevaluation(exp);
    printf("The calculation of above prefix evaluation is %d",val);
    return 0;
}