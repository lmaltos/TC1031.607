#include <fstream>
#include <sstream>
using namespace std;

void leerPorCampo() {
    ifstream file;
    file.open("Bitacora.txt");
    string mes, dia, hhmmss, ipAdress, message;
    while (!file.eof()){
        file >> mes;
        file >> dia;
        file >> hhmmss;
        file >> ipAdress;
        getline(file,message); // resto de la linea
    }
    
}

void parseLine(string);

void leerPorLinea() {
    ifstream file;
    string line;
    file.open("Bitacora.txt");
    while (!file.eof()) {
        getline(file,line);
        istringstream iss(line);
        iss >> month;
    }
}

void parseLine(string line) {
    string month;
    string day;
    string hhmmss;
    string ipAdress;
    string message;
    istringstream iss(line);
    iss >> month;
    iss >> day;
    iss >> hhmmss;
    iss >> ipAdress;
    iss.getline(message,-1);
}