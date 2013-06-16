using namespace std;
#include<iostream>
int front = -1;
int rear = -1;
int push(int array[],int data);
int pop(int array[]);
void display(int array[]);

const int size = 7;
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
    if((front == 0 && rear == size - 1) || front == rear + 1)
      return 0;
    else if(front == -1)
    {
      front = 0;
      rear = 0;
      array[rear] = data;
    }
    else if(rear == size - 1)
    {
      rear = 0;
      array[rear] = data;
    }
    else
    {
      rear = rear + 1;
      array[rear] = data;
    }
    return 1;
}

int pop(int array[])
{
  int temp;
  if(front == -1)
   return -1;
  else
  {
     temp = array[front];
     if(front == rear)
       front=rear=-1;
     else if (front == size - 1)
       front = 0;
     else
     front = front + 1;
  }
  return temp;
}

void display(int array[])
{
  if(front == -1)
  {
    cout<<"Nothing to display"<<endl;
    exit(0) ;
  }
  else if(rear >= front)
  {
    for(int i = 0;i < front;i++)
       cout<<'-';
    cout<<">>>";
    for(int i = front;i <= rear;i++)
      cout<<array[i]<<"<-";
    cout<<"<<<";
  }
  else
  {
    for(int i = 0;i <= rear;i++)
      cout<<array[i]<<"<-";
    cout<<"<<<";
    for(int i = rear + 1;i<front;i++)
      cout<<'-';
    cout<<">>>";
    for(int i = front;i<size;i++)
      cout<<array[i]<<"<-";
  }
}


