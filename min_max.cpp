#include<bits/stdc++.h>

using namespace std;

void find_min(int arr[], int n)
{
int min;
int i;
for(i=0;i<n;i++)
{
if(arr[i] < min)
min = arr[i];
}

cout<<"minimum element is : "<<min;
}

int main()
{

cout<<"enter number of elements in array";
int n;
cin>>n;
int arr[n];
int i;
for(i=0;i<n;i++)
{
cin>>arr[i];
}
find_min(arr,n);
}

