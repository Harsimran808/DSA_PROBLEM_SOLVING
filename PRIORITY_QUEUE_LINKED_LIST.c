#include<stdio.h>
#include<stdlib.h>
struct node{
    int priority;
    int data;
    struct node* next;
};
struct node*front;
void insert(int data,int priority)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("Overflow");
    }
    else{
        newnode->data=data;
        newnode->priority=priority;
        if(front==NULL || priority<front->priority)
        {
            newnode->next=front;
            front=newnode;
        }
        else{
            struct node*temp=front;
            while(temp->next!=NULL && temp->next->priority<=priority)
            {
                temp=temp->next;
            }
            newnode->next=temp->next;
            temp->next=newnode;
        }
    }
}
void del()
{
    struct node*temp;

    if (front == NULL)
            printf("Queue Underflow\n");
    else
    {
        temp = front;
        printf("Deleted item is %d\n", temp->data);
        front = front->next;
        free(temp);
    }
}
void display()
{
    struct node *ptr;
    ptr = front;
    if (front == NULL)
        printf("Queue is empty\n");
    else
    {
        printf("Queue is :\n");
        printf("Priority       Item\n");
        while (ptr!= NULL)
        {
            printf("%d        %d\n", ptr->priority, ptr->data);
            ptr = ptr->next;
        }
    }
}
int main()
{
    int choice, data, priority;
    do
    {
        printf("1.Insert\n");
        printf("2.Delete\n");
        printf("3.Display\n");
        printf("4.Quit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the data which is to be added in the queue : ");
            scanf("%d", &data);
            printf("Enter its priority : ");
            scanf("%d", &priority);
            insert(data, priority);
            break;
        case 2:
            del();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting\n");
            break;
        default:
            printf("Wrong choice\n");
        }
    } while (choice!= 4);

    return 0;
}