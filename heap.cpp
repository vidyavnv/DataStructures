using namespace std;
#include<iostream>
void build_heap(int *array,int);
void max_heapify(int *array,int i,int heap_size);
int left(int);
int right(int);
int *array;
int main()
{
  int n,i;
  cout<<"No. of elements";
  cin>>n;
  array = new int[n];
  cout<<"Enter elements";
  for(i = 0;i < n;i++)
    cin>>array[i];
  build_heap(array,n);
  cout<<"Elements in heap: \n";
  for(i = 0;i<n;i++)
    cout<<array[i];
  return 0;
}
void build_heap(int *array,int n)
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


int left(int i)
{
    return (2*i + 1);        //book 2i
}

int right(int i)
{
  return (2*i + 2);           //book 2i+1
}
