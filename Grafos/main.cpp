#include <iostream>
#include <fstream>
#include <sstream>
#include "grafo.h"

using namespace std;

int main() {
    grafo g;
    nodo *n;
    string id,idAdyacencia,linea;
    ifstream archivo;
    archivo.open("grafoEjemplo.txt");
    while (!archivo.eof()) {
        archivo >> id;
        getline(archivo,linea);
        istringstream iss(linea);
        n = g.addNodo(id);
        cout << "add nodo " << id << endl;
        getline(iss, idAdyacencia,' '); // lee el primer espacio
        while (getline(iss, idAdyacencia,' ')) {
            g.addAdyacencia(n,idAdyacencia);
            cout << "add adyacencia " << idAdyacencia << endl;
        }
    }
    archivo.close();
    g.BreadthFirst();
    return 0;
}