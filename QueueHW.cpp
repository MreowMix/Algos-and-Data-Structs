#include <iostream>
using namespace std;

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

class Queue
{
public:
	Node *top;
	Queue()
	{
		top= NULL;
	}

	//This will be the entrance.
	void enQueue(int input)
	{
		Node *newNode = new Node();
		Node *current, *preNode;
		newNode->value = input;

		//If list is empty, add a node.
		if (top == NULL)
		{
			top = newNode;
			top->next=NULL;
		}
		else
		{
			current = top;
			preNode = top;
			//Travel to end of queue
			while(current)
			{
				preNode = current;
				current = current -> next;
			}
			//Adding at end
			preNode->next = newNode;
			newNode->next= NULL;
		}
	}

	//This will be the exit
	void deQueue()
	{
		Node *temp;
		temp = top;
		
		//If queue is empty
		if(top == NULL)
		{
			cout << "There is nothing to dequeue. " <<endl << endl;
			return;
		}
		else
		{
			//Exit at beginning
			if(temp->next != NULL)
			{
				top = top->next;
				delete temp;
			}
			else
			{
				delete temp;
				top = NULL;
			}
		}
	}

	//This will display
	void printContents()
	{
		Node *current;
		current = top;
		cout << "Here is your queue: " << endl;
		while (current)
		{
			cout << current ->value << " -> ";
			current = current->next;
		}
		cout << "NULL" << endl << endl;
	}
};

int main()
{
	Queue queueObj;
	int choice, input;

	while (1)
	{
		cout << "Press 1 to add to queue." << endl;
		cout << "Press 2 to remove from queue. " << endl;
		cout << "Press 3 to display the list. " <<endl;
		cout << "Anything else to exit. " <<endl;
		cin >> choice;

		switch (choice)
		{
		case 1: cout << "Enter a value to add to the queue: " << endl;
					cin >> input;
					queueObj.enQueue(input);
					break;
		case 2: cout << "Removing from queue." << endl;
					queueObj.deQueue();
					break;
		case 3: queueObj.printContents();
					break;
		default: exit(1);
		}
	}

	system("pause");
	return 1;
}