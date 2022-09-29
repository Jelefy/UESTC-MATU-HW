#include <cstdio>
#include <climits>
using namespace std;

int n, res = 1;

int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        if(INT_MAX / i <= res){
            printf("%d!=%d", i - 1, res);
            return 0;
        }
        res *= i;
    }
    printf("%d!=%d", n, res);
    return 0;
}