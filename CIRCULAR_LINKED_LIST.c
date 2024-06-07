#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;
struct node *createnode(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}
struct node *insertfirst(struct node *head, int data)
{
    struct node *newnode = createnode(data);
    if (head == NULL)
    {
        newnode->next = newnode;
        head = newnode;
    }
    else
    {
        struct node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        newnode->next = head;
        temp->next = newnode;
        head = newnode;
    }

    return head;
}
struct node *insertend(struct node *head, int data)
{
    struct node *newnode = createnode(data);
   
        struct node *temp = head;
        do
        {
            temp = temp->next;
        }while (temp->next != head);
        temp->next = newnode;
       newnode->next=head;
    
    return head;
}
struct node *del(struct node *head, int key)
{
    struct node *curr = head->next;
    struct node *prev = head;
    if (curr == head && curr->data == key)
    {
        free(curr);
        return NULL;
    }
    do
    {
        if (curr->data == key)
        {
            prev->next = curr->next;
            free(curr);
            break;
        }
        prev = curr;
        curr = curr->next;
    } while (curr != head->next);

    return head;
}
struct node *display(struct node *head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return head;
    }
    struct node *temp = head->next;
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head->next);
    printf("\n");
    return head;
}
int main()
{
    
    int choice, data, key;

    do
    {
        printf("\n1. Insert\n");
        printf("2. insert at end\n");
        printf("3. delete\n");
        printf("4. display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the element to insert: ");
            scanf("%d", &data);
            head = insertfirst(head, data);
            break;
        case 2:
            printf("Enter the element to insert at last: ");
            scanf("%d", &data);
            head = insertend(head, data);
            break;
        case 3:
            printf("Enter the element to delete: ");
            scanf("%d", &key);
            head = del(head, key);
            break;
        case 4:
            printf("The list is: ");
            display(head);
            break;
        case 5:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 5);

    return 0;
}
