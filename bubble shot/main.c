#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n,a[10],i,j;
    printf("How many numbers you want to enter:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
         printf("enter %d no:",i+1);
         scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
         for(j=0;j<n;j++)
         {
              if(a[i] < a[j])
              {
                   int temp=a[i];
                   a[i]=a[j];
                   a[j]=temp;
              }
         }
    }
    printf("\n::Assending order::::");
    for(i=0;i<n;i++)
    {
         printf("\nno[%d]:%d",i+1,a[i]);
    }

    return 0;
}
