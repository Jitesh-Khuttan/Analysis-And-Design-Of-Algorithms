#include<iostream>
using namespace std;
//20 532 12 57 89 54 36 78 33 67	

class Sorting
{
	int *array;
	int length;
	private:
		void merge(int,int,int,int);
		int partition(int,int,int);
	public:
		Sorting() { }
		Sorting(int);
		void setArray(int*);
		int* getArray(); 
		void insertionSort(int);
		void bubbleSort(int);
		void selectionSort(int);
		void mergeSort(int,int,int);
		void quickSort(int,int,int);
		void printArray();
};

Sorting :: Sorting(int size)
{
	int counter;
	array = new int[size];
	length = size;
	cout<<"\n\tEnter The "<<length<<" Elements Of An Array: ";
	for(counter=0;counter<length;counter++)
	{
		cin>>array[counter];
	}
}

void Sorting :: setArray(int* arr)
{
	this->array = arr;
} 

int* Sorting :: getArray()
{
	return this->array;
}

void Sorting :: bubbleSort(int option)

{
	int counter,offset,temp,flag=0;
	if(option == 1)
	{
		for(counter=0;counter<length-1;counter++)
		{
			for(offset=0;offset<length-counter-1;offset++)
			{
				if(array[offset] > array[offset+1])
				{
					temp = array[offset];
					array[offset] = array[offset+1];
					array[offset+1] = temp;
					flag = 1;
				}
			}
			if(flag == 0)
				break;
			flag = 0;
			cout<<"\n\tPass "<<counter+1<<": ";
			printArray();
		}
	}
	else
	{
		for(counter=0;counter<length-1;counter++)
		{
			for(offset=0;offset<length-counter-1;offset++)
			{
				if(array[offset] < array[offset+1])
				{
					temp = array[offset];
					array[offset] = array[offset+1];
					array[offset+1] = temp;
					flag = 1;
				}
			}
			if(flag == 0)
				break;
			flag = 0;
			cout<<"\n\tPass "<<counter+1<<": ";
			printArray();
		}
	}
}

void Sorting :: insertionSort(int option)
{
	int key,counter,hole,offset;
	if(option == 1)
	{
		for(counter=1;counter<length;counter++)
		{
			hole = counter;
			offset = counter-1;
			key = array[counter];
			while(hole>0 && key<array[offset])
			{
				array[offset+1]=array[offset];
				hole--;
				offset--;
			}
			array[hole] = key;
			cout<<"\n\tPass "<<counter<<": ";
			printArray();
		}
	}
	else
	{
		for(counter=1;counter<length;counter++)
		{
			hole = counter;
			offset = counter-1;
			key = array[counter];
			while(hole>0 && key>array[offset])
			{
				array[offset+1]=array[offset];
				hole--;
				offset--;
			}
			array[hole] = key;
			cout<<"\n\tPass "<<counter<<": ";
			printArray();
		}
	}
}

void Sorting :: selectionSort(int option)
{
	int offset,counter,min,max,temp;
	if(option == 1)
	{
		for(counter=0;counter<length-1;counter++)
		{
			min = counter;
			for(offset=counter+1;offset<length;offset++)
			{
				if(array[offset] < array[min])
					min = offset;
			}
			if(min!=counter)
			{
				temp = array[counter];
				array[counter] = array[min];
				array[min] = temp;
			}
			cout<<"\n\tPass "<<counter+1<<": ";
			printArray();
		}
	}
	else
	{
		for(counter=0;counter<length-1;counter++)
		{
			max = counter;
			for(offset=counter+1;offset<length;offset++)
			{
				if(array[offset] > array[max])
					max = offset;
			}
			if(max!=counter)
			{
				temp = array[counter];
				array[counter] = array[min];
				array[min] = temp;
			}
			cout<<"\n\tPass "<<counter+1<<": ";
			printArray();
		}
	}
}

void Sorting :: mergeSort(int front,int end,int type)
{
	int mid;
	mid = (front+end)/2;
	if(front<end)
	{
		mergeSort(front,mid,type);
		mergeSort(mid+1,end,type);
		merge(front,mid,end,type);
	}
}

void Sorting :: merge(int front,int mid,int end,int type)
{
	int leftarray[mid-front+1],rightarray[end-mid],counter,offset;
	int insertIndex,leftindex,rightindex;
	int leftlength = mid-front+1, rightlength = end-mid;

	for(counter=front,offset=0;counter<=mid;counter++,offset++)
	{
		leftarray[offset] = array[counter];
	}

	for(counter = mid+1,offset=0;counter<=end;counter++,offset++)
	{
		rightarray[offset] = array[counter];
	}

	insertIndex = front;
	leftindex = 0;
	rightindex = 0;
	if(type == 1)
	{
		while(leftindex < (leftlength) && rightindex < (rightlength))
		{
			if(leftarray[leftindex] < rightarray[rightindex])
			{
				array[insertIndex++] = leftarray[leftindex++];
			}
			else if(rightarray[rightindex] < leftarray[leftindex])
			{
				array[insertIndex++] = rightarray[rightindex++];
			}
			else if(leftarray[leftindex] == rightarray[rightindex])
			{
				array[insertIndex++] = leftarray[leftindex++];
				array[insertIndex++] = rightarray[rightindex++];
			}
		}
		if(leftindex<leftlength)
		{
			while(leftindex<leftlength)
				array[insertIndex++] = leftarray[leftindex++];
		}
		else if(rightindex<rightlength)
		{
			while(rightindex<rightlength)
				array[insertIndex++] = rightarray[rightindex++];
		}
	}
	else if(type == 2)
	{
		while(leftindex < (leftlength) && rightindex < (rightlength))
		{
			if(leftarray[leftindex] > rightarray[rightindex])
			{
				array[insertIndex++] = leftarray[leftindex++];
			}
			else if(rightarray[rightindex] > leftarray[leftindex])
			{
				array[insertIndex++] = rightarray[rightindex++];
			}
			else if(leftarray[leftindex] == rightarray[rightindex])
			{
				array[insertIndex++] = leftarray[leftindex++];
				array[insertIndex++] = rightarray[rightindex++];
			}
		}
		if(leftindex<leftlength)
		{
			while(leftindex<leftlength)
				array[insertIndex++] = leftarray[leftindex++];
		}
		else if(rightindex<rightlength)
		{
			while(rightindex<rightlength)
				array[insertIndex++] = rightarray[rightindex++];
		}
	}
}

void Sorting :: quickSort(int start,int end,int type)
{
	int pivot;
	if(start<end)
	{
		pivot = partition(start,end,type);
		quickSort(start,pivot-1,type);
		quickSort(pivot+1,end,type);
	}
}

int Sorting :: partition(int start,int end,int type)
{
	int pivot,pindex,last,temp;
	static int counter=0;
	pivot = array[end];
	pindex = start; 
	last = end-1;
	if(type == 1)
	{
		while(pindex <= last)
		{
			if(array[pindex] < pivot)
				pindex++;
			if(pindex>last)	break;
			if(array[last] > pivot)
				last--;
			if(pindex>last)	break;
			if(array[pindex] > pivot && array[last] < pivot)
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
		// cout<<"\n\tPass "<<counter++<<": ";
		// printArray();
		// cout<<"\n\tPindex: "<<pindex;
	}
	else if(type == 2)
	{
		while(pindex <= last)
		{
			if(array[pindex] > pivot)
				pindex++;
			if(pindex>last)	break;
			if(array[last] < pivot)
				last--;
			if(pindex>last)	break;
			if(array[pindex] < pivot && array[last] > pivot)
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
		// cout<<"\n\tPass "<<counter++<<": ";
		// printArray();
		// cout<<"\n\tPindex: "<<pindex;

	}
	return pindex;
}

void Sorting :: printArray()
{
	int counter;
	for(counter=0;counter<length;counter++)
	{
		cout<<array[counter]<<" ";
	}
}

/*int main()
{
	Sorting obj;
	int size,searchChoice,type;
	char sentinal = 'y';
	cout<<"\n\tEnter The Size Of An Array: ";
	cin>>size;
	obj = size;
	while(sentinal == 'y'|| sentinal == 'Y')
	{
		DataEntry:
			cout<<"\n\t1.Insertion Sort\n\t2.Bubble Sort\n\t3.Selection Sort\n\t4.Merge Sort\n\t5.Quick Sort\n\t";
			cin>>searchChoice;
			if(searchChoice<1 || searchChoice>5)
			{
				cout<<"\n\tPlease Enter The Valid Choice\n\t";
				goto DataEntry;
			}
			cout<<"\n\t1.Ascending\n\t2.Descending\n\t";
			cin>>type;
			if(type<1 || type >2)
			{
				cout<<"\n\tPlease Enter The Valid Choice\n\t";
				goto DataEntry;
			}
			cout<<"\n\tBefore Sorting\n\t";
			obj.printArray();
		switch(searchChoice)
		{
			
			case 1:
				obj.insertionSort(type);
				cout<<"\n\tAfter Sorting\n\t";
				obj.printArray();	
				break;
			case 2:
				obj.bubbleSort(type);
				cout<<"\n\tAfter Sorting\n\t";
				obj.printArray();
				break;
			case 3:
				obj.selectionSort(type);
				cout<<"\n\tAfter Sorting\n\t";
				obj.printArray();
				break;
			case 4:
				obj.mergeSort(0,size-1,type);
				cout<<"\n\tAfter Sorting\n\t";
				obj.printArray();
				break;
			case 5:
				obj.quickSort(0,size-1,type);
				cout<<"\n\tAfter Sorting\n\t";
				obj.printArray();
				break;
		}
		cout<<"\n\tContinue?(Y/N)\n\t";
		cin>>sentinal;
	}
	return 0;
}*/
