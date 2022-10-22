#include "ShapeFactory.h"
const float PI = 3.14;

class Triangle : public ShapeFactory{
private:
    float a, b, c;

public:
    Triangle(float a, float b, float c) : a(a), b(b), c(c) {}
    float Circumstance(){
        return a + b + c;
    }
};

class Quadrilateral : public ShapeFactory{
private:
    float a, b, c, d;

public:
    Quadrilateral(float a, float b, float c, float d) : a(a), b(b), c(c), d(d){}
    float Circumstance(){
        return a + b + c + d;
    }
};

class Circle : public ShapeFactory{
private:
    float r;

public:
    Circle(float r) : r(r){}
    float Circumstance(){
        return 2 * PI * r;
    }
};

ShapeFactory *ShapeFactory::Create(float a, float b, float c){
    return new Triangle(a, b, c);
}
ShapeFactory *ShapeFactory::Create(float a, float b, float c, float d){
    return new Quadrilateral(a, b, c, d);
}
ShapeFactory *ShapeFactory::Create(float r){
    return new Circle(r);
}