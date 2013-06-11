using namespace std;
#include<iostream>
int top = -1;
int push(int array[],int data);
int pop(int array[]);
void display(int array[]);

const int size = 50;
int array[size];
int main()
{
  char choice;
  int index;
  int push_val,pop_val;
  do
  {
    cout<<"\nEnter information: ";
    cin>>index;
    push_val = push(array,index);
    if(push_val == -1)
    {
      cout<<"\nData cannot be entered";
      exit(0);
    }
    display(array);
    cout<<"\nDo you want to enter more elements: ";
    cin>>choice;
  }while(choice == 'y');
  
  cout<<"\nDeleting elements: ";
  do
  {
    pop_val = pop(array);
    if(pop_val == -1)
    {
      cout<<"\nNothing to delete";
      exit(0);
    }
    else
    {
      cout<<"\nDeleted element is:";
      cout<<pop_val<<endl;
    }
    display(array);
    cout<<"\nDo you want to delete more elements: ";
    cin>>choice;
  }while(choice == 'y');

  return 0;
}

int push(int array[],int data)
{
    if(top == size - 1)
      return 0;
    else
    {
      top = top + 1;
      array[top] = data;
    }
    return 1;
}

int pop(int array[])
{
  int temp;
  if(top == -1)
   return -1;
  else
  {
     temp = array[top];
     top = top - 1;
  }
  return temp;
}

void display(int array[])
{
  if(top == -1)
  {
    cout<<"Nothing to display"<<endl;
    exit(0) ;
  }
  cout<<array[top]<<"<--"<<endl;
  for(int i = top-1;i >= 0;i--)
     cout<<array[i]<<endl;
}

