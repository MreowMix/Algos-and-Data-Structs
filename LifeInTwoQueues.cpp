#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

//customer places random order between  1 and 6 minutes
//customers arrive with pa(t)
//pa() = probability of arrival which is a function of the time of day.

//average wait time
//average service time
//average queue length
//best and worst case (min/max) & what time did that happen for each of the above
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
	
	//Returns first in queue
	int getFront()
	{
		if(top!=NULL)
			return top->value;
		else
			return -1;
	}

	//Returns the size of the queue
	int getSize()
	{
		int count=0;
		Node *current;
		current = top;
		while(current!=NULL)
		{
			current=current->next;
			count++;
		}
		return count;
	}

	//Returns the sum of all values in queue except for the first
	int serviceTot()
	{
		int count=0, sum=0;
		Node *traverse;
		if(top != NULL && top->next !=NULL)
		{
			traverse = top->next;
			while (traverse !=NULL)
			{
				sum +=traverse->value;
				traverse = traverse->next;
			}
		}
		else
			sum+=0;

		return sum;
	}
	
};

int main()
{
	Queue lineA, lineB;
	Node *pointer;
	int countA=0, countB=0, customer, timeOfDay=0, waitTime;
	int FrontA, FrontB;
	double waitSum=0, sizeSum=0, avgCounter=0, sizeCount=0, serviceSum=0;

	srand(time(NULL));

	for(timeOfDay=0; timeOfDay<=1020;timeOfDay++)
	{
		customer = rand()%100;
		waitTime = rand()%6+1;
			
		if(timeOfDay <=120 &&customer <= 30)
		{
			if(lineA.getSize()<=lineB.getSize())
			{
				lineA.enQueue(waitTime);
			}
			else
			{
				lineB.enQueue(waitTime);
			}
			waitSum += waitTime;

			if(lineA.getFront() == -1)
				FrontA = 0;
			else
				FrontA=lineA.getFront();
			if(lineB.getFront() == -1)
				FrontB = 0;
			else
				FrontB=lineB.getFront();

			serviceSum = lineA.serviceTot()+(FrontA-countA)+lineB.serviceTot()+(FrontB-countB);
			avgCounter++;
		}
		else if(timeOfDay>120 && timeOfDay<=210 && customer <= 10)
		{
			if(lineA.getSize()<=lineB.getSize())
			{
				lineA.enQueue(waitTime);
			}
			else
			{
				lineB.enQueue(waitTime);
			}
			waitSum += waitTime;
			serviceSum = lineA.serviceTot()+(lineA.getFront()-countA)+lineB.serviceTot()+(lineB.getFront()-countB);
			avgCounter++;
		}
		else if(timeOfDay>210 && timeOfDay<=330 && customer <= 40)
		{
			if(lineA.getSize()<=lineB.getSize())
			{
				lineA.enQueue(waitTime);
			}
			else
			{
				lineB.enQueue(waitTime);
			}
			waitSum += waitTime;
			serviceSum = lineA.serviceTot()+(lineA.getFront()-countA)+lineB.serviceTot()+(lineB.getFront()-countB);
			avgCounter++;
		}
		else if(timeOfDay>330 && timeOfDay<=570 && customer <= 10)
		{
			if(lineA.getSize()<=lineB.getSize())
			{
				lineA.enQueue(waitTime);
			}
			else
			{
				lineB.enQueue(waitTime);
			}
			waitSum += waitTime;
			serviceSum = lineA.serviceTot()+(lineA.getFront()-countA)+lineB.serviceTot()+(lineB.getFront()-countB);
			avgCounter++;
		}
		else if(timeOfDay>570 && timeOfDay<=720 && customer <= 25)
		{
			if(lineA.getSize()<=lineB.getSize())
			{
				lineA.enQueue(waitTime);
			}
			else
			{
				lineB.enQueue(waitTime);
			}
			waitSum += waitTime;
			serviceSum = lineA.serviceTot()+(lineA.getFront()-countA)+lineB.serviceTot()+(lineB.getFront()-countB);
			avgCounter++;
		}
		else if(timeOfDay>720 && timeOfDay<=900 && customer <= 20)
		{
			if(lineA.getSize()<=lineB.getSize())
			{
				lineA.enQueue(waitTime);
			}
			else
			{
				lineB.enQueue(waitTime);
			}
			waitSum += waitTime;
			serviceSum = lineA.serviceTot()+(lineA.getFront()-countA)+lineB.serviceTot()+(lineB.getFront()-countB);
			avgCounter++;
		}
		else if(timeOfDay>900 && timeOfDay<=1020 && customer <= 10)
		{
			if(lineA.getSize()<=lineB.getSize())
			{
				lineA.enQueue(waitTime);
			}
			else
			{
				lineB.enQueue(waitTime);
			}
			waitSum += waitTime;
			serviceSum = lineA.serviceTot()+(lineA.getFront()-countA)+lineB.serviceTot()+(lineB.getFront()-countB);
			avgCounter++;
		}

		sizeSum=sizeSum+lineA.getSize()+lineB.getSize();
		sizeCount++;	

		if(countA == lineA.getFront())
		{
			lineA.deQueue();
			countA=1;
		}
		else if(lineA.getFront() != -1 && countA < lineA.getFront())
		{
			countA++;
		}
		if(countB == lineB.getFront())
		{
			lineB.deQueue();
			countB=1;
		}
		else if(lineB.getFront() != -1 && countB < lineB.getFront())
		{
			countB++;
		}
	}

	//Calculations for averages
	double avgWait = waitSum/avgCounter;
	if(waitSum == 0)
		avgWait = 0;
	double avgService = serviceSum/avgCounter;
	if(serviceSum == 0)
		avgService = 0;
	double avgLength = sizeSum/sizeCount;
	if(sizeSum == 0)
		avgLength = 0;

	cout << "The average wait time was: " << avgWait << endl;
	cout << "The average service time was: " << avgService << endl;
	cout << "The average queue length was: " << avgLength << endl;

	system("pause");
	return 1;
}