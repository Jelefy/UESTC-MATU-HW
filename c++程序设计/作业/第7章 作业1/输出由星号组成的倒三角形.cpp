#include <cstdio>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    if(n < 1 || n > 80 || n % 2 == 0){
        printf("error");
        return 0;
    }
    for(int i = n; i >= 1; i -= 2){
        for (int j = 1; j <= (n - i) / 2; j++)
            putchar(' ');
        for (int j = 1; j <= i; j++)
            putchar('*');
        putchar('\n');
    }
    return 0;
}