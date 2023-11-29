#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node
{
  int data;
  struct node *left;
  struct node *right;
};
typedef struct node node;
node *root=NULL;
node *create_node(int);
void insert(int);
node *delet(node *,int);
int search(int);
void printtree(node *,int);
void inorder(node *);
void postorder();
void preorder();
node *smallest_node(node *);
node *largest_node(node *);
int get_data();
int main()
{
 int userChoice;
 int userActive='y';
 int data;
 node *result=NULL;
 clrscr();
 while(userActive=='y'||userActive=='Y')
 {
   printf("\n\nOpertion of Binary Search....\n");
   printf("\n 1.Insertion");
   printf("\n 2.Deletion");
   printf("\n 3.Searching");
   printf("\n 4.Get Largest Data");
   printf("\n 5.Get Smallest Data");
   printf("\n 6.Print the tree");
   printf("\n------Traversal------");
   printf("\n 7.Preorder");
   printf("\n 8.Inorder");
   printf("\n 9.Postorder");
   printf("\n 10.Exit");
   printf("\n Enter your choice:");
   scanf("%d",&userChoice);
   printf("\n");
   switch(userChoice)
   {
     case 1:data=get_data();
	    insert(data);
	    break;
     case 2:data=get_data();
	    root=delet(root,data);
	    printf("\n %d deleted",data);
	    break;
     case 3:data=get_data();
	    if(search(data)==1)
	    {
	      printf("\nData was found");
	    }
	    else
	    {
	      printf("\n Data not found");
	    }
	    break;
     case 4:result=largest_node(root);
	    if(result!=NULL)
	    {
	      printf("\n Largest Data:%d",result->data);
	    }
	    break;
     case 5:result=smallest_node(root);
	    if(result!=NULL)
	    {
	      printf("\n smallest Data:%d",result->data);
	    }
	    break;

     case 6:printf("\n Binary search tree:\n");
	    printtree(root,1);
	    break;
     case 7:printf("\n Preorder traversal:");
	    preorder(root,1);
	    break;
     case 8:printf("\n Inorder traversal:");
	    inorder(root);
	    break;
     case 9:printf("\n Postorder traversal:");
	    postorder(root);
	    break;
     case 10:exit(0);
	     break;
     default:printf("Invalid choice");
	     break;
   }
   printf("\nDo you want to continue?(y/n):");
   fflush(stdin);
   scanf("%c",&userActive);
 }
 return 0;
}
node *create_node(int data)
{
  node *new_node=(node *)malloc(sizeof(node));
  if(new_node==NULL)
  {
    printf("\n Memoryallocation failed");
    return NULL;
  }
  new_node->data=data;
  new_node->left=NULL;
  new_node->right=NULL;
  return new_node;
}
void insert(int data)
{
  node *temp,*prev;
  node *new_node=create_node(data);
  if(new_node!=NULL)
  {
    if(root==NULL)
    {
      root=new_node;
      printf("\n Data %d was inserted in Node",data);
      return;
    }
    temp=root;
    prev=NULL;
    while(temp!=NULL)
    {
      prev=temp;
      if(data>temp->data)
      {
	temp=temp->right;
      }
      else
      {
	temp=temp->left;
      }
    }
    if(data>prev->data)
    {
      prev->right=new_node;
    }
    else
    {
      prev->left=new_node;
    }
    printf("\n Data %d was inserted in node \n",data);
  }
}
node *delet(node *root,int key)
{
  node *temp;
  if(root==NULL)
  {
    return root;
  }
  if(key<root->data)
  {
    root->left=delet(root->left,key);
  }
  else if(key>root->data)
  {
    root->right=delet(root->right,key);
  }
  else
  {
    if(root->left==NULL)
    {
      node *temp=root->right;
      free(root);
      return temp;
    }
    else if (root->right==NULL)
    {
      node *temp=root->left;
      free(root);
      return temp;
    }
    temp=smallest_node(root->right);
    root->data=temp->data;
    root->right=delet(root->right,temp->data);
  }
  return root;
}
int search(int key)
{
  node *temp=root;
  while(temp!=root)
  {
    if(key==temp->data)
    {
      return 1;
    }
    else if(key>temp->data)
    {
      temp=temp->right;
    }
    else
    {
      temp=temp->left;
    }
  }
  return 0;
}
node *smallest_node(node *root)
{
  node * curr=root;
  while(curr!=NULL&&curr->left!=NULL)
  {
    curr=curr->left;
  }
  return curr;
}
node *largest_node(node *root)
{
  node *curr=root;
  while(curr!=NULL&&curr->right!=NULL)
  {
    curr=curr->right;
  }
  return curr;
}
void printtree(node *t,int level)
{
  int i;
  if(t!=NULL)
  {
    printtree(t->right,level+1);
    for(i=0;i<level;i++)
    {
      printf(" ");
    }
    printf("%d\n",t->data);
    printtree(t->left,level+1);
  }
}
void inorder(node *root)
{
  if(root==NULL)
  {
    return;
  }
  inorder(root->left);
  printf("\t%d",root->data);
  inorder(root->right);
}
void preorder(node *root)
{
  if(root==NULL)
  {
    return;
  }
  printf("\t%d",root->data);
  preorder(root->left);
  preorder(root->right);
}
void postorder(node *root)
{
  if(root==NULL)
  {
    return;
  }
  postorder(root->left);
  postorder(root->right);
  printf("%d",root->data);
}
int get_data()
{
  int data;
  printf("\n Enter data:");
  scanf("%d",&data);
  return data;
}

