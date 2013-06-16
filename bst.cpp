using namespace std;

#include<iostream>

struct node{
             int index;
             //node* parent;
             node* left;
             node* right;
           }*root;

node* create_node(int);
void find(int,node**,node**);
void insert(int);
//void pop();
void display(node *);
void preorder(node *);
void inorder(node *);
void postorder(node *);
void delete_node(int);
int main()
{
  
  int info,disp;
  char choice;
  root = NULL;

  struct node *newptr;
  
  do
  {
    cout<<"\nEnter index for the node: ";
    cin>>info;
    insert(info);
    cout<<"\nDo you want to enter more code(y/n): ";
    cin>>choice;
  }while(choice == 'y');
  cout<<"\nEnter element to delete: ";
  cin>>info;
  delete_node(info);
  display(root);
  preorder(root);
  inorder(root);
  postorder(root);
  return 0;
}

node *create_node(int data)
{
  struct node *newptr;
  newptr = new node;
  newptr -> index = data;
 // newptr -> parent = NULL;
  newptr -> left = NULL;
  newptr -> right = NULL;
  return newptr;
}

void find(int item, struct node** par,struct node** loc)
{
  struct node *save,*ptr;
  if(root == NULL)
  {
    *loc = NULL;
    *par = NULL;
    return;
  }
  else if (root -> index == item)
  {
    *loc = root;
    *par = NULL;
    return;
  }
  else 
  {
    if(root -> index > item)
      ptr = root -> left;
    else
      ptr = root -> right;
    save = root;
    while(ptr!=NULL)
    {
      if(ptr -> index == item)
      {
        *loc = ptr;
        *par = save;
         return;
      }
      else if(ptr -> index > item)
      {
        save = ptr;
        ptr = ptr -> left;
      }
      else
      {
        save = ptr;
        ptr = ptr -> right;
      }
    }
      *par = save;
      *loc = NULL;
   }
}

void insert(int data)
{
  struct node *par,*loc,*new_ptr;
  find(data,&par,&loc);
  if(loc != NULL)
  {
    cout<<"Item already exists";
    return;
  }
  new_ptr = create_node(data);
  if(new_ptr == NULL)
  {
    cout<<"Sorry node can't be created";
    exit(0);
  }
  if((par) == NULL)
    root = new_ptr;
  else if((par) -> index > data)
    (par) -> left = new_ptr;
  else
    (par) -> right = new_ptr;
}

void delete_node(int data)
{
  struct node *suc,*parsuc,*ptr,*save,*par,*loc,*child;
  find(data,&par,&loc);
  if(loc == NULL)
  {
    cout<<"\nItem not present\n";
    return;
  }
  else
  {
    if(loc -> right != NULL && loc -> left != NULL)
    {
           ptr = loc -> right;
           save = loc;
           while(ptr -> left != NULL)
           {
             save = ptr;
             ptr = ptr -> left;
           }
           suc = ptr;
           parsuc = save;
           
           if(suc -> left == NULL && suc -> right == NULL)
                  child = NULL;
           else if(suc -> left != NULL)
                  child = suc -> left;
           else
                  child = suc -> right;
      
           if(par != NULL)
           {
                  if(suc = parsuc -> left)
                        parsuc -> left = child;
                  else
                        parsuc -> right = child;
           }
           else
                  root = child;
           
           if(par != NULL)
           {
                  if(loc == par -> left)
                        par -> left = suc;
                  else
                        par -> right = suc;
           }
           else
                  par = suc;
           
           suc -> left = loc -> left;
           suc -> right = loc -> right;
  }
    else
    {
      if(loc -> left == NULL && loc -> right == NULL)
        child = NULL;
      else if(loc -> left != NULL)
        child = loc -> left;
      else
        child = loc -> right;
      if(par != NULL)
      {
        if(loc == par -> left)
          par -> left = child;
        else
          par -> right = child;
      }
      else
        root = child;
    }
  }
}
/*void pop()
{
  if(top == NULL)
    cout<<"\nUnderflow";
  else
  {
    save = top;
    top = top -> link;
    delete save;
  }
} */
void display(node* nd)
{
      if (nd == NULL)
                return;
          /* display node data */
          printf("%d",nd->index);
              if(nd->left != NULL)
                        printf("(L:%d)",nd->left->index);
                  if(nd->right != NULL)
                            printf("(R:%d)",nd->right->index);
                      printf("\n");
                       
                          display(nd->left);
                              display(nd->right);
}

void preorder(node *p)
{
    if(p == NULL)
      return;
    else
    {
      cout<<p -> index<<endl;
      preorder(p -> left);
      preorder(p -> right);
    }
  }
void inorder(node *p)
{
    if(p == NULL)
      return;
    else
    {
      inorder(p -> left);
      cout<<p -> index<<endl;
      inorder(p -> right);
    }
  }
void postorder(node *p)
{
    if(p == NULL)
      return;
    else
    {
      postorder(p -> left);
      postorder(p -> right);
      cout<<p -> index<<endl;
    }
  }
/*void display(node* t,int level)
/*void display(node* t,int level)
/*void display(node* t,int level)
{
   int i;
    if(t!=NULL)
       {
           display(t->right, level+1);
             printf("\n");
               for(i=0;i<level;i++)
                    printf(" ");
                 printf("%d", t->index);
                   display(t->left, level+1);
                    }
}*/
/*void display(node *root,int level)
{
  int i;
  struct node *move = root;
  if(move == NULL)
  {
    cout<<"Nothing to display";
    exit(0);
  }
  else
  {
    while(move != NULL)
    {
      display(move -> right,level+1);
      printf("\n");
      for(i = 0;i<level;i++)
        printf("  ");
      printf("%d",move -> index);
      display(move -> left, level + 1);
    }
  }
} */
