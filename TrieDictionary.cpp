#include <iostream>
#include <fstream>
#include <string>
using namespace std;

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

    void load(string word){
        int offset, wordLength;
        //need to lowercase;

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
    bool contains(string word){
        Node *current = root;
        int offset, wordLength;
        wordLength = (int)word.length();

        for(int i=0; i < wordLength; i++){
            offset = (int)word[i] - (int)'a';
            //if pointer of next letter doesn't exist, not a word
            if(current->next[offset] == NULL)
                    return false;
            current = current->next[offset];
        }
        return current->isWord;
    }

    //Retruns true if contains anywords that starts with these letters
    bool startsWith(string prefix){
        Node* current = root;
        int offset, prefixLength, letter;
        letter = 0;
        prefixLength = (int)prefix.length();

        for(int i=0; i < prefixLength; i++){
            offset = (int)prefix[i] - (int)'a';
            if(current->next[offset] == NULL)
                    return false;
            else
                current = current->next[offset];
        }
        return true;
    }
};

int main()
{
    //fstream inputs from HW4a.txt
    Trie a;
    ifstream dictFile, infile;
    dictFile.open("dict.txt");
    infile.open("HW6a.txt");
    string word;

    if(dictFile.good()){
        //extracts from "dictFile" to "word" line by line
        while(!dictFile.eof()){
            getline(dictFile, word);
            a.load(word);
        }
        cout << "Successfully loaded dictionary." << endl << endl;

        //opens file
        if(infile.good()){
            while(!infile.eof()){
                //extracts from "infile" to "word"
                getline(infile, word);
                if (a.contains(word))
                    cout << "YES: The word <<" << word << ">> exists in the dictionary." << endl;
                else
                    cout << "NO: The word <<" << word << ">> DOES NOT exist in the dictionary." << endl;

                //Determine if words are prefixes
                if (a.startsWith(word))
                    cout << "YES: There exists words that start with <<" << word << ">> in the dictionary." << endl;
                else
                    cout << "NO: There DOES NOT exist words that start with <<" << word << ">> in the dictionary." << endl;
                cout << endl;
            }
        }
        else
            cout << "Error: HW file not found." << endl;
    }
    else
        cout << "Error: Dictionary File not found." << endl;

}
