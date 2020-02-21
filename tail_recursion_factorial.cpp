#include<bits/stdc++.h>

using namespace std;

int fact(int n, int f)
{
if(n==1)
return f;
else
return fact(n-1 , n*f);
}

int main()
{
cout<<"enter number";
int n;
cin>>n;
int result;
result = fact(n, 1);
cout<<"result is : "<<result;
}
