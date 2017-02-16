#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class Node{
public:
    Node *next;
    int value;

    //constructor
    Node(){
        next = NULL;
    }
};

class List{
private:
    void addFront(int input){
        Node *newNode = new Node();
        newNode->value = input;

        //if empty, add node
        if(head == NULL){
            head = newNode;
            head->next = NULL;
            tail = newNode;
            tail->next = NULL;
        }
        else{
            newNode->next = head;
            head = newNode;
        }
    }

    void addBack(int input){
        Node *newNode = new Node();
        newNode->value = input;
        tail = head;

        while(tail->next != NULL){
            tail = tail->next;
        }

        //if empty, add node
        if(head == NULL){
            newNode->next = NULL;
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            newNode->next = NULL;
            tail = newNode;
        }
    }

    void remove(int mode){
        Node *temp;

        if(head == NULL){
            cout << "Nothing to remove." << endl;
            return;
        }
        else{
            temp = head;
            //Remove Head
            if(mode == 0){
                if(temp->next != NULL){
                    head = head-> next;
                    delete temp;
                }
                else{
                    delete temp;
                    head = NULL;
                }
            }
            //Remove Tail
            else if(mode == 1){
                temp = head;
                while(temp->next != tail){
                    temp = temp->next;
                }
                tail = temp;
                temp = temp->next;
                delete temp;
                tail->next = NULL;
            }
            else
                cout << "Error removing." << endl;
        }
    }

public:
    Node *head, *tail;
    List(){
        head = NULL;
        tail = NULL;
    }

    void addBackCommand(int start, int step, int end){
        cout << "Adding to back ..." << endl;
        for(int i=start; i<=end; i+=step)
            addBack(i);
    }

    void addFrontCommand(int start, int step, int end){
        cout << "Adding to front ..." << endl;
        for(int i=start; i<=end; i+=step){
            addFront(i);
        }
    }
    void removeFront(int num){
        cout << "Removing " << num << " values from front." << endl;
        for(int i=0; i<num; i++)
            remove(0);
    }

    void removeBack(int num){
        cout << "Removing " << num << " values from back." << endl;
        for(int i=0; i<num; i++)
            remove(1);
    }

    void get(){
        cout << "Outputting!" << endl;
        Node *current;
        cout << "Here is your list: " << endl;
        current = head;
        while(current!=NULL){
            cout << current->value << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }

};

int main()
{
    List a;
    //fstream - outputs to file, inputs from HW4a.txt
    ifstream infile;
    infile.open("HW4b.txt");
    string command, line, num;
    int start, step, end, value;

    //opens file
    if(infile.good()){

        //stringstream to parse the command from
        stringstream iss;

        //extracts from "infile" to "command" until "commandDelim"
        while(!infile.eof()){
            while(getline(infile, line)){
                iss << line;
                getline(iss, command, ' ');
                if(command == "REMOVE_FRONT"){
                    getline(iss, num);
                    value = atoi(num.c_str());
                    a.removeFront(value);
                }
                else if(command == "REMOVE_BACK"){
                    getline(iss, num);
                    value = atoi(num.c_str());
                    a.removeBack(value);
                }
                else if(command == "ADD_BACK"){
                    getline(iss, num, ':');
                    start = atoi(num.c_str());
                    getline(iss, num, ':');
                    step = atoi(num.c_str());
                    getline(iss, num, ':');
                    end = atoi(num.c_str());
                    a.addBackCommand(start, step, end);
                }
                else if(command == "ADD_FRONT"){
                    getline(iss, num, ':');
                    start = atoi(num.c_str());
                    getline(iss, num, ':');
                    step = atoi(num.c_str());
                    getline(iss, num, ':');
                    end = atoi(num.c_str());
                    a.addFrontCommand(start, step, end);
                }
                else if(command == "OUTPUT")
                    a.get();
                else
                    cout << "Incorrect command" << endl << endl;
                iss.clear();
            }
        }
    }
    else
        cout << "Error: File not found." << endl;
}
