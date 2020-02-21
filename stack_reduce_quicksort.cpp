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

int random_partition(int arr[],int lb , int ub)
{
int random = (rand() % (ub-lb+1))+lb;
int temp;
temp = arr[ub];
arr[ub] = arr[random];
arr[random] = temp;
partition(arr,lb,ub);
}



void reduce_stack(int arr[] , int lower ,int upper)
{
while(lower<upper)
{
int q = random_partition(arr,lower,upper);
if((q-lower) < (upper-q))
{
reduce_stack(arr,lower,q-1);
lower = q+1;
}
else
{
reduce_stack(arr,q+1,upper);
upper=q-1;
}
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
reduce_stack(arr,0,n-1);
cout<<endl;
cout<<"Array after sorting is :"<<endl;
for(i=0;i<n;i++)
cout<<arr[i]<<" ";
}

