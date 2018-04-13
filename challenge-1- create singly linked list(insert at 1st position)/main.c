/******single linked list(insert at first)*********/
#include <stdio.h>
#include <stdlib.h>
struct node
{
     int data;
     struct node *next;
}*head;
void insert(int x)
{
     struct node *temp;
     temp=(struct node *)malloc(sizeof(struct node));
     temp->data=x;
     temp->next=head;
     head=temp;
}
void print()
{
      struct node *temp;
      printf("list are:");
      while(temp!=NULL)
      {
           printf("%d\n",temp->data);
           temp=temp->next;
      }
    return;
}
int main()
{
    head=NULL;
    int x,n,i;
    printf("\nHow many numbers:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
         printf("Enter no:");
         scanf("%d",&x);
         insert(x);
    }
     print();
    return 0;
}
