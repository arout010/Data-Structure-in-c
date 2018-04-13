#include <stdio.h>
#include <stdlib.h>
struct node
{
     int data;
     struct node *next;
}*head=NULL;
void push(int x)
{
     struct node *temp,*temp1;
     temp=(struct node *)malloc(sizeof(struct node));
     temp->data=x;
     temp->next=NULL;

     if(head==NULL)
     {
          temp->next=head;
          head=temp;
     }
     else
     {
          temp1=head;
          while(temp1->next!=NULL)
               temp1=temp1->next;

          temp1->next=temp;
     }
}
void display()
{
     struct node *temp=head;
     int i=0;
     printf("\nfront>>");
     while(temp!=NULL)
     {
          i++;
          printf("\t%d",temp->data);
          temp=temp->next;
     }
     if(i==0)
          printf("Empty Queue!!!!");

      printf("\t<<[%d]rear",i);
}
int pop()
{
     struct node *temp1=head;

     if(temp1==NULL)
     {
          return 1;
     }
     else
     {
          head=temp1->next;
          return temp1->data;
          free(temp1);
     }

}

int main()
{

    int ch,x;
    while(1)
    {
         printf("\nEnter choice..");
         printf("\n1.push");
         printf("\n2.pop");
         printf("\n3.display");
         printf("\n4.exit\n");
         scanf("%d",&ch);
         if(ch==1)
         {
              printf("\nenter no:");
              scanf("%d",&x);
              push(x);
         }
         else if(ch==2)
         {
              int p;
              p=pop();
              if(p==1)
              {
                 printf("Error:under flow!!!");
              }
              else
               {
                 printf("\npop item:%d\n",p);
                 printf("\nnumbers poped successfully!!!!!!!\n");
               }
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
          printf("Invalid Choice!!!!");

    }
    return 0;
}
