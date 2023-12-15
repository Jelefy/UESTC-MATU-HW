#include "Shape.h"
#define PI (3.14)
class Rectangle : public Shape {
private:
    double l, w;

public:
    Rectangle(double l, double w) : l(l), w(w) {}
    double GetArea() {
        return l * w;
    }
    double GetPerimeter() {
        return 2 * (l + w);
    }
};
class Circle : public Shape {
private:
    double r;

public:
    Circle(double r) : r(r) {}
    double GetArea() {
        return r * r * PI;
    }
    double GetPerimeter() {
        return 2 * r * PI;
    }
};
Shape *Shape::createRectangle(double l, double w) { return new Rectangle(l, w); }
Shape *Shape::createCircle(double r) { return new Circle(r); }