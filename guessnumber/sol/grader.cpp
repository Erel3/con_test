#include <cstdio>
#include <cstdlib>
#include <cassert>

using namespace std;

namespace {
    const int maxn = 1000;
    const int maxq = 1000;
    int numq = 0;
    int n;
    int hidden_number;
    void wrong_answer(const char *MSG) {
        printf("-1\n");
        exit(0);
    }
}

char ask(int x) {
    if (++numq > maxq) wrong_answer("-1");
    if (x < 1 || x > n) wrong_answer("-1");
    if (x < hidden_number) return '<';
    else if (x > hidden_number) return '>';
    else return '=';
}

int guess_number(int n);

int main() {
    assert(scanf("%d %d", &n, &hidden_number) == 2);
    int g = guess_number(n);
    printf("%d\n", g);
    printf("%d\n", numq);
    return 0;
}
