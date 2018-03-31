#ifndef LINKEDLIST
#define LINKEDLIST

#include "node.h"
#include <bits/stdc++.h>
using namespace std;

	/* ********************************************************* */
								/*LinkedList Class*/
class LinkedList
{
	
	private:
		Node* head,currentNode;
	public:
		LinkedList();
		void insertNode(int v,int weight);
		void deleteNode(int v);
		void traverseList();
		Node* getHead();
};

#endif
