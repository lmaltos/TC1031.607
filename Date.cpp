#include "Date.h"
#include <vector>

bool Date::operator>(const Date &b) const {
    if (this->month != b.month) {
        return month_i > b.month_i;
    }
    else if (this->day != b.day) {
        return day > b.day;
    }
    else {
        return hhmmss > b.hhmmss;
    }
}

void ejemploCompara() {
    Date a, b;
    if (a > b) {
        
    }
}

template <typename T>
void ordenaPrueba(vector<T> &myVect) {
    int n = myVect.size();
    int i, j;
    T aux;
    for (int i = 0; i < n-1; i++) {
        for (j = i+1; j < n; j++) {
            if (myVect[i] > myVect[j]) {
                aux = myVect[j];
                myVect[j] = myVect[i];
                myVect[i] = aux;
            }
        }
    }
}