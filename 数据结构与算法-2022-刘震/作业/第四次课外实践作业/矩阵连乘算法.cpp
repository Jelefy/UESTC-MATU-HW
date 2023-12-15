#include <cstring>
const int N = 501;

int from[N][N];
long long dp[N][N];

void foo(int l, int r, int *&p){
    if(l + 1 == r){
        *p++ = r;
        return;
    }
    *p++ = -1;
    foo(l, from[l][r], p);
    foo(from[l][r], r, p);
    *p++ = -2;
}

void solve(int n, int p[], int out[]){
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 0; i < n; i++)
        dp[i][i + 1] = 0;
    for (int i = 2; i <= n; i++)
        for (int l = 0; l + i <= n; l++){
            int r = l + i;
            for (int m = l + 1; m < r; m++)
                if(dp[l][r] > dp[l][m] + dp[m][r] + p[l] * p[m] * p[r]){
                    dp[l][r] = dp[l][m] + dp[m][r] + p[l] * p[m] * p[r];
                    from[l][r] = m;
                }
        }
    out[0] = dp[0][n] % 1000000007;
    int *ptr = out + 1;
    foo(0, n, ptr);
}