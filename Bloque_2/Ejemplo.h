#ifndef EJEMPLO_H
#define EJEMPLO_H
#include <iostream>

class Ejemplo {
  private:
    int a,b,c;
    float x,y,z;
    char s,t,u;
    int *ptrInt;
    float *ptrFlt;
  public:
    Ejemplo();
    Ejemplo(int);
    Ejemplo(float);
    Ejemplo(char);
    Ejemplo(int,int);
    ~Ejemplo();
    int getA() {return a;}
    int getB() {return b;}
    float getX() {return x;}
    char getS() {return s;}
    void setA(int);
    void setB(int);
};


Ejemplo::Ejemplo() {
    std::cout << "Constructor Ejemplo()" << std::endl;
    ptrInt = NULL;
    ptrFlt = NULL;
    a = b = 0;
}

Ejemplo::Ejemplo(int _a) {
    std::cout << "Constructor Ejemplo(int)" << std::endl;
    a = _a;
    b = 0;
    ptrInt = new int[a];
    ptrFlt = NULL;
}

Ejemplo::Ejemplo(float _x) {
    std::cout << "Constructor Ejemplo(float)" << std::endl;
    x = _x;
    ptrInt = NULL;
    ptrFlt = NULL;
    a = b = 0;
}

Ejemplo::Ejemplo(char _s) {
    std::cout << "Constructor Ejemplo(char)" << std::endl;
    s = _s;
    ptrInt = NULL;
    ptrFlt = NULL;
    a = b = 0;
}

Ejemplo::Ejemplo(int _a, int _b) {
    std::cout << "Constructor Ejemplo(int)" << std::endl;
    a = _a;
    b = _b;
    ptrInt = new int[a];
    ptrFlt = new float[b];
}

Ejemplo::~Ejemplo() {
    std::cout << "Destructor ~Ejemplo()" << std::endl;
    std::cout << "ptrInt[" << a <<"] = " << ptrInt << std::endl;
    delete[] ptrInt;
    std::cout << "ptrflt[" << b << "] = " << ptrFlt << std::endl;
    delete[] ptrFlt;
}

void Ejemplo::setA(int _a) {
    std::cout << "ptrInt[" << a << "] = " << ptrInt << std::endl;
    a = _a;
    delete[] ptrInt;
    ptrInt = new int[a];
}

void Ejemplo::setB(int _b) {
    std::cout << "ptrFlt[" << b << "] = " << ptrFlt << std::endl;
    b = _b;
    delete[] ptrFlt;
    ptrFlt = new float[b];
}


#endif