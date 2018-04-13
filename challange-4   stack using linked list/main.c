#include <stdio.h>
#include <stdlib.h>
struct node
{
     int data;
     struct node *next;
}*head=NULL;
void push(int x)
{
     struct node *temp;
     temp=(struct node *)malloc(sizeof(struct node));
     temp->data=x;
     temp->next=head;
     head=temp;
}
void peep()
{
     struct node *temp=head;
     printf("\nitems are:");
     if(temp == NULL)
     	{
     		printf("Empty stack");
		 }
     while(temp!=NULL)
     {
          printf("\n%d",temp->data);
          temp=temp->next;
     }
     printf("\n");
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
    int x,n,item,ch,i;
    while(1)
    {
         printf("\n\t\t\tenter choice\n");
         printf("1.push\n");
         printf("2.pop\n");
         printf("3.peep\n");
         printf("4.exit\n");
         scanf("%d",&ch);
         if(ch==1)
         {
                   printf("enter no:");
                   scanf("%d",&x);
                   push(x);
                    printf("numbers pushed successfully!!!!!!!");
         }
         if(ch==2)
         {
              int p;
              p=pop(n);
              if(p==1)
              {
                 printf("Error:under flow!!!");
              }
              else
               {
                 printf("\npop item:%d",p);
                 printf("\nnumbers poped successfully!!!!!!!");
               }
         }
         if(ch==3)
         {
              peep();
         }
         if(ch==4)
         {
              return 0;
         }
    }
    return 0;
}
