#include<bits/stdc++.h>
using namespace std;

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
		Type returnTop();
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
	Node<Type>* newNode = (Node<Type> *)malloc(sizeof(Node<Type>));
	size++;
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
Type Stack<Type> :: returnTop()
{
	if(top == NULL)
	{
		cout<<"\n\tStack is Empty";
		return;
	}
	return top->value;
}

template<typename Type>
int Stack<Type> :: getSize()
{
	return size;
}


// ---------------------------------------------Expression Tree ------------------------------------------------------
struct treeNode
{
    char value;
    treeNode* left;
    treeNode* right;
};

class ExpressionTree
{
private:
    treeNode* root;
    static int treeSize;

    string ReversePolishNotation(string);
    void preTraversal(treeNode*);

public:
    ExpressionTree();
    void createTree(string);
    void preOrderTraversal();
};

ExpressionTree :: ExpressionTree()
{
    root = NULL;
}
int ExpressionTree :: treeSize = 0;

void ExpressionTree :: createTree(string expression)
{
    Stack<treeNode*> expStack;
    treeNode* newNode;

    string rpnExpression = ReversePolishNotation(expression);

    for(int i=0;i < rpnExpression.length();i++)
    {
        if(rpnExpression[i] == '+' || rpnExpression[i] == '-' || rpnExpression[i] == '*'
           || rpnExpression[i] == '/' || rpnExpression[i] == '^')
        {
            newNode = (treeNode*)malloc(sizeof(treeNode));
            newNode->value = rpnExpression[i];
            newNode->right = expStack.pop();
            newNode->left = expStack.pop();
            expStack.push(newNode);
        }
        else    //If it is an operand
        {
            newNode = (treeNode*)malloc(sizeof(treeNode));
            newNode->value = rpnExpression[i];
            newNode->right = NULL;
            newNode->left = NULL;
            expStack.push(newNode);
        }
    }
    root = newNode;
}

string ExpressionTree :: ReversePolishNotation(string expression)
{
    string rpnExpression = "";
    char topCharacter;
    Stack<char> expStack;
    expStack.push('(');

    for(int i=0;i<expression.length();i++)
    {
        /*If the incoming operator has lower or equal precendence,pop the operators from stack till precedence is  > top of stack
        or '(' is encountered*/

        //Since '+' and '-' has lowest precedence,therefore we need to pop all operators till "(" is encountered
        if(expression[i] == '+' || expression[i] == '-')
        {
            while((topCharacter = expStack.pop()) != '(')
            {
                rpnExpression += topCharacter;
            }
            expStack.push(topCharacter); //Since it got popped during condition check
            expStack.push(expression[i]);
        }
        else if(expression[i] == '*' || expression[i] == '/')
        {
            topCharacter = expStack.pop();
            while(topCharacter != '-' && topCharacter != '+' && topCharacter != '(')
            {
                rpnExpression += topCharacter;
                topCharacter = expStack.pop();
            }
            expStack.push(topCharacter);
            expStack.push(expression[i]);
        }
        else if(expression[i] == '^')
        {
            while((topCharacter = expStack.pop()) == '^')
            {
                rpnExpression += topCharacter;
            }
            expStack.push(topCharacter);
            expStack.push(expression[i]);
        }
        else if(expression[i] == ')')
        {
            while((topCharacter = expStack.pop()) != '(')
            {
                rpnExpression += topCharacter;
            }
        }
        else    //When an operand comes
        {
            rpnExpression += expression[i];
        }
    }
    while(!expStack.isEmpty())
    {
        if((topCharacter = expStack.pop()) != '(')
            rpnExpression += topCharacter;
        else
            expStack.pop();
    }

    cout<<"\n\tRPN Expression: "<<rpnExpression<<endl;
    return rpnExpression;
}

void ExpressionTree :: preOrderTraversal()
{
    cout<<"\n\tPre Order Traversal: ";
    preTraversal(root);
}

void ExpressionTree :: preTraversal(treeNode* root)
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
    ExpressionTree tree;
    tree.createTree("a+b*c-d/e");
    tree.preOrderTraversal();
    return 0;
}
