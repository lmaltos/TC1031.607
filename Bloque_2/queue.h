#ifndef QUEUE_H
#define QUEUE_H
#define QUEUE_MAX_SIZE 10
#include <iostream>

template <typename T>
class queue {
  private:
    T datos[QUEUE_MAX_SIZE];
    int start,end;
  public:
    queue();
    void push(T);
    void pop();
    T front();
    bool isEmpty();
    bool isFull();
};

template <typename T>
queue<T>::queue() {
    start = end = -1;
}

template <typename T>
void queue<T>::push(T data) {
    if (isFull())
        return;
    if (isEmpty()) {
        start = end = 0;
    }
    else {
        end++;
        //if (end >= QUEUE_MAX_SIZE) end = 0;
        //end = end % QUEUE_MAX_SIZE;
        end %= QUEUE_MAX_SIZE;
    }
    datos[end] = data;
}

template <typename T>
void queue<T>::pop() {
    if (isEmpty())
        return;
    if (start == end) {
        start = end = -1;
    }
    else {
        start++;
        start %= QUEUE_MAX_SIZE;
    }
}

template <typename T>
T queue<T>::front() {
    return datos[start];
}

template <typename T>
bool queue<T>::isEmpty() {
    return start == -1;
}

template <typename T>
bool queue<T>::isFull() {
    //std::cout << "start = " << start << "\t(end+1)= " << ((end + 1) % QUEUE_MAX_SIZE) << std::endl;
    return start == ((end + 1) % QUEUE_MAX_SIZE);
}

#endif