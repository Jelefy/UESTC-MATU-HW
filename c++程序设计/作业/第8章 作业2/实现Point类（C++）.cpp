#include <iostream>
#include <cmath>
using namespace std;
struct Point{
    double x, y;
    Point(double x, double y) : x(x), y(y){}
    double Distance(const Point &b){
        return sqrt((x - b.x) * (x - b.x) + (y - b.y) * (y - b.y));
    }
};

int main(){
    double a,b,c,d;
	cin>>a>>b>>c>>d;
	Point A(a,b),B(c,d);
	cout<<A.Distance(B)<<endl;
	return 0;
}