#include "linkedList.h"
#include <iostream>

using namespace std;

int main() {
    linkedList<std::string> lista;
    lista.addFirst("Plato");
    lista.addFirst("Olla");
    lista.addFirst("Jarra");
    lista.addFirst("Estufa");
    lista.addLast("Cuchara");
    lista.addLast("Tenedor");
    cout << "lista[3] = " << lista[3] << endl;
    lista.print();

    
    linkedList<int> listaInt;
    listaInt.addFirst(1);
    listaInt.addFirst(2);
    listaInt.addFirst(3);
    listaInt.addFirst(1);
    listaInt.print();
    listaInt.addLast(1);
    listaInt.addLast(2);
    listaInt.addLast(3);
    listaInt.addLast(4);
    listaInt.print();
}