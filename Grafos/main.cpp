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
        cout << "add nodo " << id << endl;
        archivo >> id;
        getline(archivo,linea);
        //istringstream iss(linea);
        n = g.addNodo(id);
        g.addAdyacencia(n,"");
        i = 0;
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