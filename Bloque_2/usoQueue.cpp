#include <iostream>
#include "queue.h"

using namespace std;

int main() {
    queue<char> fila;
    fila.push('f');
    fila.push('g');
    fila.push('h');
    fila.push('i');
    fila.push('j');
    fila.push('k');
    fila.push('l');
    fila.push('m');
    fila.push('n');
    fila.push('o');
    fila.push('p');
    fila.push('q');
    cout << "fila.isFull() = " << fila.isFull() << endl;
    cout << "fila.isEmpty() = " << fila.isEmpty() << endl;
    while (!fila.isEmpty()) {
        cout << fila.front() << endl;
        fila.pop();
    }
    cout << "fila.isEmpty() = " << fila.isEmpty() << endl;
}