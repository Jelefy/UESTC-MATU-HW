#include <cstdio>
#include <cctype>
using namespace std;
void count(char *s){
    int alpha = 0, digit = 0, space = 0;
    for (char *c = s; *c; c++){
        if(isalpha(*c))
            alpha++;
        else if(isdigit(*c))
            digit++;
        else if(*c == ' ')
            space++;
    }
    printf("%d,%d,%d", alpha, digit, space);
}