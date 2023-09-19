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

// Regla 1 por cada new un delete    
void Decalogo01() {
    int *p = new int;
    *p = 12;
    delete p;
    cout << "Despues de delete p = " << p << endl;
    cout << "*p = " << *p << endl;
    // ¿Qué pasa si borramos nuevamete p?
    delete p;
    cout << "Despues del segundo delete p = " << p << endl;
    cout << "*p = " << *p << endl;
}

// Regal 2 un DELETE libera el espacio independientemente de la cantidad de apntadores
void Decalogo02() {
    int *p, *q, *r;
    p = new int;
    cout << "p = " << p << endl;
    cout << "q = " << q << endl;
    cout << "r = " << r << endl;
    q = r = p;
    delete r;
    cout << "Despues del delete" << endl;
    cout << "p = " << p << endl;
    cout << "q = " << q << endl;
    cout << "r = " << r << endl;
    //delete q;
}

string *test3() {
    string *p = new string;
    *p = "hola";
    cout << "&p = " << &p << endl;
    cout << "p = " << p << endl;
    cout << "*p = " << *p << endl;
    return p;
}
// Regla 3
void Decalogo03() {
    string *q;
    q = test3();
    cout << "Despues de la llamada" << endl;
    cout << "&q = " << &q << endl;
    cout << "q = " << q << endl;
    cout << "*q = " << *q << endl;
    delete q;
    cout << "Despues de delete" << endl;
    cout << "&q = " << &q << endl;
    cout << "q = " << q << endl;
    cout << "*q = " << *q << endl;
}

int main() {
    Decalogo03();
}