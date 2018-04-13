#include <stdio.h>
#include <stdlib.h>
char stack[6];
int top=-1;
void push(char x)
{
     stack[++top]=x;
}
void pop(char x)
{
     if(x==')')
     {
          if(stack[top]=='(')
          {
               top--;
          }
     }
     else if(x=='}')
     {
          if(stack[top]=='{')
          {
               top--;
          }
     }
     else if(x==']')
     {
          if(stack[top]=='[')
          {
               top--;
          }
     }
}
void display()
{
     if(top==-1)
          printf("\nexpression is balanced!!!!\n");
     else
          printf("\nError:expression is not balanced!!!!\n");
}

int main()
{
     char ch[20],t;
     int i,length;
     printf("\nenter expression:");
     scanf("%s",ch);
     printf("\nexpression is:%s\n",ch);
     length=strlen(ch);

     for(i=0;i<length;i++)
     {
          if((ch[i]=='(') || (ch[i]=='[') || (ch[i]=='{'))
               {
                    t=ch[i];
                      push(t);
               }
          else if((ch[i]==')') ||(ch[i]==']') || (ch[i]=='}'))
               {
                    t=ch[i];
                      pop(t);
               }

     }
     display();

    return 0;
}
