#include "ClockAndDate.h"
const int DAYMONTH[2][12] = {
    {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

bool isLeapYear(int year) {
    return year % 400 == 0 || year % 4 == 0 && year % 100 != 0;
}

int Date::days(int year, int month) {
    return DAYMONTH[isLeapYear(year)][month - 1];
}
void Date::NewDay() {
    day++;
    if (day > days(year, month)) {
        day = 1;
        month++;
    }
    if (month > 12) {
        month = 1;
        year++;
    }
}

class ClockWithDate : public Clock, public Date {
public:
    ClockWithDate(int h, int m, int s, int year, int month, int day) : Clock(h, m, s), Date(year, month, day) {}
    virtual void showTime() {
        cout << "Now:" << hour << ":" << minute << ":" << second << endl;
        cout << year << "-" << month << "-" << day << endl;
    }
    virtual void run() {
        second++;
        if (second > 59) {
            second = 0;
            minute++;
        }
        if (minute > 59) {
            minute = 0;
            hour++;
        }
        if (hour > 23) {
            hour = 0;
            NewDay();
        }
    }
};
Clock *Clock::createClockWithDate(int h, int m, int s, int year, int month, int day) {
    return new ClockWithDate(h, m, s, year, month, day);
}
