#include<stdio.h>
#define max 100
int tree[max];
int count=0;
void insert(int value)
{
    if(count==max)
    {
        printf("Tree is full");
        return;
    }
    else{
        tree[count]=value;
        count++;
    }
}
int search(int value)
{
    int i;
    for(i=0;i<count;i++)
    {
        if(tree[i]==value)
        {
            return i;
        }
    }
    printf("Element not found");
    return -1;
}
void delete(int value)
{
    int i;
    int index=-1;
    for(i=0;i<count;i++)
    {
        if(tree[i]==value)
        {
            index= i;
        }
    }
    if(index==-1)
    {
        printf("Element not found");
    }
    else{
        tree[index]=tree[count-1];
        count--;
    }
}
void inorder(int index)
{
    if(index>=count)
    {
        return;//not enough elements 
    }
    else{
        inorder(2*index+1);
        printf("%d ",tree[index]);
        inorder(2*index+2);
    }
}
void preorder(int index)
{
    if(index>=count)
    {
         return;
    }
    else{
         printf("%d ",tree[index]);
        preorder(2*index+1);
        preorder(2*index+2);
    }
}
void postorder(int index)
{
    if(index>=count)
    {
       return;
    }
    else{
        
        postorder(2*index+1);
        postorder(2*index+2);
        printf("%d ",tree[index]);
    }
}
int main() {
    int choice, value;

    while (choice!=7) {
        printf("\n1. Insert\n");
        printf("2. Search\n");
        printf("3. Delete\n");
        printf("4. In-order traversal\n");
        printf("5. Pre-order traversal\n");
        printf("6. Post-order traversal\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                printf("Enter the value to search: ");
                scanf("%d", &value);
                int index = search(value);
                if (index == -1) {
                    printf("Value not found in the tree\n");
                } else {
                    printf("Value found at index %d\n", index);
                }
                break;
            case 3:
                printf("Enter the value to delete: ");
                scanf("%d", &value);
                delete(value);
                break;
            case 4:
                printf("In-order traversal: ");
                inorder(0);
                printf("\n");
                break;
            case 5:
                printf("Pre-order traversal: ");
                preorder(0);
                printf("\n");
                break;
            case 6:
                printf("Post-order traversal: ");
                postorder(0);
                printf("\n");
                break;
            case 7:
                printf("Exited");
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
