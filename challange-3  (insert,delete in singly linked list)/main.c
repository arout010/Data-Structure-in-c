#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct node
{
     int data;
     struct node *next;
}*head=NULL;
void insert(int x)
{
     struct node *temp;
     temp=(struct node *)malloc(sizeof(struct node));
     temp->data=x;
     temp->next=NULL;

     if(head==NULL)
     {
          temp->next=head;
          head=temp;
          return;
     }

          struct node *temp2=head;
          while(temp2->next!=NULL)
          {
               temp2=temp2->next;
          }

          temp2->next=temp;

}
void insertipt(int x,int n)
{
     struct node *temp;
     temp=(struct node *)malloc(sizeof(struct node));
     temp->data=x;
     temp->next=NULL;

     if(n==1)
     {
          temp->next=head;
          head=temp;
          return;
     }
     int i,j=0;
     struct node *temp2=head;
     for(i=0;i<n-2;i++){
     	if(temp2=temp2->next)
     		j++;
     	else
     	{
     		printf("\ninvalid Position!!!!!!\n");
     		return 0;
		}
	 }
          
     temp->next=temp2->next;
     temp2->next=temp;
}

void display()
{
     struct node *temp=head;
     printf("\nitems are:");
     while(temp!=NULL)
     {
          printf("%d\t\t",temp->data);
          temp=temp->next;
     }
     printf("\n");
}
int deleteitem(int n)
{
     struct node *temp1=head,*temp2;

     if(n==1)
     {

          head=temp1->next;
          return &temp1->data;
          free(temp1);
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
          return &temp2->data;
          free(temp2);
     }
}
int main()
{
    int x,n,item,ch,i;
    while(1)
    {
         printf("\n\t\tEnter choice\n\n");
         printf("1.insert\n");
         printf("2.delete\n");
         printf("3.display\n");
         printf("4.insert at any position\n");
         printf("5.exit\n");
         printf("\nEnter choice: ");
         scanf("%d",&ch);
         if(ch==1)
         {
              printf("enter how many numbers you want to enter:");
              scanf("%d",&item);
              for(i=0;i<item;i++)
              {
                   printf("enter no:");
                   scanf("%d",&x);
                   insert(x);
              }
              printf("numbers entered successfully!!!!!!!");
         }
         if(ch==2)
         {
              int *j;
              printf("enter position of element you want to delete:");
              scanf("%d",&n);
              j=deleteitem(n);
              printf("deleted item is:%d",*j);

         }
         if(ch==3)
         {
              display();
         }
         if(ch==4)
         {
              printf("enter no:");
              scanf("%d",&x);
              printf("enter position of element you want to Insert:");
              scanf("%d",&n);
              insertipt(x,n);
         }
         else if(ch==5)
         {
              return 0;
         }

    }
    return 0;
}
