#include "Clock.h"

Clock::Clock(int h, int m, int s){
    hour = h >= 0 && h < 24 ? h : 0;
    minute = m >= 0 && m < 60 ? m : 0;
    second = s >= 0 && s < 60 ? s : 0;
}

void Clock::SetAlarm(int h, int m, int s){
    Ahour = h < 24 ? h : 0;
    Aminute = m < 60 ? m : 0;
    Asecond = s < 60 ? s : 0;
}

void Clock::run(){
    second++;
    if(second == 60){
        second = 0;
        minute++;
    }
    if(minute == 60){
        minute = 0;
        hour++;
    }
    if(hour == 24)
        hour = 0;
    if(hour == Ahour && minute == Aminute && second == Asecond)
        puts("Plink!plink!plink!...");
}