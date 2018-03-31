#include<bits/stdc++.h>
using namespace std;

template<typename Type>
struct Node
{
	Type value;
	Node<Type>* next;
};

template<typename Type>
class Queue
{
	private:
		Node<Type>* front;
		Node<Type>* rear;
		static int size;
	public:
		Queue();
		void enqueue(Type);
		Type dequeue();
		int getSize();
		bool isEmpty();
};

template<typename Type>
int Queue<Type> :: size = 0;

template<typename Type>
Queue<Type> :: Queue()
{
	rear = front = NULL;
}

template<typename Type>
void Queue<Type> :: enqueue(Type value)
{
	Node<Type>* newNode = (Node<Type>*)malloc(sizeof(Node<Type>));
	
	if(!newNode)
	{
		cout<<"\n\tMemory Full!";
		return;
	}
	
	newNode->value = value;
	newNode->next = NULL;
	size++;	
	if(rear == NULL)	//Means Queue is Empty,We could either check rear or front for NULL.
	{
		rear = front = newNode;
		return;
	}	
	rear->next = newNode;
	rear = newNode;
}

template<typename Type>
Type Queue<Type> :: dequeue()
{
	Node<Type>* temp;
	Type value;
	if(rear == NULL && front == NULL)
	{
		cout<<"\n\tQueue is Empty";
	}
	else
	{
		size--;
		temp = front;
		value = temp->value;
		
		if(rear == front)	//If there is only single node in the Queue
			rear = front = NULL;
		else
			front = front->next;
		free(temp);
		return value;
	}
}

template<typename Type>
int Queue<Type> :: getSize()
{
	return size;
}


template<typename Type>
bool Queue<Type> :: isEmpty()
{
	if(rear == NULL && front == NULL)
		return true;
	return false;
}

int main()
{
	Queue<int> queue;
	queue.enqueue(10);
	queue.enqueue(20);
	queue.enqueue(30);
	queue.dequeue();
	queue.dequeue();
	queue.dequeue();
	queue.dequeue();
	cout<<"Size: "<<queue.getSize();
}
