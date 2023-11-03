#include <iostream>
#include "AVL.h"

using namespace std;

int main() {
    AVL<int> arbol;
    for (int i = 1; i < 100;i++) {
        arbol.push(i);
        if (i % 20 == 0)
            arbol.printPorNivel();
    }
    
}