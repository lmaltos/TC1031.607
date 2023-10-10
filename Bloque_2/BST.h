#ifndef BST_H
#define BST_H
#include "nodeT.h"

template <typename T>
class BST {
  private:
    nodeT<T> *root; // podemos seguir sin definir el tipo de dato T
  public:
    BST();
    bool search(T);
    void push(T);
};

template <typename T>
BST<T>::BST() {
    root = NULL;
}

template <typename T>
bool BST<T>::search(T data) {
    nodeT<T>* p;
    p = root;
    while (p != NULL) {
        if (p->Data() == data)
            return true;
        p = p->Data() > data ? p->Left() : p->Right();
    }
    return false;
}

template <typename T>
void BST<T>::push(T data) {
    nodeT<T> *p = root; // pointer para recorrer el arbol
    nodeT<T> *padre; // nodo referencia a padre un paso anterior
    if (search(data)) return; // el valor ya existe en nuestro arbol
    //while (!(p->Data() > data && p->Left() == NULL) || !(p->Data() < data && p->Right() == NULL)) {
    while (p != NULL) {
        padre = p; // guardamos el valor anterior de p como posible padre
        p = p->Data() > data ? p->Left() : p->Right(); // avanzamos p
    }
    nodeT<T> *nodo = new nodeT<T>(data); // nuevo nodo contenedor
    if (padre == NULL) { // caso cuando el arbol esta vacio y se agrega un primer elemento
        root = nodo;
    }
    else {
        if (padre->Data() > data) {
            padre->setLeft(nodo);
        }
        else {
            padre->setRight(nodo);
        }
    }
}

#endif