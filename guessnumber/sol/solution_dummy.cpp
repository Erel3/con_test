
#include "guessnumber.h"
#include <cstdio>

int guess(int n) {
    int l = 1, r = n;
    while(1) {
        char c = ask(l);
        if(c == '=') break;
        l++;
    }
    return l;
}
