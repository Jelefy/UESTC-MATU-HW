#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string bigint_minus(string a, string b){
    if(a.length() < b.length() || (a.length() == b.length() && a < b))
        return (string)"-" + bigint_minus(b, a).substr(1);
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    for (int i = 0; i < b.length(); i++){
        a[i] -= b[i] - '0';
        if(a[i] < '0'){
            a[i] += 10;
            a[i + 1]--;
        }
    }
    a.push_back('+');
    reverse(a.begin(), a.end());
    return a;
}

int main(){
    string a, b;
    cin >> a >> b;
    if(a == b)
        putchar('0');
    else
        cout << bigint_minus(a, b);
    return 0;
}