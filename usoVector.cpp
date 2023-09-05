#include <vector>
#include <cstdlib>
#include <iostream>

using namespace std;

template <typename T>
void swap(vector<T> &,int,int);

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

template <typename T>
void swap(vector<T> &myVect, int a, int b) {
    T aux;
    aux = myVect[b];
    myVect[b] = myVect[a];
    myVect[a] = aux;
}