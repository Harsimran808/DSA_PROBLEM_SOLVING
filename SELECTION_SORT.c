#include<stdio.h>
int main()
{
    int n,i;
    printf("Enter the size of array\n");
    scanf("%d",&n);
    int a[n];
    int temp;
    printf("Enter the elements of array\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Array elements are\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    int j;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i]>a[j])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    printf("\nArray elements after sorting in ascending order are\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}