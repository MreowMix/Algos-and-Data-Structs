#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#define MIN_LEN 3
using namespace std;

//Node for Trie
class Node{
public:
    Node* next[26];
    bool isWord; //216 bytes min

    Node(){
        for(int i = 0; i < 26; i++){
            next[i] = NULL;
            isWord = false;
        }
    }
};

class Trie{
public:
    Node *root; //node is 268 bytes
    Trie(){
        root = new Node();
    }

    //loads word into the trie
    void load(string word){
        int offset, wordLength;
        //Determines length of word
        wordLength = (int)word.length();
        Node *current = root;

        for(int i=0; i < wordLength; i++){
            offset = (int)word[i] - (int)'a';
            //INITIAL CASE: if pointer of letter doesn't exist, add the letter
            if(current->next[offset] == NULL)
                current->next[offset] = new Node();
            current = current->next[offset];
        }
        current->isWord = true;
    }

    //Returns true if word is found in dictionary previously loaded.
    //0 = nonexistant
    //1 = letter exists
    //2 = is word
    int contains(int offset, int max){
        Node *current = root;
        //if offset does not exist, returns 0
        if(current->next[offset] == NULL)
                return 0;
        //if offset exists, returns 1
        else{
            current = current->next[offset];
            return 1;
            //if offset exists and is word, return 2
            if(current->isWord)
                return 2;
        }
    }
};


//Node for List
class ListNode{
public:
    ListNode *next;
    int value;

    ListNode(){
        next = NULL;
    }
};

class List{
public:
    ListNode *head;
    List(){
        head = NULL;
    }

    ~List(){
        ListNode *current, *temp;
        if(head != NULL){
            for(current=head; current->next != NULL; current=temp){
                temp = current->next;
                delete current;
            }
        }
    }

    //Adds node to end of list
    void addBack(int input){
        ListNode *newNode = new ListNode();
        newNode->value = input;
        ListNode *current = head;

        //if empty, add node
        if(head == NULL){
            newNode->next = NULL;
            head = newNode;
        }
        else{
            while(current->next != NULL)
                current = current->next;
            current->next = newNode;
            newNode->next = NULL;
            current = newNode;
        }
    }
    //returns current value of node at position v
    int get(int v){
        ListNode *current = head;
        for(int i=0; i<v; i++)
            current = current->next;
        return current->value;
    }

    //prints out everything in the list
    void print(){
        ListNode *current = head;
        while(current->value != NULL){
            cout << current->value;
            current = current->next;
        }
    }
    //determines the size of the list
    int size(){
        ListNode *current = head;
        int count = 0;
        while(current!=NULL){
            count++;
            current = current->next;
        }
        return count;
    }
};

class Boggle{
private:
    int mapSize;

public:
    List* hMap;

    Boggle(int size){
        hMap = new List[size];
        mapSize = size;
    }

    ~Boggle(){
        delete[] hMap;
    }

    //adds the character offset at the position given
    void addWord(int pos, int value){
        hMap[pos].addBack(value);
    }

    //determines the current value at the current column and row
    int is(int col, int row){
        ListNode *current = hMap[col].head;
        if(row == 0)
            return hMap[col].head->value;
        for(int i=0; i<row; i++){
            if(current->value != NULL)
                current = current->next;
        }
        return current->value;
    }

    //searches and traverses the boggle board
    void search(int k, int col, int row, List found, Trie dict){
        //if row and columns are within 0 and board size and the list is not null
        //check if the offset value exists in the dictionary and check the return value
        //if 1, continue and add to the list of found letters and increment size of current letters found
        //if size of current letters found is greater than n2, return and exit
        if(row>=0 && row<mapSize && col>=0 && col<mapSize && hMap[col].get(row) != NULL){
            if(dict.contains(hMap[col].get(row), mapSize*mapSize) == 1){
                found.addBack(hMap[col].get(row));
                k++;
                if(k > mapSize*mapSize)
                    return;
            }
            //if size of current letters found is greater than 3 and if the offset value returns 2 from the dictionary, print the word
            if(k>=3 && dict.contains(hMap[col].get(row), mapSize*mapSize) == 2)
                found.print();

            //search all neighbors
            search(k, row-1, col-1, found, dict);
            search(k, row-1, col, found, dict);
            search(k, row-1, col+1, found, dict);
            search(k, row, col-1, found, dict);
            search(k, row, col+1, found, dict);
            search(k, row+1, col-1, found, dict);
            search(k, row+1, col, found, dict);
            search(k, row+1, col+1, found, dict);
        }
    }
};

/*
4
a e t m
s n i a
e r f o
b a t i
*/

int main()
{
    //fstream inputs from HW4a.txt
    Trie dict;
    List found;
    ifstream dictFile, infile;
    dictFile.open("dict.txt");
    infile.open("boggle.txt");
    string line, word, num, letter;
    int tabSize, offset;

    if(dictFile.good()){
        //extracts from "dictFile" to "word" line by line
        while(!dictFile.eof()){
            getline(dictFile, word);
            dict.load(word);
        }
        cout << "Successfully loaded dictionary." << endl << endl;

        //opens file
        if(infile.good()){
            stringstream iss;
            while(!infile.eof()){
                //extracts from "infile" to "word"
                //first line represents the size
                getline(infile, num);
                tabSize = atoi(num.c_str());
                cout << "Reading " << num << "x" << num << " grid." << endl;
                Boggle tab(tabSize);
                cout << "Created Boggle List." << endl;
                while(getline(infile, line)){
                    iss << line;
                    for(int i=0; i<tabSize; i++){
                        getline(iss, letter, ' ');
                        offset = (int)letter[0] - (int)'a';
                        tab.addWord(i, offset);
                        cout << letter << "," << offset << "\t";
                    }
                    cout << endl;
                    iss.clear();
                }

                //search the board
                for(int i=0; i<tabSize; i++){
                    for(int j=0; j<tabSize; j++){
                        tab.search(0,i,j, found, dict);
                    }
                }
            }
        }
        else
            cout << "Error: HW file not found." << endl;
    }
    else
        cout << "Error: Dictionary File not found." << endl;

}
