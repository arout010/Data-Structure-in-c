
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char postfix[20],infix[25],stack[20];
int top=-1;
void push(char symbol)
{
     //top=top+1;
     stack[++top]=symbol;
}
char pop()
{
     char item;
     if(top==-1)
     {
          printf("\n\nUnderflow:can't delete");
          return 0;
     }
     item=stack[top];
     top--;
     return(item);
}
void convert(char *infix,int l)
{
    int i,postfixIndex=-1;
    char item,x,symbol;
    for(i=0;i<l;i++)
     {
          symbol=infix[i];
         // printf("%c\t",symbol);
          if(symbol=='(')
          {
               push(symbol);

          }
          else if(symbol=='+' || symbol=='-' || symbol=='*' || symbol=='/')
          {
               push(symbol);
               //continue;
          }
          else if(symbol==')')
          {
               item=pop();
               while(item!='(')
               {
                    postfix[++postfixIndex]=item;
                    item=pop();
               }
              continue;
          }
          else
          {
               postfix[++postfixIndex]=symbol;
               continue;
          }
     }
     i=top;
     while(i>-1)
     {
          x=pop();
          postfix[++postfixIndex]=x;
          i--;
     }
}
int main()
{
     int length,i,postfixIndex=-1;
     char item,x;
     printf("\nEnter infix Expression: ");
     gets(infix);
     length=strlen(infix);
     printf("\ninfix is:");
     puts(infix);
     convert(infix,length);
     printf("postfix is:");
     puts(postfix);
     return 0;
}

