#include <iostream>
using namespace std;

template <typename _T>
_T get_sum(_T *a, int len) {
    _T ret = 0;
    for (int i = 0; i < len; i++)
        ret += a[i];
    return ret;
}

int main() {
    int arr_int[6] = {1, 2, 3, 4, 5, 6};
    double arr_double[6] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6};
    cout << get_sum(arr_int, 6) << endl;
    cout << get_sum(arr_double, 6) << endl;
    return 0;
}
