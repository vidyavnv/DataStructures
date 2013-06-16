using namespace std;
#include<iostream>
void build_heap(int *array);
void max_heapify(int *array,int i,int heap_size);
int maximum(int *array);
void increase_key(int *array,int i,int key);
int extract_maximum(int *array);
void insert_key(int *array,int key);
int left(int);
int right(int);
int parent(int);
int *array;
int n;
int main()
{
  int i;
  
  cout<<"No. of elements: ";
  cin>>n;
  
  array = new int[n];

  cout<<"Enter elements: ";
  for(i = 0;i < n;i++)
    cin>>array[i];
  
  build_heap(array);
  cout<<"Elements in heap: \n";
  for(i = 0;i<n;i++)
    cout<<array[i]<<endl;
  
  cout<<endl<<"maximum in the heap: "<<maximum(array);
  
  cout<<endl<<"After extraction: "<<extract_maximum(array);
  
  cout<<endl;
  for(i = 0;i<n;i++)
    cout<<array[i]<<endl;
  
  increase_key(array,8,15);
  cout<<endl<<"After increasing key: ";
  for(i = 0;i<n;i++)
    cout<<array[i]<<endl;
  
  cout<<endl<<"Inserting key";
  insert_key(array,20);
  for(i = 0;i<n;i++)
    cout<<array[i];
  
  return 0;
}
void build_heap(int *array)
{
  int i;
  for(i = n/2 - 1;i >= 0; i--)
     max_heapify(array,i,n);
}
void max_heapify(int *array,int i,int heap_size)
{ 
  int largest,temp,l,r;
  l = left(i);
  r = right(i);
  if(l < heap_size && array[l] > array[i])
       largest = l;
  else 
       largest = i;
  if(r < heap_size && array[r] > array[largest])
       largest = r;
  if(largest != i)
  {
    temp = array[i];
    array[i] = array[largest];
    array[largest] = temp;
    max_heapify(array,largest,heap_size);
  }
}

int maximum(int *array)
{
  int max;
  max =  array[0];
  return max;
}
int extract_maximum(int *array)
{
 if(n < 0)
   exit(0);
 int max;
 max = array[0];
 array[0] = array[n - 1];
 n = n - 1;
 max_heapify(array,0,n);
 return max;
}

void increase_key(int *array,int i,int key)
{
  if(key < array[i])
  {
    cout<<"new key small"<<endl;
    return ;
  }
  int temp;
  array[i] =  key;
  while(i > 0 && array[parent(i)] < array[i])
  {
    temp = array[i];
    array[i] = array[parent(i)];
    array[parent(i)] = temp;
    i = parent(i);
  }
}

void insert_key(int *array,int key)
{
  n = n + 1;
  array[n-1] = -32768;
  increase_key(array,n-1,key);
}
int left(int i)
{
    return (2*i + 1);        //book 2i
}

int right(int i)
{
  return (2*i + 2);           //book 2i+1
}

int parent(int i)
{
  if(i%2 == 0)
    return (i/2 - 1);
  else
    return (i/2);
}
