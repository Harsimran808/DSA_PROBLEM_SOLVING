#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
};
struct node*head;
void push()
{
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("Overflow");
    }
    else{
        int val;
        printf("Enter the element you want to push\n");
        scanf("%d",&val);
        if(head==NULL)
        {
            newnode->data=val;
            newnode->next=NULL;
            head=newnode;
        }
        else{
            newnode->data=val;
            newnode->next=head;
            head=newnode;
        }
    }
    
}
void pop()
{
    
    if(head==NULL)
    {
        printf("Underflow");
    }
    else{
        struct node*temp=head;
        head=head->next;
        free(temp);

    }
}
void display()
{
    struct node*temp=head;
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
}
int main()
{
    int choice;
    printf("Stack operations using linked list\n");
    while (choice != 4)
    {
        printf("Chose one from the below options...\n");
        printf("\n1.Push\n2.Pop\n3.Show\n4.Exit");
        printf("\n Enter your choice \n");
        scanf("%d", &choice);
        switch (choice)
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
        
            printf("Exiting....");
            break;
        
        default:
        
            printf("Please Enter valid choice ");
        }
        
    }
}