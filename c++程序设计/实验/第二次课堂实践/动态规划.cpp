#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int dp[1001][1001];
int BestValue(int row[], int col[], int n) {
    if(!row || !col || n <= 0){
        printf("error");
        return 0;
    }
    for (int i = 0; i < n; i++)
        if(row[i] <= 0 || col[i] <= 0){
            printf("error");
            return 0;
        }
    for (int i = 1; i < n; i++)
        if (col[i - 1] != row[i]) {
            printf("error");
            return 0;
        }
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 0; i < n; i++)
        dp[i][i] = 0;
    for (int l = 1; l < n; l++)
        for (int i = 0; i + l < n; i++)
            for (int k = 0; k < l; k++)
                dp[i][i + l] = min(dp[i][i + l], dp[i][i + k] + dp[i + k + 1][i + l] + row[i] * col[i + k] * col[i + l]);
    return dp[0][n - 1];
}