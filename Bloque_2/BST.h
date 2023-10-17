#ifndef BST_H
#define BST_H
#include "nodeT.h"
#include <iostream>

template <typename T>
class BST {
  private:
    nodeT<T> *root; // podemos seguir sin definir el tipo de dato T
  public:
    BST();
    ~BST();
    void borraNodo(nodeT<T>*);
    bool search(T);
    void push(T);
    void pop(T);
    void printPreorden();
    void preoden(nodeT<T>*);
    void printInorden();
    void inorden(nodeT<T>*);
    void printPostorden();
    void postorden(nodeT<T>*);
};

template <typename T>
BST<T>::BST() {
    root = NULL;
}

template <typename T>
BST<T>::~BST() {
    borraNodo(root);
}

template <typename T>
void BST<T>::borraNodo(nodeT<T> *nodo) {
    if (nodo == NULL)
        return;
    borraNodo(nodo->Left());
    borraNodo(nodo->Right());
    std::cout << "Delete nodo " << nodo->Data() << std::endl;
    delete nodo;
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
    //std::cout << "push(" << data << ")" << std::endl;
    nodeT<T> *p = root; // pointer para recorrer el arbol
    nodeT<T> *padre = NULL; // nodo referencia a padre un paso anterior
    if (search(data)) return; // el valor ya existe en nuestro arbol
    //std::cout << "valor no presente en arbol" << std::endl;
    //while (!(p->Data() > data && p->Left() == NULL) || !(p->Data() < data && p->Right() == NULL)) {
    while (p != NULL) {
        padre = p; // guardamos el valor anterior de p como posible padre
        p = p->Data() > data ? p->Left() : p->Right(); // avanzamos p
    }
    nodeT<T> *nodo = new nodeT<T>(data); // nuevo nodo contenedor
    if (padre == NULL) { // caso cuando el arbol esta vacio y se agrega un primer elemento
        //std::cout << "Arbol vacio" << std::endl;
        root = nodo;
    }
    else {
        //std::cout << "Se encontro padre" << std::endl;
        if (padre->Data() > data) {
            padre->setLeft(nodo);
        }
        else {
            padre->setRight(nodo);
        }
    }
}

template <typename T>
void BST<T>::pop(T data) {
    nodeT<T> *p = root; // pointer para recorrer el arbol
    nodeT<T> *padre = NULL; // nodo referencia a padre un paso anterior
    if (!search(data)) return; // el valor no existe en nuestro arbol
    //std::cout << "valor esta presente en arbol" << std::endl;
    while (p->Data() != data) {
        padre = p; // guardamos el valor anterior de p como posible padre
        p = p->Data() > data ? p->Left() : p->Right(); // avanzamos p
    }
    if (p->Left() == NULL && p->Right() == NULL) { // es un nodo hoja
        delete p; // se libera nodo
        if (padre == NULL) {
            root = NULL; // se trataba del unico elemento dejando al arbo vacío
        }
        else {
            if (padre->Data() > data) {
                padre->setLeft(NULL); // se borra referencia izquierda
            }
            else {
                padre->setRight(NULL); // se borra referencia derecha
            }
        }
    }
    else if (p->Left() != NULL && p->Right() != NULL) { // nodo padre con dos hijos
        nodeT<T> *predecesor;
        nodeT<T> *subarbolIzq;
        predecesor = p->Left(); // uno a la izquierda
        padre = p; // rehusamos padre para guardar referencia a padre del predecesor
        while (predecesor->Right() != NULL) {
            padre = predecesor;
            predecesor = predecesor->Right(); // todo a la derecha
        }
        subarbolIzq = predecesor->Left();
        p->setData(predecesor->Data()); // se actualiza el valor del nodo con su predecesor
        delete predecesor;
        if (p == padre) {
            padre->setLeft(subarbolIzq); // caso donde no se avanza el padre
        }
        else {
            padre->setRight(subarbolIzq);
        }
    }
    else { // nodo padre con un hijo
        nodeT<T> *subarbol;
        subarbol = p->Left() != NULL ? p->Left() : p->Right(); // referencia a subarbol
        delete p; // liberamos el nodo
        if (padre == NULL) {
            root = subarbol;
        }
        else {
            if (padre->Data() > data) {
                padre->setLeft(subarbol); // se actualiza referencia izquierda
            }
            else {
                padre->setRight(subarbol); // se actualiza referencia derecha
            }
        }
}
}

template <typename T>
void BST<T>::printPreorden(){
    preoden(root);
}

template <typename T>
void BST<T>::preoden(nodeT<T>* nodo) {
    if (nodo == NULL)
        return;
    std::cout << nodo->Data() << " ";
    preoden(nodo->Left());
    preoden(nodo->Right());
}

template <typename T>
void BST<T>::printInorden(){
    inorden(root);
}

template <typename T>
void BST<T>::inorden(nodeT<T>* nodo){
    if (nodo == NULL)
        return;
    inorden(nodo->Left());
    std::cout << nodo->Data() << " ";
    inorden(nodo->Right());
}

template <typename T>
void BST<T>::printPostorden(){
    postorden(root);
}

template <typename T>
void BST<T>::postorden(nodeT<T>* nodo){
    if (nodo == NULL)
        return;
    postorden(nodo->Left());
    postorden(nodo->Right());
    std::cout << nodo->Data() << " ";
}
#endif