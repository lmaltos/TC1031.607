#include <vector>
#include <cstdlib>
#include <iostream>

using namespace std;

void swap(vector<int> &,int,int);

int main() {
    vector<int> myVect;
    int n = 1000;
    int a,b;
    for (int i = 0; i < n; i++) {
        myVect.push_back(rand());
    }
    a = rand() % n;
    b = rand() % n;
    cout << "myVect[" << a << "] = " << myVect[a] << endl;
    cout << "myVect[" << b << "] = " << myVect[b] << endl;
    swap(myVect,a,b);
    cout << "Despues del swap" << endl;
    cout << "myVect[" << a << "] = " << myVect[a] << endl;
    cout << "myVect[" << b << "] = " << myVect[b] << endl;

    cout << "Primeros 100 elementos:" << endl;
    for (int i = 0; i < 100; i++) {
        cout << myVect[i] << " ";
    }
}

void swap(vector<int> &myVect, int a, int b) {
    int aux;
    aux = myVect[b];
    myVect[b] = myVect[a];
    myVect[a] = aux;
}