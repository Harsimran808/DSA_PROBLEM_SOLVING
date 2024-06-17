#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define max 100
void postfixtoinfix(char source[],char target[])
{
    char temp[max],s[100][100];
    int len=strlen(source);
    int i=0,k=0;
    strcpy(target,"");
    for(i=0;i<len;i++)
    {
        if(isalpha(source[i]))
        {
            char t[]={source[i],'\0'};
            strcpy(s[k++],t);
        }
        else{
            char *op2=s[--k];
            char *op1=s[--k];
            sprintf(temp,"(%s%c%s)",op1,source[i],op2);
            strcpy(s[k++],temp);
        }
    }
    strcpy(target,s[--k]);
}
int main()
{
    char postfix[max];
    printf("Enter the postfix expression\n");
    scanf("%s",postfix);
    char infix[max];
    postfixtoinfix(postfix,infix);
    printf("Infix expression is %s\n",infix);
}
