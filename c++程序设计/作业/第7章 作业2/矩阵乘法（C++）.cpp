#include <cstdio>
using namespace std;
void Matrix_Mul(int a[3][2], int b[2][4]){
    int res[3][4] = {};
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 4; j++){
            for (int k = 0; k < 2; k++)
                res[i][j] += a[i][k] * b[k][j];
            printf("%d ", res[i][j]);
        }
        putchar('\n');
    }
}