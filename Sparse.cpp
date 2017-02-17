#include <iostream>
#include <time.h>
using namespace std;

class Node
{
public: 
	int value, locR, locC;
	Node *next;

	//constructor
	Node()
	{
		value = -1;
		locC = -1;
		locR = -1;
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
	void listMatrix(int input, int col, int row)
	{
		Node *newNode = new Node();
		Node *current, *preNode;
		newNode -> value = input;
		newNode -> locC = col;
		newNode -> locR = row;

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

	void createMatrixA(int row, int col)
	{
		int m = col;
		int n = row;

		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=m; j++)
			{
				int random = rand()%100 + 1;
				if(random <=5)
				{
					listMatrix(7, j, i);
				}
			}
		}
	}

	void createMatrixB(int row, int col)
	{
		int m = col;
		int n = row;

		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=m; j++)
			{
				int random = rand()%100 + 1;
				if(random <=5)
				{
					listMatrix(7, j, i);
				}
			}
		}
	}

	void addMatrixC(List matrixA, List matrixB, int row, int col)
	{
		Node *currentA, *currentB, *traverse;
		currentA = matrixA.top;
		currentB = matrixB.top;
		int sum=0;
		int total = row*col;
		
		if(currentA == NULL && currentB != NULL)
		{
			while(currentB != NULL)
			{
				listMatrix(currentB->value, currentB->locC, currentB->locR);
			}
		}
		else if(currentA != NULL && currentB == NULL)
		{
			while(currentA != NULL)
			{
				listMatrix(currentA->value, currentA->locC, currentA->locR);
			}
		}
		else
		{
			while(currentA != NULL)
			{
				while(currentB !=NULL)
				{
					if(currentA->locC == currentB->locC && currentA->locR == currentB->locR)
					{
						sum = currentA->value + currentB->value;
						listMatrix(sum, currentA->locC, currentA->locR);
						currentB = currentB->next;
					}
					else
					{
						listMatrix(currentA->value, currentA->locC, currentA->locR);
						listMatrix(currentB->value, currentB->locC, currentB->locR);
						currentB = currentB->next;
					}
				}
			currentA = currentA->next;
			}
		}
	}

	//This will display the list.
	void displayContents(int row, int col)
	{
		Node *current, *traverse;
		traverse = top;
		current = top;
		int total;
		total = row * col;
		int countC=1, countR=1;

	if(current != NULL)
		{
			while(countR <= row)
			{
				if(countC <= col)
				{
					if(countC == current->locC && countR == current->locR)
					{
						cout << " " << current->value << " ";
						countC++;
						if(current->next != NULL)
							current = current->next;
					}
					else
					{
						cout << " 0 ";
						countC++;
					}
				}
				else
				{
					cout << endl;
					countC = 1;
					countR++;
				}
			}
		}
		else
			cout << endl;
		cout << endl;
	}

	void displaylist()
	{
		Node *current;
		current = top;
		cout << "Here is your queue: " << endl;
		while (current)
		{
			cout << current ->value << ", " << current->locC << ", " << current->locR << " -> ";
			current = current->next;
		}
		cout << "NULL" << endl << endl;
	}

};

int main()
{
	List matrixA, matrixB, matrixC;
	int choice, input, pos;
	int row, col;

	srand(time(NULL));

	cout << "How many rows?" << endl;
	cin >> row;
	cout << "How many columns?" << endl;
	cin >> col;

	matrixA.createMatrixA(row, col);
	matrixB.createMatrixB(row, col);
	matrixC.addMatrixC(matrixA, matrixB, row, col);

	matrixA.displaylist();
	matrixB.displaylist();
	matrixC.displaylist();

	while(1)
	{
		cout << "Press 1 to display MatrixA." << endl;
		cout << "Press 2 to display MatrixB. " << endl;
		cout << "Press 3 to display MatrixC (A+B). " << endl;
		cout << "Anything else to exit. " <<endl;
		cin >> choice;

		switch (choice)
		{
		case 1: 	matrixA.displaylist();
					matrixA.displayContents(row, col);
					break;
		case 2:	matrixB.displaylist();
					matrixB.displayContents(row, col);
					break;
		case 3: matrixC.displaylist();
					matrixC.displayContents(row, col);
					break;

		default: exit(1);
		}
	}
	return 1;
}