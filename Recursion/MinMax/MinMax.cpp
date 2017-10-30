#include<iostream>

using namespace std;
//20 532 12 57 89 54 36 78 33 67

class MinMax
{
	private:
		int *array;
		int min,max,size,min1,max1;
		void findMinMaxR(int,int,int&,int&);
	public:
		MinMax();
		MinMax(int);
		void dataEntry();
		void findMinMax();
		void findMinMaxRecursively(int,int);
		void printMinMax();
		
};

MinMax :: MinMax()
{}

MinMax :: MinMax(int size)
{
	array = new int[size];
	this->size = size;
	min = max = min1 = max1 = 0;
}

void MinMax :: dataEntry()
{
	int counter;
	cout<<"\n\tEnter The Elements Of The Array: ";
	for(counter=0;counter<size;counter++)
	{
		cin>>array[counter];
	}
}

void MinMax :: findMinMax()
{
	int counter;
	max = min = array[0];
	for(counter=1;counter<size;counter++)
	{
		if(min > array[counter])
			min = array[counter];
		if(max < array[counter])
			max = array[counter];
	}
	printMinMax();
} 

void MinMax :: findMinMaxRecursively(int front,int end)
{
	findMinMaxR(front,end,min,max);
	printMinMax();
}

void MinMax :: findMinMaxR(int front,int end,int &min,int &max)
{
	if(front == end)
	{
		min = max = array[front];
	}
	else if(front == end-1)
	{
		if(array[front] > array[end])
		{
			max = array[front];
			min = array[end];
		}

		if(array[front] < array[end])
		{
			max = array[end];
			min = array[front];
		}
	}
	else
	{
		int mid = (front+end)/2;
		findMinMaxR(front,mid,min,max);
		findMinMaxR(mid+1,end,min1,max1);
		if(max1 > max)
		{
			max = max1;
		}
		if(min1 < min)
		{
			min = min1;
		}
	}
}

void MinMax :: printMinMax()
{
	cout<<"\n\tMinimum: "<<min<<" Maximum: "<<max<<"\n\t";
}



int main()
{
	MinMax object;
	int size;
	cout<<"\n\tEnter The Size Of An Array: ";
	cin>>size;
	object = size;
	object.dataEntry();
	object.findMinMaxRecursively(0,size-1);
	return 0;
}