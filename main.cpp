#include <iostream>
#include "myClass.h"

using namespace std;

int Max(int a, int b) {
    if (a > b)
        return a;
    return b;
}

template <typename T>
T Max(T a, T b) {
    if (a > b)
        return a;
    return b;
}

int main_old() {
    int a = 5, b= 8;
    float c = 3.14, d = 2.35;
    char e = 'e', f = 'G';
    cout << "Max " << a << " " << b << " es " << Max(a,b) << endl;
    cout << "Max " << c << " " << d << " es " << Max<float>(c,d) << endl;
    cout << "Max " << e << " " << f << " es " << Max<char>(e,f) << endl;
    return 0;
}

int main() {
    myClass<int, float> a(1,2,3.14,9.8);
    cout << "a= " << a.getA() << endl;
    cout << a.myFunction() << endl;
    cout << "b= " << a.getB() << endl;
    return 0;
}