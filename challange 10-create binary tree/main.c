#include <stdio.h>
#include <stdlib.h>
struct btree
{
     int data;
     struct btree *left;
     struct btree *right;
}*root=NULL;
void create(int x)
{
     struct btree *node=(struct btree *)malloc(sizeof(struct btree));
     node->data=x;
     node->left=NULL;
     node->right=NULL;

     if(root==NULL)
     {
          root=node;
          return;
     }
     else
     {
          struct btree *temp;
          temp=root;
          while(temp!=NULL)
          {
               if(temp->data >= node->data)
               {
                    if(temp->left==NULL){
                         temp->left=node;
                         return;}
                    temp=temp->left;
               }
               else if(temp->data <= node->data)
               {
                    if(temp->right==NULL){
                         temp->right=node;
                         return;}
                    temp=temp->right;
               }

          }
     }
}
/**preorder**/
void display(struct btree *temp)
{
     if(temp)
     {
          printf("%d,",temp->data);
          display(temp->left);
          display(temp->right);
     }
}
/**postorder**/
void displaypost(struct btree *temp)
{
     if(temp)
     {
          display(temp->left);
          display(temp->right);
          printf("%d,",temp->data);
     }
}
/**inorder**/
void displayin(struct btree *temp)
{
     if(temp)
     {
          display(temp->left);
          printf("%d,",temp->data);
          display(temp->right);
     }
}
int search(struct btree *temp,int x)
{
     int ans=0;
     if(temp==NULL)
          return ans;
     if(temp->data==x){
          ans=1;
          return(ans);}
    if(temp->data > x)
         ans=search(temp->left,x);
    if(temp->data < x)
         ans=search(temp->right,x);

     return(ans);
}
int main()
{
    int x,ch,n,i;
    while(1)
    {
         printf("\nenter choice..\n\n1.create a node\n2.display(inorder)\n3.display(preorder)\n4.display(post order)");
         printf("\n5.search\n6.Exit\n");
         scanf("%d",&ch);
         if(ch==1)
         {
              printf("\nenter how many numbers:");
              scanf("%d",&n);
              for(i=0;i<n;i++)
              {
                   printf("Enter no:");
                   scanf("%d",&x);
                   create(x);
              }
         }
          else if(ch==2)
         {
              displayin(root);
         }
         if(ch==3)
         {
              printf("\nPre order traversion of tree\n");
              display(root);
         }
         else if(ch==4)
         {
              printf("\nPost order traversion of tree\n");
              displaypost(root);
         }
        else if(ch==5)
         {
              printf("\nEnter no to be search:");
              scanf("%d",&x);
              int p=search(root,x);
              if(p==0)
                   printf("\nError:element is not found!!!!!!");
              else
                    printf("\nelement is founded!!!!!!");
         }

          if(ch==6)
         {
              return;
         }


    }
    return 0;
}
