#include <cstdio>
using namespace std;

int n;

int main(){
    scanf("%d", &n);
    if(n <= 3){
        printf("error");
        return 0;
    }
    for (int i = 2; (long long)i * i <= n; i++)
        if(n % i == 0){
            printf("no");
            return 0;
        }
    printf("yes");
    return 0;
}