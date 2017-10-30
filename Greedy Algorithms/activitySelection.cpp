#include<bits/stdc++.h>
using namespace std;

class Activities
{
	int start,end;
	public:
		void setStartEndTime(int,int);
		static bool compare(Activities,Activities);
		int getStart();
		int getEnd();
};

void Activities :: setStartEndTime(int start,int end)
{
	this->start = start;
	this->end = end;
}

bool Activities :: compare(Activities act1,Activities act2)
{
	return(act1.end < act2.end);
}

int Activities :: getStart()
{
	return this->start;
}

int Activities :: getEnd()
{
	return this->end;
}


class ActivitySelection
{
	private:
		Activities *activity;
		int size;
	public:
		ActivitySelection(){}
		void createActivities(int);
		void setTime();
		void possibleActivities();
};

void ActivitySelection :: createActivities(int size)
{
	activity = (Activities*)calloc(size,sizeof(Activities));
	this->size = size;
}


void ActivitySelection :: setTime()
{
	int counter,start,end;
	for(counter=0;counter<size;counter++)
	{
		cout<<"\n\tEnter the start time of Activity "<<counter+1<<" : ";
		cin>>start;
		cout<<"\n\tEnter the end time of Activity "<<counter+1<<" : ";
		cin>>end;
		activity[counter].setStartEndTime(start,end);
	}
}

void ActivitySelection :: possibleActivities()
{
	int counter,selected=0;
	sort(activity,activity+size,Activities :: compare);
	cout<<"\n\tSelected Activities";
	cout<<"\n\t"<<selected+1<<" ";
	for(counter=1;counter<size;counter++)
	{
		if(activity[selected].getEnd() <= activity[counter].getStart())
		{
			selected = counter;
			cout<<"\n\t"<<selected+1<<" ";
		}
	}
	cout<<endl;
}


int main()
{
	ActivitySelection activity;
	int size,counter,start,end;
	cout<<"\n\tEnter the total number of activities: ";
	cin>>size;
	activity.createActivities(size);
	activity.setTime();
	activity.possibleActivities();
}