#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 3
int stack[MAX_SIZE];
top=-1;
void push(int x)
{
     if(top>=MAX_SIZE-1)
     {
          printf("Error:over flow!!!!!!!!");
          return;
     }
     stack[++top]=x;
     printf("\n%d pushed successfully!!!!!\n",x);
}
void peep()
{
     int i;
     for(i=top;i>=0;i--)
     {
          printf("\n%d",stack[i]);
     }
}
void pop()
{
     if(top<0)
     {
          printf("Error:under flow!!!!!!!");
          return;
     }
     int n = stack[top];
     top--;
     printf("\nPoped Number is %d:\n",n);
}


int main()
{
   int x,ch;
   while(1)
   {
        printf("\nEnter choice...\n");
        printf("\n1.Push");
        printf("\n2.Pop");
        printf("\n3.Peep");
        printf("\n4.Exit\n");
        scanf("%d",&ch);
        if(ch==1)
        {
             printf("\nenter no:");
             scanf("%d",&x);
             push(x);
        }
        if(ch==2)
        {
            pop();
        }
        if(ch==3)
        {
             printf("\nNumbers are:\n");
             peep();
        }
        if(ch==4)
        {
             return;
        }

   }

    return 0;
}
