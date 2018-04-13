#include <stdio.h>
#include <stdlib.h>
struct node
{
     int data;
     struct node *next;
     struct node *prev;
}*head=NULL;
void insert(int x)
{
     struct node *temp,*temp2;
     temp=(struct node *)malloc(sizeof(struct node));
     temp->data=x;
     temp->next=NULL;
     temp->prev=NULL;
/***insert at 1st position****/
     if(head==NULL)
     {
          head=temp;
          return;
     }
/***insert at one aftre  another****/
     temp2=head;
     while(temp2->next!=0)
     {
          temp2=temp2->next;
     }
     temp2->next=temp;
     temp->prev=temp2;
     temp->next=NULL;

}
void display()
{
     struct node *temp=head;
     printf("elements are:");
     while(temp!=0)
     {
          printf("\n%d",temp->data);
          temp=temp->next;
     }
}
int deleteitem(int n)
{
     struct node *temp=head,*temp1,*temp2;
     int i;
/***delete at 1st position****/
     if(n==1)
     {
         head=temp->next;
         return &temp->data;
         temp1=head;
         temp1->prev=NULL;
         free(temp1);
         return;

     }
/***delete at any position****/
          for(i=0;i<n-2;i++)
          {
               temp=temp->next;
          }
          temp1=temp->next;
/***delete at last position****/
          if(temp1->next==NULL)
          {
               temp1->prev=NULL;
               temp->next=NULL;
               return &temp1->data;
               free(temp1);
          }
          temp->next=temp1->next;

          temp2=temp1->next;
          temp2->prev=temp;

          return &temp1->data;
          free(temp1);
}
void reverse()
{
     struct node *temp=head;
     if(temp==0)
          return;
     while(temp->next!=0)
     {
          temp=temp->next;
     }
     printf("reverse:");
      while(temp!=0)
     {
          printf("\n%d",temp->data);
          temp=temp->prev;
     }
}
void insertipt(int x,int n)
{
      struct node *temp,*temp1=head,*temp2;
      int i;
      temp=(struct std *)malloc(sizeof(struct node));
      temp->data=x;
      temp->next=NULL;
      temp->prev=NULL;
/***insert at 1st position****/
      if(n==1)
      {
           temp->next=head;
           head=temp;
           return;
      }
		int j =0;
      for(i=0;i<n-2;i++)
      {
      	if( temp1=temp1->next)
      		j++;
      	else
      	{
      		printf("\nInvalid Position!!!!!!!!\n");
      		return 0;
		}
	  }
         
/***insert at last position****/
       if(temp1->next==NULL)
      {
         temp1->next=temp;
         temp->prev=temp1;
         return;
      }
/***insert at any position****/
      temp2=temp1->next;

      temp1->next=temp;
      temp2->prev=temp;

      temp->next=temp2;
      temp->prev=temp1;

}
void search(int x)
{
     int c=0,flag=1;
     struct node *temp=head;
     while(temp->next!=NULL)
     {
          c++;
          if(x == temp->data)
          {
               printf("item found at position %d",c);
              break;
          }
          temp=temp->next;
     }
    if(x!=temp->data)
      printf("item is not found");
}
void shorting()
{
     struct node *temp1,*temp2;

     for(temp1=head;temp1!=NULL;temp1=temp1->next)
     {
          for(temp2=temp1->next;temp2!=NULL;temp2=temp2->next)
          {
               if(temp1->data > temp2->data)
                    {
                         int t=temp1->data;
                         temp1->data=temp2->data;
                         temp2->data=t;
                    }
          }

     }
     display();
}
int main()

{
  int x,n,item,ch,i;
    while(1)
    {
         printf("\n\t\tMain Menu\n\n");
         printf("1.insert\n");
         printf("2.delete\n");
         printf("3.display\n");
         printf("4.insert at any position\n");
         printf("5.reverse\n6.search\n7.shorting\n8.exit\n");
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
              reverse();
         }
          else if(ch==6)
         {
              printf("enter no:");
              scanf("%d",&x);
             search(x);
         }
          else if(ch==7)
         {

             shorting(x);
         }
          else if(ch==8)
         {

             return;
         }



    }
   return 0;
}
