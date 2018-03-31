#include<bits/stdc++.h>
using namespace std;

// -------------------------------------------- Generic Stack ------------------------------------------------------

template<typename Type>
struct Node
{
	Type value;
	Node<Type>* next;
};

template<typename Type>
class Stack
{
	private:
		Node<Type>* top;
		static int size;
		
	public:
		Stack();
		void push(Type value);
		Type pop();
		bool isEmpty();
		void returnTop();
		int getSize();
};

template<typename Type>
int Stack<Type> :: size = 0;

template<typename Type>
Stack<Type> :: Stack()
{
	top = NULL;
}

template<typename Type>
void Stack<Type> :: push(Type value)
{
	size++;
	Node<Type>* newNode = (Node<Type> *)malloc(sizeof(Node<Type>));
	
	if(!newNode)
	{
		cout<<"\n\tMemory Full!";
		return;
	}
	
	newNode->value = value;
	if(top == NULL)
	{
		top = newNode;
		newNode->next = NULL;
		return;
	}
	newNode->next = top;
	top = newNode;
}

template<typename Type>
Type Stack<Type> :: pop()
{
	if(top == NULL)
	{
		cout<<"\n\tStack is Empty";
	}
	else
	{
		size--;
		Node<Type>* temp = top;
		Type value = top->value;
		top = top->next;
		free(temp);
		return value;
	}
}

template<typename Type>
bool Stack<Type> :: isEmpty()
{
	if(top == NULL)
		return true;
	return false;
}

template<typename Type>
void Stack<Type> :: returnTop()
{
	if(top == NULL)
	{
		cout<<"\n\tStack is Empty";
		return;
	}
	cout<<top->value;
}

template<typename Type>
int Stack<Type> :: getSize()
{
	return size;
}

// ---------------------------------------------- Generic Tree --------------------------------------------------------------

template<typename Type>
struct treeNode
{
	Type value;
	treeNode<Type>* left;
	treeNode<Type>* right;
};

template<typename Type>
class Tree
{
	private:
		Stack<treeNode<Type>*> stack;
		treeNode<Type>* root;
		void buildTree(treeNode<Type>*);
		void inTraversal(treeNode<Type>*);
		void preTraversal(treeNode<Type>*);
		void postTraversal(treeNode<Type>*);
	public:
		Tree();
		void createTree(Type);
		void inOrderTraversal();
		void preOrderTraversal();
		void postOrderTraversal();
};

template<typename Type>
Tree<Type> :: Tree()
{
	root = NULL;
}

template<typename Type>
void Tree<Type> :: createTree(Type value)
{
	if(root == NULL)
	{
		treeNode<Type>* newNode = (treeNode<Type> *)malloc(sizeof(treeNode<Type>));
		newNode->value = value;
		newNode->left = NULL;
		newNode->right = NULL;
		root = newNode;
		buildTree(root);
	}
	else
	{
		cout<<"\n\tTree Already Exists";
	}
}

template<typename Type>
void Tree<Type> :: buildTree(treeNode<Type>* root)
{
	treeNode<Type>* newNode;
	Type value;
	char choice;
	if(!root->left)		//If the left subtree of current root does not exists
	{
		cout<<"\n\tDo You Want To Create a Left Child of "<<root->value<<" (Y/N)?";
		cin>>choice;
		if(choice == 'Y' || choice == 'y')
		{
			cout<<"\n\tEnter Value of Node: ";
			cin>>value;
			newNode = (treeNode<Type> *)malloc(sizeof(treeNode<Type>));
			root->left = newNode;
			newNode->value = value;
			newNode->left = newNode->right = NULL;
			buildTree(newNode);
		}
	}
	
	if(!root->right)
	{
		cout<<"\n\tDo You Want To Create a Right Child of "<<root->value<<" (Y/N)?";
		cin>>choice;
		if(choice == 'Y' || choice == 'y')
		{
			cout<<"\n\tEnter Value of Node: ";
			cin>>value;
			newNode = (treeNode<Type> *)malloc(sizeof(treeNode<Type>));
			root->right = newNode;
			newNode->value = value;
			newNode->left = newNode->right = NULL;
			buildTree(newNode);
		}
	}
}

template<typename Type>
void Tree<Type> :: inOrderTraversal()
{
	inTraversal(root);
}

template<typename Type>
void Tree<Type> :: inTraversal(treeNode<Type>* root)
{
	while(root)
	{
		if(root->left)
		{
			stack.push(root);
			//cout<<"\n\tSize of stack is: "<<stack.getSize()<<endl;
			root = root->left;
		}
		else
		{
			cout<<root->value<<" ";
			while(root->right == NULL && !stack.isEmpty())	//Will Take Care Of Left Skew Tree
			{
				root = stack.pop();
				//cout<<"\n\tSize of stack is: "<<stack.getSize()<<endl;
				cout<<root->value<<" ";	
			}
			if(root->right)
			{
				root = root->right;
			}
			else
			{
				root = NULL;		//Condition to stop traversal when stack is empty as well as all nodes have been traversed
			}
		}
	}
}

template<typename Type>
void Tree<Type> :: preOrderTraversal()
{
	preTraversal(root);
}

template<typename Type>
void Tree<Type> :: preTraversal(treeNode<Type>* root)
{
	while(root)
	{
		cout<<root->value<<" ";
		if(root->left)
		{
			if(root->right)
				stack.push(root->right);
			root = root->left;
		}
		else
		{
			if(root->right)
				root = root->right;
			else
			{
				if(!stack.isEmpty())
					root = stack.pop();
				else
					root = NULL;	//Stack is empty and both right and left childs are NULL means that all nodes have been traversed.
			}
		}
	}
}

/* Data Type to Hold to Addresses */
template<typename Type>
struct postNode
{
	Type root;
	Type right;
};

template<typename Type>
void Tree<Type> :: postOrderTraversal()
{
	postTraversal(root);
}

template<typename Type>
void Tree<Type> :: postTraversal(treeNode<Type>* root)
{
	Stack< postNode< treeNode<Type>* > *> stack;
	while(root)
	{
		if(root->left)
		{
			postNode< treeNode<Type>* >* newNode = (postNode< treeNode<Type>* >*)malloc(sizeof(postNode< treeNode<Type> >));
			if(root->right)
			{
				newNode->root = root;
				newNode->right = root->right;
			}
			else
			{
				newNode->root = root;
				newNode->right = NULL;
			}
			stack.push(newNode);	// Push the postNode onto the stack
			root = root->left;
		}
		else
		{
			if(root->right)
			{
				postNode< treeNode<Type>* >* newNode = (postNode< treeNode<Type>* >*)malloc(sizeof(postNode< treeNode<Type> >));
				newNode->right = NULL;
				newNode->root = root;
				stack.push(newNode);
				root= root->right;	//Here we accessing the right node of a node whose left does not exist but its right exist
									//So We do not need to store the address of right node,only roots address is needed to be stored
			}
			else
			{
				cout<<root->value<<" ";  //This was the leaf node
				postNode<treeNode<Type>*>* extractedNode = stack.pop();
				if(extractedNode->right)
				{
					root = extractedNode->right;
					extractedNode->right = NULL;
					stack.push(extractedNode);
				}
				else
				{
					while(extractedNode->right == NULL)	//Taking care of left and right skew tree
					{
						cout<<extractedNode->root->value<<" ";
						free(extractedNode);	//node whose value has been read. No need to stay on stack,so deallcate this node;
						if(!stack.isEmpty())
							extractedNode = stack.pop();
						else
							root = NULL;	//This means that tree was either proper right skew or proper left skew
					}
					if(root)		//This means that tree is not proper skew,it may be semi-skew
					{
						root = extractedNode->right;
						extractedNode->right = NULL;
						stack.push(extractedNode);
					}
				}	
			}
		}
	}
}




int main()
{
	int value;
	Tree<int> tree;
	cout<<"\n\tEnter Root Nodes's Value: ";
	cin>>value;
	tree.createTree(value);
	cout<<"\n\tIn Order Traversal: ";
	tree.inOrderTraversal();
	cout<<"\n\tPre Order Traversal: ";
	tree.preOrderTraversal();
	cout<<"\n\tPost Order Traversal: ";
	tree.postOrderTraversal();
	return 0;
}
