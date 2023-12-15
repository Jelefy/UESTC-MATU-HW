#include <iostream>
using namespace std;

template <typename _T>
_T get_min(_T *a, int len) {
    _T mi = a[0];
    for (int i = 1; i < len; i++)
        mi = min(mi, a[i]);
    return mi;
}

int main() {
    int arr_int[6] = {1, 2, 3, 4, 5, 6};
    double arr_double[6] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6};
    cout << get_min(arr_int, 6) << endl;
    cout << get_min(arr_double, 6) << endl;
    return 0;
}
