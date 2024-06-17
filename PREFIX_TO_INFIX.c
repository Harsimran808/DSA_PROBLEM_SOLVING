#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define max 100
void prefixtoinfix(char source[], char target[]) {
    int i=0; 
    int k=0;
    int len=strlen(source);
    char temp[100], s1[100][30];
    strcpy(target, "");
    for(i=len-1;i>=0;i--) {
        if (isalnum(source[i])) {
            char t[]={source[i],'\0'};
            strcpy(s1[k++], t);
            
        } else {
            char *op1 = s1[--k]; 
            char *op2 = s1[--k]; 
            sprintf(temp, "(%s%c%s)", op1, source[i], op2);
            strcpy(s1[k++], temp); 
            
        }
    } 
    strcpy(target, s1[--k]); 
}
int main()
{
    char prefix[max];
    printf("Enter the prefix expression\n");
    scanf("%s",prefix);
    char infix[max];
    prefixtoinfix(prefix,infix);
    printf("Infix expression is %s\n",infix);
}*/
