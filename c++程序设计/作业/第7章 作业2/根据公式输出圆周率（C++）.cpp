#include <cstdio>
#include <cmath>
using namespace std;
const double eps = 1e-8;

int main(){
    int steps = 0;
    double pi = 0;
    int r = 1;
    for (int i = 1;; i += 2){
        steps++;
        double delta = 1.0 / i;
        pi += r * delta;
        if(delta < eps)
            break;
        r = -r;
    }
    printf("steps=%d PI=%.5f", steps, 4 * pi);
    return 0;
}