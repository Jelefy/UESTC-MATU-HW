#include <cstdio>
using namespace std;
const int N = 1001;

int n, w[N][N];
bool vis[N];

void dfs(int i){
    if(vis[i])
        return;
    vis[i] = true;
    for (int j = 1; j <= n; j++)
        if(w[i][j])
            dfs(j);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &w[i][j]);
    int ans = 0;
    for (int i = 1; i <= n; i++)
        if(!vis[i]){
            dfs(i);
            ans++;
        }
    printf("%d", ans);
    return 0;
}