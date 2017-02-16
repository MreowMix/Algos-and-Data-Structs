#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

class GrowArray {
private:
    int* data;
    int used, capacity;

    void updateCapacity(int newCapacity){
        int* newData = new int[newCapacity];
        for(int i=0; i<=used; i++)
            newData[i] = data[i];
        capacity = newCapacity;
        delete[] data;
        data = newData;
    }

    void addBack(int v){
        //if number of elements used = available capacity, increment available capacity by 2 times.
        if(used == capacity)
            updateCapacity(capacity*2);
        //if array is empty, set first to value, else set last element of used to the value
        if(used == 0)
            data[0] = v;
        else
            data[used] = v;
        //increment used
        used++;
    }

    void addFront(int v){
        //if number of elements used = available capacity, increment available capacity by 2 times.
        if(used == capacity){
            updateCapacity(capacity*2);
        }
        //copy data into a temp
        int* temp = new int[capacity];
        for(int i=0; i<=used; i++)
            temp[i] = data[i];
        //if adding to empty array, set first element to the value
        if(used == 0){
            data[0] = v;
        }
        //move each element to the next spot
        else{
            for(int i=0; i<used; i++)
                data[i+1] = temp[i];
            data[0] = v;
        }
        //increment used
        used++;
    }

public:
    GrowArray(int initialCapacity) {
        capacity = initialCapacity;
        data = new int[capacity];
        used = 0;
    }

    ~GrowArray() {
        delete [] data;
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

    void removeBack(int v) {
        cout << "Removing " << v << " values from back" << endl;
        if(v>=used)
            used = 0;
        else
            used-=v;
    }

    void removeFront(int v) {
        cout << "Removing " << v << " values from front" << endl;
        if(v>=used)
            used = 0;
        else{
            for(int i=0; i<used-v; i++)
                data[i] = data[i+v];
            used-=v;
        }
    }

    void get(){
        cout << endl << "--START OUTPUT--" << endl;
        if(used == 0)
            cout << "Array is empty!" << endl;
        else{
            for(int i=0; i<used; i++)
                cout << data[i] << " ";
        }
        cout << endl << "--END OF OUTPUT--" << endl << endl;
    }
};

int main()
{
    GrowArray a(1);
    //fstream - outputs to file, inputs from HW4a.txt
    ifstream infile;
    //ofstream cout("output.txt");
    infile.open("HW4a.txt");
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
/*
would output:
9,7,5,3,1,5,10,15,20,25
5,3,1,5,10,15
*/
