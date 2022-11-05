#include <map>

int *swapson(int *a, std::map<int, int> &b, int *res, int la, int ra, int lb, int rb){
    if(la > ra)
        return res;
    *res++ = a[la];
    int m = b[a[la++]];
    res = swapson(a, b, res, ra - (rb - m) + 1, ra, m + 1, rb);
    res = swapson(a, b, res, la, la + (m - lb) - 1, lb, m - 1);
    return res;
}

std::map<int, int> pos;
void solve(int n, int *preOrder, int *inOrder, int *outOrder){
    for (int i = 0; i < n; i++)
        pos[inOrder[i]] = i;
    swapson(preOrder, pos, outOrder, 0, n - 1, 0, n - 1);
}