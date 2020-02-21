#include<bits/stdc++.h>

using namespace std;


int find_expo(int number , int expo)
{
if(expo == 0)
return 1;
else
{

int half = find_expo(number , expo/2);
half = half *half;
if(expo%2) 
half = number *half;
return half;
}
}

int main()
{
cout<<"enter the number"<<endl;
int n;
cin>>n;
cout<<"enter exponentiation"<<endl;
int expo;
cin>>expo;
int x = find_expo(n,expo);
cout<<"result is :"<<x;
}

