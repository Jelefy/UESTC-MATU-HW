#include <iostream>
#include "CDate.h"
using namespace std;
const int DAY[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int Date::days(int year, int month){
    return DAY[month] + (month == 2 && (year % 400 == 0 || year % 100 != 0 && year % 4 == 0));
}
Date::Date(int y, int m, int d){
    if(m < 1 || m > 12){
        cout << "Invalid month!" << endl;
        m = 1;
    }
    if(d < 1 || d > days(y, m)){
        cout << "Invalid day!" << endl;
        d = 1;
    }
    year = y, month = m, day = d;
}
void Date::NewDay(){
    day++;
    if(day > days(year, month)){
        month++;
        day = 1;
        if(month > 12){
            year++;
            month = 1;
        }
    }
}