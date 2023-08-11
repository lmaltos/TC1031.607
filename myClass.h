#ifndef MYCLASS_H
#define MYCLASS_H

template <class T, class D>
class myClass {
  private:
    T a;
    T b;
    D x;
    D y;
  public:
    myClass(T _a, T _b, D _x, D _y) : a(_a), b(_b), x(_x), y(_y) {}
    T getA() {return a;}
    T getB() {return b;}
    D getX() {return x;}
    D getY() {return y;}
    T myFunction();
};

template<class T,class D>
T myClass<T,D>::myFunction(){
    return a;
}

#endif