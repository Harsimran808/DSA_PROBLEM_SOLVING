#include<stdio.h>
int max,rear=-1,front=-1;
int queue[100];
void enqueue();
void enqueue(){
    int val;
    printf("Enter the value to be inserted: ");
    scanf("%d",&val);
    if((rear+1)%max==front)
    {
        printf("Overflow");
    }
    else{
        if(front==-1){
            rear=front=0;
        }
        else{
            rear=(rear+1)%max;
        }
        queue[rear]=val;
    }
}
int dequeue();
int dequeue(){
    if(front==-1)
    {
        printf("underflow");
    }
    else{
        printf("%d element dequeued\n",queue[front]);
        if(front==rear)
        {
            front=rear=-1;
        }
        else{
            front=(front+1)%max;
        }
   }
}
int display();
int display()
{
    int i;
   if (front == -1) {
        printf("Queue is empty\n");
    } else {
        int i = front;
        printf("Queue elements: ");
        while (i != rear) {//while front not equals to zero as they coincid ein circular queue
            printf("%d ", queue[i]);
            i = (i + 1) % max;//circularly incrementing
        }
        printf("%d\n", queue[rear]);  // Display the last element separately
    } 
}
int main()
{
    printf("Enter the size of queue\n");
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