#include "Clock.h"

class NewClock : public Clock {
public:
    NewClock(int h, int m, int s) : Clock(h, m, s) {}
    void showTime() {
        cout << "Now:" << getHour() % 12 << ":" << getMinute() << ":" << getSecond() << (getHour() < 12 ? "AM" : "PM") << endl;
    }
};
Clock *Clock::createNewClock(int h, int m, int s) {
    return new NewClock(h, m, s);
}