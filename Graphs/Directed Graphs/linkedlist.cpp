#include "linkedlist.h"

LinkedList :: LinkedList()
{
	head = NULL;
}

Node* LinkedList :: getHead()
{
	return this->head;
}

void LinkedList :: insertNode(int v,int weight)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	Node* temp;

	if(!newNode)
	{
		cout<<"\n\tMemory Full!";
		return;
	}

	temp = this->head;
	while(temp!=NULL)
	{
		if(temp->getData() == v)
		{
			cout<<"\n\tEdge Already Exists!";
			return;
		}
		temp = temp->getNextNodeAddress();
	}

	if(this->head == NULL)
	{
		newNode->setData(v,weight,NULL);
		this->head = newNode;
		return;
	}

	newNode->setData(v,weight,NULL);

	temp = this->head;
	while(temp->getNextNodeAddress() != NULL)
	{
		temp = temp->getNextNodeAddress();
	}
	temp->setNextAddress(newNode);
}

void LinkedList :: deleteNode(int v)
{
	Node* temp = this->head;
	Node* previous = NULL;


	while(temp->getData() != v)
	{
		previous = temp;
		temp = temp->getNextNodeAddress();
	}

	if(previous == NULL)
	{
		this->head = this->head->getNextNodeAddress();
		return;
	}
	previous->setNextAddress(temp->getNextNodeAddress());
	free(temp);
}

void LinkedList :: traverseList()
{
	Node* temp;
	temp = this->head;
	if(temp == NULL)
		return;
	while(temp!=NULL)
	{
		cout<<temp->getData()<<" ";
		temp = temp->getNextNodeAddress();
	}
}
