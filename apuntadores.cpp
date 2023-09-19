#include <iostream>

using namespace std;

void test1() {
    int a = 5, *p;
    p = new int;
    cout << "&a = " << &a << endl;
    cout << "p = " << p << endl;
    *p = a;
    a = *p + 2;
    cout << a << " " << *p << endl;
    delete p;
    cout << "Despues de delete p = " << p << endl;
    cout << "*p = " << *p << endl;
    p = NULL;
    cout << "Despues de p = NULL, p = " << p << endl;
    
    p = &a;
    *p = 42;
    cout << "a = " << a << endl;
    cout << "p = " << p << endl;
}

int main() {
    test1();
}