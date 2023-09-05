#ifndef DATE_H
#define DATE_H
#include <string>

using namespace std;
class Date {
  private:
    string month; // Aug, Sep, Oct,...
    int month_i; // 9, 10, 11,...
    int day;
    string hhmmss;
  public:
    bool operator>(const Date &) const;
};

#endif