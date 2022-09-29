#include <cstdio>
#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    double res = 0, now;
    bool isdiv = false;
    while(cin >> now){
        if(isdiv)
            res -= now;
        else
            res += now;
        char ch = getchar();
        if(ch == '+')
            isdiv = false;
        else if(ch == '-')
            isdiv = true;
        else if (ch == ';'){
            cout << fixed << setprecision(6) << res;
            return 0;
        }
        else{
            printf("error");
            return 0;
        }
    }
    printf("error");
    return 0;
}