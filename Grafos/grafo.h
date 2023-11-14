#ifndef GRAFO_H
#define GRAFO_H
#include "nodo.h"

class grafo {
  private:
    nodo *head = nullptr;
  public:
    ~grafo();
    nodo* addNodo(std::string);
    void addAdyacencia(nodo*,std::string);
    void BreadthFirst();
    void DepthFirst();
    nodo* getNodoByID(std::string);
};

#endif