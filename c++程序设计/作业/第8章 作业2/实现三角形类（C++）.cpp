#include <iostream>
#include <cmath>
using namespace std;

struct Ctriangle{
    double a, b, c;
    Ctriangle(double a, double b, double c) : a(a), b(b), c(c){}
    void display(){
        cout << "Ctriangle:a=" << a << ",b=" << b << ",c=" << c << endl;
    }
    double GetPerimeter(){
        return a + b + c;
    }
    double GetArea(){
        double p = (a + b + c) / 2;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }
};

int main(){
	double a,b,c;
	cin>>a>>b>>c;
	Ctriangle T(a,b,c);
	T.display();
	cout<<"Perimeter:"<<T.GetPerimeter()<<endl;
	cout<<"Area:"<<T.GetArea()<<endl;
	return 0;	 
}