#include <iostream>
#include <fstream>
#include <string>
#define NUM_BIN 500000
#define HIST_NUM 11
using namespace std;

//T testing
//T cat
//F harrassmentation
//F Yu-Dong
//T advertisement

class Node{
public:
    Node *next;
    int value;

    Node(){
        next = NULL;
    }
};

class List{
public:
    Node *head;
    List(){
        head = NULL;
    }

    ~List(){
        Node *current, *temp;
        if(head != NULL){
            for(current=head; current->next != NULL; current=temp){
                temp = current->next;
                delete current;
            }
        }
    }

    void addFront(int input){
        Node *newNode = new Node();
        newNode->value = input;

        //if empty, add node
        if(head == NULL){
            head = newNode;
            head->next = NULL;
        }
        else{
            newNode->next = head;
            head = newNode;
        }
    }

    void removeFront(){
        if(head != NULL){
            Node *temp = head;
            if(temp->next != NULL){
                head = head-> next;
                delete temp;
            }
            else{
                delete temp;
                head = NULL;
            }
        }
    }

    void removeBack(){
        Node *temp = head->next;
        Node *current = head;
        while(temp->next != NULL){
            temp = temp->next;
            current = current->next;
        }
        delete temp;
        current->next = NULL;
    }

    int size(){
        Node *current = head;
        int count = 0;
        while(current!=NULL){
            count++;
            current = current->next;
        }
        return count;
    }
};


class HashMap{
private:
    int mapSize;

    unsigned long charHash(const char *str){
        unsigned long hash = 5381;
        int c = 0;

        while (c = *str++)
            hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

        return hash;
    }

public:
    List* hMap;

    HashMap(int size){
        hMap = new List[size];
        mapSize = size;
    }

    ~HashMap(){
        delete[] hMap;
    }

    int hashNum(unsigned long v){
        return v%mapSize;
    }

    void addWord(const char *str){
        unsigned long hValue = charHash(str);
        int position = hashNum(hValue);
        hMap[position].addFront(hValue);
    }

    bool contains(const char *str){
        unsigned long hValue = charHash(str);
        int position = hashNum(hValue);
        Node *current = hMap[position].head;
        while(current != NULL){
            if(current->value == hValue)
                return true;
            else
                current = current->next;
        }
        return false;
    }

    void hist(){
        int *histogram = new int[HIST_NUM];
        for(int i=0; i<HIST_NUM; i++)
            histogram[i] = 0;
        for(int i=0; i<mapSize; i++){
            int size = hMap[i].size();
            if (size > 10)
                size = 10;
            histogram[size]++;
        }

        cout << "--- HISTOGRAM ---" << endl;
        cout << "Insert      Count" << endl;
        for(int i=0; i<HIST_NUM; i++){
            cout << " " << i << "\t  " << histogram[i] << endl;
        }
    }
};

int main()
{
    //fstream inputs from HW4a.txt
    HashMap h(NUM_BIN);
    ifstream dictFile, infile;
    dictFile.open("dict.txt");
    infile.open("HW8.txt");
    string word;

    if(dictFile.good()){
        //extracts from "dictFile" to "word" line by line
        while(!dictFile.eof()){
            getline(dictFile, word);
            h.addWord(word.c_str());
        }
        cout << "Successfully loaded dictionary." << endl << endl;

        //opens file
        if(infile.good()){
            while(!infile.eof()){
                //extracts from "infile" to "word"
                getline(infile, word);
                if (h.contains(word.c_str()))
                    cout << "YES: The word <<" << word << ">> exists in the dictionary." << endl;
                else
                    cout << "NO: The word <<" << word << ">> DOES NOT exist in the dictionary." << endl;
                cout << endl;
            }
            h.hist();
        }
        else
            cout << "Error: HW file not found." << endl;
    }
    else
        cout << "Error: Dictionary File not found." << endl;

}
