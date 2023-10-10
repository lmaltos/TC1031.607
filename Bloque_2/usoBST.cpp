#include <iostream>
#include "nodeT.h"
#include "BST.h"

using namespace std;

int main() {
    BST<int> arbol;
    int a;
    for (int i = 0; i < 50; i++) {
        a = rand() % 100;
        arbol.push(a);
        cout << a;
        if (i % 10 == 9)
            cout << endl;
        else
            cout << " ";
    }
    cout << "Se agregan elementos" << endl;
    for (int i = 0; i < 100; i++) {
        cout << arbol.search(i);
        if (i % 10 == 9)
            cout << endl;
        else
            cout << " ";
    }
}