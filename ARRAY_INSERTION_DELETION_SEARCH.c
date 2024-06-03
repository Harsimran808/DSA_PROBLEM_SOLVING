#include <stdio.h>
int n;
int a[20];
int count=0;

int insert();
int insert()
{
    int ele,pos;
    printf("Enter the element to be inserted\n");
    scanf("%d",&ele);
    printf("Enter the index position where you want to insert the element\n");
    scanf("%d",&pos);
    int i;
    for(i=n;i>=pos;i--)
    {
        a[i+1]=a[i];
        a[i]=ele;
    }
    n=n+1;
}
int delete();
int delete(){
    int el;
    int po;
    printf("Enter the element you wwant to delete\n");
    scanf("%d",&el);
    for(int i=0;i<n;i++)
    {
        if(a[i]==el)
        {
            po=i;
        }
    }
    for(int i=po;i<n;i++)
    {
        a[i]=a[i+1];
    }
    n=n-1;
}
int search();
int search()
{
    int e,p;
    printf("Enter the element you want to search\n");
    scanf("%d",&e);
    for(int i=0;i<n;i++)
    {
        if(a[i]==e)
        {
            p=i;
            count++;
        }
    }
    if(count==0)
    {
        printf("Element not found\n");

    }
    else{
        printf("Element found at position %d\n",p);
    }
}
int display();
int display(){
    for(int i=0;i<n;i++)
    {
        printf("%d\n",a[i]);
    }
}
int main()
{
    printf("Enter the size of array\n");
    scanf("%d",&n);
    printf("Enter the array elements\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Array is\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    int choice;
    int d=0;
    while(d==0){
    printf("\n1.Insert\n2.Delete\n3.Search\n4.Display\n5.exit\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        insert();
        break;
        case 2:
        delete();
        break;
        case 3:
        search();
        break;
        case 4:
        display();
        break;
        case 5:
        d++;
        printf("Exiting..");
        break;
        default:
        printf("Invalid choice");
    }
    }
}