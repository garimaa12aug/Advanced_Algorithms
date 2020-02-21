#include<bits/stdc++.h>

using namespace std;


int euclids_hcf(int a,int b)
{
if(b==0)
return a;
else
return euclids_hcf(b, a%b);
}

int main()
{
cout<<"enter larger number";
int x,y;
cin>>x;
cout<<endl;
cout<<"enter smaller number";
cin>>y;
int result;
result = euclids_hcf(x,y);
cout<<endl<<"HCF of the two numbers is : "<<result;
}

