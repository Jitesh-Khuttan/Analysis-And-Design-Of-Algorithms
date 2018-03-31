#include<bits/stdc++.h>
using namespace std;

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
		treeNode<Type>* root;
		void buildTree(treeNode<Type>*);
	public:
		Tree();
		void createTree(Type);
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

int main()
{
	Tree<int> tree;
	tree.createTree(10);
	return 0;
}

