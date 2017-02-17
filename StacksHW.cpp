#include <iostream>
//Linux exit:
//#include <stdlib>
using namespace std;

//class RecommendedItme{}
//Node is a basic building block for your structure
class Node
{
public: 
	int value;
	Node *next;

	Node() 
	{
		value = -1;
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

	void push (int x) 
	{
		Node *temp = new Node;
		temp -> value = x;
		//top is null if stack is empty
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
			cout << " Empty stack..." << endl;
			return;
		}
		else 
		{
			top = top -> next; 
			cout << " About to delete: " << temp ->value << endl;
			delete temp;
		}
	}
	void display()
	{
		Node *temp;
		temp = top;

		cout << "Here is your stack: " << endl;
		while(temp)
		{
		cout << temp->value << " -> ";
		temp = temp-> next;
		}
		cout << "NULL" << endl;
	}
};

int main() 
{
	Stack stackObject;
	int choice, value;

	while (1)
	{
		cout << "Press 1 to add." << endl;
		cout << "Press 2 to delete. " << endl;
		cout << "Press 3 to display. " << endl;
		cout << "Anything else to exit. " <<endl;
		cin >> choice;

		switch (choice)
		{
		case 1: cout << "Enter the value you want to add" << endl;
					cin >> value;
					stackObject.push(value);
					break;
		case 2: stackObject.pop();
					break;
		case 3: stackObject.display();
					break;
		default: exit(1);
		}
	}


	system("pause");
	return 1;
}