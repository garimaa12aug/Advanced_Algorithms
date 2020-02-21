#include<bits/stdc++.h>

using namespace std;

int partition(int arr[], int lb , int ub)
{
int pivot = arr[ub];
int i,j,p,temp;
i = lb-1;
for(j=lb;j<ub;j++)
{
if(arr[j] < pivot)
{
i++;
temp = arr[i];
arr[i] = arr[j];
arr[j] = temp;

}
}
temp = arr[i+1];
arr[i+1] = pivot;
arr[ub] = temp;
return i+1;
}

void quicksort(int arr[] , int lower ,int upper)
{
if(lower<upper)
{
int q = partition(arr,lower,upper);
quicksort(arr,lower,q-1);
quicksort(arr,q+1,upper);
}
}

int main()
{
int n;
cout<<"enter number of elements in array";
cin>>n;
int i;
int arr[n];
for(i=0;i<n;i++)
{
cin>>arr[i];
}
quicksort(arr,0,n-1);
cout<<endl;
cout<<"Array after sorting is :"<<endl;
for(i=0;i<n;i++)
cout<<arr[i]<<" ";
}

