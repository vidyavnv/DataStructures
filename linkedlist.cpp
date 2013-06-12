using namespace std;

#include<iostream>

struct node {
                int info;
                node *next;

}*save,*front,*rear,*newptr,*ptr;

node *create_node(int);
void front_insert_node(node*);
void rear_insert_node(node*);
void front_delete_node();
void value_delete_node(int);
void delete_duplicates(int);
int number_elements();
int display();

int main()
{
  int info,disp,option,value;
  char choice;
  front = NULL;
  rear = NULL;
  
  do
  {
     cout<<"\nEnter info: ";
     cin>>info;
     ptr = create_node(info);
     if(ptr==NULL)
     {
       cout<<"\nNode cannot be entered";
       break;
     }
    
     cout<<"\nDo you want to enter node at the beginning(1) / end(2): ";
     cin>>option;
     
     switch(option){

       case 1: front_insert_node(ptr);
               disp = display();
               if(disp == 0)
                   break;
               break;
       case 2: rear_insert_node(ptr);
               disp = display();
               if(disp == 0)
                   break;
               break;
       default: break;
     }
     
     cout<<"\nDo you want to insert more nodes (Y/N): ";
     cin>>choice;
  }while(choice=='y');
  
  disp = display();
  if(disp == 0)
    exit(0);
  
  cout<<"\nDelete a node: \n"; 
  cout<<"Menu:\n1.Front\n2.Given Value\n";
  cin>>option;
  
  switch(option){
        case 1: do
            {
               front_delete_node();
               disp = display();
               if(disp == 0)
                   break;
               cout<<"\nDo you want to delete a node(y/n): ";
               cin>>choice;
            }while(choice=='y');
            break;
        case 2: do
            {
               cout<<"\nEnter value to be deleted: ";
               cin>>value;
               value_delete_node(value);
               disp = display();
               if(disp == 0)
                   break;
               cout<<"\nDo you want to delete a node(y/n): ";
               cin>>choice;
            }while(choice=='y');
            break;
        default: break;
  }
  
  cout<<"\nRemoving duplicates: ";
  cin>>option;
  delete_duplicates(option);
  disp = display();
  cout<<"\nNumber of nodes in list are: "<<number_elements();
  return 0;

}

node *create_node(int data)
{
  newptr = new node;
  newptr -> info = data;
  newptr -> next = NULL;
  return newptr;
}

void rear_insert_node(node *ptr)
{
  if(front == NULL)
  {
    front = ptr;
    rear = ptr;
  }
  else
  {
    rear -> next = ptr;
    rear = ptr;
  }
}

void front_insert_node(node *ptr)
{
  if(front==NULL)
  {
    front = ptr;
    rear = ptr;
  }
  else
    {
      ptr -> next = front;
      front = ptr;
    }
}

int number_elements()
{
  int count = 0;
  if(front==NULL)
    return count;
  else
  {
    ptr = front;
    while(ptr!=NULL)
    {
      count++;
      ptr = ptr->next;
    }
    return count;
  }
}

int display()
{
  if(front==NULL)
  {
    cout<<"No node to display";
    return 0;
  }
  else
  {
    ptr = front;
    while(ptr != NULL)
    {
       cout<<ptr->info<<" -> ";
       ptr = ptr->next;
    }
    cout<<"!";
    return 1;
  }
}

void front_delete_node()
{
  if(front==NULL)
    cout<<"\nNothing to delete\n";
  else
  {
    ptr = front;
    front =  front -> next;
    delete[] ptr;
  }
}

void value_delete_node(int value)
{
  if(front==NULL)
    cout<<"\nNothing to delete\n";
  else if(front->info == value)
    front = front ->next;
  else
  {
    ptr = front;
    while((ptr->next->info) != value)
       ptr = ptr -> next;
    if(ptr->next->info == value)
    {
       ptr -> next = ptr -> next -> next;
    }
    else
      cout<<"No node of this value exists";
  }
}

/*void delete_duplicates(int value)
{
  if(front==NULL)
    cout<<"Nothing to delete\n";
  else if(front -> info == value)
  {
    while(front -> info == value)
    {
       ptr = front;
       front = front -> next;
       delete ptr;
    }
  }
  else
  {
    ptr = front;
    save = front;
    while(ptr != NULL)
    {
       if(ptr -> info != value)
       {
          save = ptr;
          ptr = ptr ->next;
       }
       else
       {
         save -> next = ptr -> next;
         newptr = ptr;
         ptr = ptr -> next;
         delete newptr;
       }
       ptr = ptr -> next;
    }
  }
}

*/
