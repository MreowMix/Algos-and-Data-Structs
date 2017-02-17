#include <iostream>
using namespace std;

class Node
{
public: 
	char value;
	Node *next;

	Node() 
	{
		value = 0;
		next = NULL;
	}
};

class Stack 
{
public: 
	Node *top;
	
	Stack() 
	{
		top = NULL;
	}

	void push (char x) 
	{
		Node *temp = new Node;
		temp -> value = x;
		if(top == NULL)
			top = temp;
		else 
		{
			temp -> next = top;
			top =temp;
		}
	}

	void pop() 
	{
		Node *temp;
		temp = top;
		if(top == NULL)	
		{
			cout << " Empty stack." << endl;
			return;
		}
		else 
		{
			top = top -> next; 
			delete temp;
		}
	}

	char getLast()
	{
		Node *last;
		last = top;
		while (last!=NULL)
			last = last->next;
		return last->value;
	}

	int readChar()
	{
		//returns the next character in a program text
	}

	int checkParentheses()
	{
		Stack stackpar;
		Node *current;
		current = top;
		char nextChar = readChar();
		while (nextChar != EOF)
		{
			if(nextChar == '(' || nextChar == '[' || nextChar == '{')
			{
				if(nextChar == '(')
					stackpar.push(')');
				else if(nextChar == '{')
					stackpar.push('}');
				else if(nextChar == '[')
					stackpar.push(']');
			}
			else if (nextChar == ')' || nextChar == ']' || nextChar == '}')
			{
				if(stackpar.getLast() == nextChar)
					stackpar.pop();
				else
					return -1;
			}
			nextChar = readChar();
		}
		if(current == NULL)
			return 1;
	}
};