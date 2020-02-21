#include<bits/stdc++.h>

using namespace std;

int partition(int arr[] ,  int lb, int ub)
{
int pivot = arr[ub];
int i = lb-1;
int j;
int temp;
for(j=lb;j<ub;j++)
{
if(arr[j] <= pivot)
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

int rpartition(int arr[], int lb , int ub)
{
int num = (rand() % (ub - lb + 1)) + lb;
int temp;
temp = arr[ub]; 
arr[ub] = arr[num];
arr[num] = temp;
return partition(arr , lb, ub);
}

int iorder(int arr[] , int lb , int ub , int i)
{
if(ub < lb)
return 0;
else
{
 int q = rpartition(arr, lb, ub);
int abs = q-lb+1;
if(abs == i)
return arr[q];
if(i<abs)
return iorder(arr,lb,q-1,i);
if(i>abs)
return iorder(arr , q+1,ub,i-abs);
}
}

int main()
{
cout<<"enter size of array";
int n;
cin>>n;
int k;
int arr[n];
for(k=0;k<n;k++)
{
cin>>arr[k];
}
cout<<"enter the value of i (ith order static you want)";
int i;
cin>>i;
int x = iorder(arr,0,n-1,i);
cout<<x;
}
