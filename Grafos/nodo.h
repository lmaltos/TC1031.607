#ifndef NODO_H
#define NODO_H
#include <string>
#include "adyacencia.h"

enum estatus {
    enEspera,
    procesado,
    listo,
};

class nodo {
  private:
    std::string id;
    nodo *next = nullptr;
    adyacencia *conexiones = nullptr;
    estatus estado;
  public:
    nodo(std::string _id) {id = _id;}
    ~nodo();
    void addAdyacencia(std::string);
    adyacencia* getAdyacencia() {return conexiones;}
    nodo* getNext() {return next;}
    void setNext(nodo* _next) {next = _next;}
    void setEstatus(estatus _estado) {estado = _estado;}
    estatus getEstatus() {return estado;}
};
#endif