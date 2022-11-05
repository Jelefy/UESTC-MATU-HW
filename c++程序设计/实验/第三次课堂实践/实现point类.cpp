#include <iostream>
#include <cmath>
using namespace std;

struct Point{
    double a, b;
    Point(double a, double b);
    double Distance(const Point &q) const{
        return sqrt((a - q.a) * (a - q.a) + (b - q.b) * (b - q.b));
    }
};

int main() {
    double a, b, c, d;
    cin >> a >> b >> c >> d;
    Point A(a, b), B(c, d);
    cout << A.Distance(B) << endl;
    return 0;
}