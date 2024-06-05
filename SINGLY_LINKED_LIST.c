#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *createnode(int data)
{
    struct node *newdata = (struct node *)malloc(sizeof(struct node));
    newdata->data = data;
    newdata->next = NULL;
    return newdata;
}
struct node *insertbegining(struct node *head, int data)
{
    struct node *newdata = createnode(data);
    newdata->next = head;
    head = newdata;
    return head;
}
struct node *insertend(struct node *head, int data)
{
    struct node *newdata = createnode(data);
    struct node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newdata;
    return head;
}
struct node *insertspecific(struct node *head, int data, int position)
{
    struct node *newdata = createnode(data);
    struct node *temp = head;
    int i;
    for (i = 0; i < position - 1 && temp->next != NULL; i++)
    {
        temp = temp->next;
    }
    newdata->next = temp->next;
    temp->next = newdata;
    return head;
}
struct node *delete(struct node *head, int key)
{
    if (head == NULL)
    {
        printf("Linked list is empty\n");
    }
    if (head->data == key)
    {
        struct node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    struct node *temp = head;
    while (temp->next != NULL)
    {
        if (temp->next->data == key)
        {
            struct node *del = temp->next;
            temp->next = del->next;
            free(del);
            return head;
        }
        temp = temp->next;
    }
    return head;
}
struct node *display(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main()
{
    struct node *head = NULL;
    int choice, data, position, key;
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
            scanf("%d", &data);
            head = insertbegining(head, data);
            break;
        case 2:
            printf("Enter the data: ");
            scanf("%d", &data);
            head = insertend(head, data);
            break;
        case 3:
            printf("Enter the data\n: ");
            scanf("%d", &data);
            printf("Enter the positon\n");
            scanf("%d", &position);
            head = insertspecific(head, data, position);
            break;
        case 4:
            printf("Enter the key to delete\n");
            scanf("%d", &key);
            head = delete (head, key);
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