#include <iostream>
#include "stack.h"
#include "stack2.h"

using namespace std;

int main() {
    stack<int> myStack;
    myStack.push(123);
    for (int i = 0; i < MAX_SIZE; i++) {
        myStack.push(i+1);
    }
    cout << "ifFull? " << (myStack.isFull() ? "yes" : "no") << endl;
    while (!myStack.isEmpty()) {
        cout << myStack.top() << endl;
        myStack.pop();
    }

    stack2<int> myStack2;
    myStack2.push(123);
    for (int i = 0; i < MAX_SIZE; i++) {
        myStack2.push(i+1);
    }
    cout << "ifFull? " << (myStack2.isFull() ? "yes" : "no") << endl;
    while (!myStack2.isEmpty()) {
        cout << myStack2.Top() << endl;
        myStack2.pop();
    }

}