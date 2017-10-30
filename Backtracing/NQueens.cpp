#include<bits/stdc++.h>
using namespace std;

int *queensplace;
int totalSolutions=0;

int place(int row,int column)
{
	int eachrow;
	for(eachrow=0;eachrow<row;eachrow++)
	{
		if(queensplace[eachrow] == column)
			return false;
		if(abs(eachrow-row) == abs(queensplace[eachrow]-column))
			return false;
	}
	return true;
}

void NQueens(int row,int size)
{
	int column,counter;
	for(column=0;column<size;column++)
	{
		if(place(row,column))
		{
			queensplace[row] = column;
			if(row == size-1)
			{
				cout<<"\n\tThe Queens can be placed at following columns";
				cout<<"\n\tRow\tColumn";
				for(counter=0;counter<size;counter++)
				{
					cout<<"\n\t"<<counter<<"\t"<<queensplace[counter];
				}
				cout<<"\n";
				totalSolutions++;
			}
			else
				NQueens(row+1,size);
		}
	}
}

int main()
{
	int size;
	cout<<"\n\tEnter the number of queens: ";
	cin>>size;
	queensplace = new int[size];
	NQueens(0,size);
	cout<<"\n\tTotal Solutions: "<<totalSolutions<<endl;
}