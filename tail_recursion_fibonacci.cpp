#include<bits/stdc++.h>

using namespace std;

int fibo(int n,int a, int b)
{
if(n==0)
return a;
if(n==1)
return b;
else
return fibo(n-1,b,a+b);
}

int main()
{
cout<<"enter number";
int n;
cin>>n;
int result;
result = fibo(n,0,1);
cout<<result;
}
