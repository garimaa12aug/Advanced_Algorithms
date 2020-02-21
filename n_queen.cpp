#include<bits/stdc++.h>

using namespace std;

int result[4];


bool is_safe(int row, int column)
{
int i;
for(i=1;i<=row-1;i++)
{
if(result[i]== column || abs(i-row) == abs(result[i]-column))
return 0;
}
return 1;
}


bool solve_for(int row)
{
if(row>4)
return 1;
int column;
	for(column =1;column <=4;column++)
	{
		if(is_safe(row,column))
		{
		result[row] = column;
		bool answer;
		answer = solve_for(row+1);
		if(answer)
		return answer;
		}
	}
return 0;
}


int main()
{
solve_for(1);
int i;
cout<<"Solution to 4 queen problem is :"<<endl;
for(i=1;i<=4;i++)
{
cout<<result[i]<<" ";
}
cout<<endl;
}
