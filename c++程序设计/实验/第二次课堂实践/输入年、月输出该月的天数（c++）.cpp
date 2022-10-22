#include <cstdio>
using namespace std;
const int DAYS[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
// 每月的天数（平年）

int main(){
    int y, m;
    scanf("%d%d", &y, &m);
    m = (m - 1) % 12 + 1;
    if(m == 2 && (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)))
        printf("days:29");
    else
        printf("days:%d", DAYS[m]);
    return 0;
}