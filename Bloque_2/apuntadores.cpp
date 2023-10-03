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
    q = NULL;
    cout << "Despues de delete" << endl;
    cout << "&q = " << &q << endl;
    cout << "q = " << q << endl;
    cout << "*q = " << *q << endl; // Segmentarion fault
}

void Decalogo04() {
    int *p, *q = NULL;
    cout << "p = " << p << endl;
    cout << "q = " << q << endl;
}

void Decalogo05() {
    int *p, a = 41;
    cout << "p = " << p << endl;
    //delete p; puede tronar si p != 0
    p = new int;
    cout << "p = " << p << endl;
    *p = 56;
    cout << "*p = " << *p << endl;
    delete p;
    cout << "delete p" << endl;
    cout << "p = " << p << endl;
    cout << "*p = " << *p << endl;
    //delete p; // ya no apunta a memoria dinamica
    cout << "p = &a" << endl;
    p = &a;
    cout << "p = " << p << endl;
    cout << "*p = " << *p << endl;
    //delete p; // munmap_chunk(): invalid pointer
    p = NULL;
    delete p;
}

void Decalogo06() {
    int *p = NULL;
    cout << "&p = " << &p << endl;
    cout << "p = " << p << endl;
    cout << "*p = " << *p << endl;
}

void Decalogo07() {
    int *p;
    cout << "p = " << p << endl;
    p = new int;
    cout << "p = new int" << endl;
    *p = 55;
    cout << "p = " << p << endl;
    cout << "*p = " << *p << endl;
    p = new int; // referencia anterior a p no fue liberada :(
    cout << "p = new int" << endl;
    cout << "p = " << p << endl;
    cout << "*p = " << *p << endl;
    delete p;
}

void Decalogo08() {
    int a,b,c;
    int *p;
    cout << "&a = " << &a << endl;
    cout << "&b = " << &b << endl;
    cout << "&c = " << &c << endl;
    cout << "&p = " << &p << endl;
    a = 23;
    b = 34;
    c = 45;
    cout << "a = " << a << "\tb = " << b << "\tc = " << c << endl;
    p = &a;
    *p = 56;
    cout << "p = &a; *p = 56" << endl;
    cout << "a = " << a << "\tb = " << b << "\tc = " << c << endl;
    p++;
    *p = 67;
    cout << "p++; *p = 67" << endl;
    cout << "a = " << a << "\tb = " << b << "\tc = " << c << endl;
    p++;
    *p = 78;
    cout << "p++; *p = 78" << endl;
    cout << "a = " << a << "\tb = " << b << "\tc = " << c << endl;
    p++;
    cout << "p = " << p << endl;
    cout << "*p = " << *p << endl;
}

void Decalogo09() {
    int *p, *q;
    int a,b,c;
    cout << "&a = " << &a << endl;
    cout << "&b = " << &b << endl;
    cout << "&c = " << &c << endl;
    p = &a;
    q = &c;
    if (p == q) {
        cout << "p == q\t" << p << endl;
    }
    else {
        cout << "p != q\t" << p << " != " << q << endl;
    }
    p++;
    cout << "p++" << endl;
    if (p == q) {
        cout << "p == q\t" << p << endl;
    }
    else {
        cout << "p != q\t" << p << " != " << q << endl;
    }
    p++;
    cout << "p++" << endl;
    if (p != q) {
        cout << "p != q\t" << p << " != " << q << endl;
    }
    else {
        cout << "p == q\t" << p << endl;
    }

}

void Decalogo10() {
    string *p;
    int *q;
    p = new string;
    *p = "hola";
    cout << "*p = " << *p << endl;
    *p += " mundo";
    cout << "*p = " << *p << endl;
    delete p;

    q = new int;
    *q = 5;
    cout << "*q =5 " << *q << endl;
    (*q)++;
    cout << "(*q)++ " << *q << endl;
    *q /= 2;
    cout << "*q /=2 " << *q << endl;
    *q *= 7;
    cout << "*q *=7 " << *q << endl;
    delete q;
}

int main() {
    Decalogo10();
}