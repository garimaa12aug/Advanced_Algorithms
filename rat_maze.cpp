#include<bits/stdc++.h>

using namespace std;

/*
{ 1, 0, 0, 0 }, 
                       { 1, 1, 0, 1 }, 
                       { 0, 1, 0, 0 }, 
                       { 1, 1, 1, 1 } 
*/
int counter = 0;
int m,n;
int visited[20][20]={0};
int solution[20][20] = {0};
int add_x[4] = {0,0,-1,1};
int add_y[4] = {-1,1,0,0};
int grid[20][20];
int result[20][20] = {0};

bool is_safe(  int x,int y)
{
if(x<0 || y<0)
return 0;
if(grid[x][y] == 0)
return 0;
if(x>m || y>n)
return 0;
if(visited[x][y] == 1)
return 0;
return 1;
}

bool solve_for(int x, int y)
{
if(x==m-1 && y==n-1)
return true;
int x_new,y_new;
int i;
//visited[x][y]=1;
for(i=0;i<4;i++)
{
x_new = x + add_x[i];
y_new = y + add_y[i];
if(is_safe( x_new , y_new))
{
visited[x_new][y_new] = 1;
bool answer = solve_for( x_new,y_new);
if(answer)
{
//counter = counter +1;
return answer;
}
}
}
return 0;
}

int main()
{
cout<<"enter number or rows";
cin>>m;
cout<<endl<<"enter number of columns";
cin>>n;
int i,j;
cout<<"enter values of grid"<<endl;
for(i=0;i<m;i++)
{
cout<<"enter next row";
for(j=0;j<n;j++)
{
cin>>grid[i][j];
}

}

bool answer;
answer = solve_for( 0 , 0);
if(answer)
cout<<"path exist";
else
cout<<"path not exist";

cout<<endl;
for(i=0;i<m;i++){
for(j=0;j<n;j++)
{
cout<<visited[i][j]<<" ";
}
cout<<endl;
}
//cout<<endl<<endl<<counter;
}
