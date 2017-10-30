#include<iostream>
using namespace std;

class knapsack
{
	private:
		struct Data
		{
			float weight,profit,ratio;
			int entryNumber;
		};
		Data *array;
		int length,totalEntries;
		float knapProfit,maxKnapWeight;
		float *check;
		void quickSort(int,int);
		int partition(int,int);
	public:
		knapsack(){}
		knapsack(int,float);
		float maxProfit();
		void printEntries();
};

knapsack :: knapsack(int size,float maxKnapWeight)
{
	int counter;
	this->length = size;
	this->maxKnapWeight = maxKnapWeight;
	knapProfit = 0;
	totalEntries = 0;
	this->check = new float[size];
	this->array = new Data[size];

	cout<<"\n\tEnter The Weights: ";
	for(counter=0;counter<size;counter++)
	{
		cin>>array[counter].weight;
		array[counter].entryNumber = counter+1;
	}

	cout<<"\n\tEnter The Profits: ";
	for(counter=0;counter<size;counter++)
	{
		cin>>array[counter].profit;
	}

	for(counter=0;counter<size;counter++)
	{
		array[counter].ratio = array[counter].profit/array[counter].weight;
	}
}

void knapsack :: quickSort(int start,int end)
{
	int pivot;
	if(start<end)
	{
		pivot = partition(start,end);
		quickSort(start,pivot-1);
		quickSort(pivot+1,end);
	}
}

int knapsack :: partition(int start,int end)
{
	float pivot;
	int pindex,last;
	Data temp;
	pivot = array[end].ratio;
	pindex = start; 
	last = end-1;
	while(pindex <= last)
	{
		if(array[pindex].ratio > pivot)
			pindex++;
		if(pindex>last)	break;
		if(array[last].ratio < pivot)
			last--;
		if(pindex>last)	break;
		if(array[pindex].ratio < pivot && array[last].ratio > pivot)
		{
			temp = array[pindex];
			array[pindex] = array[last];
			array[last] = temp;
			pindex++; last--;
		}
		
	}
	temp = array[end];
	array[end] = array[pindex];
	array[pindex] = temp;
	return pindex;
}

float knapsack :: maxProfit()
{
	int counter;
	float temp = maxKnapWeight;
	quickSort(0,length-1);
	for(counter=0;counter<length;counter++)
	{
		if((temp-array[counter].weight) > 0)
		{
			knapProfit += array[counter].profit;
			temp -= array[counter].weight;
			check[counter] = 1;
			totalEntries += 1;
		}
		else
		{
			break;
		}
	}
	if(counter<length)
	{
		check[counter] = temp/array[counter].weight;
		knapProfit += check[counter]*array[counter].profit;
		totalEntries += 1; 
	}
	return knapProfit;
}

void knapsack :: printEntries()
{
	cout<<"\n\n\tEntry Number\tWeight Used\tProfit Earned";
	for(int counter=0;counter<totalEntries;counter++)
	{
		cout<<"\n\t    "<<array[counter].entryNumber<<"\t\t  "<<array[counter].weight*check[counter]<<"\t\t  "<<array[counter].profit*check[counter];
	}
	cout<<"\n";
}


int main()
{
	int size;
	float maxweight;
	float maxProfit;
	cout<<"\n\tEnter The Number Of Weights: ";
	cin>>size;
	cout<<"\n\tEnter The Maximum Weight A knapsack Can Contain:";
	cin>>maxweight;
	knapsack object(size,maxweight);
	maxProfit = object.maxProfit();
	cout<<"\n\tMaximum Profit Obtained Is: "<<maxProfit;
	object.printEntries();
}