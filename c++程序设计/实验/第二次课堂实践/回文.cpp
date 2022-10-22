#include <cstdio>
#include <cstring>
using namespace std;

char s[31];

int main(){
    scanf("%s", s);
    int n = strlen(s);
    for (int i = 0; i + i < n; i++)
        if(s[i] != s[n - i - 1]){
            printf("false");
            return 0;
        }
    printf("true");
    return 0;
}