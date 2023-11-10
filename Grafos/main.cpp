#include <iostream>
#include <fstream>
//#include <sstream>
#include "grafo.h"

using namespace std;

int main() {
    grafo g;
    nodo *n;
    string id,idAdyacencia,linea;
    ifstream archivo;
    int i;
    archivo.open("grafoEjemplo.txt");
    while (!archivo.eof()) {
        archivo >> id;
        getline(archivo,linea);
        //istringstream iss(linea);
        n = g.addNodo(id);
        cout << "add nodo " << id << endl;
        g.addAdyacencia(n,"");
        i = 1;
        while (i < linea.length()) {
            idAdyacencia = linea[i];
            g.addAdyacencia(n,idAdyacencia);
            cout << "add adyacencia " << idAdyacencia << endl;
            i+=2;
        }
    }
    
    archivo.close();
    return 0;
}