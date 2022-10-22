#include <cstring>
#include <iostream>
#define PI (3.14)
using namespace std;

class Table {
private:
    float high;

public:
    Table(float h) : high(h) {}
    float GetHigh() { return high; }
};

class Circle {
private:
    float radius;

public:
    Circle(float r) : radius(r) {}
    float GetArea() {
        return PI * radius * radius;
    }
};

class RoundTable : public Table, public Circle {
private:
    char color[20];

public:
    RoundTable(float r, float h, char *c) : Circle(r), Table(h) {
        strcpy(color, c);
    }
    char *GetColor() {
        return color;
    }
};

int main() {
    float radius, high;
    char color[20];
    cin >> radius >> high >> color;

    RoundTable RT(radius, high, color);
    cout << "Area:" << RT.GetArea() << endl;
    cout << "High:" << RT.GetHigh() << endl;
    cout << "Color:" << RT.GetColor() << endl;
    return 0;
}
