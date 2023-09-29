#ifndef STACK_H
#define STACK_H
#define MAX_SIZE 100

template <class T>
class stack {
  private:
    T datos[MAX_SIZE];
    int tope;
  public:
    stack();
    void push(T);
    void pop();
    T top();
    bool isFull();
    bool isEmpty();
};

template <class T>
stack<T>::stack(){
    tope = -1;
}

template <class T>
void stack<T>::push(T data){
    if (!isFull()){
        tope++;
        datos[tope] = data;
    }
}

template <class T>
void stack<T>::pop(){
    tope--;
}

template <class T>
T stack<T>::top() {
    return datos[tope];
}

template <class T>
bool stack<T>::isFull(){
    return tope == MAX_SIZE - 1;
}

template <class T>
bool stack<T>::isEmpty(){
    return tope == -1;
}

#endif