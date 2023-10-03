#include <iostream>

using namespace std;

void ejemploArreglo01() {
    int arreglo[100];
    int j = rand() % 100;
    cout << "arreglo = " << arreglo << endl;
    cout << "j = " << j << endl;
    cout << "arreglo[j] = " << arreglo[j] << endl;
    cout << "*(arreglo + j) = " << *(arreglo + j) << endl;
    if (arreglo[j] == *(arreglo + j)) {
        cout << "arreglo[j] == *(arreglo + j)" << endl;
    }
    else {
        cout << "arreglo[j] != *(arreglo + j)" << endl;
    }

    cout << "&arreglo[j] = " << &arreglo[j] << endl;
    cout << "(arreglo + j) = " << arreglo + j << endl;
    if (&arreglo[j] == (arreglo + j)) {
        cout << "&arreglo[j] == (arreglo + j)" << endl;
    }
    else {
        cout << "&arreglo[j] != (arreglo + j)" << endl;
    }
}

void EjemploArreglo02() {
    int *p;
    int n;
    cin >> n;
    p = new int[n];
    for (int i = 0; i < n; i++) {
        p[i] = rand() % 50;
    }
    for (int i = 0; i < n; i++) {
        cout << *(p + i) << endl;
    }
    //delete p; // Solo se elimina el primer elemento
    delete[] p;
    cout << "delete[] p" << endl;
    for (int i = 0; i < n; i++) {
        cout << *(p + i) << endl;
    }
}
int main() {
    EjemploArreglo02();
}