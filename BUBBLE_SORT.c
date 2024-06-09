#include<stdio.h>
int main()
{
    int n,i;
    printf("Enter the size of array\n");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements of array\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("The array elements are\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    int j=0;
    int temp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])//ascending order
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }

printf("\nAscending order array is \n");
for(i=0;i<n;i++)
{
    printf("%d\t",a[i]);
}
}