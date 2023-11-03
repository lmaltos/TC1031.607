#ifndef AVL_H
#define AVL_H
#include "BST.h"
#include "nodeT.h"

template <typename T>
class AVL : public BST<T> {
    public:
    bool isBalanced(T);
    bool isBalanced(nodeT<T>*);
    int calcHeight(nodeT<T>*);
    void push(T);
    nodeT<T>* getPivote(T);
    void swap(nodeT<T>*,nodeT<T>*);
    void RSI(nodeT<T>*,T);
    void RSD(nodeT<T>*,T);
    void RDI(nodeT<T>*,T);
    void RDD(nodeT<T>*,T);
};

template <typename T>
bool AVL<T>::isBalanced(T data) {
    nodeT<T>* nodo = BST<T>::root;
    while (nodo->Data() != data) // no se ha llegado al nodo hoja recien creado
    {
        if (!isBalanced(nodo))
            return false;
        //nodo = nodo->Data() > data ? nodo->Left() : nodo->Right(); // forma compacta de hacer lo siguiente
        if (nodo->Data() > data) {
            nodo = nodo->Left();
        }
        else {
            nodo = nodo->Right();
        }
    }
    return true; // nuestro arbol sigue balanceado :)
}

template <typename T>
bool AVL<T>::isBalanced(nodeT<T>* node) {
    int leftHeight = calcHeight(node->Left());
    int rightHeight = calcHeight(node->Right());
    if (rightHeight - leftHeight <= 1 && rightHeight - leftHeight >= -1)
        return true; // el nodo esta balanceado
    return false; // el nodo esta desbalanceado
}

template <typename T>
int AVL<T>::calcHeight(nodeT<T>* nodo){
    if (nodo == NULL) {
        return 0; // altura 0
    }
    int leftHeight = calcHeight(nodo->Left());
    int rightHeight = calcHeight(nodo->Right());
    int height = leftHeight > rightHeight ? leftHeight : rightHeight;
    return height + 1;
}

template <typename T>
void AVL<T>::push(T data) {
    BST<T>::push(data);
    if (!isBalanced(data)) {
        nodeT<T> *pivote = getPivote(data);
        nodeT<T> *A;
        // Hacer alguna rotacion
        if (pivote->Data() < data) {
            A = pivote->Right();
            if (A->Data() < data){
                // Se requiere una Rotacion Simple a la Izquierda
                RSI(pivote,data);
            }
            else { // Se requiere una Rotacion Doble a la Izquierda
                RDI(pivote,data);
            }
        }
        else {
            A = pivote->Left();
            if (A->Data() > data){ // Se requiere una Rotacion Simple a la Derecha
                RSD(pivote,data);
            }
            else { // Se requiere una Rotacion Doble a la Derecha
                RDD(pivote, data);
            }
        }
    }
}

template <typename T>
nodeT<T>* AVL<T>::getPivote(T data) {
    nodeT<T>* nodo = BST<T>::root;
    nodeT<T>* pivote;
    while (nodo->Data() != data) {// no se ha llegado al nodo hoja recien creado
        if (!isBalanced(nodo)) {
            pivote = nodo;
        }
        nodo = nodo->Data() > data ? nodo->Left() : nodo->Right();
    }
    return pivote;
}

/// @brief Cambia referencia a pivote apunte a nuevo
/// @tparam T 
/// @param pivote 
/// @param nuevo 
template <typename T>
void AVL<T>::swap(nodeT<T>* pivote,nodeT<T>* nuevo) {
    if (pivote == BST<T>::root) {
        BST<T>::root = nuevo;
        return;
    }
    nodeT<T> *nodo = BST<T>::root;
    nodeT<T> *padre;
    while (nodo != pivote) {
        padre = nodo;
        nodo = nodo->Data() > pivote->Data() ? nodo->Left() : nodo->Right();
    }
    if (pivote->Data() < padre->Data()) {
        padre->setLeft(nuevo);
    }
    else {
        padre->setRight(nuevo);
    }
}

template <typename T>
void AVL<T>::RSI(nodeT<T>* pivote,T data){
    nodeT<T> *A = pivote->Right();
    pivote->setRight(A->Left());
    A->setLeft(pivote);
    // cambiarPivote
    swap(pivote,A);
}

template <typename T>
void AVL<T>::RSD(nodeT<T>* pivote,T data){
    nodeT<T> *A = pivote->Left();
    pivote->setLeft(A->Right());
    A->setRight(pivote);
    // cambiarPivote
    swap(pivote,A);
}

template <typename T>
void AVL<T>::RDI(nodeT<T>* pivote,T data){
    //ToDo
}

template <typename T>
void AVL<T>::RDD(nodeT<T>* pivote,T data){
    // ToDo
}

#endif