#include<iostream>
#include "sorting.cpp"
using namespace std;
//20 532 12 57 89 54 36 78 33 67

class BinarySearch
{
	private:
		int *arr;
		int length;
		bool binaryR(int,int,int);
	public:
		BinarySearch(){}
		BinarySearch(int);
		bool binaryIterative(int,int,int);	
		bool binaryRecursive(int,int,int);
		void printArray();	
};

BinarySearch :: BinarySearch(int size)
{
	arr = new int[size];
	this->length = size;
	cout<<"\n\tEnter The Elements Of An Array: ";
	for(int counter=0;counter<size;counter++)
	{
		cin>>arr[counter];
	}
}

void BinarySearch :: printArray()
{
	cout<<"\n\t";
	for(int counter=0;counter<length;counter++)
	{
		cout<<arr[counter]<<" ";
	}
}

bool BinarySearch :: binaryIterative(int low,int high,int value)
{
	Sorting object;
	int mid;
	object.setArray(this->arr);
	object.quickSort(low,high,1);
	this->arr = object.getArray();
	printArray();
	while(low<=high)
	{
		mid = (low+high)/2;
		if(arr[mid] == value)
		{
			return true;
		}
		else if(arr[mid] > value)
		{
			high = mid-1;
		}
		else if(arr[mid] < value)
		{
			low = mid+1;
		}
	}
	return false;
}

bool BinarySearch :: binaryRecursive(int low,int high,int value)
{
	Sorting object;
	object.setArray(arr);
	object.quickSort(low,high,1);
	arr = object.getArray();
	printArray();
	return binaryR(low,high,value);
}

bool BinarySearch :: binaryR(int low,int high,int value)
{
	int mid;
	if(low<=high)
	{
		mid = (low+high)/2;
		if(arr[mid] == value)
		{
			return true;
		}
		else if(arr[mid] > value)
		{
			return binaryR(low,mid-1,value);
		}
		else if(arr[mid] < value)
		{
			return binaryR(mid+1,high,value);
		}
	}
	return false;
}

int main()
{
	BinarySearch obj;
	int choice,size,value;
	char sentinal='y';
	bool result;
	cout<<"\n\tEnter the size of the array";
	cin>>size;
	obj = 10;
	while(sentinal=='y')
	{
		cout<<"\n\t1.Iterative Search\n\t2.Recursive Search\n\t";
		cin>>choice;
		cout<<"\n\tEnter The Value To Search: ";
		cin>>value;
		switch(choice)
		{
			case 1:
				result = obj.binaryIterative(0,size-1,value);
				if(result == true)
					cout<<"\n\t"<<value<<" found!";
				else if(result == false)
					cout<<"\n\t"<<value<<" not found!";
				break;
			case 2:
				result = obj.binaryRecursive(0,size-1,value);
				if(result == true)
					cout<<"\n\t"<<value<<" found!";
				else if(result == false)
					cout<<"\n\t"<<value<<" not found!";
				break;
			default:
				cout<<"\n\tWrong Option!";
				break;
		}
		cout<<"\n\tContinue?(Y/N): ";
		cin>>sentinal;
	}
	return 0;
}