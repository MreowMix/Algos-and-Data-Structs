#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <time.h>
#include <vector>
using namespace std;

class GrowArray {
private:
    int* data;
    int* data2;
    int used, capacity;

    void updateCapacity(int newCapacity){
        int* newData = new int[newCapacity];
        for(int i=0; i<=used; i++)
            newData[i] = data[i];
        capacity = newCapacity;
        delete[] data;
        data = newData;
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

    void copyArray(){
        data2 = new int[used];
        for(int i=0; i<used; i++)
            data2[i] = data[i];
    }

    void getPrint(){
        if(used == 0){
            cout << "Array is empty!" << endl;
            return;
        }

        else{
            copyArray();
            cout << endl << "--START QUICK SORT--" << endl;
            quickSort(data2, 0, used-1);
            for(int i=0; i<used; i++)
                cout << data2[i] << " ";
            cout << endl << "--END OF QUICK SORT--" << endl << endl;

            copyArray();
            cout << endl << "--START INSERTION SORT--" << endl;
            insertionSort(data2, used);
            for(int i=0; i<used; i++)
                cout << data2[i] << " ";
            cout << endl << "--END OF INSERTION SORT--" << endl << endl;
        }
    }
    void get(){
        if(used == 0)
            return;
        else{
            cout << "-- Sorting... --" << endl;
            copyArray();
            quickSort(data2, 0, used-1);
            copyArray();
            insertionSort(data2, used);
        }
    }

    void quickSort(int arr[], int left, int right){
        if(left < right){
            int pivot = arr[(left+(right-left)/2)];
            int i = left;
            int j = right;
            while(i <= j){
                while(arr[i] < pivot)
                    i++;
                while(arr[j] > pivot)
                    j--;
                if(i <= j){
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                    i++;
                    j--;
                }
                if(left < j)
                    quickSort(arr, left, j);
                if(i < right)
                    quickSort(arr, i, right);
            }
        }
            for(int i=0; i<used; i++)
                data2[i] = arr[i];
    }

    void insertionSort(int arr[], int size){
        int temp, j;

        for(int i=1; i<size; i++){
            temp = arr[i];
            j=i-1;
            while(j>=0 && arr[j] > temp){
                arr[j+1] = arr[j];
                j-=1;
            }
            arr[j+1] = temp;
        }
        data2 = new int[used];
        for(int i=0; i<used; i++){
            data2[i] = arr[i];
        }
    }
};

int main()
{
    ifstream infile;
    infile.open("HW5a.txt");
    string command, line, num, mode;
    int size, max, value, randNum;
    double startTime, stopTime, CPS;
    CPS = CLOCKS_PER_SEC;

    srand(time(0));

    //opens file
    if(infile.good()){

        //stringstream to parse the command from
        stringstream iss;

        //extracts from "infile" to "command" until "commandDelim"
        while(!infile.eof()){
            while(getline(infile, line)){
                iss << line;
                getline(iss, command, ' ');
                cout << "Command: " << command << endl;

                //print before and after sorting
                if(command == "PRINT"){
                    getline(iss, mode, ' ');
                    cout << "Mode: " << mode << endl;
                    if(mode == "RANDOM"){
                        getline(iss, num, ' ');
                        size = atoi(num.c_str());
                        getline(iss, num);
                        max = atoi(num.c_str());
                        GrowArray a(size);
                        for(int i=0; i<size; i++){
                            randNum = rand() % max;
                            cout << randNum << " ";
                            a.addBack(randNum);
                        }
                        cout << endl;
                        a.getPrint();
                    }

                    //read n numbers from the file
                    else if(mode == "INPUT"){
                        getline(iss, num, ' ');
                        size = atoi(num.c_str());
                        iss.clear();
                        getline(infile,line);
                        iss << line;
                        GrowArray a(size);
                        for(int i=0; i<size; i++){
                            getline(iss, num, ' ');
                            value = atoi(num.c_str());
                            a.addBack(value);
                        }
                        a.getPrint();
                    }
                }

                //do sort and print time it takes to get array
                else if(command == "BENCHMARK"){
                    startTime = clock();
                    getline(iss, mode, ' ');
                    if(mode == "RANDOM"){
                        getline(iss, num, ' ');
                        size = atoi(num.c_str());
                        getline(iss, num);
                        max = atoi(num.c_str());
                        GrowArray a(size);
                        for(int i=0; i<size; i++){
                            randNum = rand() % max;
                            a.addBack(randNum);
                        }
                        a.get();
                        stopTime = clock();
                    }
                    else if(mode == "INPUT"){
                        getline(iss, num, ' ');
                        size = atoi(num.c_str());
                        iss.clear();
                        getline(infile,line);
                        iss << line;
                        GrowArray a(size);
                        for(int i=0; i<size; i++){
                            getline(iss, num, ' ');
                            value = atoi(num.c_str());
                            a.addBack(value);
                        }
                        a.get();
                        stopTime = clock();
                    }
                    cout << "Time: " << (stopTime-startTime)/CPS << " seconds." << endl;
                }
                else
                    cout << "Incorrect command" << endl << endl;
                cout << "-----" << endl << endl;
                iss.clear();
            }
        }
    }
    else
        cout << "Error: File not found." << endl;
}
