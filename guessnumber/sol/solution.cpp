#include "guessnumber.h"
#include <cstdio>

int guess_number(int n) {
    int l = 1, r = n;
    while(1) {
        int m = (l + r) >> 1;
        char c = ask(m);
        if(c == '=') break;
        if(c == '<') l = m + 1;
        if(c == '>') r = m - 1;
    }
    return (l + r) >> 1;
}
