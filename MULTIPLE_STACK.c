#include <stdio.h>
#define max 6
int stack[6];
int topA = -1, topB = max, val;
int pushA();
int pushA()
{

    if (topA == max / 2 - 1)
    {
        printf("OIverflow");
    }
    else
    {
        while (topA < max / 2 - 1)
        {
            topA++;
            printf("Enter the value to  be pushed in stack A\n");
            scanf("%d", &val);

            stack[topA] = val;
        }
    }
    for (int i = topA; i >= 0; i--)
    {
        printf("%d\n", stack[i]);
    }
}
int popA();
int popA()
{
    if (topA == -1)
    {
        printf("Underflow");
    }
    else
    {
        return stack[topA--];
    }
}
int pushB();
int pushB()
{

    if (topB == max / 2)
    {
        printf("Overfloe");
    }
    else
    {
        while (topB > max / 2)
        {
            topB--;
            printf("Enter the value to be pushed in stack B\n");
            scanf("%d", &val);
            stack[topB] = val;
        }
    }
    for (int i = topB; i < max; i++)
    {
        printf("%d\n", stack[i]);
    }
}
int popB();
int popB()
{
    if (topB == max)
    {
        printf("Underflow");
    }
    else
    {
        return stack[topB++];
    }
}
int displayFullArray();
int displayFullArray()
{
    int i;
    printf("Full Array is:\n");
    for (i = 0; i < max; i++)
    {
        printf("%d\n", stack[i]);
    }
}
int main()
{
    int choice;

    int d = 0;
    while (d == 0)
    {
        printf("\n1.pushA\n2.pushB\n3.popA\n4.popB\n5.display\n6.exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            pushA();
            break;
        case 2:
            pushB();
            break;
        case 3:
            printf("Popped element from A is %d\n", popA());
            break;
        case 4:
            printf("Popped element from B is %d\n", popB());
            break;
        case 5:
            displayFullArray();
            break;
        case 6:
            printf("Exit\n");
            d++;
            break;
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}