#include <iostream>
#include <cstring>
#include <cstdlib>
#define maxn 1000
using namespace std;

int a[maxn], b[maxn];

void mul(char str1[], char str2[]){
    int i = 0, j = 0;
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    for (i = len1 - 1, j = 0; i >= 0; i--)
        a[j++] = str1[i] - '0';
    for (i = len2 - 1, j = 0; i >= 0; i--)
        b[j++] = str2[i] - '0';
    int c[maxn] = {};
    for (i = 0; i < len1; i++)
        for (int j = 0; j < len2; j++)
            c[i + j] += a[i] * b[j];
    int len = len1 + len2;
    for (i = 0; i + 1 < len; i++){
        c[i + 1] += c[i] / 10;
        c[i] %= 10;
    }
    while(len >= 0 && c[len - 1] == 0)
        len--;
    if(!len)
        putchar('0');
    else
        for (i = len - 1; i >= 0; i--)
            printf("%d", c[i]);
}

int main(void){
    char str1[maxn], str2[maxn];
    cin >> str1 >> str2;
    mul(str1, str2);
    return 0;
}
