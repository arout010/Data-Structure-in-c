#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char infix[20],prefix[20],stack[10];
int top=-1,prefixIndex=-1;
void push(char item)
{
     if(top > 9)
     {
          return;
     }
     stack[++top]=item;
}
char pop()
{
     char token;
     if(top==-1)
     {
          return;
     }
     token=stack[top];
     top--;
     return(token);
}

int main()
{
     int len,i,x;
     char symbol,item;
     printf("\nEnter infix: ");
     gets(infix);
     len=strlen(infix);
     for(i=0;i<len;i++)
     {
          symbol=infix[i];
          if(symbol=='+' || symbol=='-' || symbol=='*' || symbol=='/')
          {
               //push(symbol);
               prefix[++prefixIndex]=symbol;
               continue;
          }
          else if(symbol=='(')
          {
               push(symbol);
          }
          else if(symbol==')')
          {
               item=pop();
               while(item != '(')
               {
                     prefix[++prefixIndex]=item;
                     item=pop();
               }
               continue;
          }
          else
          {
               push(symbol);
          }

     }
     x=top;
     while(x >= 0)
     {
          item=pop();
          prefix[++prefixIndex]=item;
          x--;
     }
     printf("\nprefix:");
     puts(prefix);

     return 0;
}
