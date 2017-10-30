#ifndef QUEUE
#define QUEUE

#include <bits/stdc++.h>
#include "node.h"
using namespace std;

class Queue
{	
	private:
		Node* *queue;
		int front,rear,size;
	public:
		Queue(){}
		Queue(int);
		void enqueue(Node*);
		Node* dequeue();
		bool isEmpty();
		bool isFull();
		int getrear()
		{
			return rear;
		}
		int getfront()
		{
			return front;
		}
		int print(int index)
		{
			cout<<queue[index];
		}
};

#endif
