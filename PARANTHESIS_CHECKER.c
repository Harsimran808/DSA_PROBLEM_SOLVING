#include<stdio.h>
#include<string.h>
#define max 100
int stack[max];
int top=-1,i;
void push(char);
char pop();
void push(char c)
{
    if(top==max-1)
    {
        printf("Overflow");
    }
    else{
        top++;
        stack[top]=c;
    }
}
char pop(){
    if(top==-1){
        printf("Underflow");
    }
    else{
         return stack[top--];
    }
}
int main()
{
    char exp[max],temp;
    int count =1;
    printf("Enter the paranthesised expression\n");
    scanf("%s",&exp);
    int a=strlen(exp);
    for(i=0;i<a;i++)
    {
        if(exp[i]=='('||exp[i]=='{'||exp[i]=='[')
        {
            push(exp[i]);
        }
        else if(exp[i]==')'||exp[i]=='}'||exp[i]==']')
        {
            if(top==-1)
            {
                count=0;
            }
            else{
                temp=pop();
            if(exp[i]==')'&& temp!='(')
            {
                count=0;
            }
            else if(exp[i]=='}'&& temp!='{')
            {
                count=0;
            }
            else if(exp[i]==']'&& temp!='[')
            {
                count=0;
            }
            }
        }
    }
    if(top>=0)
    {
        count = 0;
    }
    if(count==1)
    {
        printf("correctly paranthesised\n");
    }
    else{
        printf(" NOT Correctly paranthesised\n");
    }
}