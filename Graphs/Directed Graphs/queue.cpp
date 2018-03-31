#include "queue.h"

Queue :: Queue(int size)
{
	this->size = size;
	queue = (Node**)calloc(size,sizeof(Node*));
	front=-1;rear=-1;
	// cout<<"\n\tQueue Created!\n\tSize: "<<size;
	// cout<<"\n\t";
	// for(int counter=0;counter<size;counter++)
	// {
	// 	cout<<queue[counter];
	// }
}

bool Queue :: isFull()
{
	if(front == (rear+1)%size)
		return true;
	return false;
}

bool Queue :: isEmpty()
{
	if(rear == front && rear == -1)
		return true;
	return false;
}

void Queue :: enqueue(Node* address)
{
	if(isFull())
	{
		cout<<"Overflow Condition!";
		return;
	}
	if(isEmpty())
		front = rear = 0;
	else
		rear = (rear+1)%size;
	queue[rear] = address;
}

Node* Queue :: dequeue()
{
	if(isEmpty())
	{
		cout<<"Underflow Condition!";
		return NULL;
	}
	Node* temp = queue[front];
	if(front == rear)
	{
		front = rear = -1;
		return temp;
	}
	front = (front+1)%size;
	return temp;
}
