#include "Ejemplo.h"
#include <iostream>

using namespace std;

int main() {
    Ejemplo obj1(2);
    Ejemplo *ptrObj;
    ptrObj = new Ejemplo(3.14f);
    obj1.getA();
    obj1.setB(45);
    (*ptrObj).setA(78);
    ptrObj->setA(90);
    ptrObj->setB(1000);
    delete ptrObj;
}