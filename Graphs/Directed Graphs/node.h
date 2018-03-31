#ifndef NODE
#define NODE

#include<bits/stdc++.h>
using namespace std;

			
		/* ********************************************************* */
								/*Node Class*/

class Node
{
	private:
		int nodeNumber;
		int weight;
		Node* next;
	public:
		void setData(int value,int weight,Node* address);
		int getData();
		int getWeight();
		void setNextAddress(Node* address);
		Node* getNextNodeAddress();
		Node* getNodeAddress();
};

#endif
