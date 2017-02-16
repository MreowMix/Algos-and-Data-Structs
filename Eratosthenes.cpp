#include <iostream>
#include <math.h>
using namespace std;

//This function calculates the number of primes up to a number n.
int eSieve(int n){
    int *sieve = new int[n];
    int count = 0;
    for(int i=2; i<=n; i++)
        sieve[i]=1;
    for(int i=2; i<=n; i++){
        if(sieve[i] == 1){
            for(int j=i*i; j<=n; j+=2*i){
                sieve[j] = 0;
            }
        }
    }
    for(int i=2; i<=n; i++){
        if(sieve[i] == 1){
            count++;
        }
    }
    return count;
}

//This function calculates the number of primes given a range.
long eSieve2Int(long long start, long long end){
    int count, sqrtN;
    sqrtN = sqrt(end);
    count = 0;
    bool* sieve = new bool[end];

    if(start == 0 || start == 1)
        start = 2;
    //from 1 to end, set to true
    for(int i=2; i<=end; i++){
        sieve[i]=true;
    }

    //from 2 to square root of end, set multiples to false
    for(int i=2; i<=sqrtN; i++){
        if(sieve[i]){
            for(int j=i*i; j<=end; j+=i){
                sieve[j] = false;
            }
        }
    }

    //count all primes from start to end
    for(long long k=start; k<=end; k++){
        if(sieve[k])
            count++;
            //cout << k << ", ";
    }
    return count;
}

int main(){
    /*
    int userInput, primeNums;
    cout << "Please input a number." << endl;
    cin >> userInput;
    primeNums = eSieve(userInput);
    cout << "There are " << primeNums << " primes from 1 to " << userInput << "." << endl << endl;
    */

    long long firstInput, secondInput, result, max;
    max = pow(10,14);
    while(1){
        cout << "Please input an integer a and an integer b such that a < b <= 10^14." << endl;
        cout << "Enter your 'a' input: " << endl;
        cin >> firstInput;
        cout << "Enter your 'b' input: " << endl;
        cin >> secondInput;
        if(firstInput > max || secondInput > max)
            cout << "Your input is too high." << endl;
        else if(firstInput < secondInput){
            eSieve2Int(firstInput, secondInput);
            result = eSieve2Int(firstInput, secondInput);
            cout << "There are " << result << " prime number(s) from " << firstInput << " to " << secondInput << "." << endl;
        }
        else
            cout << "Your inputs do not follow a < b <= 10^14." << endl;
    }
}
