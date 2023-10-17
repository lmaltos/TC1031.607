#ifndef QUEUE2_H
#define QUEUE2_H
#include "node.h"

template <typename T>
class queue2 {
  private:
    node<T> *tail;
    int start;
  public:
    queue2();
    void push(T);
    void pop();
    T front();
    bool isEmpty();
    bool isFull();
};

template <typename T>
queue2<T>::queue2() {
    tail = NULL;
    start = -1;
}

template <typename T>
void queue2<T>::push(T data) {
    node<T> *nodo;
    nodo = new node<T>(data);
    if (isEmpty()) {
        start = 1;
        nodo->setNext(nodo);
    }
    else {
        nodo->setNext(tail->getNext());
        tail->setNext(nodo);
    }
    tail = nodo;
}

template <typename T>
void queue2<T>::pop() {
    if (isEmpty())
        return;
    node<T> *inicial = tail->getNext();
    if (inicial->getNext() == inicial) {
        tail = NULL;
    }
    else {
        tail->setNext(inicial->getNext());
    }
    delete inicial;
}

template <typename T>
T queue2<T>::front() {
    node<T> *inicial = tail->getNext();
    return inicial->getData();
}

template <typename T>
bool queue2<T>::isEmpty() {
    return tail == NULL;
}

template <typename T>
bool queue2<T>::isFull() {
    return false;
}

#endif