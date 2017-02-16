#include <iostream>
#include <math.h>
#include <fstream>
#include <time.h>
#include <vector>
using namespace std;

long long powermod(int x, int n, int m){
    long long prod = 1;
    while(n>0){
        if((n%2) != 0)
            prod = (prod*x)%m;
        x = (x*x)%m;
        n = n/2;
    }
    return prod;
}

bool millerRabin(int n, int k){
    int num, a, r, d, exitNum;
    long long x;
    r = 1;
    d = 0;
    num = n-1;

    //all even numbers are not prime
    if(n<2)
        return false;
    if(n != 2 && n%2 == 0)
        return false;

    //determine n-1 = 2^r * d
    while(exitNum == 0){
        if(num % ((int)pow(2,r)) == 0){
            r++;
        }
        else{
            r = r-1;
            d = num / ((int)pow(2,r));
            exitNum = 1;
        }
    }

    for(int i=1; i<=k; i++){
        a = 2+rand()%(n-4);
        x = powermod(a,d,n);
        if (x == 1 || x == num)
            continue;
        for(int j = 1; j<r; j++){
            x = powermod(x,2,n);
            if(x == 1)
                return false;
            if(x == num)
                continue;
        }
        return false;
    }
    return true;
}

int main(){
    int readArray[6] = {5, 561, 7919, 7923, 961748941, 961748947};
    int k, n, uInput;
    srand(time(NULL));
    ifstream myFile;

    myFile.open("hw2.dat", ios::in|ios::binary);
    if(myFile.is_open()){
        cout << "How many trials?" << endl;
        cin >> k;

        while(!myFile.eof()){
            for(int j=0; j<6 ; j++){
                myFile >> readArray[j];
                cout << readArray[j] << ": " << millerRabin(readArray[j], k) << endl << endl;
            }
        }
    }
    else
        cout << "File not opened." << endl;

    myFile.close();
    return 0;
}

