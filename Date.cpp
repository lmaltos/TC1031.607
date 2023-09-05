#include "Date.h"

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