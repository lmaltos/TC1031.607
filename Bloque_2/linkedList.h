#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "node.h"
#include <iostream>

template <class D>
class linkedList {
  private:
    node<D> *head;
    int size;
  public:
    linkedList();
    ~linkedList();
    void addFirst(D);
    void addLast(D);
    void print();
    node<D>* getElement(int);
    D operator[](int);
};

template <class D>
linkedList<D>::linkedList() {
    head = NULL;
    size = 0;
}

template <class D>
linkedList<D>::~linkedList() {
    node<D> *node,*next;
    node = head;
    head = NULL;
    while (node != NULL) {
        next = node->getNext();
        std::cout << "delete " << node << "\t" << node->getData() << std::endl;
        delete node;
        node = next;
    }
}

template <class D>
void linkedList<D>::addFirst(D data) {
    node<D> *newNode;
    newNode = new node<D>(data,head);
    //newNode->setNext(head); // se hace en el constructor
    head = newNode;
    size++;
}

template <class D>
void linkedList<D>::addLast(D data) {
    node<D> *newNode, *last;
    newNode = new node<D>(data);
    last = getElement(size - 1);
    last->setNext(newNode);
    size++;
}

template <class D>
void linkedList<D>::print() {
    node<D> *node;
    node = head;
    while (node != NULL) {
        std::cout << node->getData() << " ";
        node = node->getNext();
    }
    std::cout << std::endl;
}

template <class D>
node<D>* linkedList<D>::getElement(int k) {
    node<D> * nodo;
    nodo = head;
    if (k < size) {
        for (int i = 0; i < k; i++) {
            nodo = nodo->getNext();
        }
        return nodo;
    }
    return NULL;
}

template <class D>
D linkedList<D>::operator[](int k) {
    node<D>* nodo = getElement(k);
    return nodo->getData();
}

#endif