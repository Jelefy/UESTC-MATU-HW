#include "CSet.h"
#include <cstring>
using namespace std;

Set &Set::operator+=(int e){
    if (IsElement(e))
        return *this;
    int *npS = new int[n + 2];
    memcpy(npS + 1, pS + 1, sizeof(int) * n);
    npS[++n] = e;
    delete pS;
    pS = npS;
    return *this;
}
Set &Set::operator-=(int e){
    if (!IsElement(e))
        return *this;
    int *npS = new int[n];
    int p = 0;
    for (int i = 1; i <= n; i++)
        if(pS[i] != e)
            npS[++p] = pS[i];
    n--;
    delete pS;
    pS = npS;
    return *this;
}

Set Set::operator|(const Set &s) const{
    Set ret;
    for (int i = 1; i <= n; i++)
        ret += pS[i];
    for (int i = 1; i <= s.n; i++)
        ret += s.pS[i];
    return ret;
}
Set Set::operator&(const Set &s) const{
    Set ret;
    for (int i = 1; i <= n; i++)
        if (s.IsElement(pS[i]))
            ret += pS[i];
    return ret;
}
Set Set::operator-(const Set &s) const{
    Set ret;
    for (int i = 1; i <= n; i++)
        if(!s.IsElement(pS[i]))
            ret += pS[i];
    return ret;
}
bool Set::operator<=(const Set &s) const{
    for (int i = 1; i <= n; i++)
        if (!s.IsElement(pS[i]))
            return false;
    return true;
}
bool Set::operator==(const Set &s) const{
    if (n != s.n)
        return false;
    for (int i = 1; i <= n; i++)
        if (!s.IsElement(pS[i]))
            return false;
    return true;
}