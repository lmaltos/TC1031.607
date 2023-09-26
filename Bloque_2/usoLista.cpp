#include "linkedList.h"
#include <string>

int main() {
    linkedList<std::string> lista;
    lista.addFirst("Plato");
    lista.addFirst("Olla");
    lista.addFirst("Jarra");
    lista.addFirst("Estufa");
    lista.print();
}