#ifndef NODET_H
#define NODET_H
#include <cstddef>

template <typename T> // Define un tipo de dato T que se espeficara despues
class nodeT {
  private:
    T data;
    nodeT<T> *left, *right; // referencias a nodos hijos
    // el tipo de dato al que apuntan los hijos es nodeT<T> aun sin especificar el tipo exacto de dato
  public:
    nodeT(); // constructor default
    nodeT(T); // constructor con informacion
    T Data(); // regresa un tipo de dato T no espeficado aun
    nodeT<T>* Left(); // lo que regresa es un puntero al nodo izquierdo de tipo nodeT<T>
    nodeT<T>* Right();
    void setData(T);
    void setLeft(nodeT<T>*);
    void setRight(nodeT<T>*);
};

template <typename T>
nodeT<T>::nodeT() {
    left = right = NULL; // en un inicio no se tienen hijos por lo que el valor inicial debe ser nulo
}

template <typename T>
nodeT<T>::nodeT(T data) {
    this->data = data; // this es el pointer que hace referencia a la instancia en la que nos encontramos
    left = right = NULL;
}

template <typename T>
T nodeT<T>::Data() {
    return data;
}

template <typename T>
nodeT<T>* nodeT<T>::Left() {
    return left;
}

template <typename T>
nodeT<T>* nodeT<T>::Right() {
    return right;
}

template <typename T>
void nodeT<T>::setData(T _data) {
    data = _data; // no ocurre enmascaramiento al tener un nombre distinto a la propiedad
}

template <typename T>
void nodeT<T>::setLeft(nodeT<T>* _left) {
    left = _left;
}

template <typename T>
void nodeT<T>::setRight(nodeT<T>* _right) {
    right = _right;
}

#endif