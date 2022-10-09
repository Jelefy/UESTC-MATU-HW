#include <cstring>
#include <cctype>
#include "CString.h"
using namespace std;

bool String::IsSubstring(const char *str){
    int len = strlen(str);
    for (int i = 0; i + len <= this->len; i++){
        bool flag = true;
        for (int j = 0; j < len; j++)
            if(mystr[i + j] != str[j]){
                flag = false;
                break;
            }
        if(flag)
            return true;
    }
    return false;
}

bool String::IsSubstring(const String &str){
    int len = str.len;
    for (int i = 0; i + len <= this->len; i++){
        bool flag = true;
        for (int j = 0; j < len; j++)
            if(mystr[i + j] != str.mystr[j]){
                flag = false;
                break;
            }
        if(flag)
            return true;
    }
    return false;
}

int String::str2num(){
    int res = 0;
    for (char *c = mystr; *c; c++)
        if(isdigit(*c))
            res = res * 10 + (*c - '0');
    return res;
}

void String::toUppercase(){
    for (char *c = mystr; *c; c++)
        if(islower(*c))
            *c = toupper(*c);
}