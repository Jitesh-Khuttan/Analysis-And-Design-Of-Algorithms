#include<iostream>
using namespace std;
#define v 5
int main()
{
	 int cost[v][v] = {{999, 2, 999, 6, 999},
                      {2, 999, 3, 8, 5},
                      {999, 3, 999, 999, 7},
                      {6, 8, 999, 999, 9},
                      {999, 5, 7, 9, 999},
                     };
  for(int k=0;k<v;k++)
  {
  	for(int i=0;i<v;i++)
  	{
  		for(int j=0;j<v;j++)
  		{
  			if(i!=j && cost[i][j]>cost[i][k]+cost[k][j])
  			{
  				cost[i][j]=cost[i][k]+cost[k][j];
			  }
  			
		  }
	  }
	}

  cout<<"***floyd's algorithm***"<<endl<<"updated cost matrix:"<<endl<<endl;
  for(int i=0;i<v;i++)
  {
  	for(int j=0;j<v;j++)
  	{
  		if(cost[i][j]==999)
  		{
  			cost[i][j]=0;
		  }
  		cout<<cost[i][j]<<"  ";
	  }
  	cout<<endl;
  }
}