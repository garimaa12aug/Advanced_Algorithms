#include<bits/stdc++.h>

using namespace std;;

//int grid[9][9];

bool all_assigned(int grid[9][9],int &row,int &column)
{
int i,j;
for(i=0;i<9;i++)
{
for(j=0;j<9;j++)
{
if(grid[i][j] == 0)
{
row = i;
column = j;
return 0;
}
}
} 
return 1;
}


bool is_safe(int grid[9][9],int row,int column , int option)
{
int y;
for(y=0;y<9;y++)
{
if(grid[row][y] == option)
return 0;
}
for(y=0;y<9;y++)
{
if(grid[y][column] == option)
return 0;
}
int starting_row = row-row%3;
int starting_column = column-column%3;
int i,j;
for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
{
if(grid[starting_row+i][starting_column+j] == option)
return 0;
}
}
return 1;
}

//solve for function
bool solve_for(int grid[9][9])
{
int row, column;
if(all_assigned(grid,row,column))
return true;
int option;
for(option=1;option<=9;option++)
{
if(is_safe(grid,row,column,option))
{
grid[row][column] = option;
bool answer;
answer = solve_for(grid);
if(answer)
return answer;
//grid[row][column] = 0;
}
}
grid[row][column] = 0;
return 0;
}


int main()
{
int grid[9][9];
solve_for(grid);
int i,j;
cout<<"enter number of elements in sudoku";
int v;
cin>>v;
for(i=0;i<v;i++)
{
int x,y,z;
cin>>x>>y>>z;
grid[x][y]=z;
}
solve_for(grid);
//int i,j;
for(i=0;i<9;i++)
{
for(j=0;j<9;j++)
{
cout<<grid[i][j]<<" ";
}
cout<<endl;
}
}
