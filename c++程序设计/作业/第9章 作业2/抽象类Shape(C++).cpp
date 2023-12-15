#include "Shape.h"

class Circle:public Shape
{
	private:
		double r;
	public:
		Circle(double r_):Shape()
		{
			r=r_;
		}
	 double GetArea(){
	 	return 3.14*r*r;
	 }
	 double GetPerimeter(){
	 	return 2*3.14*r;
	 }
 }; 
class Rectangle:public Shape//基本上的继承，析构函数，虚构函数 
{
	private:
		double a,b;
	public:
		Rectangle(double a_,double b_):Shape()
		{
			a=a_; b=b_;
		}
		double GetArea()
		{
			return a*b;
		}
		double GetPerimeter()
		{
			return 2*(a+b);
		}
};
Shape * Shape::createRectangle(double l,double w){return new Rectangle(l,w);}
Shape * Shape::createCircle(double r){return new Circle(r);}
void print(Shape *p)//print不是类的成员函数，算是一个全局函数，这里注意 
{
	cout<<"Area:"<<p->GetArea()<<endl<<"Perimeter:"<<p->GetPerimeter()<<endl;
}
