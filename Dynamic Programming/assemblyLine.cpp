#include<iostream>
using namespace std;

class AssemblyLine
{
	private:
		int *optimalTime1,*optimalTime2;	//Arrays of fastest times to reach jth station
		int *compTime1,*compTime2;			//Arrays of time taken to complete job at station j
		int *transferTime1,*transferTime2;
		int *tracking1,*tracking2;
		int entryTime1,entryTime2,exitTime1,exitTime2,size,finalexit;
	public:
		AssemblyLine(){}
		AssemblyLine(int);
		void setData();
		void calculateMinimumTime();
		void traceLines();
};

AssemblyLine :: AssemblyLine(int size)
{
	this->size = size;
	optimalTime1 = new int[size];
	optimalTime2 = new int[size];
	compTime1 = new int[size];
	compTime2 = new int[size];
	transferTime1 = new int[size-1];
	transferTime2 = new int[size-1];
	tracking1 = new int[size];
	tracking2 = new int[size];

}

void AssemblyLine :: setData()
{
	int counter;
	cout<<"\n\tEnter the entry time on line 1: ";
	cin>>entryTime1;
	cout<<"\n\tEnter the entry time on line 2: ";
	cin>>entryTime2;
	cout<<"\n\tEnter the Exit time on line 1: ";
	cin>>exitTime1;
	cout<<"\n\tEnter the Exit time on line 2: ";
	cin>>exitTime2;
	for(counter=0;counter<size;counter++)
	{
		cout<<"\n\tEnter the completion time A(1,"<<counter+1<<") : ";
		cin>>compTime1[counter];
	}
	for(counter=0;counter<size;counter++)
	{
		cout<<"\n\tEnter the completion time A(2,"<<counter+1<<") : ";
		cin>>compTime2[counter];
	}
	for(counter=0;counter<size-1;counter++)
	{
		cout<<"\n\tEnter the transfer time T(1,"<<counter+1<<") : ";
		cin>>transferTime1[counter];
	}
	for(counter=0;counter<size-1;counter++)
	{
		cout<<"\n\tEnter the transfer time T(2,"<<counter+1<<") : ";
		cin>>transferTime2[counter];
	}
}

void AssemblyLine :: calculateMinimumTime()
{
	int counter,temp;
	optimalTime1[0] = entryTime1 + compTime1[0];
	optimalTime2[0] = entryTime2 + compTime2[0];

	for(counter=1;counter<size;counter++)
	{
		//Calculation for Fastest(1,counter)
		if(optimalTime1[counter-1] + compTime1[counter] < optimalTime2[counter-1]+transferTime2[counter-1]+compTime1[counter])
		{
			optimalTime1[counter] = optimalTime1[counter-1] + compTime1[counter];
			tracking1[counter] = 1;
		}
		else
		{
			optimalTime1[counter] = optimalTime2[counter-1]+transferTime2[counter-1]+compTime1[counter];
			tracking1[counter] = 2;
		}
		//Calculation for Fastest(2,counter)
		if(optimalTime1[counter-1] + compTime2[counter] + transferTime1[counter-1] < optimalTime2[counter-1] + compTime2[counter])
		{
			optimalTime2[counter] = optimalTime1[counter-1] + compTime2[counter] + transferTime1[counter-1];
			tracking2[counter] = 1;
		}
		else
		{
			optimalTime2[counter] = optimalTime2[counter-1] + compTime2[counter];
			tracking2[counter] = 2;
		}
	}
	optimalTime1[size-1] += exitTime1;
	optimalTime2[size-1] += exitTime2;
	if(optimalTime1[size-1] < optimalTime2[size-1])
		finalexit = 1;
	else
		finalexit = 2;
}

void AssemblyLine :: traceLines()
{
	int counter;
	cout<<"\n\toptimal1: ";
	for(counter=0;counter<size;counter++)
	{
		cout<<optimalTime1[counter]<<" ";
	}
	cout<<"\n\toptimal2: ";
	for(counter=0;counter<size;counter++)
	{
		cout<<optimalTime2[counter]<<" ";
	}
	cout<<"\n\tTracking1: ";
	for(counter=1;counter<size;counter++)
	{
		cout<<tracking1[counter]<<" ";
	}
	cout<<"\n\tTracking2: ";
	for(counter=1;counter<size;counter++)
	{
		cout<<tracking2[counter]<<" ";
	}
	cout<<"\n\tFinalExit: "<<finalexit;
	cout<<"\n\t";
	if(finalexit == 1)
	{
		cout<<"S(1"<<","<<size-1<<") ";
		for(counter=size-1;counter>0;counter--)
		{
			cout<<"S("<<tracking1[counter]<<","<<counter-1<<") ";
		}
	}
	else if(finalexit == 2)
	{
		cout<<"S(2"<<","<<size-1<<") ";
		for(counter=size-1;counter>0;counter--)
		{
			cout<<"S("<<tracking2[counter]<<","<<counter-1<<") ";
		}
	}
}


int main()
{
	AssemblyLine object;
	object = AssemblyLine(6);
	object.setData();
	object.calculateMinimumTime();
	object.traceLines();
	return 0;
}