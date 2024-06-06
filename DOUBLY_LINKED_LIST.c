#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *previous;
};
struct node *createnode(int value)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;
    newnode->previous = NULL;
    return newnode;
}
struct node *insertfirst(struct node *head, int value)
{
    struct node *newnode = createnode(value);
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {

        head->previous = newnode;
        newnode->next = head;
        head = newnode;
    }
    return head;
}
struct node *insertend(struct node *head, int value)
{
    struct node *newnode = createnode(value);
    struct node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->previous = temp;
    return head;
}
struct node *insertspecific(struct node *head, int value, int position)
{
    if (position == 0)
    {
        return insertfirst(head, value);
    }
    int i;
    struct node *newnode = createnode(value);
    struct node *temp = head;
    for (i = 0; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }
    newnode->next = temp->next;
    newnode->previous = temp;
    if (temp->next != NULL)
    {
        temp->next->previous = newnode;
    }
    temp->next = newnode;
    return head;
}
struct node *del(struct node *head, int key)
{
    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }
    struct node *temp = head;
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Key not found\n");
        return head;
    }
    if (temp->previous != NULL) {
        temp->previous->next = temp->next;
    } else {
        head = temp->next;
    }
    if (temp->next != NULL) {
        temp->next->previous = temp->previous;
    }
    free(temp);
    return head;
  }
    struct node *display(struct node * head)
    {
        struct node *temp = head;
        while (temp != NULL)
        {
            printf("%d->", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
        return head;
    }
    int main()
    {
        struct node *head = NULL;

        int choice, value, position, key;
        while (1)
        {
            printf("1. Insert at beginning\n");
            printf("2. Insert at end\n");
            printf("3. Insert at specific position\n");
            printf("4. delete a node\n");
            printf("5. Display linked list\n");
            printf("6. Exit\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);

            switch (choice)
            {
            case 1:
                printf("Enter the data: ");
                scanf("%d", &value);
                head = insertfirst(head, value);
                break;
            case 2:
                printf("Enter the data: ");
                scanf("%d", &value);
                head = insertend(head, value);
                break;
            case 3:
                printf("Enter the data\n: ");
                scanf("%d", &value);
                printf("Enter the positon\n");
                scanf("%d", &position);
                head = insertspecific(head, value, position);
                break;
            case 4:
                printf("Enter the key to delete\n");
                scanf("%d", &key);
                head = del(head, key);
                break;
            case 5:
                display(head);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
            }
        }
    }