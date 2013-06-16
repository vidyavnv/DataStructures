using namespace std;

#include<iostream>

struct node{
             int index;
             node* link;
           }*front,*rear,*save,*ptr,*newptr;

node* create_node(int);
void push(node*);
void pop();
int display();

int main()
{
  
  int info,disp;
  char choice;
  front = NULL;
  rear = NULL;

  do
  {
    cout<<"\nEnter index for the node: ";
    cin>>info;
    newptr = create_node(info);
    if(newptr == NULL)
    {
      cout<<"\nNode can't be created";
      exit(0);
    }
    push(newptr);
    disp = display();
    if(disp == 0)
      cout<<"\nNo node to display";
    cout<<"\nDo you want to enter more code(y/n): ";
    cin>>choice;
  }while(choice == 'y');
  
  cout<<"\nDeleting a node:";
  do
  {
    pop();
    if(display() == 0)
    {
      cout<<"\nNo node to display";
      exit(0);
    }
    cout<<"\nDo you want to delete more nodes(y/n)?";
    cin>>choice;
  }while(choice=='y');
  
  return 0;
}
node *create_node(int data)
{
  newptr = new node;
  newptr -> index = data;
  newptr -> link = NULL;
  return newptr;
}

void push(node *ptr)
{
  if(front == NULL)
  {
    front = ptr;
    rear = ptr;
  }
  else
  {
    rear -> link = ptr;
    rear = ptr;
  }

    rear -> link = front;
}

void pop()
{
  if(front == NULL)
    cout<<"\nUnderflow";
  else if(front == rear)
  {
    front = NULL;
    rear = NULL;
    return;
  }
  else
  {
    save = front;
    front = front -> link;
    rear -> link = front;
    delete save;
  }
}

int display()
{
  if(front == NULL)
    return 0;
  else
  {
    ptr = front;
    while(ptr != rear)
    {
      cout<<ptr -> index<<" -> ";
      ptr = ptr -> link;
    }
    if(rear -> link != NULL)
     cout<<rear -> index<<" -> "<<rear -> link -> index;
    else
      cout<<rear -> index;
    cout<<'!';
    return 1;
  }
}
