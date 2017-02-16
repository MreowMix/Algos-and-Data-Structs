#include <iostream>
#include <math.h>
using namespace std;

void powermod(int a,int n,int m){

    cout << "Count: " << count << " iteration; ";
    cout << "Prod: " << prod << "; ";
    cout << "n: " << n << "; ";
    cout << "a: " << a << "; ";
}

int main()
{
    int a, n, m;
    cout << "a, n, m" << endl;
    cin >> a;
    cin >> n;
    cin >> m;

    powermod(a,n,m);
}
