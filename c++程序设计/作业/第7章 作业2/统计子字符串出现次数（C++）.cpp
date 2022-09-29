#include <cstdio>
using namespace std;

int SubStrNum(char *str, char *substr){
    int cnt = 0;
    while(*str){
        char *p = str;
        char *q = substr;
        while(*q && *p == *q)
            p++, q++;
        if(!*q){
            cnt++;
            str = p;
        }
        else
            str++;
    }
    printf("match times=%d", cnt);
    return cnt;
}