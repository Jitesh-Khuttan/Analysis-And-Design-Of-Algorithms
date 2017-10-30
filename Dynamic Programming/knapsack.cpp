#include<bits/stdc++.h>
using namespace std;

int max(int value1,int value2)
{
	return(value1>value2?value1:value2);
}

void knapsack(int maxWeight,int *profit,int *weights,int length)
{
	int matrix[length][maxWeight+1];
	int counter,offset;
	for(counter=0,offset=0;offset<maxWeight+1;offset++)
	{
		if(offset==0)
			matrix[counter][offset] = 0;
		else if(weights[counter] > offset)
			matrix[counter][offset] = 0;
		else
			matrix[counter][offset] = profit[counter];
	}
	for(counter=1;counter<length;counter++)
	{
		for(offset=0;offset<maxWeight+1;offset++)
		{
			if(offset == 0)
				matrix[counter][offset] = 0;
			else if(weights[counter] > offset)
			{
				matrix[counter][offset] = matrix[counter-1][offset];
			}
			else
			{
				matrix[counter][offset] = max(profit[counter] + matrix[counter-1][offset-weights[counter]],matrix[counter-1][offset]);
			}
		}
	}
	// cout<<"\n\t";
	// for(counter=0;counter<length;counter++)
	// {
	// 	for(offset=0;offset<maxWeight+1;offset++)
	// 	{
	// 		cout<<matrix[counter][offset]<<" ";
	// 	}
	// 	cout<<"\n\t";
	// }
	counter=length-1;offset=maxWeight;
	cout<<"\tWeight\tValue";
	while(matrix[counter][offset] != 0)
	{
		if(matrix[counter][offset] != matrix[counter-1][offset])
		{
			cout<<"\n\t"<<weights[counter]<<"\t"<<profit[counter];
			offset = offset-weights[counter];
			counter--;
		}
		else
			counter--;
	}
	cout<<"\n\tMaximum Profit: "<<matrix[length-1][maxWeight]<<endl;
}

int main()
{
	int size,counter,maxWeight;
	int *weights,*profit;
	cout<<"\n\tEnter number of items: ";
	cin>>size;
	weights = new int[size];
	profit = new int[size];
	cout<<"\n\tEnter weight of knapsack:";
	cin>>maxWeight;
	for(counter=0;counter<size;counter++)
	{
		cout<<"\n\tEnter weight of item "<<counter+1<<": ";
		cin>>weights[counter];
	}
	for(counter=0;counter<size;counter++)
	{
		cout<<"\n\tEnter profit of item "<<counter+1<<": ";
		cin>>profit[counter];
	}
	knapsack(maxWeight,profit,weights,size);
}