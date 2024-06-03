#include<stdio.h>
void push();
void pop();
int display();
int stack[10];
int top=-1,i,max;
void push()
{
    int val;
    printf("Enter the value to be pushed\n");
    scanf("%d",&val);
    if(top==max-1)
    {
        printf("Overflow\n");
    }
    else{
        top++;
        stack[top]=val;
    }

}
void pop()
{
    if(top==-1)
    {
        printf("Underflow");
    }
    else{
        top--;
    }
}
int display(){
    for(i=top;i>=0;i--)
    {
        printf("%d\n",stack[i]);
    }
}
int main()
{
    printf("Enter the size of stack\n");
    scanf("%d",&max);
    int choice;
    int d=0;
    while(d==0)
    {
        printf("\n1.push\n2.pop\n3.display\n4.exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            push();
            break;
            case 2:
            pop();
            break;
            case 3:
            display();
            break;
            case 4:
            d++;
            printf("Exit\n");
            break;
            default:
            printf("Invalid choice");
        }
    }
    return 0;
}