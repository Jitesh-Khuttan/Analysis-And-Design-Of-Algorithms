#include "node.h"

void Node :: setData(int value,int weight,Node* address)
{
	this->nodeNumber = value;
	this->weight = weight;
	this->next = address;
}

int Node :: getData()
{
	return this->nodeNumber;
}

int Node :: getWeight()
{
	return this->weight;
}

void Node :: setNextAddress(Node* address)
{
	this->next = address;
}

Node* Node :: getNextNodeAddress()
{
	return this->next;
}

Node* Node :: getNodeAddress()
{
	return this;
}
