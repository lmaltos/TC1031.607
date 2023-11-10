#include "grafo.h"

void nodo::addAdyacencia(std::string _id) {
    adyacencia *nueva = new adyacencia(_id);
    if (conexiones == nullptr) {
        conexiones = nueva;
        return;
    }
    adyacencia *last = conexiones;
    while (last->getNext() != nullptr) {
        last = last->getNext();
    }
    last->setNext(nueva);
}

nodo::~nodo(){
    adyacencia *last = conexiones, *next;
    while (last != nullptr) {
        next = last->getNext();
        delete last;
        last = next;
    }
}

grafo::~grafo() {
    nodo *last = head, *next;
    while (last != nullptr) {
        next = last->getNext();
        delete last;
        last = next;
    }
}

nodo* grafo::addNodo(std::string id) {
    nodo *nuevo = new nodo(id);
    if (head == nullptr) {
        head = nuevo;
        return nuevo;
    }
    nodo *last = head;
    while (last->getNext() != nullptr) {
        last = last->getNext();
    }
    last->setNext(nuevo);
    return nuevo;
}

void grafo::addAdyacencia(nodo* nodo,std::string id) {
    nodo->addAdyacencia(id);
}

void grafo::BreadthFirst() {
    
}