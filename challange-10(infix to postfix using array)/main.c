#include <stdio.h>
#include <stdlib.h>
char postfix[30];
top=-1;
char stack[30];

void push(char x)
{
     stack[++top]=x;
}
char pop()
{
      if(top<0)
     {
          printf("Error:under flow!!!!!!!");
          return;
     }
     char n = stack[top];
     top--;
     return n;
}
int priority(char x)
{
     if(x=='(')
          return(0);
     if(x=='+'|| x=='-')
          return(1);
     if(x=='*' || x=='/' || x=='%')
          return(2);
}
void postfixf(char x)
{
     int i;
     do
     {
          i=0;
          postfix[i]=x;
          i++;
     }while(i<30);
}
void print()
{
     int i;
     while(postfix!='\0')
     {
          printf("%c",postfix[i]);
          i++;
     }
}
char isempty()
{
     if(top==-1)
          return(1);
}

int main()
{
     char exp[30],t,x,n;
     int i,l;
     printf("\nEnter expression:");
     scanf("%s",exp);
     l=strlen(exp);
     printf("%d",l);
     for(i=0;i<l;i++)
     {


          if(exp[i]=='(' || exp[i]=='+' || exp[i]=='-' || exp[i]=='*' || exp[i]=='/')
          {
                t=exp[i];
               push(t);
                 printf("%c",t);
          }
          else
          {
               if(exp[i]==')')
               {
                    while(x=pop()!='(')
                              printf("\n%c",x);
                         postfixf(x);
               }
               else
               {
                  while(priority(exp[i])<=priority(n=stack[top]) && !isempty())
                        {
                             x=pop();
                               printf("\n%c",x);
                             postfixf(x);
                        }
               }
          }
            printf("\n%c",t);
          postfixf(t);

     }
   print();
    return 0;
}
