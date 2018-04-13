/******single linked list(insert nth first)*********/
#include <stdio.h>
#include <stdlib.h>
struct node
{
     int data;
     struct node *next;
}*head;
void insert(int data1,int y)
{
     struct node *temp,*temp2;
     int i;
     temp=(struct node *)malloc(sizeof(struct node));
     temp->data=data1;
     temp->next=NULL;
     if(y==1)
     {
          temp->next=head;
          head=temp;
          return;
     }
     temp2=head;
     for(i=0;i<y-2;i++)
     {
          temp2=temp2->next;
     }
     temp->next=temp2->next;
     temp2->next=temp;
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
    int data1,n,i,y;
    printf("\nHow many numbers:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
         printf("Enter no:");
         scanf("%d",&data1);
         printf("Enter position:");
         scanf("%d",&y);

         insert(data1,y);
    }
     print();
    return 0;
}
