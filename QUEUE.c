#include<stdio.h>
int front=-1,rear=-1,max;
int queue[100];
void enqueue();
int dequeue();
void enqueue()
{
    int val;
    printf("Enter the value to be inserted: ");
    scanf("%d",&val);
    if(rear==max-1)
    {
        printf("Overflow");
    }
    else{
        rear++;
        queue[rear]=val;
    }
}
int dequeue(){
    if(front==rear)
    {
        printf("Underflow");
    }
    
    else{
        queue[front++];
    }
}
int display();
int display(){
    int i;
    for(i=front+1;i<=rear;i++)
    {
        printf("%d\n",queue[i]);
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
        printf("\n1.enqueue\n2.dequeue\n3.display\n4.exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            enqueue();
            break;
            case 2:
            dequeue();
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