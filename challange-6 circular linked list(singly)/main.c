#include <stdio.h>
#include <stdlib.h>
struct Node
{
     int data;
     struct Node *next;
}*head=NULL;

void insert(int x)
{
     struct Node *temp1=head,*temp;
     temp=(struct Node *)malloc(sizeof(struct Node));
     temp->data=x;
     temp->next=NULL;
     if(head==NULL)
     {
          head=temp;
          temp->next=head;
          return;
     }
     else
    {
         while(temp1->next!=head)
         {
              temp1=temp1->next;
         }

         temp1->next=temp;
         temp->next=head;
         return;
    }
}
void display()
{
     struct Node *temp=head;
     printf("\nitem's are:");
    if(head==NULL)
    {
        printf("Empty linked list\n");
        return;
    }
    else
    {
         while(temp->next!=head)
         {
              printf("\n%d",temp->data);
              temp=temp->next;
         }
         printf("\n%d",temp->data);
    }
}
void deleteNode(int n)
{
    struct Node *temp1=head,*temp2;
    if(temp1->next==head)
     {
         head=NULL;
         printf("\nDeleted item is : %d",temp1->data);
         free(temp1);
     }
    else if(n==1)
    {
        /////
        while(temp1->next!=head)
         {
              temp1=temp1->next;
         }
        /////
        temp1->next=head->next;
        temp2 = head;
        head = head->next;
        printf("Item deleted id %d",temp2->data);
        free(temp2);
        return;

    }
    else
    {

          int i;
          for(i=0;i<n-2;i++)
          {
               temp1=temp1->next;
          }
          temp2=temp1->next;
          temp1->next=temp2->next;
          printf("item deleted is %d",temp2->data);
          free(temp2);

    }

}
int main()
{
     int x,n,i,y,ch;
     while(1)
     {
         printf("\n\tMAIN MENU");
         printf("\n1.Insert");
         printf("\n2.Delete");
         printf("\n3.Display");
         printf("\n4.Exit");
         printf("\nEnter your choice:");
         scanf("%d",&ch);
         if(ch==1)
         {
              printf("enter no:");
              scanf("%d",&x);
              insert(x);
         }
         else if(ch==2)
         {
              printf("\nEnter Node no to be deleted:");
              scanf("%d",&y);
              deleteNode(y);
         }
         else if(ch==3)
         {
              display();
         }
         else if(ch==4)
         {
             return;
         }
         else
         {
             printf("\n\nInvalid choice.....");
         }
     }

    return 0;
}
