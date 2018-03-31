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


int main()
{
	Stack<char> stack;
//	cout<<sizeof(stack);
	stack.push('c');
	stack.push('j');
	stack.push('i');
	cout<<"Poped: "<<stack.pop();
	cout<<"Poped: "<<stack.pop();
//	stack.pop();
//	stack.pop();
//	stack.pop();
//	stack.push('h');
//	cout<<sizeof(stack);
	stack.returnTop();
	cout<<"Size of Stack: "<<stack.getSize();
	return 0;
}
