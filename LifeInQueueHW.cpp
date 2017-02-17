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
	Queue burgerLine;
	Node *pointer;
	//timeOfDay = 0 = 8AM (opening time)
	int count=0, customer, timeOfDay=0, waitTime;
	//variables to calculate averages
	double waitSum=0, sizeSum=0, avgCounter=0, sizeCount=0, serviceSum=0;
	//variables to calculate mins and maxes
	int waitMax=0, waitMin=7, sizeMax=0, sizeMin=0, serviceMax=0, serviceMin=0;
	//Time hold
	int waitMaxTime, waitMinTime=-1, sizeMaxTime=-1, sizeMinTime=-1, serviceMaxTime=-1,serviceMinTime=-1;

	srand(time(NULL));

	for(timeOfDay=0; timeOfDay<=1020;timeOfDay++)
	{
		customer = rand()%100;
		waitTime = rand()%6+1;
			
		if(timeOfDay <=120 &&customer <= 30)
		{
			burgerLine.enQueue(waitTime);
			waitSum += waitTime;
			serviceSum = burgerLine.serviceTot()+(burgerLine.getFront()-count);
			avgCounter++;

			//Min and Max for wait time
			if (waitMax < waitTime)
			{
				waitMax = waitTime;
				waitMaxTime = timeOfDay;
			}
			if(waitMin > waitTime)
			{
				waitMin = waitTime;
				waitMinTime = timeOfDay;
			}

			//Min and Max for service time
			if (serviceMax < serviceSum)
			{
				serviceMax = serviceSum;
				serviceMaxTime = timeOfDay;
			}
			if(serviceMin ==0)
			{
				serviceMin = serviceSum;
				serviceMinTime = timeOfDay;
			}
			else if(serviceMin > serviceSum)
			{
				serviceMin = serviceSum;
				serviceMinTime = timeOfDay;
			}
		}

		else if(timeOfDay >120 && timeOfDay <=210 && customer <= 10)
		{
			burgerLine.enQueue(waitTime);
			waitSum += waitTime;
			serviceSum = burgerLine.serviceTot()+(burgerLine.getFront()-count);
			avgCounter++;

			//Min and Max for wait time
			if (waitMax < waitTime)
			{
				waitMax = waitTime;
				waitMaxTime = timeOfDay;
			}
			if(waitMin > waitTime)
			{
				waitMin = waitTime;
				waitMinTime = timeOfDay;
			}

			//Min and Max for service time
			if (serviceMax < serviceSum)
			{
				serviceMax = serviceSum;
				serviceMaxTime = timeOfDay;
			}
			if(serviceMin ==0)
			{
				serviceMin = serviceSum;
				serviceMinTime = timeOfDay;
			}
			else if(serviceMin > serviceSum)
			{
				serviceMin = serviceSum;
				serviceMinTime = timeOfDay;
			}
		}
		else if(timeOfDay >210 && timeOfDay <=330 && customer <= 40)
		{
			burgerLine.enQueue(waitTime);
			waitSum += waitTime;
			serviceSum = burgerLine.serviceTot()+(burgerLine.getFront()-count);
			avgCounter++;

			//Min and Max for wait time
			if (waitMax < waitTime)
			{
				waitMax = waitTime;
				waitMaxTime = timeOfDay;
			}
			if(waitMin > waitTime)
			{
				waitMin = waitTime;
				waitMinTime = timeOfDay;
			}

			//Min and Max for service time
			if (serviceMax < serviceSum)
			{
				serviceMax = serviceSum;
				serviceMaxTime = timeOfDay;
			}
			if(serviceMin ==0)
			{
				serviceMin = serviceSum;
				serviceMinTime = timeOfDay;
			}
			else if(serviceMin > serviceSum)
			{
				serviceMin = serviceSum;
				serviceMinTime = timeOfDay;
			}
		}
		else if(timeOfDay >330 && timeOfDay <=570 && customer <= 10)
		{
			burgerLine.enQueue(waitTime);
			waitSum += waitTime;
			serviceSum = burgerLine.serviceTot()+(burgerLine.getFront()-count);
			avgCounter++;

			//Min and Max for wait time
			if (waitMax < waitTime)
			{
				waitMax = waitTime;
				waitMaxTime = timeOfDay;
			}
			if(waitMin > waitTime)
			{
				waitMin = waitTime;
				waitMinTime = timeOfDay;
			}

			//Min and Max for service time
			if (serviceMax < serviceSum)
			{
				serviceMax = serviceSum;
				serviceMaxTime = timeOfDay;
			}
			if(serviceMin ==0)
			{
				serviceMin = serviceSum;
				serviceMinTime = timeOfDay;
			}
			else if(serviceMin > serviceSum)
			{
				serviceMin = serviceSum;
				serviceMinTime = timeOfDay;
			}
		}
		else if(timeOfDay >570 && timeOfDay <=720 && customer <= 25)
		{
			burgerLine.enQueue(waitTime);
			waitSum += waitTime;
			serviceSum = burgerLine.serviceTot()+(burgerLine.getFront()-count);
			avgCounter++;

			//Min and Max for wait time
			if (waitMax < waitTime)
			{
				waitMax = waitTime;
				waitMaxTime = timeOfDay;
			}
			if(waitMin > waitTime)
			{
				waitMin = waitTime;
				waitMinTime = timeOfDay;
			}

			//Min and Max for service time
			if (serviceMax < serviceSum)
			{
				serviceMax = serviceSum;
				serviceMaxTime = timeOfDay;
			}
			if(serviceMin ==0)
			{
				serviceMin = serviceSum;
				serviceMinTime = timeOfDay;
			}
			else if(serviceMin > serviceSum)
			{
				serviceMin = serviceSum;
				serviceMinTime = timeOfDay;
			}
		}
		else if(timeOfDay >720 && timeOfDay <=900 && customer <= 20)
		{
			burgerLine.enQueue(waitTime);
			waitSum += waitTime;
			serviceSum = burgerLine.serviceTot()+(burgerLine.getFront()-count);
			avgCounter++;

			//Min and Max for wait time
			if (waitMax < waitTime)
			{
				waitMax = waitTime;
				waitMaxTime = timeOfDay;
			}
			if(waitMin > waitTime)
			{
				waitMin = waitTime;
				waitMinTime = timeOfDay;
			}

			//Min and Max for service time
			if (serviceMax < serviceSum)
			{
				serviceMax = serviceSum;
				serviceMaxTime = timeOfDay;
			}
			if(serviceMin ==0)
			{
				serviceMin = serviceSum;
				serviceMinTime = timeOfDay;
			}
			else if(serviceMin > serviceSum)
			{
				serviceMin = serviceSum;
				serviceMinTime = timeOfDay;
			}
		}
		else if(timeOfDay >900 && timeOfDay <=1020 && customer <= 10)
		{
			burgerLine.enQueue(waitTime);
			waitSum += waitTime;
			serviceSum = burgerLine.serviceTot()+(burgerLine.getFront()-count);
			avgCounter++;

			//Min and Max for wait time
			if (waitMax < waitTime)
			{
				waitMax = waitTime;
				waitMaxTime = timeOfDay;
			}
			if(waitMin > waitTime)
			{
				waitMin = waitTime;
				waitMinTime = timeOfDay;
			}

			//Min and Max for service time
			if (serviceMax < serviceSum)
			{
				serviceMax = serviceSum;
				serviceMaxTime = timeOfDay;
			}
			if(serviceMin ==0)
			{
				serviceMin = serviceSum;
				serviceMinTime = timeOfDay;
			}
			else if(serviceMin > serviceSum)
			{
				serviceMin = serviceSum;
				serviceMinTime = timeOfDay;
			}
		}


		sizeSum+=burgerLine.getSize();
		if (sizeMax < burgerLine.getSize())
		{
			sizeMax = burgerLine.getSize();
			sizeMaxTime = timeOfDay;
		}
		if(sizeMin == 0)
		{
			sizeMin = burgerLine.getSize();
			sizeMinTime = timeOfDay;
		}
		else if(sizeMin > burgerLine.getSize())
		{
			sizeMin = burgerLine.getSize();
			sizeMinTime = timeOfDay;
		}
		sizeCount++;	
		//Dequeue statement
		if(count == burgerLine.getFront())
		{
			burgerLine.deQueue();
			count=1;
		}
		else if(burgerLine.getFront() != -1 && count < burgerLine.getFront())
		{
			count++;
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

	//wait
	cout << "The average wait time was: " << avgWait << endl;
	if(waitMinTime==-1)
		cout << "There was no minimum wait time." << endl;
	else
		cout << "The minimum wait time was: " << waitMin << " at time " << waitMinTime  << endl;
	if(waitMax==0)
		cout << "There was no maximum wait time." << endl;
	else
		cout << "The maximum wait time was: " << waitMax << " at time " << waitMaxTime << endl;

	//service
	cout << "The average service time was: " << avgService << endl;
	if(serviceMinTime==-1)
		cout << "There was no minimum service time." << endl;
	else
		cout << "The minimum service time was: " << serviceMin << " at time " << serviceMinTime  << endl;
	if(serviceMax==0)
		cout << "There was no maximum service time." << endl;
	else
		cout << "The maximum service time was: " << serviceMax << " at time " << serviceMaxTime << endl;

	//queue
	cout << "The average queue length was: " << avgLength << endl;
	cout << "The minimum queue length was: " << sizeMin << " at time " << sizeMinTime  << endl;
	if(sizeMax==0)
		cout << "There was no maximum queue length time." << endl;
	else
		cout << "The maximum queue length was: " << sizeMax << " at time " << sizeMaxTime << endl;

	system("pause");
	return 1;
}