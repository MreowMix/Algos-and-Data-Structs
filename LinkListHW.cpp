#include <iostream>
using namespace std;

class Node
{
public: 
	int value;
	Node *next;

	//constructor
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

	//This will insert at the beginning of the list.
	void insertAtHead(int input)
	{
		Node *newNode = new Node();
		newNode -> value = input;

		//If list is empty, add a node.
		if(top==NULL)
		{
			top = newNode;
			top->next = NULL;
		}
		//If list is not empty.
		else
		{
			newNode -> next = top;
			top=newNode;
		}
	}

	//This will insert at a position.
	void insertAtPos(int position, int input)
	{
		Node *preNode, *current;
		Node *newNode = new Node();
		newNode->value = input;
		int count=0;
		current = top;
		preNode=top;

		//CASE 1: List is empty
		if(top == NULL)
		{
			newNode->next = NULL;
			top = newNode;
		}

		//CASE 2, 3, 4: Insert at beginning, in middle, at end
		else
		{
			while (current->next!=NULL && count < position)
			{
				preNode = current;
				current = current->next;
				count++;
			}
			//Case 2: Insert at beginning
			if(preNode==current && position<=0)
			{
				newNode->next = top;
				top = newNode;
			}
			//Case 4: Insert at end;
			else if(current->next==NULL)
			{
				current->next = newNode;
				newNode->next= NULL;
			}
			//Case 3: Insert at middle because neither end or beginning
			else
			{
				preNode->next= newNode;
				newNode->next = current;
			}
		}
	}

	//This will remove at a position.
	void removeFromPos(int position)
	{
		Node *temp, *traverse;
		int count=0;
		
		//Check to make sure there is something in the list.
		if(top == NULL)
		{
			cout << "Nothing to remove." << endl;
			return;
		}
		//If there is at least something in the list, will remove.
		else
		{
			temp = top;
			traverse = top;
			while(temp->next!=NULL && count < position)
			{
				traverse = temp;
				temp = temp->next;
				count ++;
			}

			//CASE 2: Removing beginning
			if(traverse == temp || position <= 0)
			{
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

			//CASE 4: Removing end
			else if (temp->next == NULL)
			{
				delete temp;
				traverse->next=NULL;
			}

			//CASE 3: Removing middle
			else
			{
				traverse->next = temp->next;
				delete temp;
			}
		}
	}

	//This will display the list.
	void displayContents()
	{
		Node *current;
		cout << "Here is your list: " << endl;
		//while current is not NULL
		current = top;
		while (current != NULL)
		{
			cout << current ->value << " -> ";
			current = current->next;
		}
		cout << " NULL" << endl;
	}
};

int main()
{
	List listObject;
	int choice, input, pos;

	while (1)
	{
		cout << "Press 1 to add at head." << endl;
		cout << "Press 2 to insert at a position. " << endl;
		cout << "Press 3 to remove at a position. " << endl;
		cout << "Press 4 to display the list. " <<endl;
		cout << "Anything else to exit. " <<endl;
		cin >> choice;

		switch (choice)
		{
		case 1: cout << "Enter the new head: " <<endl;
					cin >> input;
					listObject.insertAtHead(input);
					break;
		case 2: cout << "Enter the position to add: " << endl;
					cin >> pos;
					cout << "Enter the value you want to add: " << endl;
					cin >> input;
					listObject.insertAtPos(pos, input);
					break;
		case 3: cout << "Enter the position to delete: " << endl;
					cin >> pos;
					listObject.removeFromPos(pos);
					break;
		case 4: listObject.displayContents();
					cout << endl;
					break;
		default: exit(1);
		}
	}

	system("pause");
	return 1;
}