#include <iostream>
using namespace std;

void swap(int array[] , int i , int j)
{
    /*array[i] = array[i]+array[j];
    array[j] = array[i]-array[j];
    array[i] = array[i]-array[j];*/
    int temp;
    temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}
void MaxHeapify(int array[] , int i , int hSize)
{
    int l = 2*i;
    int r = 2*i+1;
    int largest;
    if(l<=hSize && array[l]>array[i])
    {
        largest = l;
    }
    else
    {
        largest = i;
    }
    if(r<=hSize && array[r]>array[largest])
    {
        largest = r;
    }
    if(largest != i)
    {
        swap(array , i , largest);
        MaxHeapify(array , largest , hSize);
    }
}

void BuildMaxHeap(int array[] , int hSize)
{
    for(int i=hSize/2 ; i>=1 ; i--)
    {
        MaxHeapify(array , i , hSize);
    }
}

void HeapSort(int array[] , int length)
{
    int hSize = length;
    BuildMaxHeap(array , hSize);
    for(int i=length ; i>=2 ; i--)
    {
        swap(array , 1 , i);
        hSize--;
        MaxHeapify(array , 1 , hSize);
    }
}
int main()
{
    int a[10]={4,2,6,7,0,3,8,1,9,5};
    HeapSort(a,10);
    for(int i=0 ; i<10 ; i++)
    {
        cout << a[i] << ' ';
    }
    return 0;
}


