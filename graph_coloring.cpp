#include<bits/stdc++.h>

using namespace std;

/*
test for
0 1 1 1
1 0 1 0
1 1 0 1
1 0 1 0
*/

bool adj_matrix[10][10];
int color[10]={0};
int n;

bool all_colored()
{
int i;
for(i=1;i<=n;i++)
{
if(color[i] ==0)
return 0;
}
return 1;
}

bool is_safe(int vertex , int c)
{
int i;
for(i=1;i<=n;i++)
{
if(adj_matrix[vertex][i]==1 && color[i] == c)
return 0;
}
return 1;
}

bool solve_for(int vertex , int m)
{
if(all_colored())
return 1;
int c;
for(c=1;c<=m;c++)
{
if(is_safe(vertex,c))
{
color[vertex] = c;
bool answer;
answer = solve_for(vertex+1,m);
if(answer)
return answer;
color[vertex] = 0;
}
}
return 0;
}

void print_result()
{
int i;
cout<<"Solution is : "<<endl;
for(i=1;i<=4;i++)
cout<<color[i]<<" ";
}

int main()
{
cout<<"enter n";
cin>>n;
int i,j;
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
cin>>adj_matrix[i][j];
}
cout<<"enter next row";
}

int m;
int vertex=0;
bool ans;
for(m=1;m<=6;m++)
{
ans = solve_for(vertex,m);
if(ans)
{
cout<<"Solution exist for m = "<<m<<endl;
print_result();
break;
}
else
cout<<"Solution does not exixt for m = "<<m<<endl;
}
 
}

