#include<bits/stdc++.h>
using namespace std;

template<typename Type>
struct Node
{
	Type value;
	Node<Type>* next;
};

template<typename Type>
struct treeNode
{
	Type value;
	treeNode<Type>* left;
	treeNode<Type>* right;	
};

// --------------------------------------------------- Generic Queue ------------------------------------------------

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


// ----------------------------------------------- Generic Complete Binary Tree ----------------------------------------------------------

template<typename Type>
class CompleteBinaryTree
{
	private:
		treeNode<Type>* root;
		void buildTree(treeNode<Type>*);
		Queue<treeNode<Type>*> queue;
		void preTraversal(treeNode<Type>*);
	public:
		CompleteBinaryTree();
		void createTree(Type);
		void preOrderTraversal();
};

template<typename Type>
CompleteBinaryTree<Type> :: CompleteBinaryTree()
{
	root = NULL;
}

template<typename Type>
void CompleteBinaryTree<Type> :: createTree(Type value)
{
	treeNode<Type>* newNode = (treeNode<Type>*)malloc(sizeof(treeNode<Type>));
	newNode->value = value;
	newNode->left = newNode->right = NULL;
	root = newNode;
	buildTree(newNode);
}

template<typename Type>
void CompleteBinaryTree<Type> :: buildTree(treeNode<Type>* root)
{
	treeNode<Type>* newNode;
	char choice;
	Type value;
	
	//For Inserting Node as the left child
	cout<<"\n\tDo you want to insert a Node ? (Y/N)";
	cin>>choice;
	if(choice == 'Y' || choice == 'y')
	{
		newNode = (treeNode<Type>*)malloc(sizeof(treeNode<Type>));
		cout<<"\n\tEnter Value: ";
		cin>>value;
		newNode->value = value;
		newNode->left = newNode->right = NULL;
		root->left = newNode;
		queue.enqueue(newNode);
	}
	else
		return;
	
	//For Inserting Node as the right child
	cout<<"\n\tDo you want to insert a Node ? (Y/N)";
	cin>>choice;
	if(choice == 'Y' || choice == 'y')
	{
		newNode = (treeNode<Type>*)malloc(sizeof(treeNode<Type>));
		cout<<"\n\tEnter Value: ";
		cin>>value;
		newNode->value = value;
		newNode->left = newNode->right = NULL;
		root->right = newNode;
		queue.enqueue(newNode);
	}
	else
		return;
	
	buildTree(queue.dequeue());
}

template<typename Type>
void CompleteBinaryTree<Type> :: preOrderTraversal()
{
	preTraversal(root);	
} 

template<typename Type>
void CompleteBinaryTree<Type> :: preTraversal(treeNode<Type>* root)
{
	if(root != NULL)
	{
		cout<<root->value<<" ";
		preTraversal(root->left);
		preTraversal(root->right);
	}
}


int main()
{
	CompleteBinaryTree<int> tree;
	tree.createTree(60);
	tree.preOrderTraversal();
	return 0;
}



