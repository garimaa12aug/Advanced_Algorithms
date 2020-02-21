#include<bits/stdc++.h>

using namespace std;

void max_heapify(int arr[] , int n , int i)
{
int l = 2*i+1;
int r = 2*i+2;
int largest = i;
if (l < n && arr[l] > arr[largest])
largest = l;
if (r < n && arr[r] > arr[largest])
largest = r;
int temp;
if(largest!=i)
{
temp =arr[i];
arr[i] = arr[largest];
arr[largest] = temp;
max_heapify(arr,n,largest);
}
}

void build_max_heap(int arr[], int n)
{
int i;
for(i= floor(n/2) ; i>=0;i--)
max_heapify( arr , n , i);
}

void heapsort(int arr[] , int n)
{
build_max_heap(arr,  n);
int i;
for(i = n-1;i>=0;i--) 
{
int temp;
temp = arr[0];
arr[0] = arr[i];
arr[i] = temp;
max_heapify(arr ,i,0);
}
}

void print_array(int arr[] , int n)
{
int i;
for(i=0;i<n;i++)
{
cout<<arr[i]<<" ";
}
cout<<endl;
}

void return_max(int arr[],int n)
{
build_max_heap(arr,n);
cout<<"Maximum element is : "<<arr[0]<<endl;
}

void extract_max(int arr[] , int n)
{
build_max_heap(arr,n);
int temp = arr[0];
arr[0] = arr[n-1];
max_heapify(arr, n-1,0);
cout<<"Maximum element extracted : "<<temp<<endl;
}

int findd(int arr[],int n, int x)
{
int i;
for(i=0;i<n;i++)
{
if(arr[i] == x)
return i;
break;
}
}

void increase_key(int arr[] , int i , int key)
{
if(key < arr[i])
cout<<"error: new key is smaller than current key";
arr[i] = key;
int parent = floor(i/2);
while(i>0 && arr[parent] < arr[i])
{
int temp = arr[i];
arr[i] = arr[parent];
arr[parent] = temp;
i = parent;
}
}

void insert_key(int arr[] , int n , int key)
{
arr[n] = -INFINITY;
increase_key(arr,n+1,key);
}

int main()
{
cout<<"enter number of elements in heap";
int n;
cin>>n;
int x;
int i;
int arr[n];
for(i=0;i<n;i++)
{
cin>>arr[i];
}
int k;
while(1)
{
cout<<"choose the operation\n";
cout<<"1. Insert key\n2. Increase key\n3. Extract Max\n4. Return max\n5. Sort\n6. Print array\n7. exit\n";
cin>>k;
switch(k)
{
case 1 : cout<<"enter key value";
int key;
cin>>key;
insert_key(arr,n,key);
case 2 : cout<<"enter new key value";
	int key_new, index;
	cin>>key_new;
	cout<<endl<<"enter old key value";
	int old_key;
	cin>>old_key;
	 index = findd(arr,n,old_key);
	increase_key(arr , index , key_new);
	break;

case 3 : extract_max(arr,n);
break;
case 4 : return_max(arr,n);
break;
case 5 : heapsort(arr,n);
cout<<"Heap sort applied successfully"<<endl;
break;
case 6 : print_array(arr , n);
break;
case 7 : exit(0);
 
}
}
}
