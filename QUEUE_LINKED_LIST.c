#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
};
struct node*head=NULL;
struct node*front;
struct node*rear;
void enqueue()
{
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    int val;
    if(newnode==NULL)
    {
        printf("Overflow");
        return ;
    }
    else{
        printf("Enter the value to enqueue\n");
        scanf("%d",&val);
        newnode->data=val;
        if(rear==NULL)
        {
            rear=front=newnode;
            rear->next=NULL;
            front->next=NULL;
        }
        else{
            rear->next=newnode;
            rear=newnode;
            rear->next=NULL;
        }
    }

}
void dequeue()
{
    struct node*temp;
    if(front==NULL)
    {
        printf("Underflow");
        return ;
    }
    else{
        printf("Dequeued value is %d\n",front->data);
        temp=front;
        front=front->next;
        free(temp);

    }
}
void display()  
{  
    struct node *ptr; 
    ptr = front;      
    if(front == NULL) 
    {  
        printf("\nEmpty queue\n");  
    }  
    else  
    {   printf("\nprinting values .....\n");  
        while(ptr != NULL)     
        {  
            printf("\n%d\n",ptr -> data);   
            ptr = ptr -> next; 
        }  
    }  
}
void main ()  
{  
    int choice;   
    while(choice != 4)   
    {     
        printf("\n1.enqueue\n2.dequeue\n3.Display the queue\n4.Exit\n");  
        printf("\nEnter your choice ?");  
        scanf("%d",& choice);  
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
            exit(0);  
            break;  
            default:   
            printf("\nEnter valid choice??\n");  
        }  
    }  
}  