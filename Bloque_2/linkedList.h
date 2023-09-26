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
    void print();
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

#endif