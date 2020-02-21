#include<bits/stdc++.h>

using namespace std;

void find_min(int arr[], int n)
{
int minimum,maximum;
if(arr[0] < arr[1])
{
minimum = arr[0];
maximum = arr[1];
}
else
{
minimum = arr[1];
maximum = arr[0];
}
int i;
for(i=2;i<n;i++)
{
if(arr[i] < arr[i+1])
{
if(arr[i] < minimum)
minimum = arr[i];
if(arr[i+1] > maximum)
maximum = arr[i+1];

}
else
{
if(arr[i] > maximum)
maximum = arr[i];
if(arr[i+1] < minimum)
minimum = arr[i+1];

}
i++;
}
cout<<"minimum element is : "<<minimum<<endl<<"maximum element is : "<<maximum<<endl;
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
return 0 ;
}

