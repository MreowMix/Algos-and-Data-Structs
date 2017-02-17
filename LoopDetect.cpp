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

class List
{
public: 
	Node *top;
	List()
	{
		top=NULL;
	}

	int getLength()
	{
		//returns length of list
	}

	void detectRemoveLoop(Node *top)
	{
		List listobj;
		int size = getLength();
		Node *current, *prev, *loop, *head;
		current = top;
		prev = top;
		int count = 0;

		if(top == NULL)
		{
			cout << "There is no loop." << endl;
			return;
		}
		else
		{
			while (count < size)
			{
				prev = prev->next;
				current = current->next->next;
				if(prev == current)
				{
					cout << "A loop was found." << endl;
					loop = current->next;
					head = top;
					while(1)
					{
						while (current->next != loop && current ->next !=top)
						{
							current = current->next;
						}
						if(current->next = head)
							break;
						else
							head = head->next;
					}
					current->next = NULL;
				}
				count ++;
			}
			cout << "There is no loop." << endl;

		}
	}
};